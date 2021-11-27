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

#ifndef HEADER_LIBLINUX_PARISC_ERROR_H_INCLUDED
#define HEADER_LIBLINUX_PARISC_ERROR_H_INCLUDED

#include "../generic/error-base.h"

#include <stdint.h>

#define linux_ENOMSG          UINT16_C( 35)      ///< No message of desired type
#define linux_EIDRM           UINT16_C( 36)      ///< Identifier removed
#define linux_ECHRNG          UINT16_C( 37)      ///< Channel number out of range
#define linux_EL2NSYNC        UINT16_C( 38)      ///< Level 2 not synchronized
#define linux_EL3HLT          UINT16_C( 39)      ///< Level 3 halted
#define linux_EL3RST          UINT16_C( 40)      ///< Level 3 reset
#define linux_ELNRNG          UINT16_C( 41)      ///< Link number out of range
#define linux_EUNATCH         UINT16_C( 42)      ///< Protocol driver not attached
#define linux_ENOCSI          UINT16_C( 43)      ///< No CSI structure available
#define linux_EL2HLT          UINT16_C( 44)      ///< Level 2 halted
#define linux_EDEADLK         UINT16_C( 45)      ///< Resource deadlock would occur
#define linux_EDEADLOCK       linux_EDEADLK      ///< Resource deadlock would occur
#define linux_ENOLCK          UINT16_C( 46)      ///< No record locks available
#define linux_EILSEQ          UINT16_C( 47)      ///< Illegal byte sequence
#define linux_ENONET          UINT16_C( 50)      ///< Machine is not on the network
#define linux_ENODATA         UINT16_C( 51)      ///< No data available
#define linux_ETIME           UINT16_C( 52)      ///< Timer expired
#define linux_ENOSR           UINT16_C( 53)      ///< Out of streams resources
#define linux_ENOSTR          UINT16_C( 54)      ///< Device not a stream
#define linux_ENOPKG          UINT16_C( 55)      ///< Package not installed
#define linux_ENOLINK         UINT16_C( 57)      ///< Link has been severed
#define linux_EADV            UINT16_C( 58)      ///< Advertise error
#define linux_ESRMNT          UINT16_C( 59)      ///< Srmount error
#define linux_ECOMM           UINT16_C( 60)      ///< Communication error on send
#define linux_EPROTO          UINT16_C( 61)      ///< Protocol error
#define linux_EMULTIHOP       UINT16_C( 64)      ///< Multihop attempted
#define linux_EDOTDOT         UINT16_C( 66)      ///< RFS specific error
#define linux_EBADMSG         UINT16_C( 67)      ///< Not a data message
#define linux_EUSERS          UINT16_C( 68)      ///< Too many users
#define linux_EDQUOT          UINT16_C( 69)      ///< Quota exceeded
#define linux_ESTALE          UINT16_C( 70)      ///< Stale file handle
#define linux_EREMOTE         UINT16_C( 71)      ///< Object is remote
#define linux_EOVERFLOW       UINT16_C( 72)      ///< Value too large for defined data type
#define linux_EBADE           UINT16_C(160)      ///< Invalid exchange
#define linux_EBADR           UINT16_C(161)      ///< Invalid request descriptor
#define linux_EXFULL          UINT16_C(162)      ///< Exchange full
#define linux_ENOANO          UINT16_C(163)      ///< No anode
#define linux_EBADRQC         UINT16_C(164)      ///< Invalid request code
#define linux_EBADSLT         UINT16_C(165)      ///< Invalid slot
#define linux_EBFONT          UINT16_C(166)      ///< Bad font file format
#define linux_ENOTUNIQ        UINT16_C(167)      ///< Name not unique on network
#define linux_EBADFD          UINT16_C(168)      ///< File descriptor in bad state
#define linux_EREMCHG         UINT16_C(169)      ///< Remote address changed
#define linux_ELIBACC         UINT16_C(170)      ///< Can not access a needed shared library
#define linux_ELIBBAD         UINT16_C(171)      ///< Accessing a corrupted shared library
#define linux_ELIBSCN         UINT16_C(172)      ///< .lib section in a.out corrupted
#define linux_ELIBMAX         UINT16_C(173)      ///< Attempting to link in too many shared libraries
#define linux_ELIBEXEC        UINT16_C(174)      ///< Cannot exec a shared library directly
#define linux_ERESTART        UINT16_C(175)      ///< Interrupted system call should be restarted
#define linux_ESTRPIPE        UINT16_C(176)      ///< Streams pipe error
#define linux_EUCLEAN         UINT16_C(177)      ///< Structure needs cleaning
#define linux_ENOTNAM         UINT16_C(178)      ///< Not a XENIX named type file
#define linux_ENAVAIL         UINT16_C(179)      ///< No XENIX semaphores available
#define linux_EISNAM          UINT16_C(180)      ///< Is a named type file
#define linux_EREMOTEIO       UINT16_C(181)      ///< Remote I/O error
#define linux_ENOMEDIUM       UINT16_C(182)      ///< No medium found
#define linux_EMEDIUMTYPE     UINT16_C(183)      ///< Wrong medium type
#define linux_ENOKEY          UINT16_C(184)      ///< Required key not available
#define linux_EKEYEXPIRED     UINT16_C(185)      ///< Key has expired
#define linux_EKEYREVOKED     UINT16_C(186)      ///< Key has been revoked
#define linux_EKEYREJECTED    UINT16_C(187)      ///< Key was rejected by service
#define linux_ENOSYM          UINT16_C(215)      ///< symbol does not exist in executable
#define linux_ENOTSOCK        UINT16_C(216)      ///< Socket operation on non-socket
#define linux_EDESTADDRREQ    UINT16_C(217)      ///< Destination address required
#define linux_EMSGSIZE        UINT16_C(218)      ///< Message too long
#define linux_EPROTOTYPE      UINT16_C(219)      ///< Protocol wrong type for socket
#define linux_ENOPROTOOPT     UINT16_C(220)      ///< Protocol not available
#define linux_EPROTONOSUPPORT UINT16_C(221)      ///< Protocol not supported
#define linux_ESOCKTNOSUPPORT UINT16_C(222)      ///< Socket type not supported
#define linux_EOPNOTSUPP      UINT16_C(223)      ///< Operation not supported on transport endpoint
#define linux_EPFNOSUPPORT    UINT16_C(224)      ///< Protocol family not supported
#define linux_EAFNOSUPPORT    UINT16_C(225)      ///< Address family not supported by protocol
#define linux_EADDRINUSE      UINT16_C(226)      ///< Address already in use
#define linux_EADDRNOTAVAIL   UINT16_C(227)      ///< Cannot assign requested address
#define linux_ENETDOWN        UINT16_C(228)      ///< Network is down
#define linux_ENETUNREACH     UINT16_C(229)      ///< Network is unreachable
#define linux_ENETRESET       UINT16_C(230)      ///< Network dropped connection because of reset
#define linux_ECONNABORTED    UINT16_C(231)      ///< Software caused connection abort
#define linux_ECONNRESET      UINT16_C(232)      ///< Connection reset by peer
#define linux_ENOBUFS         UINT16_C(233)      ///< No buffer space available
#define linux_EISCONN         UINT16_C(234)      ///< Transport endpoint is already connected
#define linux_ENOTCONN        UINT16_C(235)      ///< Transport endpoint is not connected
#define linux_ESHUTDOWN       UINT16_C(236)      ///< Cannot send after transport endpoint shutdown
#define linux_ETOOMANYREFS    UINT16_C(237)      ///< Too many references: cannot splice
#define linux_ETIMEDOUT       UINT16_C(238)      ///< Connection timed out
#define linux_ECONNREFUSED    UINT16_C(239)      ///< Connection refused
#define linux_EREFUSED        linux_ECONNREFUSED ///< for HP's NFS apparently
#define linux_EREMOTERELEASE  UINT16_C(240)      ///< Remote peer released connection
#define linux_EHOSTDOWN       UINT16_C(241)      ///< Host is down
#define linux_EHOSTUNREACH    UINT16_C(242)      ///< No route to host
#define linux_EALREADY        UINT16_C(244)      ///< Operation already in progress
#define linux_EINPROGRESS     UINT16_C(245)      ///< Operation now in progress
#define linux_EWOULDBLOCK     linux_EAGAIN       ///< Operation would block (Not HPUX compliant)
#define linux_ENOTEMPTY       UINT16_C(247)      ///< Directory not empty
#define linux_ENAMETOOLONG    UINT16_C(248)      ///< File name too long
#define linux_ELOOP           UINT16_C(249)      ///< Too many symbolic links encountered
#define linux_ENOSYS          UINT16_C(251)      ///< Function not implemented
#define linux_ECANCELLED      UINT16_C(253)      ///< aio request was canceled before complete (POSIX.4 / HPUX)
#define linux_ECANCELED       linux_ECANCELLED   ///< SuSv3 and Solaris wants one 'L'
#define linux_EOWNERDEAD      UINT16_C(254)      ///< For robust mutexes: Owner died
#define linux_ENOTRECOVERABLE UINT16_C(255)      ///< For robust mutexes: State not recoverable
#define linux_ERFKILL         UINT16_C(256)      ///< Operation not possible due to RF-kill
#define linux_EHWPOISON       UINT16_C(257)      ///< Memory page has hardware error

#endif // !HEADER_LIBLINUX_PARISC_ERROR_H_INCLUDED
