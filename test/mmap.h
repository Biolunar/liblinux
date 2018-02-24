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

#ifndef HEADER_LIBLINUX_TEST_MMAP_H_INCLUDED
#define HEADER_LIBLINUX_TEST_MMAP_H_INCLUDED

#include "types.h"

#include <stddef.h>

#include <liblinux/error.h>

enum linux_error_t mmap(void const* addr, size_t len, unsigned long prot, unsigned long flags, linux_fd_t fd, linux_off_t off, void** result);

#endif // !HEADER_LIBLINUX_TEST_MMAP_H_INCLUDED
