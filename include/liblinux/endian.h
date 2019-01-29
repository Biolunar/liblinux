/*
 * Copyright 2018-2019 Mahdi Khanalizadeh
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

#ifndef HEADER_LIBLINUX_ENDIAN_H_INCLUDED
#define HEADER_LIBLINUX_ENDIAN_H_INCLUDED

#include "version.h"

// If no endianness was selected, autodetect it.
#if !defined(LINUX_ENDIAN_LITTE) && \
    !defined(LINUX_ENDIAN_BIG)

// GCC macros
#if defined(__BYTE_ORDER__)          && \
    defined(__ORDER_LITTLE_ENDIAN__) && \
    defined(__ORDER_BIG_ENDIAN__)

#if   __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define LINUX_ENDIAN_LITTE
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#define LINUX_ENDIAN_BIG
#endif

#endif // End GCC macros

// ARM macros
#if defined(__ARMEL__)   || \
    defined(__THUMBEL__)
#define LINUX_ENDIAN_LITTE
#elif defined(__ARMEB__)   || \
      defined(__THUMBEB__)
#define LINUX_ENDIAN_BIG
#endif

// ARM64 macros
#if defined(__AARCH64EL__)
#define LINUX_ENDIAN_LITTE
#elif defined(__AARCH64BL__)
#define LINUX_ENDIAN_BIG
#endif

#endif // End autodetect

#if !defined(LINUX_ENDIAN_LITTE) && \
    !defined(LINUX_ENDIAN_BIG)
#error "Endianness could not be autodetected."
#endif

#if defined(LINUX_ENDIAN_LITTE) && \
    defined(LINUX_ENDIAN_BIG)
#error "Cannot select both little and big endian at the same time."
#endif

#endif // !HEADER_LIBLINUX_ENDIAN_H_INCLUDED
