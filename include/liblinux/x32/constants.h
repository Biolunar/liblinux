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

#ifndef HEADER_LIBLINUX_X32_CONSTANTS_H_INCLUDED
#define HEADER_LIBLINUX_X32_CONSTANTS_H_INCLUDED

//=============================================================================
// signal

//-----------------------------------------------------------------------------
// signals

#define linux_SIGHUP     1
#define linux_SIGINT     2
#define linux_SIGQUIT    3
#define linux_SIGILL     4
#define linux_SIGTRAP    5
#define linux_SIGABRT    6
#define linux_SIGIOT     6
#define linux_SIGBUS     7
#define linux_SIGFPE     8
#define linux_SIGKILL    9
#define linux_SIGUSR1   10
#define linux_SIGSEGV   11
#define linux_SIGUSR2   12
#define linux_SIGPIPE   13
#define linux_SIGALRM   14
#define linux_SIGTERM   15
#define linux_SIGSTKFLT 16
#define linux_SIGCHLD   17
#define linux_SIGCONT   18
#define linux_SIGSTOP   19
#define linux_SIGTSTP   20
#define linux_SIGTTIN   21
#define linux_SIGTTOU   22
#define linux_SIGURG    23
#define linux_SIGXCPU   24
#define linux_SIGXFSZ   25
#define linux_SIGVTALRM 26
#define linux_SIGPROF   27
#define linux_SIGWINCH  28
#define linux_SIGIO     29
#define linux_SIGPOLL   linux_SIGIO
#define linux_SIGPWR    30
#define linux_SIGSYS    31
#define	linux_SIGUNUSED 31
#define linux_SIGRTMIN  32
#define linux_SIGRTMAX  64

//-----------------------------------------------------------------------------
// sigaction flags

#define linux_SA_NOCLDSTOP 0x00000001
#define linux_SA_NOCLDWAIT 0x00000002
#define linux_SA_SIGINFO   0x00000004
#define linux_SA_RESTORER  0x04000000
#define linux_SA_ONSTACK   0x08000000
#define linux_SA_RESTART   0x10000000
#define linux_SA_NODEFER   0x40000000
#define linux_SA_RESETHAND 0x80000000
#define linux_SA_NOMASK    linux_SA_NODEFER
#define linux_SA_ONESHOT   linux_SA_RESETHAND

//-----------------------------------------------------------------------------
// sigaltstack

#define linux_MINSIGSTKSZ 2048
#define linux_SIGSTKSZ    8192

//-----------------------------------------------------------------------------
// sigprocmask

#define linux_SIG_BLOCK   0
#define linux_SIG_UNBLOCK 1
#define linux_SIG_SETMASK 2

//=============================================================================
// memory

//-----------------------------------------------------------------------------
// mmap

#define linux_PROT_NONE      0x00000000
#define linux_PROT_READ      0x00000001
#define linux_PROT_WRITE     0x00000002
#define linux_PROT_EXEC      0x00000004
#define linux_PROT_SEM       0x00000008
#define linux_PROT_GROWSDOWN 0x01000000
#define linux_PROT_GROWSUP   0x02000000

#define linux_MAP_SHARED          0x000001
#define linux_MAP_PRIVATE         0x000002
#define linux_MAP_SHARED_VALIDATE 0x000003
#define linux_MAP_TYPE            0x00000f
#define linux_MAP_FIXED           0x000010
#define linux_MAP_ANONYMOUS       0x000020
#define linux_MAP_UNINITIALIZED   0x000000
#define linux_MAP_GROWSDOWN       0x000100
#define linux_MAP_DENYWRITE       0x000800
#define linux_MAP_EXECUTABLE      0x001000
#define linux_MAP_LOCKED          0x002000
#define linux_MAP_NORESERVE       0x004000
#define linux_MAP_POPULATE        0x008000
#define linux_MAP_NONBLOCK        0x010000
#define linux_MAP_STACK           0x020000
#define linux_MAP_HUGETLB         0x040000
#define linux_MAP_SYNC            0x080000
#define linux_MAP_FIXED_NOREPLACE 0x100000
#define linux_MAP_FILE            0x000000

//-----------------------------------------------------------------------------
// mlockall

#define linux_MCL_CURRENT 1
#define linux_MCL_FUTURE  2
#define linux_MCL_ONFAULT 4

//-----------------------------------------------------------------------------
// msync

#define linux_MS_ASYNC      1
#define linux_MS_INVALIDATE 2
#define linux_MS_SYNC       4

//-----------------------------------------------------------------------------
// madvise

#define linux_MADV_NORMAL         0
#define linux_MADV_RANDOM         1
#define linux_MADV_SEQUENTIAL     2
#define linux_MADV_WILLNEED       3
#define linux_MADV_DONTNEED       4
#define linux_MADV_FREE           8
#define linux_MADV_REMOVE         9
#define linux_MADV_DONTFORK      10
#define linux_MADV_DOFORK        11
#define linux_MADV_HWPOISON     100
#define linux_MADV_SOFT_OFFLINE 101
#define linux_MADV_MERGEABLE     12
#define linux_MADV_UNMERGEABLE   13
#define linux_MADV_HUGEPAGE      14
#define linux_MADV_NOHUGEPAGE    15
#define linux_MADV_DONTDUMP      16
#define linux_MADV_DODUMP        17
#define linux_MADV_WIPEONFORK    18
#define linux_MADV_KEEPONFORK    19

//-----------------------------------------------------------------------------
// pkey

#define linux_PKEY_DISABLE_ACCESS  0x1
#define linux_PKEY_DISABLE_WRITE   0x2
#define linux_PKEY_ACCESS_MASK    (PKEY_DISABLE_ACCESS | PKEY_DISABLE_WRITE)

//=============================================================================
// open

#define linux_O_ACCMODE       000000003
#define linux_O_RDONLY        000000000
#define linux_O_WRONLY        000000001
#define linux_O_RDWR          000000002
#define linux_O_CREAT         000000100
#define linux_O_EXCL          000000200
#define linux_O_NOCTTY        000000400
#define linux_O_TRUNC         000001000
#define linux_O_APPEND        000002000
#define linux_O_NONBLOCK      000004000
#define linux_O_DSYNC         000010000
#define linux_FASYNC          000020000
#define linux_O_DIRECT        000040000
#define linux_O_LARGEFILE     000100000
#define linux_O_DIRECTORY     000200000
#define linux_O_NOFOLLOW      000400000
#define linux_O_NOATIME       001000000
#define linux_O_CLOEXEC       002000000
#define linux_O_SYNC         (004000000 | linux_O_DSYNC)
#define linux_O_PATH          010000000
#define linux_O_TMPFILE      (020000000 | linux_O_DIRECTORY)
#define linux_O_TMPFILE_MASK (020000000 | linux_O_DIRECTORY | linux_O_CREAT)      
#define linux_O_NDELAY        linux_O_NONBLOCK

//=============================================================================
// socket

enum linux_sock_type
{
	linux_SOCK_STREAM    =  1,
	linux_SOCK_DGRAM     =  2,
	linux_SOCK_RAW       =  3,
	linux_SOCK_RDM       =  4,
	linux_SOCK_SEQPACKET =  5,
	linux_SOCK_DCCP      =  6,
	linux_SOCK_PACKET    = 10,
	linux_SOCK_MAX,
};
#define linux_SOCK_TYPE_MASK 0xf

#define linux_SOCK_NONBLOCK linux_O_NONBLOCK

#define linux_SOL_SOCKET 1

#define linux_SO_TIMESTAMP    linux_SO_TIMESTAMP_OLD
#define linux_SO_TIMESTAMPNS  linux_SO_TIMESTAMPNS_OLD
#define linux_SO_TIMESTAMPING linux_SO_TIMESTAMPING_OLD
#define linux_SO_RCVTIMEO     linux_SO_RCVTIMEO_OLD
#define linux_SO_SNDTIMEO     linux_SO_SNDTIMEO_OLD

#endif // !HEADER_LIBLINUX_X32_CONSTANTS_H_INCLUDED
