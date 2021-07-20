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

#ifndef HEADER_LIBLINUX_TYPES_H_INCLUDED
#define HEADER_LIBLINUX_TYPES_H_INCLUDED

#include "version.h"
#include "endian.h"
#include "arch.h"

#include <stdint.h>

//=============================================================================
// Generic types

typedef int32_t  linux_fd_t;
typedef int32_t  linux_pid_t;
typedef uint32_t linux_poll_t;
typedef int32_t  linux_rwf_t;

#endif // !HEADER_LIBLINUX_TYPES_H_INCLUDED
