/*
 * Copyright 2018-2020 Mahdi Khanalizadeh
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

#ifndef HEADER_LIBLINUX_X86_64_TYPES_H_INCLUDED
#define HEADER_LIBLINUX_X86_64_TYPES_H_INCLUDED

#include <stdint.h>

typedef int                  linux_daddr_t;
typedef long                 linux_kernel_long_t;
typedef unsigned long        linux_kernel_ulong_t;
typedef unsigned int         linux_kernel_mode_t;
typedef int                  linux_kernel_ipc_pid_t;
typedef linux_kernel_ulong_t linux_kernel_size_t;
typedef linux_kernel_long_t  linux_kernel_ssize_t;
typedef linux_kernel_long_t  linux_suseconds_t;
typedef linux_kernel_ulong_t linux_kernel_ino_t;
typedef linux_kernel_long_t  linux_statfs_word;
typedef linux_signalfn_t*    linux_sighandler_t;

#endif // !HEADER_LIBLINUX_X86_64_TYPES_H_INCLUDED
