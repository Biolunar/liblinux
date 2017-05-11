/*
 * Copyright 2017 Mahdi Khanalizadeh
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

#ifndef HEADER_LIBLINUX_SYSCALL_ERROR_H_INCLUDED
#define HEADER_LIBLINUX_SYSCALL_ERROR_H_INCLUDED

#include <stdbool.h>
#include <stdint.h>

enum linux_error_t
{
	linux_error_none      =    0,

	// generic
	linux_EPERM           =    1, // Operation not permitted
	linux_ENOENT          =    2, // No such file or directory
	linux_ESRCH           =    3, // No such process
	linux_EINTR           =    4, // Interrupted system call
	linux_EIO             =    5, // I/O error
	linux_ENXIO           =    6, // No such device or address
	linux_E2BIG           =    7, // Argument list too long
	linux_ENOEXEC         =    8, // Exec format error
	linux_EBADF           =    9, // Bad file number
	linux_ECHILD          =   10, // No child processes
	linux_EAGAIN          =   11, // Try again
	linux_ENOMEM          =   12, // Out of memory
	linux_EACCES          =   13, // Permission denied
	linux_EFAULT          =   14, // Bad address
	linux_ENOTBLK         =   15, // Block device required
	linux_EBUSY           =   16, // Device or resource busy
	linux_EEXIST          =   17, // File exists
	linux_EXDEV           =   18, // Cross-device link
	linux_ENODEV          =   19, // No such device
	linux_ENOTDIR         =   20, // Not a directory
	linux_EISDIR          =   21, // Is a directory
	linux_EINVAL          =   22, // Invalid argument
	linux_ENFILE          =   23, // File table overflow
	linux_EMFILE          =   24, // Too many open files
	linux_ENOTTY          =   25, // Not a typewriter
	linux_ETXTBSY         =   26, // Text file busy
	linux_EFBIG           =   27, // File too large
	linux_ENOSPC          =   28, // No space left on device
	linux_ESPIPE          =   29, // Illegal seek
	linux_EROFS           =   30, // Read-only file system
	linux_EMLINK          =   31, // Too many links
	linux_EPIPE           =   32, // Broken pipe
	linux_EDOM            =   33, // Math argument out of domain of func
	linux_ERANGE          =   34, // Math result not representable

	// i386, x86_64, x32
	linux_EDEADLK         =   35, // Resource deadlock would occur
	linux_ENAMETOOLONG    =   36, // File name too long
	linux_ENOLCK          =   37, // No record locks available
	linux_ENOSYS          =   38, // Invalid system call number
	linux_ENOTEMPTY       =   39, // Directory not empty
	linux_ELOOP           =   40, // Too many symbolic links encountered
	linux_EWOULDBLOCK     = linux_EAGAIN, // Operation would block
	linux_ENOMSG          =   42, // No message of desired type
	linux_EIDRM           =   43, // Identifier removed
	linux_ECHRNG          =   44, // Channel number out of range
	linux_EL2NSYNC        =   45, // Level 2 not synchronized
	linux_EL3HLT          =   46, // Level 3 halted
	linux_EL3RST          =   47, // Level 3 reset
	linux_ELNRNG          =   48, // Link number out of range
	linux_EUNATCH         =   49, // Protocol driver not attached
	linux_ENOCSI          =   50, // No CSI structure available
	linux_EL2HLT          =   51, // Level 2 halted
	linux_EBADE           =   52, // Invalid exchange
	linux_EBADR           =   53, // Invalid request descriptor
	linux_EXFULL          =   54, // Exchange full
	linux_ENOANO          =   55, // No anode
	linux_EBADRQC         =   56, // Invalid request code
	linux_EBADSLT         =   57, // Invalid slot
	linux_EDEADLOCK       = linux_EDEADLK,
	linux_EBFONT          =   59, // Bad font file format
	linux_ENOSTR          =   60, // Device not a stream
	linux_ENODATA         =   61, // No data available
	linux_ETIME           =   62, // Timer expired
	linux_ENOSR           =   63, // Out of streams resources
	linux_ENONET          =   64, // Machine is not on the network
	linux_ENOPKG          =   65, // Package not installed
	linux_EREMOTE         =   66, // Object is remote
	linux_ENOLINK         =   67, // Link has been severed
	linux_EADV            =   68, // Advertise error
	linux_ESRMNT          =   69, // Srmount error
	linux_ECOMM           =   70, // Communication error on send
	linux_EPROTO          =   71, // Protocol error
	linux_EMULTIHOP       =   72, // Multihop attempted
	linux_EDOTDOT         =   73, // RFS specific error
	linux_EBADMSG         =   74, // Not a data message
	linux_EOVERFLOW       =   75, // Value too large for defined data type
	linux_ENOTUNIQ        =   76, // Name not unique on network
	linux_EBADFD          =   77, // File descriptor in bad state
	linux_EREMCHG         =   78, // Remote address changed
	linux_ELIBACC         =   79, // Can not access a needed shared library
	linux_ELIBBAD         =   80, // Accessing a corrupted shared library
	linux_ELIBSCN         =   81, // .lib section in a.out corrupted
	linux_ELIBMAX         =   82, // Attempting to link in too many shared libraries
	linux_ELIBEXEC        =   83, // Cannot exec a shared library directly
	linux_EILSEQ          =   84, // Illegal byte sequence
	linux_ERESTART        =   85, // Interrupted system call should be restarted
	linux_ESTRPIPE        =   86, // Streams pipe error
	linux_EUSERS          =   87, // Too many users
	linux_ENOTSOCK        =   88, // Socket operation on non-socket
	linux_EDESTADDRREQ    =   89, // Destination address required
	linux_EMSGSIZE        =   90, // Message too long
	linux_EPROTOTYPE      =   91, // Protocol wrong type for socket
	linux_ENOPROTOOPT     =   92, // Protocol not available
	linux_EPROTONOSUPPORT =   93, // Protocol not supported
	linux_ESOCKTNOSUPPORT =   94, // Socket type not supported
	linux_EOPNOTSUPP      =   95, // Operation not supported on transport endpoint
	linux_EPFNOSUPPORT    =   96, // Protocol family not supported
	linux_EAFNOSUPPORT    =   97, // Address family not supported by protocol
	linux_EADDRINUSE      =   98, // Address already in use
	linux_EADDRNOTAVAIL   =   99, // Cannot assign requested address
	linux_ENETDOWN        =  100, // Network is down
	linux_ENETUNREACH     =  101, // Network is unreachable
	linux_ENETRESET       =  102, // Network dropped connection because of reset
	linux_ECONNABORTED    =  103, // Software caused connection abort
	linux_ECONNRESET      =  104, // Connection reset by peer
	linux_ENOBUFS         =  105, // No buffer space available
	linux_EISCONN         =  106, // Transport endpoint is already connected
	linux_ENOTCONN        =  107, // Transport endpoint is not connected
	linux_ESHUTDOWN       =  108, // Cannot send after transport endpoint shutdown
	linux_ETOOMANYREFS    =  109, // Too many references: cannot splice
	linux_ETIMEDOUT       =  110, // Connection timed out
	linux_ECONNREFUSED    =  111, // Connection refused
	linux_EHOSTDOWN       =  112, // Host is down
	linux_EHOSTUNREACH    =  113, // No route to host
	linux_EALREADY        =  114, // Operation already in progress
	linux_EINPROGRESS     =  115, // Operation now in progress
	linux_ESTALE          =  116, // Stale file handle
	linux_EUCLEAN         =  117, // Structure needs cleaning
	linux_ENOTNAM         =  118, // Not a XENIX named type file
	linux_ENAVAIL         =  119, // No XENIX semaphores available
	linux_EISNAM          =  120, // Is a named type file
	linux_EREMOTEIO       =  121, // Remote I/O error
	linux_EDQUOT          =  122, // Quota exceeded
	linux_ENOMEDIUM       =  123, // No medium found
	linux_EMEDIUMTYPE     =  124, // Wrong medium type
	linux_ECANCELED       =  125, // Operation Canceled
	linux_ENOKEY          =  126, // Required key not available
	linux_EKEYEXPIRED     =  127, // Key has expired
	linux_EKEYREVOKED     =  128, // Key has been revoked
	linux_EKEYREJECTED    =  129, // Key was rejected by service
	linux_EOWNERDEAD      =  130, // Owner died
	linux_ENOTRECOVERABLE =  131, // State not recoverable
	linux_ERFKILL         =  132, // Operation not possible due to RF-kill
	linux_EHWPOISON       =  133, // Memory page has hardware error

	linux_error_max       = 4095,
};

static inline bool linux_syscall_returned_error(intptr_t const ret)
{
	return ret < 0 && ret >= -linux_error_max;
}

#endif // !HEADER_LIBLINUX_SYSCALL_ERROR_H_INCLUDED
