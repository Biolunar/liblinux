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

#ifndef HEADER_LIBLINUX_SPARC_ERROR_H_INCLUDED
#define HEADER_LIBLINUX_SPARC_ERROR_H_INCLUDED

#include "../generic/errno-base.h"

#include <stdint.h>

#define linux_EWOULDBLOCK     linux_EAGAIN  ///< Operation would block
#define linux_EINPROGRESS     UINT16_C( 36) ///< Operation now in progress
#define linux_EALREADY        UINT16_C( 37) ///< Operation already in progress
#define linux_ENOTSOCK        UINT16_C( 38) ///< Socket operation on non-socket
#define linux_EDESTADDRREQ    UINT16_C( 39) ///< Destination address required
#define linux_EMSGSIZE        UINT16_C( 40) ///< Message too long
#define linux_EPROTOTYPE      UINT16_C( 41) ///< Protocol wrong type for socket
#define linux_ENOPROTOOPT     UINT16_C( 42) ///< Protocol not available
#define linux_EPROTONOSUPPORT UINT16_C( 43) ///< Protocol not supported
#define linux_ESOCKTNOSUPPORT UINT16_C( 44) ///< Socket type not supported
#define linux_EOPNOTSUPP      UINT16_C( 45) ///< Op not supported on transport endpoint
#define linux_EPFNOSUPPORT    UINT16_C( 46) ///< Protocol family not supported
#define linux_EAFNOSUPPORT    UINT16_C( 47) ///< Address family not supported by protocol
#define linux_EADDRINUSE      UINT16_C( 48) ///< Address already in use
#define linux_EADDRNOTAVAIL   UINT16_C( 49) ///< Cannot assign requested address
#define linux_ENETDOWN        UINT16_C( 50) ///< Network is down
#define linux_ENETUNREACH     UINT16_C( 51) ///< Network is unreachable
#define linux_ENETRESET       UINT16_C( 52) ///< Net dropped connection because of reset
#define linux_ECONNABORTED    UINT16_C( 53) ///< Software caused connection abort
#define linux_ECONNRESET      UINT16_C( 54) ///< Connection reset by peer
#define linux_ENOBUFS         UINT16_C( 55) ///< No buffer space available
#define linux_EISCONN         UINT16_C( 56) ///< Transport endpoint is already connected
#define linux_ENOTCONN        UINT16_C( 57) ///< Transport endpoint is not connected
#define linux_ESHUTDOWN       UINT16_C( 58) ///< No send after transport endpoint shutdown
#define linux_ETOOMANYREFS    UINT16_C( 59) ///< Too many references: cannot splice
#define linux_ETIMEDOUT       UINT16_C( 60) ///< Connection timed out
#define linux_ECONNREFUSED    UINT16_C( 61) ///< Connection refused
#define linux_ELOOP           UINT16_C( 62) ///< Too many symbolic links encountered
#define linux_ENAMETOOLONG    UINT16_C( 63) ///< File name too long
#define linux_EHOSTDOWN       UINT16_C( 64) ///< Host is down
#define linux_EHOSTUNREACH    UINT16_C( 65) ///< No route to host
#define linux_ENOTEMPTY       UINT16_C( 66) ///< Directory not empty
#define linux_EPROCLIM        UINT16_C( 67) ///< SUNOS: Too many processes
#define linux_EUSERS          UINT16_C( 68) ///< Too many users
#define linux_EDQUOT          UINT16_C( 69) ///< Quota exceeded
#define linux_ESTALE          UINT16_C( 70) ///< Stale file handle
#define linux_EREMOTE         UINT16_C( 71) ///< Object is remote
#define linux_ENOSTR          UINT16_C( 72) ///< Device not a stream
#define linux_ETIME           UINT16_C( 73) ///< Timer expired
#define linux_ENOSR           UINT16_C( 74) ///< Out of streams resources
#define linux_ENOMSG          UINT16_C( 75) ///< No message of desired type
#define linux_EBADMSG         UINT16_C( 76) ///< Not a data message
#define linux_EIDRM           UINT16_C( 77) ///< Identifier removed
#define linux_EDEADLK         UINT16_C( 78) ///< Resource deadlock would occur
#define linux_ENOLCK          UINT16_C( 79) ///< No record locks available
#define linux_ENONET          UINT16_C( 80) ///< Machine is not on the network
#define linux_ERREMOTE        UINT16_C( 81) ///< SunOS: Too many lvls of remote in path
#define linux_ENOLINK         UINT16_C( 82) ///< Link has been severed
#define linux_EADV            UINT16_C( 83) ///< Advertise error
#define linux_ESRMNT          UINT16_C( 84) ///< Srmount error
#define linux_ECOMM           UINT16_C( 85) ///< Communication error on send
#define linux_EPROTO          UINT16_C( 86) ///< Protocol error
#define linux_EMULTIHOP       UINT16_C( 87) ///< Multihop attempted
#define linux_EDOTDOT         UINT16_C( 88) ///< RFS specific error
#define linux_EREMCHG         UINT16_C( 89) ///< Remote address changed
#define linux_ENOSYS          UINT16_C( 90) ///< Function not implemented
#define linux_ESTRPIPE        UINT16_C( 91) ///< Streams pipe error
#define linux_EOVERFLOW       UINT16_C( 92) ///< Value too large for defined data type
#define linux_EBADFD          UINT16_C( 93) ///< File descriptor in bad state
#define linux_ECHRNG          UINT16_C( 94) ///< Channel number out of range
#define linux_EL2NSYNC        UINT16_C( 95) ///< Level 2 not synchronized
#define linux_EL3HLT          UINT16_C( 96) ///< Level 3 halted
#define linux_EL3RST          UINT16_C( 97) ///< Level 3 reset
#define linux_ELNRNG          UINT16_C( 98) ///< Link number out of range
#define linux_EUNATCH         UINT16_C( 99) ///< Protocol driver not attached
#define linux_ENOCSI          UINT16_C(100) ///< No CSI structure available
#define linux_EL2HLT          UINT16_C(101) ///< Level 2 halted
#define linux_EBADE           UINT16_C(102) ///< Invalid exchange
#define linux_EBADR           UINT16_C(103) ///< Invalid request descriptor
#define linux_EXFULL          UINT16_C(104) ///< Exchange full
#define linux_ENOANO          UINT16_C(105) ///< No anode
#define linux_EBADRQC         UINT16_C(106) ///< Invalid request code
#define linux_EBADSLT         UINT16_C(107) ///< Invalid slot
#define linux_EDEADLOCK       UINT16_C(108) ///< File locking deadlock error
#define linux_EBFONT          UINT16_C(109) ///< Bad font file format
#define linux_ELIBEXEC        UINT16_C(110) ///< Cannot exec a shared library directly
#define linux_ENODATA         UINT16_C(111) ///< No data available
#define linux_ELIBBAD         UINT16_C(112) ///< Accessing a corrupted shared library
#define linux_ENOPKG          UINT16_C(113) ///< Package not installed
#define linux_ELIBACC         UINT16_C(114) ///< Can not access a needed shared library
#define linux_ENOTUNIQ        UINT16_C(115) ///< Name not unique on network
#define linux_ERESTART        UINT16_C(116) ///< Interrupted syscall should be restarted
#define linux_EUCLEAN         UINT16_C(117) ///< Structure needs cleaning
#define linux_ENOTNAM         UINT16_C(118) ///< Not a XENIX named type file
#define linux_ENAVAIL         UINT16_C(119) ///< No XENIX semaphores available
#define linux_EISNAM          UINT16_C(120) ///< Is a named type file
#define linux_EREMOTEIO       UINT16_C(121) ///< Remote I/O error
#define linux_EILSEQ          UINT16_C(122) ///< Illegal byte sequence
#define linux_ELIBMAX         UINT16_C(123) ///< Atmpt to link in too many shared libs
#define linux_ELIBSCN         UINT16_C(124) ///< .lib section in a.out corrupted
#define linux_ENOMEDIUM       UINT16_C(125) ///< No medium found
#define linux_EMEDIUMTYPE     UINT16_C(126) ///< Wrong medium type
#define linux_ECANCELED       UINT16_C(127) ///< Operation Cancelled
#define linux_ENOKEY          UINT16_C(128) ///< Required key not available
#define linux_EKEYEXPIRED     UINT16_C(129) ///< Key has expired
#define linux_EKEYREVOKED     UINT16_C(130) ///< Key has been revoked
#define linux_EKEYREJECTED    UINT16_C(131) ///< Key was rejected by service
#define linux_EOWNERDEAD      UINT16_C(132) ///< For robust mutexes: Owner died
#define linux_ENOTRECOVERABLE UINT16_C(133) ///< For robust mutexes: State not recoverable
#define linux_ERFKILL         UINT16_C(134) ///< Operation not possible due to RF-kill
#define linux_EHWPOISON       UINT16_C(135) ///< Memory page has hardware error

#endif // !HEADER_LIBLINUX_SPARC_ERROR_H_INCLUDED
