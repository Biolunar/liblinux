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

#ifndef HEADER_LIBLINUX_GENERIC_ERROR_BASE_H_INCLUDED
#define HEADER_LIBLINUX_GENERIC_ERROR_BASE_H_INCLUDED

#include "../version.h"
#include "../endian.h"
#include "../arch.h"

#include <stdint.h>

#define linux_EPERM   UINT16_C(  1) ///< Operation not permitted
#define linux_ENOENT  UINT16_C(  2) ///< No such file or directory
#define linux_ESRCH   UINT16_C(  3) ///< No such process
#define linux_EINTR   UINT16_C(  4) ///< Interrupted system call
#define linux_EIO     UINT16_C(  5) ///< I/O error
#define linux_ENXIO   UINT16_C(  6) ///< No such device or address
#define linux_E2BIG   UINT16_C(  7) ///< Argument list too long
#define linux_ENOEXEC UINT16_C(  8) ///< Exec format error
#define linux_EBADF   UINT16_C(  9) ///< Bad file number
#define linux_ECHILD  UINT16_C( 10) ///< No child processes
#define linux_EAGAIN  UINT16_C( 11) ///< Try again
#define linux_ENOMEM  UINT16_C( 12) ///< Out of memory
#define linux_EACCES  UINT16_C( 13) ///< Permission denied
#define linux_EFAULT  UINT16_C( 14) ///< Bad address
#define linux_ENOTBLK UINT16_C( 15) ///< Block device required
#define linux_EBUSY   UINT16_C( 16) ///< Device or resource busy
#define linux_EEXIST  UINT16_C( 17) ///< File exists
#define linux_EXDEV   UINT16_C( 18) ///< Cross-device link
#define linux_ENODEV  UINT16_C( 19) ///< No such device
#define linux_ENOTDIR UINT16_C( 20) ///< Not a directory
#define linux_EISDIR  UINT16_C( 21) ///< Is a directory
#define linux_EINVAL  UINT16_C( 22) ///< Invalid argument
#define linux_ENFILE  UINT16_C( 23) ///< File table overflow
#define linux_EMFILE  UINT16_C( 24) ///< Too many open files
#define linux_ENOTTY  UINT16_C( 25) ///< Not a typewriter
#define linux_ETXTBSY UINT16_C( 26) ///< Text file busy
#define linux_EFBIG   UINT16_C( 27) ///< File too large
#define linux_ENOSPC  UINT16_C( 28) ///< No space left on device
#define linux_ESPIPE  UINT16_C( 29) ///< Illegal seek
#define linux_EROFS   UINT16_C( 30) ///< Read-only file system
#define linux_EMLINK  UINT16_C( 31) ///< Too many links
#define linux_EPIPE   UINT16_C( 32) ///< Broken pipe
#define linux_EDOM    UINT16_C( 33) ///< Math argument out of domain of func
#define linux_ERANGE  UINT16_C( 34) ///< Math result not representable

#endif // !HEADER_LIBLINUX_GENERIC_ERROR_BASE_H_INCLUDED
