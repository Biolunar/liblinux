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

#ifndef HEADER_LIBLINUX_TEST_TYPES_H_INCLUDED
#define HEADER_LIBLINUX_TEST_TYPES_H_INCLUDED

typedef int linux_kernel_pid_t;
typedef linux_kernel_pid_t linux_pid_t;
typedef unsigned int linux_fd_t;
typedef unsigned short linux_umode_t;

enum
{
	linux_AT_FDCWD = -100,

	linux_O_RDONLY = 00000000,

	linux_MREMAP_MAYMOVE = 1,
};

#ifdef __i386__
#include "x86/arch.h"
#elif __x86_64__
#ifdef __ILP32__
#include "x32/arch.h"
#else // __ILP32__
#include "x86_64/arch.h"
#endif // __ILP32__
#elif __aarch64__
#include "arm64/arch.h"
#endif

typedef linux_kernel_long_t linux_kernel_off_t;
typedef linux_kernel_off_t linux_off_t;

#endif // !HEADER_LIBLINUX_TEST_TYPES_H_INCLUDED
