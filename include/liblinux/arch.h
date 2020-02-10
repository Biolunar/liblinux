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

#ifndef HEADER_LIBLINUX_ARCH_H_INCLUDED
#define HEADER_LIBLINUX_ARCH_H_INCLUDED

#include "version.h"

#include <stdint.h>

// If no arch was selected, autodetect it.
#if !defined(LINUX_ARCH_ARM_EABI) && \
    !defined(LINUX_ARCH_ARM64)    && \
    !defined(LINUX_ARCH_X86)      && \
    !defined(LINUX_ARCH_X32)      && \
    !defined(LINUX_ARCH_X86_64)

#ifdef __arm__
#define LINUX_ARCH_ARM_EABI
#endif

#ifdef __aarch64__
#define LINUX_ARCH_ARM64
#endif

#ifdef __i386__
#define LINUX_ARCH_X86
#endif

#ifdef __x86_64__
#ifdef __ILP32__
#define LINUX_ARCH_X32
#else
#define LINUX_ARCH_X86_64
#endif
#endif

#endif // End autodetect

// Set some architecture specific stuff and test if the autodetect has failed.
#if defined(LINUX_ARCH_ARM_EABI)
#define LINUX_BITS_PER_LONG 32
typedef int32_t  linux_word_t;
typedef uint32_t linux_uword_t;
#elif defined(LINUX_ARCH_ARM64)
#define LINUX_BITS_PER_LONG 64
typedef int64_t  linux_word_t;
typedef uint64_t linux_uword_t;
#elif defined(LINUX_ARCH_X86)
#define LINUX_BITS_PER_LONG 32
typedef int32_t  linux_word_t;
typedef uint32_t linux_uword_t;
#elif defined(LINUX_ARCH_X32)
#define LINUX_BITS_PER_LONG 32
typedef int64_t  linux_word_t;
typedef uint64_t linux_uword_t;
#elif defined(LINUX_ARCH_X86_64)
#define LINUX_BITS_PER_LONG 64
typedef int64_t  linux_word_t;
typedef uint64_t linux_uword_t;
#else
#error "No architecture was selected and it could not be detected automatically."
#endif

#endif // !HEADER_LIBLINUX_ARCH_H_INCLUDED
