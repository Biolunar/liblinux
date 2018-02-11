/*
 * Copyright 2018 Mahdi Khanalizadeh
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

#ifndef HEADER_LIBLINUX_SYSCALL_TESTS_X86_ARCH_H_INCLUDED
#define HEADER_LIBLINUX_SYSCALL_TESTS_X86_ARCH_H_INCLUDED

typedef long linux_kernel_long_t;
typedef void linux_signalfn_t(int);
typedef linux_signalfn_t* linux_sighandler_t;
typedef void linux_restorefn_t(void);
typedef linux_restorefn_t* linux_sigrestore_t;
typedef struct
{
	unsigned long sig[2];
} linux_sigset_t;
typedef unsigned int linux_kernel_uid32_t;
typedef linux_kernel_long_t linux_kernel_clock_t;
typedef int linux_kernel_timer_t;
typedef union
{
	int sival_int;
	void* sival_ptr;
} linux_sigval_t;
typedef unsigned int linux_u32;
typedef long linux_arch_si_band_t;
struct linux_siginfo_t
{
	int si_signo;
	int si_errno;
	int si_code;

	union
	{
		int _pad[29];

		struct
		{
			linux_kernel_pid_t pid;
			linux_kernel_uid32_t uid;
		} kill;

		struct
		{
			linux_kernel_timer_t tid;
			int overrun;
			linux_sigval_t sigval;
			int sys_private;
		} timer;

		struct
		{
			linux_kernel_pid_t pid;
			linux_kernel_uid32_t uid;
			linux_sigval_t sigval;
		} rt;

		struct
		{
			linux_kernel_pid_t pid;
			linux_kernel_uid32_t uid;
			int status;
			linux_kernel_clock_t utime;
			linux_kernel_clock_t stime;
		} sigchld;

		struct
		{
			void* addr;
			short addr_lsb;
			char _pad[2];
			union
			{
				struct
				{
					void* lower;
					void* upper;
				} addr_bnd;
				linux_u32 pkey;
			};
		} sigfault;

		struct
		{
			linux_arch_si_band_t band;
			int fd;
		} sigpoll;

		struct
		{
			void* call_addr;
			int syscall;
			unsigned int arch;
		} sigsys;
	} sifields;
};
struct linux_sigaction_t
{
	union
	{
		linux_sighandler_t sa_handler;
		void (*sa_sigaction)(int, struct linux_siginfo_t*, void*);
	} u;
	linux_sigset_t sa_mask;
	unsigned long sa_flags;
	void (*sa_restorer)(void);
};

enum
{
	linux_PROT_READ = 0x1,
	linux_PROT_WRITE = 0x2,

	linux_MAP_PRIVATE = 0x02,

	linux_MAP_ANONYMOUS = 0x20,

	linux_SIGUSR1 = 10,

	linux_SA_RESTORER = 0x04000000,

	linux_PAGE_SHIFT = 12,
};

#endif // !HEADER_LIBLINUX_SYSCALL_TESTS_X86_ARCH_H_INCLUDED
