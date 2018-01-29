/*
 * Copyright 2017 Mahdi Khanalizadeh
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "syscall.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#if __STDC_VERSION__ >= 201112L
#include <stdnoreturn.h>
#else // __STDC_VERSION__ >= 201112L
#define noreturn
#endif // __STDC_VERSION__ >= 201112L

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef int linux_kernel_pid_t;
typedef linux_kernel_pid_t linux_pid_t;
typedef unsigned int linux_fd_t;
typedef unsigned short linux_umode_t;
typedef void linux_restorefn_t(void);
typedef linux_restorefn_t* linux_sigrestore_t;

enum
{
	linux_AT_FDCWD = -100,

	linux_O_RDONLY = 00000000,

	linux_MREMAP_MAYMOVE = 1,
};

#ifdef __i386__
#include "i386.h"
#elif __x86_64__
#ifdef __ILP32__
#include "x32.h"
#else // __ILP32__
#include "x86_64.h"
#endif // __ILP32__
#elif __aarch64__
#include "aarch64.h"
#else
#error "Unsupported architecture"
#endif

typedef linux_kernel_long_t linux_kernel_off_t;
typedef linux_kernel_off_t linux_off_t;

/*
 * A small selection of syscalls from 0 to 6 parameters.
 *
 * These syscalls were chosen because the require very few extra type
 * definitions. Also it is easy to verify if they work as expected.
 */
static LINUX_DEFINE_SYSCALL0_RET(getpid, linux_pid_t)
static LINUX_DEFINE_SYSCALL1_NORET(close, linux_fd_t, fd)
static LINUX_DEFINE_SYSCALL2_NORET(pipe2, linux_fd_t*, fildes, int, flags)
static LINUX_DEFINE_SYSCALL2_NORET(munmap, void const*, addr, size_t, len)
static LINUX_DEFINE_SYSCALL2_NORET(kill, linux_pid_t, pid, int, sig)
static LINUX_DEFINE_SYSCALL3_RET(read, linux_fd_t, fd, void*, buf, size_t, count, size_t)
static LINUX_DEFINE_SYSCALL3_RET(write, linux_fd_t, fd, void const*, buf, size_t, count, size_t)
static LINUX_DEFINE_SYSCALL4_NORET(rt_sigaction, int, sig, struct linux_sigaction_t const*, act, struct linux_sigaction_t*, oact, size_t, sigsetsize)
static LINUX_DEFINE_SYSCALL5_RET(mremap, void const*, addr, size_t, old_len, size_t, new_len, unsigned long, flags, void const*, new_addr, void*)
#ifdef __i386__
static LINUX_DEFINE_SYSCALL6_RET(mmap2, void const*, addr, size_t, len, unsigned long, prot, unsigned long, flags, linux_fd_t, fd, linux_off_t, off, void*)
#else // __i386__
static LINUX_DEFINE_SYSCALL6_RET(mmap, void const*, addr, size_t, len, unsigned long, prot, unsigned long, flags, linux_fd_t, fd, linux_off_t, off, void*)
#endif // __i386__

static char const msg[] = "This is a test message.";
static bool volatile signaled = false;
enum { buffer_size = 512 };

static noreturn void die(char const* const err)
{
	fprintf(stderr, "\x1B[31m%s\x1B[m\n", err);
	exit(EXIT_FAILURE);
}

static linux_pid_t get_pid(void)
{
	linux_pid_t pid = 0;
	if (linux_getpid(&pid))
		die("linux_getpid failed");

	if (pid != getpid())
		die("linux_getpid returned the wrong pid");

	return pid;
}

static void test_pipe(void)
{
	linux_fd_t fds[2] = {(linux_fd_t)-1, (linux_fd_t)-1};
	if (linux_pipe2(fds, 0))
		die("linux_pipe failed");

	size_t bytes_written = 0;
	if (linux_write(fds[1], msg, sizeof msg, &bytes_written))
		die("linux_write failed");

	if (bytes_written != sizeof msg)
		die("linux_write did not write everything");

	char buf[sizeof msg];
	size_t bytes_read = 0;
	if (linux_read(fds[0], buf, sizeof buf, &bytes_read))
		die("linux_read failed");

	if (bytes_read != sizeof msg)
		die("linux_read did not read everything");

	if (linux_close(fds[0]) || linux_close(fds[1]))
		die("linux_close failed");
}

static void test_memory(void)
{
	size_t const old_size = sizeof msg;
	void* old_addr = 0;
#ifdef __i386__
	if (linux_mmap2(0, old_size, linux_PROT_READ | linux_PROT_WRITE, linux_MAP_PRIVATE | linux_MAP_ANONYMOUS, 0, 0, &old_addr))
#else // __i386__
	if (linux_mmap(0, old_size, linux_PROT_READ | linux_PROT_WRITE, linux_MAP_PRIVATE | linux_MAP_ANONYMOUS, 0, 0, &old_addr))
#endif // __i386__
		die("linux_mmap failed");
	memset(old_addr, 0, old_size);

	size_t const new_size = 2 * old_size;
	void* new_addr = 0;
	enum linux_error_t err = linux_mremap(old_addr, old_size, new_size, linux_MREMAP_MAYMOVE, 0, &new_addr);
	if (err)
	{
		printf("%d\n", err);
		die("linux_mremap failed");
	}
	memset(new_addr, 0, new_size);

	if (linux_munmap(new_addr, new_size))
		die("linux_munmap failed");
}

static void signal_handler(int sig)
{
	(void)sig;

	signaled = true;
}

static void test_signal(void)
{
	struct linux_sigaction_t sa =
	{
#ifdef __i386__
		.u.sa_handler = &signal_handler,
#else // __i386__
		.sa_handler = &signal_handler,
#endif // __i386__
		.sa_flags = linux_SA_RESTORER,
		.sa_restorer = &linux_rt_sigreturn,
	};

	if (linux_rt_sigaction(linux_SIGUSR1, &sa, 0, sizeof(linux_sigset_t)))
		die("linux_rt_sigaction failed");

	if (linux_kill(get_pid(), linux_SIGUSR1))
		die("linux_kill failed");

	if (!signaled)
		die("Signal did not fire");
}

int main(void)
{
	printf("Starting test...\n");

	test_pipe();
	test_memory();
	test_signal();

	printf("Test finished \x1B[32mSUCCESSFULLY\x1B[m\n");
	return EXIT_SUCCESS;
}
