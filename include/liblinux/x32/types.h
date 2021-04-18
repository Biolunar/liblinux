/*
 * Copyright 2018-2021 Mahdi Khanalizadeh
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

#ifndef HEADER_LIBLINUX_X32_TYPES_H_INCLUDED
#define HEADER_LIBLINUX_X32_TYPES_H_INCLUDED

#include <stdint.h>

typedef uint32_t           linux_size_t;
typedef void               linux_signalfn_t(int);
typedef linux_signalfn_t*  linux_sighandler_t;
typedef void               linux_restorefn_t(void);
typedef linux_restorefn_t* linux_sigrestore_t;
typedef long               linux_si_band_t;

//-----------------------------------------------------------------------------
// TODO

typedef int               linux_daddr_t;
typedef unsigned int      linux_mode_t;
typedef int               linux_ipc_pid_t; // unused
typedef int               linux_ssize_t;
typedef linux_word_t      linux_suseconds_t;
typedef linux_uword_t     linux_ino_t;
typedef uint32_t          linux_statfs_word;

#endif // !HEADER_LIBLINUX_X32_TYPES_H_INCLUDED
