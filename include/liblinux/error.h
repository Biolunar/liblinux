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

#ifndef HEADER_LIBLINUX_ERROR_H_INCLUDED
#define HEADER_LIBLINUX_ERROR_H_INCLUDED

#include "version.h"
#include "endian.h"
#include "arch.h"

#include <stdint.h>

/**
 * Error type.
 * The value 0 means no error.
 */
typedef uint16_t linux_error_t;

/**
 * Get the error code from the return value of a raw syscall.
 *
 * If the syscall did not return an error, this function returns 0.
 */
inline linux_error_t linux_get_error(linux_word_t ret)
{
	if (ret < 0 && ret > -4096) {
		return (linux_error_t)-ret;
	} else {
		return 0;
	}
}

#if defined(LINUX_ARCH_ALPHA)
#include "alpha/error.h"
#elif defined(LINUX_ARCH_MIPS)
#include "mips/error.h"
#elif defined(LINUX_ARCH_PARISC)
#include "parisc/error.h"
#elif defined(LINUX_ARCH_POWERPC)
#include "powerpc/error.h"
#elif defined(LINUX_ARCH_SPARC)
#include "sparc/error.h"
#elif defined(LINUX_ARCH_ARM_EABI) || \
      defined(LINUX_ARCH_ARM64)    || \
      defined(LINUX_ARCH_RISCV32)  || \
      defined(LINUX_ARCH_RISCV64)  || \
      defined(LINUX_ARCH_X86)      || \
      defined(LINUX_ARCH_X32)      || \
      defined(LINUX_ARCH_X86_64)
#include "generic/error.h"
#else
#error "Unknown architecture."
#endif

#endif // !HEADER_LIBLINUX_ERROR_H_INCLUDED
