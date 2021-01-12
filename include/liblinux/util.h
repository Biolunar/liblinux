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

#ifndef HEADER_LIBLINUX_UTIL_H_INCLUDED
#define HEADER_LIBLINUX_UTIL_H_INCLUDED

#include "version.h"
#include "arch.h"

#include <stdint.h>

#if defined(LINUX_ARCH_X86)
/*
 * linux_set_gs is used to set the gs register. Useful after the
 * linux_set_thread_area syscall. You can easily do that by yourself but you
 * have to touch assembly, so here's a convenience function.
 */
void linux_set_gs(uintptr_t value);
#endif

#endif // !HEADER_LIBLINUX_UTIL_H_INCLUDED
