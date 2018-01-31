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

#ifndef HEADER_LIBLINUX_SYSCALL_TESTS_X32_H_INCLUDED
#define HEADER_LIBLINUX_SYSCALL_TESTS_X32_H_INCLUDED

typedef long long linux_kernel_long_t;
typedef void linux_signalfn_t(int);
typedef linux_signalfn_t* linux_sighandler_t;
typedef struct
{
	unsigned long sig[1]; // TODO: Is this really only 1?
} linux_sigset_t;
struct linux_sigaction_t
{
	linux_sighandler_t sa_handler;
	unsigned long sa_flags;
	linux_sigrestore_t sa_restorer;
	linux_sigset_t sa_mask;
};

enum
{
	linux_PROT_READ = 0x1,
	linux_PROT_WRITE = 0x2,

	linux_MAP_PRIVATE = 0x02,

	linux_MAP_ANONYMOUS = 0x20,

	linux_SIGUSR1 = 10,

	linux_SA_RESTORER = 0x04000000,
};

#endif // !HEADER_LIBLINUX_SYSCALL_TESTS_X32_H_INCLUDED
