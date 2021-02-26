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

#ifndef HEADER_LIBLINUX_CONSTANTS_H_INCLUDED
#define HEADER_LIBLINUX_CONSTANTS_H_INCLUDED

#include "version.h"
#include "arch.h"
#include "endian.h"

#include <stddef.h>
#include <stdint.h>

//=============================================================================
// aio

#define linux_IOCB_CMD_PREAD    UINT16_C(0)
#define linux_IOCB_CMD_PWRITE   UINT16_C(1)
#define linux_IOCB_CMD_FSYNC    UINT16_C(2)
#define linux_IOCB_CMD_FDSYNC   UINT16_C(3)
//#define linux_IOCB_CMD_PREADX UINT16_C(4)
#define linux_IOCB_CMD_POLL     UINT16_C(5)
#define linux_IOCB_CMD_NOOP     UINT16_C(6)
#define linux_IOCB_CMD_PREADV   UINT16_C(7)
#define linux_IOCB_CMD_PWRITEV  UINT16_C(8)

#define linux_IOCB_FLAG_RESFD  (UINT32_C(1) << 0)
#define linux_IOCB_FLAG_IOPRIO (UINT32_C(1) << 1)

//=============================================================================
// auxvec

#define linux_AT_NULL           0
#define linux_AT_IGNORE         1
#define linux_AT_EXECFD         2
#define linux_AT_PHDR           3
#define linux_AT_PHENT          4
#define linux_AT_PHNUM          5
#define linux_AT_PAGESZ         6
#define linux_AT_BASE           7
#define linux_AT_FLAGS          8
#define linux_AT_ENTRY          9
#define linux_AT_NOTELF        10
#define linux_AT_UID           11
#define linux_AT_EUID          12
#define linux_AT_GID           13
#define linux_AT_EGID          14
#define linux_AT_PLATFORM      15
#define linux_AT_HWCAP         16
#define linux_AT_CLKTCK        17
// 18-22 are reserved
#define linux_AT_SECURE        23
#define linux_AT_BASE_PLATFORM 24
#define linux_AT_RANDOM        25
#define linux_AT_HWCAP2        26
#define linux_AT_EXECFN        31

#define linux_AT_VECTOR_SIZE_BASE 20

//=============================================================================
// signals

#define linux_SIG_DFL ((linux_sighandler_t) 0)
#define linux_SIG_IGN ((linux_sighandler_t) 1)
#define linux_SIG_ERR ((linux_sighandler_t)-1)

//=============================================================================
// aio

enum
{
	linux_IOCB_CMD_PREAD     = 0,
	linux_IOCB_CMD_PWRITE    = 1,
	linux_IOCB_CMD_FSYNC     = 2,
	linux_IOCB_CMD_FDSYNC    = 3,
	// linux_IOCB_CMD_PREADX = 4,
	linux_IOCB_CMD_POLL      = 5,
	linux_IOCB_CMD_NOOP      = 6,
	linux_IOCB_CMD_PREADV    = 7,
	linux_IOCB_CMD_PWRITEV   = 8,
};

#define linux_IOCB_FLAG_RESFD  (1 << 0)
#define linux_IOCB_FLAG_IOPRIO (1 << 1)

//=============================================================================
// wait

#define linux_WNOHANG    0x00000001
#define linux_WUNTRACED  0x00000002
#define linux_WSTOPPED   linux_WUNTRACED
#define linux_WEXITED    0x00000004
#define linux_WCONTINUED 0x00000008
#define linux_WNOWAIT    0x01000000
#define linux_WNOTHREAD  0x20000000
#define linux_WALL       0x40000000
#define linux_WCLONE     0x80000000

#define linux_P_ALL   0
#define linux_P_PID   1
#define linux_P_PGID  2
#define linux_P_PIDFD 3

//=============================================================================
// ioprio

#define linux_IOPRIO_CLASS_SHIFT             (13)
#define linux_IOPRIO_PRIO_MASK               ((1UL << linux_IOPRIO_CLASS_SHIFT) - 1)

#define linux_IOPRIO_PRIO_CLASS(mask)        ((mask) >> linux_IOPRIO_CLASS_SHIFT)
#define linux_IOPRIO_PRIO_DATA(mask)         ((mask) & linux_IOPRIO_PRIO_MASK)
#define linux_IOPRIO_PRIO_VALUE(class, data) (((class) << linux_IOPRIO_CLASS_SHIFT) | data)

#define linux_ioprio_valid(mask)             (linux_IOPRIO_PRIO_CLASS((mask)) != linux_IOPRIO_CLASS_NONE)

enum
{
	linux_IOPRIO_CLASS_NONE,
	linux_IOPRIO_CLASS_RT,
	linux_IOPRIO_CLASS_BE,
	linux_IOPRIO_CLASS_IDLE,
};

#define linux_IOPRIO_BE_NR (8)

enum
{
	linux_IOPRIO_WHO_PROCESS = 1,
	linux_IOPRIO_WHO_PGRP,
	linux_IOPRIO_WHO_USER,
};

#define linux_IOPRIO_NORM (4)

//=============================================================================
// openat2

#define linux_RESOLVE_NO_XDEV       0x01
#define linux_RESOLVE_NO_MAGICLINKS 0x02
#define linux_RESOLVE_NO_SYMLINKS   0x04
#define linux_RESOLVE_BENEATH       0x08
#define linux_RESOLVE_IN_ROOT       0x10

//=============================================================================
// limits

#define linux_NR_OPEN 1024

#define linux_NGROUPS_MAX     65536
#define linux_ARG_MAX        131072
#define linux_LINK_MAX          127
#define linux_MAX_CANON         255
#define linux_MAX_INPUT         255
#define linux_NAME_MAX          255
#define linux_PATH_MAX         4096
#define linux_PIPE_BUF         4096
#define linux_XATTR_NAME_MAX    255
#define linux_XATTR_SIZE_MAX  65536
#define linux_XATTR_LIST_MAX  65536

#define linux_RTSIG_MAX 32

//=============================================================================
// fs_types

#define linux_S_DT_SHIFT 12
#define linux_S_DT(mode) (((mode) & linux_S_IFMT) >> linux_S_DT_SHIFT)
#define linux_S_DT_MASK  (linux_S_IFMT >> linux_S_DT_SHIFT)

#define linux_DT_UNKNOWN  0
#define linux_DT_FIFO     1
#define linux_DT_CHR      2
#define linux_DT_DIR      4
#define linux_DT_BLK      6
#define linux_DT_REG      8
#define linux_DT_LNK     10
#define linux_DT_SOCK    12
#define linux_DT_WHT     14
#define linux_DT_MAX     (linux_S_DT_MASK + 1)

#define linux_FT_UNKNOWN  0
#define linux_FT_REG_FILE 1
#define linux_FT_DIR      2
#define linux_FT_CHRDEV   3
#define linux_FT_BLKDEV   4
#define linux_FT_FIFO     5
#define linux_FT_SOCK     6
#define linux_FT_SYMLINK  7
#define linux_FT_MAX      8

//=============================================================================
// reboot

#define	linux_LINUX_REBOOT_MAGIC1  0xfee1dead
#define	linux_LINUX_REBOOT_MAGIC2  672274793
#define	linux_LINUX_REBOOT_MAGIC2A 85072278
#define	linux_LINUX_REBOOT_MAGIC2B 369367448
#define	linux_LINUX_REBOOT_MAGIC2C 537993216

#define	linux_LINUX_REBOOT_CMD_RESTART    0x01234567
#define	linux_LINUX_REBOOT_CMD_HALT       0xCDEF0123
#define	linux_LINUX_REBOOT_CMD_CAD_ON     0x89ABCDEF
#define	linux_LINUX_REBOOT_CMD_CAD_OFF    0x00000000
#define	linux_LINUX_REBOOT_CMD_POWER_OFF  0x4321FEDC
#define	linux_LINUX_REBOOT_CMD_RESTART2   0xA1B2C3D4
#define	linux_LINUX_REBOOT_CMD_SW_SUSPEND 0xD000FCE2
#define	linux_LINUX_REBOOT_CMD_KEXEC      0x45584543

//=============================================================================
// access

enum // Kernel sources do not explicitly define these constants. They correspond to S_IXOTH, S_IWOTH and S_IROTH.
{
	linux_F_OK = 0,
	linux_X_OK = 1,
	linux_W_OK = 2,
	linux_R_OK = 4,
};

//=============================================================================
// clone

#define linux_CSIGNAL              0x000000ff
#define linux_CLONE_VM             0x00000100
#define linux_CLONE_FS             0x00000200
#define linux_CLONE_FILES          0x00000400
#define linux_CLONE_SIGHAND        0x00000800
#define linux_CLONE_PIDFD          0x00001000
#define linux_CLONE_PTRACE         0x00002000
#define linux_CLONE_VFORK          0x00004000
#define linux_CLONE_PARENT         0x00008000
#define linux_CLONE_THREAD         0x00010000
#define linux_CLONE_NEWNS          0x00020000
#define linux_CLONE_SYSVSEM        0x00040000
#define linux_CLONE_SETTLS         0x00080000
#define linux_CLONE_PARENT_SETTID  0x00100000
#define linux_CLONE_CHILD_CLEARTID 0x00200000
#define linux_CLONE_DETACHED       0x00400000
#define linux_CLONE_UNTRACED       0x00800000
#define linux_CLONE_CHILD_SETTID   0x01000000
#define linux_CLONE_NEWCGROUP      0x02000000
#define linux_CLONE_NEWUTS         0x04000000
#define linux_CLONE_NEWIPC         0x08000000
#define linux_CLONE_NEWUSER        0x10000000
#define linux_CLONE_NEWPID         0x20000000
#define linux_CLONE_NEWNET         0x40000000
#define linux_CLONE_IO             0x80000000

#define linux_CLONE_CLEAR_SIGHAND 0x100000000ULL

#define linux_CLONE_ARGS_SIZE_VER0 64
#define linux_CLONE_ARGS_SIZE_VER1 80

//=============================================================================
// memory

//-----------------------------------------------------------------------------
// mlock

#define linux_MLOCK_ONFAULT 0x01

//=============================================================================
// fcntl

#define linux_F_DUPFD 0
#define linux_F_GETFD 1
#define linux_F_SETFD 2
#define linux_F_GETFL 3
#define linux_F_SETFL 4

#define linux_F_SETOWN_EX     15
#define linux_F_GETOWN_EX     16
#define linux_F_GETOWNER_UIDS 17

#define linux_F_OFD_GETLK  36
#define linux_F_OFD_SETLK  37
#define linux_F_OFD_SETLKW 38

#define linux_F_OWNER_TID  0
#define linux_F_OWNER_PID  1
#define linux_F_OWNER_PGRP 2

#define linux_FD_CLOEXEC 1

#define linux_LOCK_SH 1
#define linux_LOCK_EX 2
#define linux_LOCK_NB 4
#define linux_LOCK_UN 8

#define linux_LOCK_MAND   32
#define linux_LOCK_READ   64
#define linux_LOCK_WRITE 128
#define linux_LOCK_RW    192

#define linux_F_LINUX_SPECIFIC_BASE 1024

#define linux_F_SETLEASE         (linux_F_LINUX_SPECIFIC_BASE +  0)
#define linux_F_GETLEASE         (linux_F_LINUX_SPECIFIC_BASE +  1)
#define linux_F_NOTIFY           (linux_F_LINUX_SPECIFIC_BASE +  2)
#define linux_F_CANCELLK         (linux_F_LINUX_SPECIFIC_BASE +  5)
#define linux_F_DUPFD_CLOEXEC    (linux_F_LINUX_SPECIFIC_BASE +  6)
#define linux_F_SETPIPE_SZ       (linux_F_LINUX_SPECIFIC_BASE +  7)
#define linux_F_GETPIPE_SZ       (linux_F_LINUX_SPECIFIC_BASE +  8)
#define linux_F_ADD_SEALS        (linux_F_LINUX_SPECIFIC_BASE +  9)
#define linux_F_GET_SEALS        (linux_F_LINUX_SPECIFIC_BASE + 10)
#define linux_F_GET_RW_HINT      (linux_F_LINUX_SPECIFIC_BASE + 11)
#define linux_F_SET_RW_HINT      (linux_F_LINUX_SPECIFIC_BASE + 12)
#define linux_F_GET_FILE_RW_HINT (linux_F_LINUX_SPECIFIC_BASE + 13)
#define linux_F_SET_FILE_RW_HINT (linux_F_LINUX_SPECIFIC_BASE + 14)

#define linux_F_SEAL_SEAL         0x0001
#define linux_F_SEAL_SHRINK       0x0002
#define linux_F_SEAL_GROW         0x0004
#define linux_F_SEAL_WRITE        0x0008
#define linux_F_SEAL_FUTURE_WRITE 0x0010

#define linux_RWF_WRITE_LIFE_NOT_SET 0
#define linux_RWH_WRITE_LIFE_NONE    1
#define linux_RWH_WRITE_LIFE_SHORT   2
#define linux_RWH_WRITE_LIFE_MEDIUM  3
#define linux_RWH_WRITE_LIFE_LONG    4
#define linux_RWH_WRITE_LIFE_EXTREME 5

#define linux_DN_ACCESS    0x00000001
#define linux_DN_MODIFY    0x00000002
#define linux_DN_CREATE    0x00000004
#define linux_DN_DELETE    0x00000008
#define linux_DN_RENAME    0x00000010
#define linux_DN_ATTRIB    0x00000020
#define linux_DN_MULTISHOT 0x80000000

#define linux_AT_FDCWD              -100
#define linux_AT_SYMLINK_NOFOLLOW   0x0100
#define linux_AT_EACCESS            0x0200
#define linux_AT_REMOVEDIR          0x0200
#define linux_AT_SYMLINK_FOLLOW     0x0400
#define linux_AT_NO_AUTOMOUNT       0x0800
#define linux_AT_EMPTY_PATH         0x1000
#define linux_AT_STATX_SYNC_TYPE    0x6000
#define linux_AT_STATX_SYNC_AS_STAT 0x0000
#define linux_AT_STATX_FORCE_SYNC   0x2000
#define linux_AT_STATX_DONT_SYNC    0x4000
#define linux_AT_RECURSIVE          0x8000

//=============================================================================
// scheduler

#define linux_SCHED_NORMAL   0
#define linux_SCHED_FIFO     1
#define linux_SCHED_RR       2
#define linux_SCHED_BATCH    3
#define linux_SCHED_IDLE     5
#define linux_SCHED_DEADLINE 6

#define linux_SCHED_RESET_ON_FORK 0x40000000

#define linux_SCHED_FLAG_RESET_ON_FORK  0x01
#define linux_SCHED_FLAG_RECLAIM        0x02
#define linux_SCHED_FLAG_DL_OVERRUN     0x04
#define linux_SCHED_FLAG_KEEP_POLICY    0x08
#define linux_SCHED_FLAG_KEEP_PARAMS    0x10
#define linux_SCHED_FLAG_UTIL_CLAMP_MIN 0x20
#define linux_SCHED_FLAG_UTIL_CLAMP_MAX 0x40
#define linux_SCHED_FLAG_KEEP_ALL       (linux_SCHED_FLAG_KEEP_POLICY | linux_SCHED_FLAG_KEEP_PARAMS)
#define linux_SCHED_FLAG_UTIL_CLAMP     (linux_SCHED_FLAG_UTIL_CLAMP_MIN | linux_SCHED_FLAG_UTIL_CLAMP_MAX)
#define linux_SCHED_FLAG_ALL            (linux_SCHED_FLAG_RESET_ON_FORK | linux_SCHED_FLAG_RECLAIM | linux_SCHED_FLAG_DL_OVERRUN)

//=============================================================================
// interval timer

#define linux_ITIMER_REAL    0
#define linux_ITIMER_VIRTUAL 1
#define linux_ITIMER_PROF    2

//=============================================================================
// system clocks

#define linux_CLOCK_REALTIME            0
#define linux_CLOCK_MONOTONIC           1
#define linux_CLOCK_PROCESS_CPUTIME_ID  2
#define linux_CLOCK_THREAD_CPUTIME_ID   3
#define linux_CLOCK_MONOTONIC_RAW       4
#define linux_CLOCK_REALTIME_COARSE     5
#define linux_CLOCK_MONOTONIC_COARSE    6
#define linux_CLOCK_BOOTTIME            7
#define linux_CLOCK_REALTIME_ALARM      8
#define linux_CLOCK_BOOTTIME_ALARM      9
#define linux_CLOCK_SGI_CYCLE          10
#define linux_CLOCK_TAI                11

#define linux_MAX_CLOCKS   16
#define linux_CLOCKS_MASK (linux_CLOCK_REALTIME | linux_CLOCK_MONOTONIC)
#define linux_CLOCKS_MONO  linux_CLOCK_MONOTONIC

#define linux_TIMER_ABSTIME 0x01

//=============================================================================
// rseq

enum linux_rseq_cpu_id_state
{
	linux_RSEQ_CPU_ID_UNINITIALIZED       = -1,
	linux_RSEQ_CPU_ID_REGISTRATION_FAILED = -2,
};

enum linux_rseq_flags
{
	linux_RSEQ_FLAG_UNREGISTER = (1 << 0),
};

enum linux_rseq_cs_flags_bit
{
	linux_RSEQ_CS_FLAG_NO_RESTART_ON_PREEMPT_BIT = 0,
	linux_RSEQ_CS_FLAG_NO_RESTART_ON_SIGNAL_BIT  = 1,
	linux_RSEQ_CS_FLAG_NO_RESTART_ON_MIGRATE_BIT = 2,
};

enum linux_rseq_cs_flags
{
	linux_RSEQ_CS_FLAG_NO_RESTART_ON_PREEMPT = (1U << linux_RSEQ_CS_FLAG_NO_RESTART_ON_PREEMPT_BIT),
	linux_RSEQ_CS_FLAG_NO_RESTART_ON_SIGNAL  = (1U << linux_RSEQ_CS_FLAG_NO_RESTART_ON_SIGNAL_BIT),
	linux_RSEQ_CS_FLAG_NO_RESTART_ON_MIGRATE = (1U << linux_RSEQ_CS_FLAG_NO_RESTART_ON_MIGRATE_BIT),
};

//=============================================================================
// socket

#define linux_AF_UNSPEC      0
#define linux_AF_UNIX        1
#define linux_AF_LOCAL       1
#define linux_AF_INET        2
#define linux_AF_AX25        3
#define linux_AF_IPX         4
#define linux_AF_APPLETALK   5
#define linux_AF_NETROM      6
#define linux_AF_BRIDGE      7
#define linux_AF_ATMPVC      8
#define linux_AF_X25         9
#define linux_AF_INET6      10
#define linux_AF_ROSE       11
#define linux_AF_DECnet     12
#define linux_AF_NETBEUI    13
#define linux_AF_SECURITY   14
#define linux_AF_KEY        15
#define linux_AF_NETLINK    16
#define linux_AF_ROUTE      linux_AF_NETLINK
#define linux_AF_PACKET     17
#define linux_AF_ASH        18
#define linux_AF_ECONET     19
#define linux_AF_ATMSVC     20
#define linux_AF_RDS        21
#define linux_AF_SNA        22
#define linux_AF_IRDA       23
#define linux_AF_PPPOX      24
#define linux_AF_WANPIPE    25
#define linux_AF_LLC        26
#define linux_AF_IB         27
#define linux_AF_MPLS       28
#define linux_AF_CAN        29
#define linux_AF_TIPC       30
#define linux_AF_BLUETOOTH  31
#define linux_AF_IUCV       32
#define linux_AF_RXRPC      33
#define linux_AF_ISDN       34
#define linux_AF_PHONET     35
#define linux_AF_IEEE802154 36
#define linux_AF_CAIF       37
#define linux_AF_ALG        38
#define linux_AF_NFC        39
#define linux_AF_VSOCK      40
#define linux_AF_KCM        41
#define linux_AF_QIPCRTR    42
#define linux_AF_SMC        43
#define linux_AF_XDP        44
#define linux_AF_MAX        45

#define linux_PF_UNSPEC     linux_AF_UNSPEC
#define linux_PF_UNIX       linux_AF_UNIX
#define linux_PF_LOCAL      linux_AF_LOCAL
#define linux_PF_INET       linux_AF_INET
#define linux_PF_AX25       linux_AF_AX25
#define linux_PF_IPX        linux_AF_IPX
#define linux_PF_APPLETALK  linux_AF_APPLETALK
#define linux_PF_NETROM     linux_AF_NETROM
#define linux_PF_BRIDGE     linux_AF_BRIDGE
#define linux_PF_ATMPVC     linux_AF_ATMPVC
#define linux_PF_X25        linux_AF_X25
#define linux_PF_INET6      linux_AF_INET6
#define linux_PF_ROSE       linux_AF_ROSE
#define linux_PF_DECnet     linux_AF_DECnet
#define linux_PF_NETBEUI    linux_AF_NETBEUI
#define linux_PF_SECURITY   linux_AF_SECURITY
#define linux_PF_KEY        linux_AF_KEY
#define linux_PF_NETLINK    linux_AF_NETLINK
#define linux_PF_ROUTE      linux_AF_ROUTE
#define linux_PF_PACKET     linux_AF_PACKET
#define linux_PF_ASH        linux_AF_ASH
#define linux_PF_ECONET     linux_AF_ECONET
#define linux_PF_ATMSVC     linux_AF_ATMSVC
#define linux_PF_RDS        linux_AF_RDS
#define linux_PF_SNA        linux_AF_SNA
#define linux_PF_IRDA       linux_AF_IRDA
#define linux_PF_PPPOX      linux_AF_PPPOX
#define linux_PF_WANPIPE    linux_AF_WANPIPE
#define linux_PF_LLC        linux_AF_LLC
#define linux_PF_IB         linux_AF_IB
#define linux_PF_MPLS       linux_AF_MPLS
#define linux_PF_CAN        linux_AF_CAN
#define linux_PF_TIPC       linux_AF_TIPC
#define linux_PF_BLUETOOTH  linux_AF_BLUETOOTH
#define linux_PF_IUCV       linux_AF_IUCV
#define linux_PF_RXRPC      linux_AF_RXRPC
#define linux_PF_ISDN       linux_AF_ISDN
#define linux_PF_PHONET     linux_AF_PHONET
#define linux_PF_IEEE802154 linux_AF_IEEE802154
#define linux_PF_CAIF       linux_AF_CAIF
#define linux_PF_ALG        linux_AF_ALG
#define linux_PF_NFC        linux_AF_NFC
#define linux_PF_VSOCK      linux_AF_VSOCK
#define linux_PF_KCM        linux_AF_KCM
#define linux_PF_QIPCRTR    linux_AF_QIPCRTR
#define linux_PF_SMC        linux_AF_SMC
#define linux_PF_XDP        linux_AF_XDP
#define linux_PF_MAX        linux_AF_MAX

#define linux_SOMAXCONN 4096

#define linux_MSG_OOB               1
#define linux_MSG_PEEK              2
#define linux_MSG_DONTROUTE         4
#define linux_MSG_TRYHARD           4
#define linux_MSG_CTRUNC            8
#define linux_MSG_PROBE             0x10
#define linux_MSG_TRUNC             0x20
#define linux_MSG_DONTWAIT          0x40
#define linux_MSG_EOR               0x80
#define linux_MSG_WAITALL           0x100
#define linux_MSG_FIN               0x200
#define linux_MSG_SYN               0x400
#define linux_MSG_CONFIRM           0x800
#define linux_MSG_RST               0x1000
#define linux_MSG_ERRQUEUE          0x2000
#define linux_MSG_NOSIGNAL          0x4000
#define linux_MSG_MORE              0x8000
#define linux_MSG_WAITFORONE        0x10000
#define linux_MSG_SENDPAGE_NOPOLICY 0x10000
#define linux_MSG_SENDPAGE_NOTLAST  0x20000
#define linux_MSG_BATCH             0x40000
#define linux_MSG_EOF               linux_MSG_FIN
#define linux_MSG_NO_SHARED_FRAGS   0x80000
#define linux_MSG_ZEROCOPY          0x4000000
#define linux_MSG_FASTOPEN          0x20000000
#define linux_MSG_CMSG_CLOEXEC      0x40000000
#define linux_MSG_CMSG_COMPAT       0x80000000

#define linux_SOL_IP          0
//#define linux_SOL_ICMP      1
#define linux_SOL_TCP         6
#define linux_SOL_UDP        17
#define linux_SOL_IPV6       41
#define linux_SOL_ICMPV6     58
#define linux_SOL_SCTP      132
#define linux_SOL_UDPLITE   136
#define linux_SOL_RAW       255
#define linux_SOL_IPX       256
#define linux_SOL_AX25      257
#define linux_SOL_ATALK     258
#define linux_SOL_NETROM    259
#define linux_SOL_ROSE      260
#define linux_SOL_DECNET    261
#define linux_SOL_X25       262
#define linux_SOL_PACKET    263
#define linux_SOL_ATM       264
#define linux_SOL_AAL       265
#define linux_SOL_IRDA      266
#define linux_SOL_NETBEUI   267
#define linux_SOL_LLC       268
#define linux_SOL_DCCP      269
#define linux_SOL_NETLINK   270
#define linux_SOL_TIPC      271
#define linux_SOL_RXRPC     272
#define linux_SOL_PPPOL2TP  273
#define linux_SOL_BLUETOOTH 274
#define linux_SOL_PNPIPE    275
#define linux_SOL_RDS       276
#define linux_SOL_IUCV      277
#define linux_SOL_CAIF      278
#define linux_SOL_ALG       279
#define linux_SOL_NFC       280
#define linux_SOL_KCM       281
#define linux_SOL_TLS       282
#define linux_SOL_XDP       283

#define linux_SO_DEBUG                          1
#define linux_SO_REUSEADDR                      2
#define linux_SO_TYPE                           3
#define linux_SO_ERROR                          4
#define linux_SO_DONTROUTE                      5
#define linux_SO_BROADCAST                      6
#define linux_SO_SNDBUF                         7
#define linux_SO_RCVBUF                         8
#define linux_SO_SNDBUFFORCE                   32
#define linux_SO_RCVBUFFORCE                   33
#define linux_SO_KEEPALIVE                      9
#define linux_SO_OOBINLINE                     10
#define linux_SO_NO_CHECK                      11
#define linux_SO_PRIORITY                      12
#define linux_SO_LINGER                        13
#define linux_SO_BSDCOMPAT                     14
#define linux_SO_REUSEPORT                     15
#define linux_SO_PASSCRED                      16
#define linux_SO_PEERCRED                      17
#define linux_SO_RCVLOWAT                      18
#define linux_SO_SNDLOWAT                      19
#define linux_SO_RCVTIMEO_OLD                  20
#define linux_SO_SNDTIMEO_OLD                  21
#define linux_SO_SECURITY_AUTHENTICATION       22
#define linux_SO_SECURITY_ENCRYPTION_TRANSPORT 23
#define linux_SO_SECURITY_ENCRYPTION_NETWORK   24
#define linux_SO_BINDTODEVICE                  25
#define linux_SO_ATTACH_FILTER                 26
#define linux_SO_DETACH_FILTER                 27
#define linux_SO_GET_FILTER                    linux_SO_ATTACH_FILTER
#define linux_SO_PEERNAME                      28
#define linux_SO_ACCEPTCONN                    30
#define linux_SO_PEERSEC                       31
#define linux_SO_PASSSEC                       34
#define linux_SO_MARK                          36
#define linux_SO_PROTOCOL                      38
#define linux_SO_DOMAIN                        39
#define linux_SO_RXQ_OVFL                      40
#define linux_SO_WIFI_STATUS                   41
#define linux_SCM_WIFI_STATUS                  linux_SO_WIFI_STATUS
#define linux_SO_PEEK_OFF                      42
#define linux_SO_NOFCS                         43
#define linux_SO_LOCK_FILTER                   44
#define linux_SO_SELECT_ERR_QUEUE              45
#define linux_SO_BUSY_POLL                     46
#define linux_SO_MAX_PACING_RATE               47
#define linux_SO_BPF_EXTENSIONS                48
#define linux_SO_INCOMING_CPU                  49
#define linux_SO_ATTACH_BPF                    50
#define linux_SO_DETACH_BPF                    linux_SO_DETACH_FILTER
#define linux_SO_ATTACH_REUSEPORT_CBPF         51
#define linux_SO_ATTACH_REUSEPORT_EBPF         52
#define linux_SO_CNX_ADVICE                    53
#define linux_SCM_TIMESTAMPING_OPT_STATS       54
#define linux_SO_MEMINFO                       55
#define linux_SO_INCOMING_NAPI_ID              56
#define linux_SO_COOKIE                        57
#define linux_SCM_TIMESTAMPING_PKTINFO         58
#define linux_SO_PEERGROUPS                    59
#define linux_SO_ZEROCOPY                      60
#define linux_SO_TXTIME                        61
#define linux_SCM_TXTIME                       linux_SO_TXTIME
#define linux_SO_BINDTOIFINDEX                 62
#define linux_SO_TIMESTAMP_OLD                 29
#define linux_SO_TIMESTAMPNS_OLD               35
#define linux_SO_TIMESTAMPING_OLD              37
#define linux_SO_TIMESTAMP_NEW                 63
#define linux_SO_TIMESTAMPNS_NEW               64
#define linux_SO_TIMESTAMPING_NEW              65
#define linux_SO_RCVTIMEO_NEW                  66
#define linux_SO_SNDTIMEO_NEW                  67

enum linux_sock_shutdown_cmd
{
	linux_SHUT_RD,
	linux_SHUT_WR,
	linux_SHUT_RDWR,
};

//-----------------------------------------------------------------------------
// ioctls

#define linux_SOCK_IOC_TYPE 0x89

#define linux_SIOCINQ                linux_FIONREAD
#define linux_SIOCOUTQ               linux_TIOCOUTQ
#define linux_SIOCADDRT              0x890B
#define linux_SIOCDELRT              0x890C
#define linux_SIOCRTMSG              0x890D
#define linux_SIOCGIFNAME            0x8910
#define linux_SIOCSIFLINK            0x8911
#define linux_SIOCGIFCONF            0x8912
#define linux_SIOCGIFFLAGS           0x8913
#define linux_SIOCSIFFLAGS           0x8914
#define linux_SIOCGIFADDR            0x8915
#define linux_SIOCSIFADDR            0x8916
#define linux_SIOCGIFDSTADDR         0x8917
#define linux_SIOCSIFDSTADDR         0x8918
#define linux_SIOCGIFBRDADDR         0x8919
#define linux_SIOCSIFBRDADDR         0x891a
#define linux_SIOCGIFNETMASK         0x891b
#define linux_SIOCSIFNETMASK         0x891c
#define linux_SIOCGIFMETRIC          0x891d
#define linux_SIOCSIFMETRIC          0x891e
#define linux_SIOCGIFMEM             0x891f
#define linux_SIOCSIFMEM             0x8920
#define linux_SIOCGIFMTU             0x8921
#define linux_SIOCSIFMTU             0x8922
#define linux_SIOCSIFNAME            0x8923
#define linux_SIOCSIFHWADDR          0x8924
#define linux_SIOCGIFENCAP           0x8925
#define linux_SIOCSIFENCAP           0x8926
#define linux_SIOCGIFHWADDR          0x8927
#define linux_SIOCGIFSLAVE           0x8929
#define linux_SIOCSIFSLAVE           0x8930
#define linux_SIOCADDMULTI           0x8931
#define linux_SIOCDELMULTI           0x8932
#define linux_SIOCGIFINDEX           0x8933
#define linux_SIOGIFINDEX            linux_SIOCGIFINDEX
#define linux_SIOCSIFPFLAGS          0x8934
#define linux_SIOCGIFPFLAGS          0x8935
#define linux_SIOCDIFADDR            0x8936
#define linux_SIOCSIFHWBROADCAST     0x8937
#define linux_SIOCGIFCOUNT           0x8938
#define linux_SIOCGIFBR              0x8940
#define linux_SIOCSIFBR              0x8941
#define linux_SIOCGIFTXQLEN          0x8942
#define linux_SIOCSIFTXQLEN          0x8943
//#define linux_SIOCGIFDIVERT        0x8944
//#define linux_SIOCSIFDIVERT        0x8945
#define linux_SIOCETHTOOL            0x8946
#define linux_SIOCGMIIPHY            0x8947
#define linux_SIOCGMIIREG            0x8948
#define linux_SIOCSMIIREG            0x8949
#define linux_SIOCWANDEV             0x894A
#define linux_SIOCOUTQNSD            0x894B
#define linux_SIOCGSKNS              0x894C
#define linux_SIOCDARP               0x8953
#define linux_SIOCGARP               0x8954
#define linux_SIOCSARP               0x8955
#define linux_SIOCDRARP              0x8960
#define linux_SIOCGRARP              0x8961
#define linux_SIOCSRARP              0x8962
#define linux_SIOCGIFMAP             0x8970
#define linux_SIOCSIFMAP             0x8971
#define linux_SIOCADDDLCI            0x8980
#define linux_SIOCDELDLCI            0x8981
#define linux_SIOCGIFVLAN            0x8982
#define linux_SIOCSIFVLAN            0x8983
#define linux_SIOCBONDENSLAVE        0x8990
#define linux_SIOCBONDRELEASE        0x8991
#define linux_SIOCBONDSETHWADDR      0x8992
#define linux_SIOCBONDSLAVEINFOQUERY 0x8993
#define linux_SIOCBONDINFOQUERY      0x8994
#define linux_SIOCBONDCHANGEACTIVE   0x8995
#define linux_SIOCBRADDBR            0x89a0
#define linux_SIOCBRDELBR            0x89a1
#define linux_SIOCBRADDIF            0x89a2
#define linux_SIOCBRDELIF            0x89a3
#define linux_SIOCSHWTSTAMP          0x89b0
#define linux_SIOCGHWTSTAMP          0x89b1
#define linux_SIOCDEVPRIVATE         0x89F0
#define linux_SIOCPROTOPRIVATE       0x89E0

//-----------------------------------------------------------------------------
// unix

#define linux_SIOCUNIXFILE (linux_SIOCPROTOPRIVATE + 0)

//-----------------------------------------------------------------------------
// IPv4

enum
{
	linux_IPPROTO_IP      =   0,
	linux_IPPROTO_ICMP    =   1,
	linux_IPPROTO_IGMP    =   2,
	linux_IPPROTO_IPIP    =   4,
	linux_IPPROTO_TCP     =   6,
	linux_IPPROTO_EGP     =   8,
	linux_IPPROTO_PUP     =  12,
	linux_IPPROTO_UDP     =  17,
	linux_IPPROTO_IDP     =  22,
	linux_IPPROTO_TP      =  29,
	linux_IPPROTO_DCCP    =  33,
	linux_IPPROTO_IPV6    =  41,
	linux_IPPROTO_RSVP    =  46,
	linux_IPPROTO_GRE     =  47,
	linux_IPPROTO_ESP     =  50,
	linux_IPPROTO_AH      =  51,
	linux_IPPROTO_MTP     =  92,
	linux_IPPROTO_BEETPH  =  94,
	linux_IPPROTO_ENCAP   =  98,
	linux_IPPROTO_PIM     = 103,
	linux_IPPROTO_COMP    = 108,
	linux_IPPROTO_SCTP    = 132,
	linux_IPPROTO_UDPLITE = 136,
	linux_IPPROTO_MPLS    = 137,
	linux_IPPROTO_RAW     = 255,
	linux_IPPROTO_MAX,
};

#define linux_IP_TOS                     1
#define linux_IP_TTL                     2
#define linux_IP_HDRINCL                 3
#define linux_IP_OPTIONS                 4
#define linux_IP_ROUTER_ALERT            5
#define linux_IP_RECVOPTS                6
#define linux_IP_RETOPTS                 7
#define linux_IP_PKTINFO                 8
#define linux_IP_PKTOPTIONS              9
#define linux_IP_MTU_DISCOVER           10
#define linux_IP_RECVERR                11
#define linux_IP_RECVTTL                12
#define linux_IP_RECVTOS                13
#define linux_IP_MTU                    14
#define linux_IP_FREEBIND               15
#define linux_IP_IPSEC_POLICY           16
#define linux_IP_XFRM_POLICY            17
#define linux_IP_PASSSEC                18
#define linux_IP_TRANSPARENT            19
#define linux_IP_RECVRETOPTS            linux_IP_RETOPTS
#define linux_IP_ORIGDSTADDR            20
#define linux_IP_RECVORIGDSTADDR        linux_IP_ORIGDSTADDR
#define linux_IP_MINTTL                 21
#define linux_IP_NODEFRAG               22
#define linux_IP_CHECKSUM               23
#define linux_IP_BIND_ADDRESS_NO_PORT   24
#define linux_IP_RECVFRAGSIZE           25
#define linux_IP_MULTICAST_IF           32
#define linux_IP_MULTICAST_TTL          33
#define linux_IP_MULTICAST_LOOP         34
#define linux_IP_ADD_MEMBERSHIP         35
#define linux_IP_DROP_MEMBERSHIP        36
#define linux_IP_UNBLOCK_SOURCE         37
#define linux_IP_BLOCK_SOURCE           38
#define linux_IP_ADD_SOURCE_MEMBERSHIP  39
#define linux_IP_DROP_SOURCE_MEMBERSHIP 40
#define linux_IP_MSFILTER               41
#define linux_MCAST_JOIN_GROUP          42
#define linux_MCAST_BLOCK_SOURCE        43
#define linux_MCAST_UNBLOCK_SOURCE      44
#define linux_MCAST_LEAVE_GROUP         45
#define linux_MCAST_JOIN_SOURCE_GROUP   46
#define linux_MCAST_LEAVE_SOURCE_GROUP  47
#define linux_MCAST_MSFILTER            48
#define linux_IP_MULTICAST_ALL          49
#define linux_IP_UNICAST_IF             50

#define linux_IP_PMTUDISC_DONT      0
#define linux_IP_PMTUDISC_WANT      1
#define linux_IP_PMTUDISC_DO        2
#define linux_IP_PMTUDISC_PROBE     3
#define linux_IP_PMTUDISC_INTERFACE 4
#define linux_IP_PMTUDISC_OMIT      5

#define linux_MCAST_EXCLUDE 0
#define linux_MCAST_INCLUDE 1

#define linux_IP_DEFAULT_MULTICAST_TTL  1
#define linux_IP_DEFAULT_MULTICAST_LOOP 1

#define linux_IN_CLASSA_NET    0xff000000
#define linux_IN_CLASSA_NSHIFT 24
#define linux_IN_CLASSA_HOST   (0xffffffff & ~linux_IN_CLASSA_NET)
#define linux_IN_CLASSA_MAX    128
#define linux_IN_CLASSB_NET    0xffff0000
#define linux_IN_CLASSB_NSHIFT 16
#define linux_IN_CLASSB_HOST   (0xffffffff & ~linux_IN_CLASSB_NET)
#define linux_IN_CLASSB_MAX    65536
#define linux_IN_CLASSC_NET    0xffffff00
#define linux_IN_CLASSC_NSHIFT 8
#define linux_IN_CLASSC_HOST   (0xffffffff & ~linux_IN_CLASSC_NET)
#define linux_IN_MULTICAST_NET 0xe0000000
#define linux_IN_CLASSE_NET    0xffffffff
#define linux_IN_CLASSE_NSHIFT 0

#define linux_INADDR_ANY               ((uint32_t)0x00000000)
#define linux_INADDR_BROADCAST         ((uint32_t)0xffffffff)
#define linux_INADDR_NONE              ((uint32_t)0xffffffff)
#define linux_IN_LOOPBACKNET           127
#define linux_INADDR_LOOPBACK          0x7f000001
#define linux_INADDR_UNSPEC_GROUP      0xe0000000U
#define linux_INADDR_ALLHOSTS_GROUP    0xe0000001U
#define linux_INADDR_ALLRTRS_GROUP     0xe0000002U
#define linux_INADDR_ALLSNOOPERS_GROUP 0xe000006aU
#define linux_INADDR_MAX_LOCAL_GROUP   0xe00000ffU

#define linux_SO_EE_ORIGIN_NONE         0
#define linux_SO_EE_ORIGIN_LOCAL        1
#define linux_SO_EE_ORIGIN_ICMP         2
#define linux_SO_EE_ORIGIN_ICMP6        3
#define linux_SO_EE_ORIGIN_TXSTATUS     4
#define linux_SO_EE_ORIGIN_ZEROCOPY     5
#define linux_SO_EE_ORIGIN_TXTIME       6
#define linux_SO_EE_ORIGIN_TIMESTAMPING linux_SO_EE_ORIGIN_TXSTATUS

#define linux_SO_EE_OFFENDER(ee) ((struct linux_sockaddr*)((ee)+1))

#define linux_SO_EE_CODE_ZEROCOPY_COPIED 1

#define linux_SO_EE_CODE_TXTIME_INVALID_PARAM 1
#define linux_SO_EE_CODE_TXTIME_MISSED        2

enum
{
	linux_SCM_TSTAMP_SND,
	linux_SCM_TSTAMP_SCHED,
	linux_SCM_TSTAMP_ACK,
};

//-----------------------------------------------------------------------------
// IPv6

#define linux_IN6ADDR_ANY_INIT                       { { { 0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } } }
#define linux_IN6ADDR_LOOPBACK_INIT                  { { { 0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 } } }
#define linux_IN6ADDR_LINKLOCAL_ALLNODES_INIT        { { { 0xff, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 } } }
#define linux_IN6ADDR_LINKLOCAL_ALLROUTERS_INIT      { { { 0xff, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 } } }
#define linux_IN6ADDR_INTERFACELOCAL_ALLNODES_INIT   { { { 0xff, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 } } }
#define linux_IN6ADDR_INTERFACELOCAL_ALLROUTERS_INIT { { { 0xff, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 } } }
#define linux_IN6ADDR_SITELOCAL_ALLROUTERS_INIT      { { { 0xff, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 } } }

#define linux_IPV6_FL_A_GET   0
#define linux_IPV6_FL_A_PUT   1
#define linux_IPV6_FL_A_RENEW 2

#define linux_IPV6_FL_F_CREATE  1
#define linux_IPV6_FL_F_EXCL    2
#define linux_IPV6_FL_F_REFLECT 4
#define linux_IPV6_FL_F_REMOTE  8

#define linux_IPV6_FL_S_NONE      0
#define linux_IPV6_FL_S_EXCL      1
#define linux_IPV6_FL_S_PROCESS   2
#define linux_IPV6_FL_S_USER      3
#define linux_IPV6_FL_S_ANY     255

#define linux_IPV6_FLOWINFO_FLOWLABEL 0x000fffff
#define linux_IPV6_FLOWINFO_PRIORITY  0x0ff00000

#define linux_IPV6_PRIORITY_UNCHARACTERIZED 0x0000
#define linux_IPV6_PRIORITY_FILLER          0x0100
#define linux_IPV6_PRIORITY_UNATTENDED      0x0200
#define linux_IPV6_PRIORITY_RESERVED1       0x0300
#define linux_IPV6_PRIORITY_BULK            0x0400
#define linux_IPV6_PRIORITY_RESERVED2       0x0500
#define linux_IPV6_PRIORITY_INTERACTIVE     0x0600
#define linux_IPV6_PRIORITY_CONTROL         0x0700
#define linux_IPV6_PRIORITY_8               0x0800
#define linux_IPV6_PRIORITY_9               0x0900
#define linux_IPV6_PRIORITY_10              0x0a00
#define linux_IPV6_PRIORITY_11              0x0b00
#define linux_IPV6_PRIORITY_12              0x0c00
#define linux_IPV6_PRIORITY_13              0x0d00
#define linux_IPV6_PRIORITY_14              0x0e00
#define linux_IPV6_PRIORITY_15              0x0f00

#define linux_IPPROTO_HOPOPTS    0
#define linux_IPPROTO_ROUTING   43
#define linux_IPPROTO_FRAGMENT  44
#define linux_IPPROTO_ICMPV6    58
#define linux_IPPROTO_NONE      59
#define linux_IPPROTO_DSTOPTS   60
#define linux_IPPROTO_MH       135

#define linux_IPV6_TLV_PAD1          0
#define linux_IPV6_TLV_PADN          1
#define linux_IPV6_TLV_ROUTERALERT   5
#define linux_IPV6_TLV_CALIPSO       7
#define linux_IPV6_TLV_JUMBO       194
#define linux_IPV6_TLV_HAO         201

#define linux_IPV6_ADDRFORM              1
#define linux_IPV6_2292PKTINFO           2
#define linux_IPV6_2292HOPOPTS           3
#define linux_IPV6_2292DSTOPTS           4
#define linux_IPV6_2292RTHDR             5
#define linux_IPV6_2292PKTOPTIONS        6
#define linux_IPV6_CHECKSUM              7
#define linux_IPV6_2292HOPLIMIT          8
#define linux_IPV6_NEXTHOP               9
#define linux_IPV6_AUTHHDR              10
#define linux_IPV6_FLOWINFO             11
#define linux_IPV6_UNICAST_HOPS         16
#define linux_IPV6_MULTICAST_IF         17
#define linux_IPV6_MULTICAST_HOPS       18
#define linux_IPV6_MULTICAST_LOOP       19
#define linux_IPV6_ADD_MEMBERSHIP       20
#define linux_IPV6_DROP_MEMBERSHIP      21
#define linux_IPV6_ROUTER_ALERT         22
#define linux_IPV6_MTU_DISCOVER         23
#define linux_IPV6_MTU                  24
#define linux_IPV6_RECVERR              25
#define linux_IPV6_V6ONLY               26
#define linux_IPV6_JOIN_ANYCAST         27
#define linux_IPV6_LEAVE_ANYCAST        28
#define linux_IPV6_MULTICAST_ALL        29
#define linux_IPV6_ROUTER_ALERT_ISOLATE 30
#define linux_IPV6_FLOWLABEL_MGR        32
#define linux_IPV6_FLOWINFO_SEND        33
#define linux_IPV6_IPSEC_POLICY         34
#define linux_IPV6_XFRM_POLICY          35
#define linux_IPV6_HDRINCL              36
#define linux_IPV6_RECVPKTINFO          49
#define linux_IPV6_PKTINFO              50
#define linux_IPV6_RECVHOPLIMIT         51
#define linux_IPV6_HOPLIMIT             52
#define linux_IPV6_RECVHOPOPTS          53
#define linux_IPV6_HOPOPTS              54
#define linux_IPV6_RTHDRDSTOPTS         55
#define linux_IPV6_RECVRTHDR            56
#define linux_IPV6_RTHDR                57
#define linux_IPV6_RECVDSTOPTS          58
#define linux_IPV6_DSTOPTS              59
#define linux_IPV6_RECVPATHMTU          60
#define linux_IPV6_PATHMTU              61
#define linux_IPV6_DONTFRAG             62
//#define linux_IPV6_USE_MIN_MTU        63
#define linux_IPV6_RECVTCLASS           66
#define linux_IPV6_TCLASS               67
#define linux_IPV6_AUTOFLOWLABEL        70
#define linux_IPV6_ADDR_PREFERENCES     72
#define linux_IPV6_MINHOPCOUNT          73
#define linux_IPV6_ORIGDSTADDR          74
#define linux_IPV6_RECVORIGDSTADDR      linux_IPV6_ORIGDSTADDR
#define linux_IPV6_TRANSPARENT          75
#define linux_IPV6_UNICAST_IF           76
#define linux_IPV6_RECVFRAGSIZE         77
#define linux_IPV6_FREEBIND             78

#define linux_IPV6_PMTUDISC_DONT      0
#define linux_IPV6_PMTUDISC_WANT      1
#define linux_IPV6_PMTUDISC_DO        2
#define linux_IPV6_PMTUDISC_PROBE     3
#define linux_IPV6_PMTUDISC_INTERFACE 4
#define linux_IPV6_PMTUDISC_OMIT      5

#define linux_IPV6_PREFER_SRC_TMP            0x0001
#define linux_IPV6_PREFER_SRC_PUBLIC         0x0002
#define linux_IPV6_PREFER_SRC_PUBTMP_DEFAULT 0x0100
#define linux_IPV6_PREFER_SRC_COA            0x0004
#define linux_IPV6_PREFER_SRC_HOME           0x0400
#define linux_IPV6_PREFER_SRC_CGA            0x0008
#define linux_IPV6_PREFER_SRC_NONCGA         0x0800

#define linux_RTF_DEFAULT    0x00010000
#define linux_RTF_ALLONLINK  0x00020000
#define linux_RTF_ADDRCONF   0x00040000
#define linux_RTF_PREFIX_RT  0x00080000
#define linux_RTF_ANYCAST    0x00100000
#define linux_RTF_NONEXTHOP  0x00200000
#define linux_RTF_EXPIRES    0x00400000
#define linux_RTF_ROUTEINFO  0x00800000
#define linux_RTF_CACHE      0x01000000
#define linux_RTF_FLOW       0x02000000
#define linux_RTF_POLICY     0x04000000
#define linux_RTF_PREF(pref) ((pref) << 27)
#define linux_RTF_PREF_MASK  0x18000000
#define linux_RTF_PCPU       0x40000000
#define linux_RTF_LOCAL      0x80000000

#define linux_RTMSG_NEWDEVICE 0x11
#define linux_RTMSG_DELDEVICE 0x12
#define linux_RTMSG_NEWROUTE  0x21
#define linux_RTMSG_DELROUTE  0x22

#define linux_IP6_RT_PRIO_USER     1024
#define linux_IP6_RT_PRIO_ADDRCONF  256

#define linux_IPV6_MIN_MTU 1280

#define linux_IPV6_SRCRT_STRICT 0x01
#define linux_IPV6_SRCRT_TYPE_0 0
#define linux_IPV6_SRCRT_TYPE_2 2
#define linux_IPV6_SRCRT_TYPE_4 4

#define linux_IPV6_OPT_ROUTERALERT_MLD 0x0000

enum
{
	linux_DEVCONF_FORWARDING = 0,
	linux_DEVCONF_HOPLIMIT,
	linux_DEVCONF_MTU6,
	linux_DEVCONF_ACCEPT_RA,
	linux_DEVCONF_ACCEPT_REDIRECTS,
	linux_DEVCONF_AUTOCONF,
	linux_DEVCONF_DAD_TRANSMITS,
	linux_DEVCONF_RTR_SOLICITS,
	linux_DEVCONF_RTR_SOLICIT_INTERVAL,
	linux_DEVCONF_RTR_SOLICIT_DELAY,
	linux_DEVCONF_USE_TEMPADDR,
	linux_DEVCONF_TEMP_VALID_LFT,
	linux_DEVCONF_TEMP_PREFERED_LFT,
	linux_DEVCONF_REGEN_MAX_RETRY,
	linux_DEVCONF_MAX_DESYNC_FACTOR,
	linux_DEVCONF_MAX_ADDRESSES,
	linux_DEVCONF_FORCE_MLD_VERSION,
	linux_DEVCONF_ACCEPT_RA_DEFRTR,
	linux_DEVCONF_ACCEPT_RA_PINFO,
	linux_DEVCONF_ACCEPT_RA_RTR_PREF,
	linux_DEVCONF_RTR_PROBE_INTERVAL,
	linux_DEVCONF_ACCEPT_RA_RT_INFO_MAX_PLEN,
	linux_DEVCONF_PROXY_NDP,
	linux_DEVCONF_OPTIMISTIC_DAD,
	linux_DEVCONF_ACCEPT_SOURCE_ROUTE,
	linux_DEVCONF_MC_FORWARDING,
	linux_DEVCONF_DISABLE_IPV6,
	linux_DEVCONF_ACCEPT_DAD,
	linux_DEVCONF_FORCE_TLLAO,
	linux_DEVCONF_NDISC_NOTIFY,
	linux_DEVCONF_MLDV1_UNSOLICITED_REPORT_INTERVAL,
	linux_DEVCONF_MLDV2_UNSOLICITED_REPORT_INTERVAL,
	linux_DEVCONF_SUPPRESS_FRAG_NDISC,
	linux_DEVCONF_ACCEPT_RA_FROM_LOCAL,
	linux_DEVCONF_USE_OPTIMISTIC,
	linux_DEVCONF_ACCEPT_RA_MTU,
	linux_DEVCONF_STABLE_SECRET,
	linux_DEVCONF_USE_OIF_ADDRS_ONLY,
	linux_DEVCONF_ACCEPT_RA_MIN_HOP_LIMIT,
	linux_DEVCONF_IGNORE_ROUTES_WITH_LINKDOWN,
	linux_DEVCONF_DROP_UNICAST_IN_L2_MULTICAST,
	linux_DEVCONF_DROP_UNSOLICITED_NA,
	linux_DEVCONF_KEEP_ADDR_ON_DOWN,
	linux_DEVCONF_RTR_SOLICIT_MAX_INTERVAL,
	linux_DEVCONF_SEG6_ENABLED,
	linux_DEVCONF_SEG6_REQUIRE_HMAC,
	linux_DEVCONF_ENHANCED_DAD,
	linux_DEVCONF_ADDR_GEN_MODE,
	linux_DEVCONF_DISABLE_POLICY,
	linux_DEVCONF_ACCEPT_RA_RT_INFO_MIN_PLEN,
	linux_DEVCONF_NDISC_TCLASS,
	linux_DEVCONF_MAX,
};

#define linux_IPV6_TLV_TNL_ENCAP_LIMIT     4
#define linux_IPV6_DEFAULT_TNL_ENCAP_LIMIT 4

#define linux_IP6_TNL_F_IGN_ENCAP_LIMIT    0x1
#define linux_IP6_TNL_F_USE_ORIG_TCLASS    0x2
#define linux_IP6_TNL_F_USE_ORIG_FLOWLABEL 0x4
#define linux_IP6_TNL_F_MIP6_DEV           0x8
#define linux_IP6_TNL_F_RCV_DSCP_COPY      0x10
#define linux_IP6_TNL_F_USE_ORIG_FWMARK    0x20
#define linux_IP6_TNL_F_ALLOW_LOCAL_REMOTE 0x40

//-----------------------------------------------------------------------------
// AppleTalk

#define linux_ATPORT_FIRST      1
#define linux_ATPORT_RESERVED 128
#define linux_ATPORT_LAST     254
#define linux_ATADDR_ANYNET   (uint16_t)0
#define linux_ATADDR_ANYNODE  (uint8_t)0
#define linux_ATADDR_ANYPORT  (uint8_t)0
#define linux_ATADDR_BCAST    (uint8_t)255
#define linux_DDP_MAXSZ       587
#define linux_DDP_MAXHOPS      15

#define linux_SIOCATALKDIFADDR (linux_SIOCPROTOPRIVATE + 0)

//-----------------------------------------------------------------------------
// Packet

#define linux_PACKET_HOST      0
#define linux_PACKET_BROADCAST 1
#define linux_PACKET_MULTICAST 2
#define linux_PACKET_OTHERHOST 3
#define linux_PACKET_OUTGOING  4
#define linux_PACKET_LOOPBACK  5
#define linux_PACKET_USER      6
#define linux_PACKET_KERNEL    7
#define linux_PACKET_FASTROUTE 6

#define linux_PACKET_ADD_MEMBERSHIP   1
#define linux_PACKET_DROP_MEMBERSHIP  2
#define linux_PACKET_RECV_OUTPUT      3
#define linux_PACKET_RX_RING          5
#define linux_PACKET_STATISTICS       6
#define linux_PACKET_COPY_THRESH      7
#define linux_PACKET_AUXDATA          8
#define linux_PACKET_ORIGDEV          9
#define linux_PACKET_VERSION         10
#define linux_PACKET_HDRLEN          11
#define linux_PACKET_RESERVE         12
#define linux_PACKET_TX_RING         13
#define linux_PACKET_LOSS            14
#define linux_PACKET_VNET_HDR        15
#define linux_PACKET_TX_TIMESTAMP    16
#define linux_PACKET_TIMESTAMP       17
#define linux_PACKET_FANOUT          18
#define linux_PACKET_TX_HAS_OFF      19
#define linux_PACKET_QDISC_BYPASS    20
#define linux_PACKET_ROLLOVER_STATS  21
#define linux_PACKET_FANOUT_DATA     22
#define linux_PACKET_IGNORE_OUTGOING 23

#define linux_PACKET_FANOUT_HASH          0
#define linux_PACKET_FANOUT_LB            1
#define linux_PACKET_FANOUT_CPU           2
#define linux_PACKET_FANOUT_ROLLOVER      3
#define linux_PACKET_FANOUT_RND           4
#define linux_PACKET_FANOUT_QM            5
#define linux_PACKET_FANOUT_CBPF          6
#define linux_PACKET_FANOUT_EBPF          7
#define linux_PACKET_FANOUT_FLAG_ROLLOVER 0x1000
#define linux_PACKET_FANOUT_FLAG_UNIQUEID 0x2000
#define linux_PACKET_FANOUT_FLAG_DEFRAG   0x8000

#define linux_TP_STATUS_KERNEL          0
#define linux_TP_STATUS_USER            (1 << 0)
#define linux_TP_STATUS_COPY            (1 << 1)
#define linux_TP_STATUS_LOSING          (1 << 2)
#define linux_TP_STATUS_CSUMNOTREADY    (1 << 3)
#define linux_TP_STATUS_VLAN_VALID      (1 << 4)
#define linux_TP_STATUS_BLK_TMO         (1 << 5)
#define linux_TP_STATUS_VLAN_TPID_VALID (1 << 6)
#define linux_TP_STATUS_CSUM_VALID      (1 << 7)

#define linux_TP_STATUS_AVAILABLE    0
#define linux_TP_STATUS_SEND_REQUEST (1 << 0)
#define linux_TP_STATUS_SENDING      (1 << 1)
#define linux_TP_STATUS_WRONG_FORMAT (1 << 2)

#define linux_TP_STATUS_TS_SOFTWARE     (1 << 29)
#define linux_TP_STATUS_TS_SYS_HARDWARE (1 << 30)
#define linux_TP_STATUS_TS_RAW_HARDWARE (1 << 31)

#define linux_TP_FT_REQ_FILL_RXHASH 0x1

#define linux_TPACKET_ALIGNMENT 16
#define linux_TPACKET_ALIGN(x)  (((x)+linux_TPACKET_ALIGNMENT-1)&~(linux_TPACKET_ALIGNMENT-1))
#define linux_TPACKET_HDRLEN    (linux_TPACKET_ALIGN(sizeof(struct linux_tpacket_hdr)) + sizeof(struct linux_sockaddr_ll))
#define linux_TPACKET2_HDRLEN   (linux_TPACKET_ALIGN(sizeof(struct linux_tpacket2_hdr)) + sizeof(struct linux_sockaddr_ll))
#define linux_TPACKET3_HDRLEN   (linux_TPACKET_ALIGN(sizeof(struct linux_tpacket3_hdr)) + sizeof(struct linux_sockaddr_ll))

enum linux_tpacket_versions
{
	linux_TPACKET_V1,
	linux_TPACKET_V2,
	linux_TPACKET_V3,
};

#define linux_PACKET_MR_MULTICAST 0
#define linux_PACKET_MR_PROMISC   1
#define linux_PACKET_MR_ALLMULTI  2
#define linux_PACKET_MR_UNICAST   3

//-----------------------------------------------------------------------------
// ax25

#define linux_AX25_MTU       256
#define linux_AX25_MAX_DIGIS   8

#define linux_AX25_WINDOW   1
#define linux_AX25_T1       2
#define linux_AX25_N2       3
#define linux_AX25_T3       4
#define linux_AX25_T2       5
#define linux_AX25_BACKOFF  6
#define linux_AX25_EXTSEQ   7
#define linux_AX25_PIDINCL  8
#define linux_AX25_IDLE     9
#define linux_AX25_PACLEN  10
#define linux_AX25_IAMDIGI 12
#define linux_AX25_KILL    99

#define linux_SIOCAX25GETUID     (linux_SIOCPROTOPRIVATE+0)
#define linux_SIOCAX25ADDUID     (linux_SIOCPROTOPRIVATE+1)
#define linux_SIOCAX25DELUID     (linux_SIOCPROTOPRIVATE+2)
#define linux_SIOCAX25NOUID      (linux_SIOCPROTOPRIVATE+3)
#define linux_SIOCAX25OPTRT      (linux_SIOCPROTOPRIVATE+7)
#define linux_SIOCAX25CTLCON     (linux_SIOCPROTOPRIVATE+8)
#define linux_SIOCAX25GETINFOOLD (linux_SIOCPROTOPRIVATE+9)
#define linux_SIOCAX25ADDFWD     (linux_SIOCPROTOPRIVATE+10)
#define linux_SIOCAX25DELFWD     (linux_SIOCPROTOPRIVATE+11)
#define linux_SIOCAX25DEVCTL     (linux_SIOCPROTOPRIVATE+12)
#define linux_SIOCAX25GETINFO    (linux_SIOCPROTOPRIVATE+13)

#define linux_AX25_SET_RT_IPMODE 2

#define linux_AX25_NOUID_DEFAULT 0
#define linux_AX25_NOUID_BLOCK   1

//-----------------------------------------------------------------------------
// x25

#define linux_SIOCX25GSUBSCRIP      (linux_SIOCPROTOPRIVATE +  0)
#define linux_SIOCX25SSUBSCRIP      (linux_SIOCPROTOPRIVATE +  1)
#define linux_SIOCX25GFACILITIES    (linux_SIOCPROTOPRIVATE +  2)
#define linux_SIOCX25SFACILITIES    (linux_SIOCPROTOPRIVATE +  3)
#define linux_SIOCX25GCALLUSERDATA  (linux_SIOCPROTOPRIVATE +  4)
#define linux_SIOCX25SCALLUSERDATA  (linux_SIOCPROTOPRIVATE +  5)
#define linux_SIOCX25GCAUSEDIAG     (linux_SIOCPROTOPRIVATE +  6)
#define linux_SIOCX25SCUDMATCHLEN   (linux_SIOCPROTOPRIVATE +  7)
#define linux_SIOCX25CALLACCPTAPPRV (linux_SIOCPROTOPRIVATE +  8)
#define linux_SIOCX25SENDCALLACCPT  (linux_SIOCPROTOPRIVATE +  9)
#define linux_SIOCX25GDTEFACILITIES (linux_SIOCPROTOPRIVATE + 10)
#define linux_SIOCX25SDTEFACILITIES (linux_SIOCPROTOPRIVATE + 11)
#define linux_SIOCX25SCAUSEDIAG     (linux_SIOCPROTOPRIVATE + 12)

#define linux_X25_QBITINCL 1

#define linux_X25_PS16    4
#define linux_X25_PS32    5
#define linux_X25_PS64    6
#define linux_X25_PS128   7
#define linux_X25_PS256   8
#define linux_X25_PS512   9
#define linux_X25_PS1024 10
#define linux_X25_PS2048 11
#define linux_X25_PS4096 12

#define linux_X25_MASK_REVERSE     0x01
#define linux_X25_MASK_THROUGHPUT  0x02
#define linux_X25_MASK_PACKET_SIZE 0x04
#define linux_X25_MASK_WINDOW_SIZE 0x08
#define linux_X25_MASK_CALLING_AE  0x10
#define linux_X25_MASK_CALLED_AE   0x20

//-----------------------------------------------------------------------------
// Netlink

#define linux_NETLINK_ROUTE           0
#define linux_NETLINK_UNUSED          1
#define linux_NETLINK_USERSOCK        2
#define linux_NETLINK_FIREWALL        3
#define linux_NETLINK_SOCK_DIAG       4
#define linux_NETLINK_NFLOG           5
#define linux_NETLINK_XFRM            6
#define linux_NETLINK_SELINUX         7
#define linux_NETLINK_ISCSI           8
#define linux_NETLINK_AUDIT           9
#define linux_NETLINK_FIB_LOOKUP     10
#define linux_NETLINK_CONNECTOR      11
#define linux_NETLINK_NETFILTER      12
#define linux_NETLINK_IP6_FW         13
#define linux_NETLINK_DNRTMSG        14
#define linux_NETLINK_KOBJECT_UEVENT 15
#define linux_NETLINK_GENERIC        16
#define linux_NETLINK_SCSITRANSPORT  18
#define linux_NETLINK_ECRYPTFS       19
#define linux_NETLINK_RDMA           20
#define linux_NETLINK_CRYPTO         21
#define linux_NETLINK_SMC            22
#define linux_NETLINK_INET_DIAG      linux_NETLINK_SOCK_DIAG

#define linux_MAX_LINKS 32

#define linux_NLM_F_REQUEST       0x01
#define linux_NLM_F_MULTI         0x02
#define linux_NLM_F_ACK           0x04
#define linux_NLM_F_ECHO          0x08
#define linux_NLM_F_DUMP_INTR     0x10
#define linux_NLM_F_DUMP_FILTERED 0x20
#define linux_NLM_F_ROOT          0x100
#define linux_NLM_F_MATCH         0x200
#define linux_NLM_F_ATOMIC        0x400
#define linux_NLM_F_DUMP          (linux_NLM_F_ROOT | linux_NLM_F_MATCH)
#define linux_NLM_F_REPLACE       0x100
#define linux_NLM_F_EXCL          0x200
#define linux_NLM_F_CREATE        0x400
#define linux_NLM_F_APPEND        0x800
#define linux_NLM_F_NONREC        0x100
#define linux_NLM_F_CAPPED        0x100
#define linux_NLM_F_ACK_TLVS      0x200

#define linux_NLMSG_ALIGNTO          4U
#define linux_NLMSG_ALIGN(len)       (((len)+linux_NLMSG_ALIGNTO-1) & ~(linux_NLMSG_ALIGNTO-1))
#define linux_NLMSG_HDRLEN           ((int) linux_NLMSG_ALIGN(sizeof(struct linux_nlmsghdr)))
#define linux_NLMSG_LENGTH(len)      ((len) + linux_NLMSG_HDRLEN)
#define linux_NLMSG_SPACE(len)       linux_NLMSG_ALIGN(linux_NLMSG_LENGTH(len))
#define linux_NLMSG_DATA(nlh)        ((void*)(((char*)nlh) + linux_NLMSG_LENGTH(0)))
#define linux_NLMSG_NEXT(nlh,len)    ((len) -= linux_NLMSG_ALIGN((nlh)->nlmsg_len), (struct linux_nlmsghdr*)(((char*)(nlh)) + linux_NLMSG_ALIGN((nlh)->nlmsg_len)))
#define linux_NLMSG_OK(nlh,len)      ((len) >= (int)sizeof(struct linux_nlmsghdr) && (nlh)->nlmsg_len >= sizeof(struct linux_nlmsghdr) && (nlh)->nlmsg_len <= (len))
#define linux_NLMSG_PAYLOAD(nlh,len) ((nlh)->nlmsg_len - linux_NLMSG_SPACE((len)))
#define linux_NLMSG_NOOP             0x1
#define linux_NLMSG_ERROR            0x2
#define linux_NLMSG_DONE             0x3
#define linux_NLMSG_OVERRUN          0x4
#define linux_NLMSG_MIN_TYPE         0x10

//-----------------------------------------------------------------------------
// rtnetlink

#define linux_RTNL_FAMILY_IPMR  128
#define linux_RTNL_FAMILY_IP6MR 129
#define linux_RTNL_FAMILY_MAX   129

enum
{
	linux_RTM_BASE           = 16,
	linux_RTM_NEWLINK        = 16,
	linux_RTM_DELLINK,
	linux_RTM_GETLINK,
	linux_RTM_SETLINK,
	linux_RTM_NEWADDR        = 20,
	linux_RTM_DELADDR,
	linux_RTM_GETADDR,
	linux_RTM_NEWROUTE       = 24,
	linux_RTM_DELROUTE,
	linux_RTM_GETROUTE,
	linux_RTM_NEWNEIGH       = 28,
	linux_RTM_DELNEIGH,
	linux_RTM_GETNEIGH,
	linux_RTM_NEWRULE        = 32,
	linux_RTM_DELRULE,
	linux_RTM_GETRULE,
	linux_RTM_NEWQDISC       = 36,
	linux_RTM_DELQDISC,
	linux_RTM_GETQDISC,
	linux_RTM_NEWTCLASS      = 40,
	linux_RTM_DELTCLASS,
	linux_RTM_GETTCLASS,
	linux_RTM_NEWTFILTER     = 44,
	linux_RTM_DELTFILTER,
	linux_RTM_GETTFILTER,
	linux_RTM_NEWACTION      = 48,
	linux_RTM_DELACTION,
	linux_RTM_GETACTION,
	linux_RTM_NEWPREFIX      = 52,
	linux_RTM_GETMULTICAST   = 58,
	linux_RTM_GETANYCAST     = 62,
	linux_RTM_NEWNEIGHTBL    = 64,
	linux_RTM_GETNEIGHTBL    = 66,
	linux_RTM_SETNEIGHTBL,
	linux_RTM_NEWNDUSEROPT   = 68,
	linux_RTM_NEWADDRLABEL   = 72,
	linux_RTM_DELADDRLABEL,
	linux_RTM_GETADDRLABEL,
	linux_RTM_GETDCB         = 78,
	linux_RTM_SETDCB,
	linux_RTM_NEWNETCONF     = 80,
	linux_RTM_DELNETCONF,
	linux_RTM_GETNETCONF     = 82,
	linux_RTM_NEWMDB         = 84,
	linux_RTM_DELMDB         = 85,
	linux_RTM_GETMDB         = 86,
	linux_RTM_NEWNSID        = 88,
	linux_RTM_DELNSID        = 89,
	linux_RTM_GETNSID        = 90,
	linux_RTM_NEWSTATS       = 92,
	linux_RTM_GETSTATS       = 94,
	linux_RTM_NEWCACHEREPORT = 96,
	linux_RTM_NEWCHAIN       = 100,
	linux_RTM_DELCHAIN,
	linux_RTM_GETCHAIN,
	linux_RTM_NEWNEXTHOP     = 104,
	linux_RTM_DELNEXTHOP,
	linux_RTM_GETNEXTHOP,
	linux_RTM_NEWLINKPROP    = 108,
	linux_RTM_DELLINKPROP,
	linux_RTM_GETLINKPROP,
	linux__RTM_MAX,
#define linux_RTM_MAX (((linux__RTM_MAX + 3) & ~3) - 1)
};

#define linux_RTM_NR_MSGTYPES (linux_RTM_MAX + 1 - linux_RTM_BASE)
#define linux_RTM_NR_FAMILIES (linux_RTM_NR_MSGTYPES >> 2)
#define linux_RTM_FAM(cmd)    (((cmd) - linux_RTM_BASE) >> 2)

#define linux_RTA_ALIGNTO            4U
#define linux_RTA_ALIGN(len)         (((len) + linux_RTA_ALIGNTO - 1) & ~(linux_RTA_ALIGNTO - 1))
#define linux_RTA_OK(rta, len)       ((len) >= (int)sizeof(struct linux_rtattr) && (rta)->rta_len >= sizeof(struct linux_rtattr) && (rta)->rta_len <= (len))
#define linux_RTA_NEXT(rta, attrlen) ((attrlen) -= linux_RTA_ALIGN((rta)->rta_len), (struct linux_rtattr*)(((char*)(rta)) + linux_RTA_ALIGN((rta)->rta_len)))
#define linux_RTA_LENGTH(len)        (linux_RTA_ALIGN(sizeof(struct linux_rtattr)) + (len))
#define linux_RTA_SPACE(len)         linux_RTA_ALIGN(linux_RTA_LENGTH(len))
#define linux_RTA_DATA(rta)          ((void*)(((char*)(rta)) + linux_RTA_LENGTH(0)))
#define linux_RTA_PAYLOAD(rta)       ((int)((rta)->rta_len) - linux_RTA_LENGTH(0))

enum
{
	linux_RTN_UNSPEC,
	linux_RTN_UNICAST,
	linux_RTN_LOCAL,
	linux_RTN_BROADCAST,
	linux_RTN_ANYCAST,
	linux_RTN_MULTICAST,
	linux_RTN_BLACKHOLE,
	linux_RTN_UNREACHABLE,
	linux_RTN_PROHIBIT,
	linux_RTN_THROW,
	linux_RTN_NAT,
	linux_RTN_XRESOLVE,
	linux__RTN_MAX,
#define linux_RTN_MAX (linux__RTN_MAX - 1)
};

#define linux_RTPROT_UNSPEC     0
#define linux_RTPROT_REDIRECT   1
#define linux_RTPROT_KERNEL     2
#define linux_RTPROT_BOOT       3
#define linux_RTPROT_STATIC     4
#define linux_RTPROT_GATED      8
#define linux_RTPROT_RA         9
#define linux_RTPROT_MRT       10
#define linux_RTPROT_ZEBRA     11
#define linux_RTPROT_BIRD      12
#define linux_RTPROT_DNROUTED  13
#define linux_RTPROT_XORP      14
#define linux_RTPROT_NTK       15
#define linux_RTPROT_DHCP      16
#define linux_RTPROT_MROUTED   17
#define linux_RTPROT_BABEL     42
#define linux_RTPROT_BGP      186
#define linux_RTPROT_ISIS     187
#define linux_RTPROT_OSPF     188
#define linux_RTPROT_RIP      189
#define linux_RTPROT_EIGRP    192

enum linux_rt_scope_t
{
	linux_RT_SCOPE_UNIVERSE =   0,
	linux_RT_SCOPE_SITE     = 200,
	linux_RT_SCOPE_LINK     = 253,
	linux_RT_SCOPE_HOST     = 254,
	linux_RT_SCOPE_NOWHERE  = 255,
};

#define linux_RTM_F_NOTIFY       0x0100
#define linux_RTM_F_CLONED       0x0200
#define linux_RTM_F_EQUALIZE     0x0400
#define linux_RTM_F_PREFIX       0x0800
#define linux_RTM_F_LOOKUP_TABLE 0x1000
#define linux_RTM_F_FIB_MATCH    0x2000

enum linux_rt_class_t
{
	linux_RT_TABLE_UNSPEC  =   0,
	linux_RT_TABLE_COMPAT  = 252,
	linux_RT_TABLE_DEFAULT = 253,
	linux_RT_TABLE_MAIN    = 254,
	linux_RT_TABLE_LOCAL   = 255,
#define linux_RT_TABLE_MAX 0xFFFFFFFF
};

enum linux_rtattr_type_t
{
	linux_RTA_UNSPEC,
	linux_RTA_DST,
	linux_RTA_SRC,
	linux_RTA_IIF,
	linux_RTA_OIF,
	linux_RTA_GATEWAY,
	linux_RTA_PRIORITY,
	linux_RTA_PREFSRC,
	linux_RTA_METRICS,
	linux_RTA_MULTIPATH,
	linux_RTA_PROTOINFO,
	linux_RTA_FLOW,
	linux_RTA_CACHEINFO,
	linux_RTA_SESSION,
	linux_RTA_MP_ALGO,
	linux_RTA_TABLE,
	linux_RTA_MARK,
	linux_RTA_MFC_STATS,
	linux_RTA_VIA,
	linux_RTA_NEWDST,
	linux_RTA_PREF,
	linux_RTA_ENCAP_TYPE,
	linux_RTA_ENCAP,
	linux_RTA_EXPIRES,
	linux_RTA_PAD,
	linux_RTA_UID,
	linux_RTA_TTL_PROPAGATE,
	linux_RTA_IP_PROTO,
	linux_RTA_SPORT,
	linux_RTA_DPORT,
	linux_RTA_NH_ID,
	linux__RTA_MAX,
#define linux_RTA_MAX (linux__RTA_MAX - 1)
};

#define linux_RTM_RTA(r)     ((struct linux_rtattr*)(((char*)(r)) + linux_NLMSG_ALIGN(sizeof(struct linux_rtmsg))))
#define linux_RTM_PAYLOAD(n) linux_NLMSG_PAYLOAD(n, sizeof(struct linux_rtmsg))

#define linux_RTNH_F_DEAD        1
#define linux_RTNH_F_PERVASIVE   2
#define linux_RTNH_F_ONLINK      4
#define linux_RTNH_F_OFFLOAD     8
#define linux_RTNH_F_LINKDOWN   16
#define linux_RTNH_F_UNRESOLVED 32

#define linux_RTNH_COMPARE_MASK (linux_RTNH_F_DEAD | linux_RTNH_F_LINKDOWN | linux_RTNH_F_OFFLOAD)

#define RTNH_ALIGNTO       4
#define RTNH_ALIGN(len)    (((len) + linux_RTNH_ALIGNTO - 1) & ~(linux_RTNH_ALIGNTO - 1))
#define RTNH_OK(rtnh, len) ((rtnh)->rtnh_len >= sizeof(struct linux_rtnexthop) && ((int)(rtnh)->rtnh_len) <= (len))
#define RTNH_NEXT(rtnh)    ((struct linux_rtnexthop*)(((char*)(rtnh)) + linux_RTNH_ALIGN((rtnh)->rtnh_len)))
#define RTNH_LENGTH(len)   (linux_RTNH_ALIGN(sizeof(struct linux_rtnexthop)) + (len))
#define RTNH_SPACE(len)    linux_RTNH_ALIGN(linux_RTNH_LENGTH(len))
#define RTNH_DATA(rtnh)    ((struct linux_rtattr*)(((char*)(rtnh)) + linux_RTNH_LENGTH(0)))

#define linux_RTNETLINK_HAVE_PEERINFO 1

enum
{
	linux_RTAX_UNSPEC,
	linux_RTAX_LOCK,
	linux_RTAX_MTU,
	linux_RTAX_WINDOW,
	linux_RTAX_RTT,
	linux_RTAX_RTTVAR,
	linux_RTAX_SSTHRESH,
	linux_RTAX_CWND,
	linux_RTAX_ADVMSS,
	linux_RTAX_REORDERING,
	linux_RTAX_HOPLIMIT,
	linux_RTAX_INITCWND,
	linux_RTAX_FEATURES,
	linux_RTAX_RTO_MIN,
	linux_RTAX_INITRWND,
	linux_RTAX_QUICKACK,
	linux_RTAX_CC_ALGO,
	linux_RTAX_FASTOPEN_NO_COOKIE,
	linux__RTAX_MAX,
#define linux_RTAX_MAX (linux__RTAX_MAX - 1)
};

#define linux_RTAX_FEATURE_ECN       (1 << 0)
#define linux_RTAX_FEATURE_SACK      (1 << 1)
#define linux_RTAX_FEATURE_TIMESTAMP (1 << 2)
#define linux_RTAX_FEATURE_ALLFRAG   (1 << 3)

#define linux_RTAX_FEATURE_MASK (linux_RTAX_FEATURE_ECN | linux_RTAX_FEATURE_SACK | linux_RTAX_FEATURE_TIMESTAMP | linux_RTAX_FEATURE_ALLFRAG)

enum
{
	linux_PREFIX_UNSPEC,
	linux_PREFIX_ADDRESS,
	linux_PREFIX_CACHEINFO,
	linux__PREFIX_MAX,
#define linux_PREFIX_MAX (linux__PREFIX_MAX - 1)
};

#define TCM_IFINDEX_MAGIC_BLOCK (0xFFFFFFFFU)

enum
{
	linux_TCA_UNSPEC,
	linux_TCA_KIND,
	linux_TCA_OPTIONS,
	linux_TCA_STATS,
	linux_TCA_XSTATS,
	linux_TCA_RATE,
	linux_TCA_FCNT,
	linux_TCA_STATS2,
	linux_TCA_STAB,
	linux_TCA_PAD,
	linux_TCA_DUMP_INVISIBLE,
	linux_TCA_CHAIN,
	linux_TCA_HW_OFFLOAD,
	linux_TCA_INGRESS_BLOCK,
	linux_TCA_EGRESS_BLOCK,
	linux__TCA_MAX,
#define linux_TCA_MAX (linux__TCA_MAX - 1)
};

#define linux_TCA_RTA(r)     ((struct linux_rtattr*)(((char*)(r)) + linux_NLMSG_ALIGN(sizeof(struct linux_tcmsg))))
#define linux_TCA_PAYLOAD(n) linux_NLMSG_PAYLOAD(n, sizeof(struct linux_tcmsg))

enum
{
	linux_NDUSEROPT_UNSPEC,
	linux_NDUSEROPT_SRCADDR,
	linux__NDUSEROPT_MAX,
#define linux_NDUSEROPT_MAX (linux__NDUSEROPT_MAX - 1)
};

#define linux_RTMGRP_LINK          0x00001
#define linux_RTMGRP_NOTIFY        0x00002
#define linux_RTMGRP_NEIGH         0x00004
#define linux_RTMGRP_TC            0x00008
#define linux_RTMGRP_IPV4_IFADDR   0x00010
#define linux_RTMGRP_IPV4_MROUTE   0x00020
#define linux_RTMGRP_IPV4_ROUTE    0x00040
#define linux_RTMGRP_IPV4_RULE     0x00080
#define linux_RTMGRP_IPV6_IFADDR   0x00100
#define linux_RTMGRP_IPV6_MROUTE   0x00200
#define linux_RTMGRP_IPV6_ROUTE    0x00400
#define linux_RTMGRP_IPV6_IFINFO   0x00800
#define linux_RTMGRP_DECnet_IFADDR 0x01000
#define linux_RTMGRP_DECnet_ROUTE  0x04000
#define linux_RTMGRP_IPV6_PREFIX   0x20000

enum linux_rtnetlink_groups
{
	linux_RTNLGRP_NONE,
	linux_RTNLGRP_LINK,
	linux_RTNLGRP_NOTIFY,
	linux_RTNLGRP_NEIGH,
	linux_RTNLGRP_TC,
	linux_RTNLGRP_IPV4_IFADDR,
	linux_RTNLGRP_IPV4_MROUTE,
	linux_RTNLGRP_IPV4_ROUTE,
	linux_RTNLGRP_IPV4_RULE,
	linux_RTNLGRP_IPV6_IFADDR,
	linux_RTNLGRP_IPV6_MROUTE,
	linux_RTNLGRP_IPV6_ROUTE,
	linux_RTNLGRP_IPV6_IFINFO,
	linux_RTNLGRP_DECnet_IFADDR,
	linux_RTNLGRP_NOP2,
	linux_RTNLGRP_DECnet_ROUTE,
	linux_RTNLGRP_DECnet_RULE,
	linux_RTNLGRP_NOP4,
	linux_RTNLGRP_IPV6_PREFIX,
	linux_RTNLGRP_IPV6_RULE,
	linux_RTNLGRP_ND_USEROPT,
	linux_RTNLGRP_PHONET_IFADDR,
	linux_RTNLGRP_PHONET_ROUTE,
	linux_RTNLGRP_DCB,
	linux_RTNLGRP_IPV4_NETCONF,
	linux_RTNLGRP_IPV6_NETCONF,
	linux_RTNLGRP_MDB,
	linux_RTNLGRP_MPLS_ROUTE,
	linux_RTNLGRP_NSID,
	linux_RTNLGRP_MPLS_NETCONF,
	linux_RTNLGRP_IPV4_MROUTE_R,
	linux_RTNLGRP_IPV6_MROUTE_R,
	linux_RTNLGRP_NEXTHOP,
	linux__RTNLGRP_MAX,
#define linux_RTNLGRP_MAX (linux__RTNLGRP_MAX - 1)
};

enum
{
	linux_TCA_ROOT_UNSPEC,
	linux_TCA_ROOT_TAB,
#define linux_TCA_ACT_TAB linux_TCA_ROOT_TAB
#define linux_TCAA_MAX    linux_TCA_ROOT_TAB
	linux_TCA_ROOT_FLAGS,
	linux_TCA_ROOT_COUNT,
	linux_TCA_ROOT_TIME_DELTA,
	linux__TCA_ROOT_MAX,
#define linux_TCA_ROOT_MAX (linux__TCA_ROOT_MAX - 1)
};

#define linux_TA_RTA(r)              ((struct linux_rtattr*)(((char*)(r)) + linux_NLMSG_ALIGN(sizeof(struct linux_tcamsg))))
#define linux_TA_PAYLOAD(n)          linux_NLMSG_PAYLOAD(n, sizeof(struct linux_tcamsg))
#define linux_TCA_FLAG_LARGE_DUMP_ON (1 << 0)

#define linux_RTEXT_FILTER_VF                (1 << 0)
#define linux_RTEXT_FILTER_BRVLAN            (1 << 1)
#define linux_RTEXT_FILTER_BRVLAN_COMPRESSED (1 << 2)
#define linux_RTEXT_FILTER_SKIP_STATS        (1 << 3)

//-----------------------------------------------------------------------------
// if_addr

enum
{
	linux_IFA_UNSPEC,
	linux_IFA_ADDRESS,
	linux_IFA_LOCAL,
	linux_IFA_LABEL,
	linux_IFA_BROADCAST,
	linux_IFA_ANYCAST,
	linux_IFA_CACHEINFO,
	linux_IFA_MULTICAST,
	linux_IFA_FLAGS,
	linux_IFA_RT_PRIORITY,
	linux_IFA_TARGET_NETNSID,
	linux__IFA_MAX,
#define linux_IFA_MAX (linux__IFA_MAX - 1)
};

#define linux_IFA_F_SECONDARY 0x01
#define linux_IFA_F_TEMPORARY linux_IFA_F_SECONDARY

#define linux_IFA_F_NODAD          0x002
#define linux_IFA_F_OPTIMISTIC     0x004
#define linux_IFA_F_DADFAILED      0x008
#define linux_IFA_F_HOMEADDRESS    0x010
#define linux_IFA_F_DEPRECATED     0x020
#define linux_IFA_F_TENTATIVE      0x040
#define linux_IFA_F_PERMANENT      0x080
#define linux_IFA_F_MANAGETEMPADDR 0x100
#define linux_IFA_F_NOPREFIXROUTE  0x200
#define linux_IFA_F_MCAUTOJOIN     0x400
#define linux_IFA_F_STABLE_PRIVACY 0x800

#define linux_IFA_RTA(r)     ((struct linux_rtattr*)(((char*)(r)) + linux_NLMSG_ALIGN(sizeof(struct linux_ifaddrmsg))))
#define linux_IFA_PAYLOAD(n) linux_NLMSG_PAYLOAD(n, sizeof(struct linux_ifaddrmsg))

//-----------------------------------------------------------------------------
// if_link

enum
{
	linux_IFLA_UNSPEC,
	linux_IFLA_ADDRESS,
	linux_IFLA_BROADCAST,
	linux_IFLA_IFNAME,
	linux_IFLA_MTU,
	linux_IFLA_LINK,
	linux_IFLA_QDISC,
	linux_IFLA_STATS,
	linux_IFLA_COST,
	linux_IFLA_PRIORITY,
	linux_IFLA_MASTER,
	linux_IFLA_WIRELESS,
	linux_IFLA_PROTINFO,
	linux_IFLA_TXQLEN,
	linux_IFLA_MAP,
	linux_IFLA_WEIGHT,
	linux_IFLA_OPERSTATE,
	linux_IFLA_LINKMODE,
	linux_IFLA_LINKINFO,
	linux_IFLA_NET_NS_PID,
	linux_IFLA_IFALIAS,
	linux_IFLA_NUM_VF,
	linux_IFLA_VFINFO_LIST,
	linux_IFLA_STATS64,
	linux_IFLA_VF_PORTS,
	linux_IFLA_PORT_SELF,
	linux_IFLA_AF_SPEC,
	linux_IFLA_GROUP,
	linux_IFLA_NET_NS_FD,
	linux_IFLA_EXT_MASK,
	linux_IFLA_PROMISCUITY,
	linux_IFLA_NUM_TX_QUEUES,
	linux_IFLA_NUM_RX_QUEUES,
	linux_IFLA_CARRIER,
	linux_IFLA_PHYS_PORT_ID,
	linux_IFLA_CARRIER_CHANGES,
	linux_IFLA_PHYS_SWITCH_ID,
	linux_IFLA_LINK_NETNSID,
	linux_IFLA_PHYS_PORT_NAME,
	linux_IFLA_PROTO_DOWN,
	linux_IFLA_GSO_MAX_SEGS,
	linux_IFLA_GSO_MAX_SIZE,
	linux_IFLA_PAD,
	linux_IFLA_XDP,
	linux_IFLA_EVENT,
	linux_IFLA_NEW_NETNSID,
	linux_IFLA_IF_NETNSID,
	linux_IFLA_TARGET_NETNSID     = linux_IFLA_IF_NETNSID,
	linux_IFLA_CARRIER_UP_COUNT,
	linux_IFLA_CARRIER_DOWN_COUNT,
	linux_IFLA_NEW_IFINDEX,
	linux_IFLA_MIN_MTU,
	linux_IFLA_MAX_MTU,
	linux_IFLA_PROP_LIST,
	linux_IFLA_ALT_IFNAME,
	linux__IFLA_MAX,
#define linux_IFLA_MAX (linux__IFLA_MAX - 1)
};

#define linux_IFLA_RTA(r)     ((struct linux_rtattr*)(((char*)(r)) + linux_NLMSG_ALIGN(sizeof(struct linux_ifinfomsg))))
#define linux_IFLA_PAYLOAD(n) linux_NLMSG_PAYLOAD(n, sizeof(struct linux_ifinfomsg))

enum
{
	linux_IFLA_INET_UNSPEC,
	linux_IFLA_INET_CONF,
	linux__IFLA_INET_MAX,
#define linux_IFLA_INET_MAX (linux__IFLA_INET_MAX - 1)
};

enum
{
	linux_IFLA_INET6_UNSPEC,
	linux_IFLA_INET6_FLAGS,
	linux_IFLA_INET6_CONF,
	linux_IFLA_INET6_STATS,
	linux_IFLA_INET6_MCAST,
	linux_IFLA_INET6_CACHEINFO,
	linux_IFLA_INET6_ICMP6STATS,
	linux_IFLA_INET6_TOKEN,
	linux_IFLA_INET6_ADDR_GEN_MODE,
	linux__IFLA_INET6_MAX,
#define linux_IFLA_INET6_MAX (linux__IFLA_INET6_MAX - 1)
};

enum linux_in6_addr_gen_mode
{
	linux_IN6_ADDR_GEN_MODE_EUI64,
	linux_IN6_ADDR_GEN_MODE_NONE,
	linux_IN6_ADDR_GEN_MODE_STABLE_PRIVACY,
	linux_IN6_ADDR_GEN_MODE_RANDOM,
};

enum
{
	linux_IFLA_BR_UNSPEC,
	linux_IFLA_BR_FORWARD_DELAY,
	linux_IFLA_BR_HELLO_TIME,
	linux_IFLA_BR_MAX_AGE,
	linux_IFLA_BR_AGEING_TIME,
	linux_IFLA_BR_STP_STATE,
	linux_IFLA_BR_PRIORITY,
	linux_IFLA_BR_VLAN_FILTERING,
	linux_IFLA_BR_VLAN_PROTOCOL,
	linux_IFLA_BR_GROUP_FWD_MASK,
	linux_IFLA_BR_ROOT_ID,
	linux_IFLA_BR_BRIDGE_ID,
	linux_IFLA_BR_ROOT_PORT,
	linux_IFLA_BR_ROOT_PATH_COST,
	linux_IFLA_BR_TOPOLOGY_CHANGE,
	linux_IFLA_BR_TOPOLOGY_CHANGE_DETECTED,
	linux_IFLA_BR_HELLO_TIMER,
	linux_IFLA_BR_TCN_TIMER,
	linux_IFLA_BR_TOPOLOGY_CHANGE_TIMER,
	linux_IFLA_BR_GC_TIMER,
	linux_IFLA_BR_GROUP_ADDR,
	linux_IFLA_BR_FDB_FLUSH,
	linux_IFLA_BR_MCAST_ROUTER,
	linux_IFLA_BR_MCAST_SNOOPING,
	linux_IFLA_BR_MCAST_QUERY_USE_IFADDR,
	linux_IFLA_BR_MCAST_QUERIER,
	linux_IFLA_BR_MCAST_HASH_ELASTICITY,
	linux_IFLA_BR_MCAST_HASH_MAX,
	linux_IFLA_BR_MCAST_LAST_MEMBER_CNT,
	linux_IFLA_BR_MCAST_STARTUP_QUERY_CNT,
	linux_IFLA_BR_MCAST_LAST_MEMBER_INTVL,
	linux_IFLA_BR_MCAST_MEMBERSHIP_INTVL,
	linux_IFLA_BR_MCAST_QUERIER_INTVL,
	linux_IFLA_BR_MCAST_QUERY_INTVL,
	linux_IFLA_BR_MCAST_QUERY_RESPONSE_INTVL,
	linux_IFLA_BR_MCAST_STARTUP_QUERY_INTVL,
	linux_IFLA_BR_NF_CALL_IPTABLES,
	linux_IFLA_BR_NF_CALL_IP6TABLES,
	linux_IFLA_BR_NF_CALL_ARPTABLES,
	linux_IFLA_BR_VLAN_DEFAULT_PVID,
	linux_IFLA_BR_PAD,
	linux_IFLA_BR_VLAN_STATS_ENABLED,
	linux_IFLA_BR_MCAST_STATS_ENABLED,
	linux_IFLA_BR_MCAST_IGMP_VERSION,
	linux_IFLA_BR_MCAST_MLD_VERSION,
	linux_IFLA_BR_VLAN_STATS_PER_PORT,
	linux_IFLA_BR_MULTI_BOOLOPT,
	linux__IFLA_BR_MAX,
#define linux_IFLA_BR_MAX (linux__IFLA_BR_MAX - 1)
};

enum
{
	linux_BRIDGE_MODE_UNSPEC,
	linux_BRIDGE_MODE_HAIRPIN,
};

enum
{
	linux_IFLA_BRPORT_UNSPEC,
	linux_IFLA_BRPORT_STATE,
	linux_IFLA_BRPORT_PRIORITY,
	linux_IFLA_BRPORT_COST,
	linux_IFLA_BRPORT_MODE,
	linux_IFLA_BRPORT_GUARD,
	linux_IFLA_BRPORT_PROTECT,
	linux_IFLA_BRPORT_FAST_LEAVE,
	linux_IFLA_BRPORT_LEARNING,
	linux_IFLA_BRPORT_UNICAST_FLOOD,
	linux_IFLA_BRPORT_PROXYARP,
	linux_IFLA_BRPORT_LEARNING_SYNC,
	linux_IFLA_BRPORT_PROXYARP_WIFI,
	linux_IFLA_BRPORT_ROOT_ID,
	linux_IFLA_BRPORT_BRIDGE_ID,
	linux_IFLA_BRPORT_DESIGNATED_PORT,
	linux_IFLA_BRPORT_DESIGNATED_COST,
	linux_IFLA_BRPORT_ID,
	linux_IFLA_BRPORT_NO,
	linux_IFLA_BRPORT_TOPOLOGY_CHANGE_ACK,
	linux_IFLA_BRPORT_CONFIG_PENDING,
	linux_IFLA_BRPORT_MESSAGE_AGE_TIMER,
	linux_IFLA_BRPORT_FORWARD_DELAY_TIMER,
	linux_IFLA_BRPORT_HOLD_TIMER,
	linux_IFLA_BRPORT_FLUSH,
	linux_IFLA_BRPORT_MULTICAST_ROUTER,
	linux_IFLA_BRPORT_PAD,
	linux_IFLA_BRPORT_MCAST_FLOOD,
	linux_IFLA_BRPORT_MCAST_TO_UCAST,
	linux_IFLA_BRPORT_VLAN_TUNNEL,
	linux_IFLA_BRPORT_BCAST_FLOOD,
	linux_IFLA_BRPORT_GROUP_FWD_MASK,
	linux_IFLA_BRPORT_NEIGH_SUPPRESS,
	linux_IFLA_BRPORT_ISOLATED,
	linux_IFLA_BRPORT_BACKUP_PORT,
	linux__IFLA_BRPORT_MAX,
#define linux_IFLA_BRPORT_MAX (linux__IFLA_BRPORT_MAX - 1)
};

enum
{
	linux_IFLA_INFO_UNSPEC,
	linux_IFLA_INFO_KIND,
	linux_IFLA_INFO_DATA,
	linux_IFLA_INFO_XSTATS,
	linux_IFLA_INFO_SLAVE_KIND,
	linux_IFLA_INFO_SLAVE_DATA,
	linux__IFLA_INFO_MAX,
#define linux_IFLA_INFO_MAX (linux__IFLA_INFO_MAX - 1)
};

enum
{
	linux_IFLA_VLAN_UNSPEC,
	linux_IFLA_VLAN_ID,
	linux_IFLA_VLAN_FLAGS,
	linux_IFLA_VLAN_EGRESS_QOS,
	linux_IFLA_VLAN_INGRESS_QOS,
	linux_IFLA_VLAN_PROTOCOL,
	linux__IFLA_VLAN_MAX,
#define linux_IFLA_VLAN_MAX (linux__IFLA_VLAN_MAX - 1)
};

enum
{
	linux_IFLA_VLAN_QOS_UNSPEC,
	linux_IFLA_VLAN_QOS_MAPPING,
	linux__IFLA_VLAN_QOS_MAX,
#define linux_IFLA_VLAN_QOS_MAX (linux__IFLA_VLAN_QOS_MAX - 1)
};

enum
{
	linux_IFLA_MACVLAN_UNSPEC,
	linux_IFLA_MACVLAN_MODE,
	linux_IFLA_MACVLAN_FLAGS,
	linux_IFLA_MACVLAN_MACADDR_MODE,
	linux_IFLA_MACVLAN_MACADDR,
	linux_IFLA_MACVLAN_MACADDR_DATA,
	linux_IFLA_MACVLAN_MACADDR_COUNT,
	linux__IFLA_MACVLAN_MAX,
#define linux_IFLA_MACVLAN_MAX (linux__IFLA_MACVLAN_MAX - 1)
};

enum linux_macvlan_mode
{
	linux_MACVLAN_MODE_PRIVATE  =  1,
	linux_MACVLAN_MODE_VEPA     =  2,
	linux_MACVLAN_MODE_BRIDGE   =  4,
	linux_MACVLAN_MODE_PASSTHRU =  8,
	linux_MACVLAN_MODE_SOURCE   = 16,
};

enum linux_macvlan_macaddr_mode
{
	linux_MACVLAN_MACADDR_ADD,
	linux_MACVLAN_MACADDR_DEL,
	linux_MACVLAN_MACADDR_FLUSH,
	linux_MACVLAN_MACADDR_SET,
};

#define linux_MACVLAN_FLAG_NOPROMISC 1

enum
{
	linux_IFLA_VRF_UNSPEC,
	linux_IFLA_VRF_TABLE,
	linux__IFLA_VRF_MAX,
#define linux_IFLA_VRF_MAX (linux__IFLA_VRF_MAX - 1)
};

enum
{
	linux_IFLA_VRF_PORT_UNSPEC,
	linux_IFLA_VRF_PORT_TABLE,
	linux__IFLA_VRF_PORT_MAX,
#define linux_IFLA_VRF_PORT_MAX (linux__IFLA_VRF_PORT_MAX - 1)
};

enum
{
	linux_IFLA_MACSEC_UNSPEC,
	linux_IFLA_MACSEC_SCI,
	linux_IFLA_MACSEC_PORT,
	linux_IFLA_MACSEC_ICV_LEN,
	linux_IFLA_MACSEC_CIPHER_SUITE,
	linux_IFLA_MACSEC_WINDOW,
	linux_IFLA_MACSEC_ENCODING_SA,
	linux_IFLA_MACSEC_ENCRYPT,
	linux_IFLA_MACSEC_PROTECT,
	linux_IFLA_MACSEC_INC_SCI,
	linux_IFLA_MACSEC_ES,
	linux_IFLA_MACSEC_SCB,
	linux_IFLA_MACSEC_REPLAY_PROTECT,
	linux_IFLA_MACSEC_VALIDATION,
	linux_IFLA_MACSEC_PAD,
	linux__IFLA_MACSEC_MAX,
#define linux_IFLA_MACSEC_MAX (linux__IFLA_MACSEC_MAX - 1)
};

enum
{
	linux_IFLA_XFRM_UNSPEC,
	linux_IFLA_XFRM_LINK,
	linux_IFLA_XFRM_IF_ID,
	linux__IFLA_XFRM_MAX,
#define linux_IFLA_XFRM_MAX (linux__IFLA_XFRM_MAX - 1)
};

enum linux_macsec_validation_type
{
	linux_MACSEC_VALIDATE_DISABLED = 0,
	linux_MACSEC_VALIDATE_CHECK    = 1,
	linux_MACSEC_VALIDATE_STRICT   = 2,
	linux__MACSEC_VALIDATE_END,
	linux_MACSEC_VALIDATE_MAX      = linux__MACSEC_VALIDATE_END - 1,
};

enum
{
	linux_IFLA_IPVLAN_UNSPEC,
	linux_IFLA_IPVLAN_MODE,
	linux_IFLA_IPVLAN_FLAGS,
	linux__IFLA_IPVLAN_MAX,
#define linux_IFLA_IPVLAN_MAX (linux__IFLA_IPVLAN_MAX - 1)
};

enum linux_ipvlan_mode
{
	linux_IPVLAN_MODE_L2  = 0,
	linux_IPVLAN_MODE_L3,
	linux_IPVLAN_MODE_L3S,
	linux_IPVLAN_MODE_MAX,
};

#define linux_IPVLAN_F_PRIVATE 0x01
#define linux_IPVLAN_F_VEPA    0x02

enum
{
	linux_IFLA_VXLAN_UNSPEC,
	linux_IFLA_VXLAN_ID,
	linux_IFLA_VXLAN_GROUP,
	linux_IFLA_VXLAN_LINK,
	linux_IFLA_VXLAN_LOCAL,
	linux_IFLA_VXLAN_TTL,
	linux_IFLA_VXLAN_TOS,
	linux_IFLA_VXLAN_LEARNING,
	linux_IFLA_VXLAN_AGEING,
	linux_IFLA_VXLAN_LIMIT,
	linux_IFLA_VXLAN_PORT_RANGE,
	linux_IFLA_VXLAN_PROXY,
	linux_IFLA_VXLAN_RSC,
	linux_IFLA_VXLAN_L2MISS,
	linux_IFLA_VXLAN_L3MISS,
	linux_IFLA_VXLAN_PORT,
	linux_IFLA_VXLAN_GROUP6,
	linux_IFLA_VXLAN_LOCAL6,
	linux_IFLA_VXLAN_UDP_CSUM,
	linux_IFLA_VXLAN_UDP_ZERO_CSUM6_TX,
	linux_IFLA_VXLAN_UDP_ZERO_CSUM6_RX,
	linux_IFLA_VXLAN_REMCSUM_TX,
	linux_IFLA_VXLAN_REMCSUM_RX,
	linux_IFLA_VXLAN_GBP,
	linux_IFLA_VXLAN_REMCSUM_NOPARTIAL,
	linux_IFLA_VXLAN_COLLECT_METADATA,
	linux_IFLA_VXLAN_LABEL,
	linux_IFLA_VXLAN_GPE,
	linux_IFLA_VXLAN_TTL_INHERIT,
	linux_IFLA_VXLAN_DF,
	linux__IFLA_VXLAN_MAX
#define linux_IFLA_VXLAN_MAX (linux__IFLA_VXLAN_MAX - 1)
};

enum linux_ifla_vxlan_df
{
	linux_VXLAN_DF_UNSET    = 0,
	linux_VXLAN_DF_SET,
	linux_VXLAN_DF_INHERIT,
	linux__VXLAN_DF_END,
	linux_VXLAN_DF_MAX      = linux__VXLAN_DF_END - 1,
};

enum
{
	linux_IFLA_GENEVE_UNSPEC,
	linux_IFLA_GENEVE_ID,
	linux_IFLA_GENEVE_REMOTE,
	linux_IFLA_GENEVE_TTL,
	linux_IFLA_GENEVE_TOS,
	linux_IFLA_GENEVE_PORT,
	linux_IFLA_GENEVE_COLLECT_METADATA,
	linux_IFLA_GENEVE_REMOTE6,
	linux_IFLA_GENEVE_UDP_CSUM,
	linux_IFLA_GENEVE_UDP_ZERO_CSUM6_TX,
	linux_IFLA_GENEVE_UDP_ZERO_CSUM6_RX,
	linux_IFLA_GENEVE_LABEL,
	linux_IFLA_GENEVE_TTL_INHERIT,
	linux_IFLA_GENEVE_DF,
	linux__IFLA_GENEVE_MAX,
#define linux_IFLA_GENEVE_MAX (linux__IFLA_GENEVE_MAX - 1)
};

enum linux_ifla_geneve_df
{
	linux_GENEVE_DF_UNSET    = 0,
	linux_GENEVE_DF_SET,
	linux_GENEVE_DF_INHERIT,
	linux__GENEVE_DF_END,
	linux_GENEVE_DF_MAX      = linux__GENEVE_DF_END - 1,
};

enum
{
	linux_IFLA_PPP_UNSPEC,
	linux_IFLA_PPP_DEV_FD,
	linux__IFLA_PPP_MAX,
#define linux_IFLA_PPP_MAX (linux__IFLA_PPP_MAX - 1)
};

enum linux_ifla_gtp_role
{
	linux_GTP_ROLE_GGSN = 0,
	linux_GTP_ROLE_SGSN,
};

enum
{
	linux_IFLA_GTP_UNSPEC,
	linux_IFLA_GTP_FD0,
	linux_IFLA_GTP_FD1,
	linux_IFLA_GTP_PDP_HASHSIZE,
	linux_IFLA_GTP_ROLE,
	linux__IFLA_GTP_MAX,
#define linux_IFLA_GTP_MAX (linux__IFLA_GTP_MAX - 1)
};

enum
{
	linux_IFLA_BOND_UNSPEC,
	linux_IFLA_BOND_MODE,
	linux_IFLA_BOND_ACTIVE_SLAVE,
	linux_IFLA_BOND_MIIMON,
	linux_IFLA_BOND_UPDELAY,
	linux_IFLA_BOND_DOWNDELAY,
	linux_IFLA_BOND_USE_CARRIER,
	linux_IFLA_BOND_ARP_INTERVAL,
	linux_IFLA_BOND_ARP_IP_TARGET,
	linux_IFLA_BOND_ARP_VALIDATE,
	linux_IFLA_BOND_ARP_ALL_TARGETS,
	linux_IFLA_BOND_PRIMARY,
	linux_IFLA_BOND_PRIMARY_RESELECT,
	linux_IFLA_BOND_FAIL_OVER_MAC,
	linux_IFLA_BOND_XMIT_HASH_POLICY,
	linux_IFLA_BOND_RESEND_IGMP,
	linux_IFLA_BOND_NUM_PEER_NOTIF,
	linux_IFLA_BOND_ALL_SLAVES_ACTIVE,
	linux_IFLA_BOND_MIN_LINKS,
	linux_IFLA_BOND_LP_INTERVAL,
	linux_IFLA_BOND_PACKETS_PER_SLAVE,
	linux_IFLA_BOND_AD_LACP_RATE,
	linux_IFLA_BOND_AD_SELECT,
	linux_IFLA_BOND_AD_INFO,
	linux_IFLA_BOND_AD_ACTOR_SYS_PRIO,
	linux_IFLA_BOND_AD_USER_PORT_KEY,
	linux_IFLA_BOND_AD_ACTOR_SYSTEM,
	linux_IFLA_BOND_TLB_DYNAMIC_LB,
	linux_IFLA_BOND_PEER_NOTIF_DELAY,
	linux__IFLA_BOND_MAX,
#define linux_IFLA_BOND_MAX (linux__IFLA_BOND_MAX - 1)
};

enum
{
	linux_IFLA_BOND_AD_INFO_UNSPEC,
	linux_IFLA_BOND_AD_INFO_AGGREGATOR,
	linux_IFLA_BOND_AD_INFO_NUM_PORTS,
	linux_IFLA_BOND_AD_INFO_ACTOR_KEY,
	linux_IFLA_BOND_AD_INFO_PARTNER_KEY,
	linux_IFLA_BOND_AD_INFO_PARTNER_MAC,
	linux__IFLA_BOND_AD_INFO_MAX,
#define linux_IFLA_BOND_AD_INFO_MAX (linux__IFLA_BOND_AD_INFO_MAX - 1)
};

enum
{
	linux_IFLA_BOND_SLAVE_UNSPEC,
	linux_IFLA_BOND_SLAVE_STATE,
	linux_IFLA_BOND_SLAVE_MII_STATUS,
	linux_IFLA_BOND_SLAVE_LINK_FAILURE_COUNT,
	linux_IFLA_BOND_SLAVE_PERM_HWADDR,
	linux_IFLA_BOND_SLAVE_QUEUE_ID,
	linux_IFLA_BOND_SLAVE_AD_AGGREGATOR_ID,
	linux_IFLA_BOND_SLAVE_AD_ACTOR_OPER_PORT_STATE,
	linux_IFLA_BOND_SLAVE_AD_PARTNER_OPER_PORT_STATE,
	linux__IFLA_BOND_SLAVE_MAX,
#define linux_IFLA_BOND_SLAVE_MAX (linux__IFLA_BOND_SLAVE_MAX - 1)
};

enum
{
	linux_IFLA_VF_INFO_UNSPEC,
	linux_IFLA_VF_INFO,
	linux__IFLA_VF_INFO_MAX,
#define linux_IFLA_VF_INFO_MAX (linux__IFLA_VF_INFO_MAX - 1)
};

enum
{
	linux_IFLA_VF_UNSPEC,
	linux_IFLA_VF_MAC,
	linux_IFLA_VF_VLAN,
	linux_IFLA_VF_TX_RATE,
	linux_IFLA_VF_SPOOFCHK,
	linux_IFLA_VF_LINK_STATE,
	linux_IFLA_VF_RATE,
	linux_IFLA_VF_RSS_QUERY_EN,
	linux_IFLA_VF_STATS,
	linux_IFLA_VF_TRUST,
	linux_IFLA_VF_IB_NODE_GUID,
	linux_IFLA_VF_IB_PORT_GUID,
	linux_IFLA_VF_VLAN_LIST,
	linux_IFLA_VF_BROADCAST,
	linux__IFLA_VF_MAX,
#define linux_IFLA_VF_MAX (linux__IFLA_VF_MAX - 1)
};

enum
{
	linux_IFLA_VF_VLAN_INFO_UNSPEC,
	linux_IFLA_VF_VLAN_INFO,
	linux__IFLA_VF_VLAN_INFO_MAX,
#define linux_IFLA_VF_VLAN_INFO_MAX (linux__IFLA_VF_VLAN_INFO_MAX - 1)
};

#define linux_MAX_VLAN_LIST_LEN 1

enum
{
	linux_IFLA_VF_LINK_STATE_AUTO,
	linux_IFLA_VF_LINK_STATE_ENABLE,
	linux_IFLA_VF_LINK_STATE_DISABLE,
	linux__IFLA_VF_LINK_STATE_MAX,
};

enum
{
	linux_IFLA_VF_STATS_RX_PACKETS,
	linux_IFLA_VF_STATS_TX_PACKETS,
	linux_IFLA_VF_STATS_RX_BYTES,
	linux_IFLA_VF_STATS_TX_BYTES,
	linux_IFLA_VF_STATS_BROADCAST,
	linux_IFLA_VF_STATS_MULTICAST,
	linux_IFLA_VF_STATS_PAD,
	linux_IFLA_VF_STATS_RX_DROPPED,
	linux_IFLA_VF_STATS_TX_DROPPED,
	linux__IFLA_VF_STATS_MAX,
#define linux_IFLA_VF_STATS_MAX (linux__IFLA_VF_STATS_MAX - 1)
};

enum
{
	linux_IFLA_VF_PORT_UNSPEC,
	linux_IFLA_VF_PORT,
	linux__IFLA_VF_PORT_MAX,
#define linux_IFLA_VF_PORT_MAX (linux__IFLA_VF_PORT_MAX - 1)
};

enum
{
	linux_IFLA_PORT_UNSPEC,
	linux_IFLA_PORT_VF,
	linux_IFLA_PORT_PROFILE,
	linux_IFLA_PORT_VSI_TYPE,
	linux_IFLA_PORT_INSTANCE_UUID,
	linux_IFLA_PORT_HOST_UUID,
	linux_IFLA_PORT_REQUEST,
	linux_IFLA_PORT_RESPONSE,
	linux__IFLA_PORT_MAX,
#define linux_IFLA_PORT_MAX (linux__IFLA_PORT_MAX - 1)
};

#define linux_PORT_PROFILE_MAX 40
#define linux_PORT_UUID_MAX    16
#define linux_PORT_SELF_VF     -1

enum
{
	linux_PORT_REQUEST_PREASSOCIATE    = 0,
	linux_PORT_REQUEST_PREASSOCIATE_RR,
	linux_PORT_REQUEST_ASSOCIATE,
	linux_PORT_REQUEST_DISASSOCIATE,
};

enum
{
	linux_PORT_VDP_RESPONSE_SUCCESS                    = 0,
	linux_PORT_VDP_RESPONSE_INVALID_FORMAT,
	linux_PORT_VDP_RESPONSE_INSUFFICIENT_RESOURCES,
	linux_PORT_VDP_RESPONSE_UNUSED_VTID,
	linux_PORT_VDP_RESPONSE_VTID_VIOLATION,
	linux_PORT_VDP_RESPONSE_VTID_VERSION_VIOALTION,
	linux_PORT_VDP_RESPONSE_OUT_OF_SYNC,
	linux_PORT_PROFILE_RESPONSE_SUCCESS                = 0x100,
	linux_PORT_PROFILE_RESPONSE_INPROGRESS,
	linux_PORT_PROFILE_RESPONSE_INVALID,
	linux_PORT_PROFILE_RESPONSE_BADSTATE,
	linux_PORT_PROFILE_RESPONSE_INSUFFICIENT_RESOURCES,
	linux_PORT_PROFILE_RESPONSE_ERROR,
};

enum
{
	linux_IFLA_IPOIB_UNSPEC,
	linux_IFLA_IPOIB_PKEY,
	linux_IFLA_IPOIB_MODE,
	linux_IFLA_IPOIB_UMCAST,
	linux__IFLA_IPOIB_MAX,
#define linux_IFLA_IPOIB_MAX (linux__IFLA_IPOIB_MAX - 1)
};

enum
{
	linux_IPOIB_MODE_DATAGRAM  = 0,
	linux_IPOIB_MODE_CONNECTED = 1,
};

enum
{
	linux_IFLA_HSR_UNSPEC,
	linux_IFLA_HSR_SLAVE1,
	linux_IFLA_HSR_SLAVE2,
	linux_IFLA_HSR_MULTICAST_SPEC,
	linux_IFLA_HSR_SUPERVISION_ADDR,
	linux_IFLA_HSR_SEQ_NR,
	linux_IFLA_HSR_VERSION,
	linux__IFLA_HSR_MAX,
#define linux_IFLA_HSR_MAX (linux__IFLA_HSR_MAX - 1)
};

enum
{
	linux_IFLA_STATS_UNSPEC,
	linux_IFLA_STATS_LINK_64,
	linux_IFLA_STATS_LINK_XSTATS,
	linux_IFLA_STATS_LINK_XSTATS_SLAVE,
	linux_IFLA_STATS_LINK_OFFLOAD_XSTATS,
	linux_IFLA_STATS_AF_SPEC,
	linux__IFLA_STATS_MAX,
#define linux_IFLA_STATS_MAX (linux__IFLA_STATS_MAX - 1)
};

#define linux_IFLA_STATS_FILTER_BIT(attr) (1 << (attr - 1))

enum
{
	linux_LINK_XSTATS_TYPE_UNSPEC,
	linux_LINK_XSTATS_TYPE_BRIDGE,
	linux_LINK_XSTATS_TYPE_BOND,
	linux__LINK_XSTATS_TYPE_MAX,
#define linux_LINK_XSTATS_TYPE_MAX (linux__LINK_XSTATS_TYPE_MAX - 1)
};

enum
{
	linux_IFLA_OFFLOAD_XSTATS_UNSPEC,
	linux_IFLA_OFFLOAD_XSTATS_CPU_HIT,
	linux__IFLA_OFFLOAD_XSTATS_MAX,
#define linux_IFLA_OFFLOAD_XSTATS_MAX (linux__IFLA_OFFLOAD_XSTATS_MAX - 1)
};

#define linux_XDP_FLAGS_UPDATE_IF_NOEXIST (1U << 0)
#define linux_XDP_FLAGS_SKB_MODE          (1U << 1)
#define linux_XDP_FLAGS_DRV_MODE          (1U << 2)
#define linux_XDP_FLAGS_HW_MODE           (1U << 3)
#define linux_XDP_FLAGS_MODES             (linux_XDP_FLAGS_SKB_MODE | linux_XDP_FLAGS_DRV_MODE | linux_XDP_FLAGS_HW_MODE)
#define linux_XDP_FLAGS_MASK              (linux_XDP_FLAGS_UPDATE_IF_NOEXIST | linux_XDP_FLAGS_MODES)

enum
{
	linux_XDP_ATTACHED_NONE = 0,
	linux_XDP_ATTACHED_DRV,
	linux_XDP_ATTACHED_SKB,
	linux_XDP_ATTACHED_HW,
	linux_XDP_ATTACHED_MULTI,
};

enum
{
	linux_IFLA_XDP_UNSPEC,
	linux_IFLA_XDP_FD,
	linux_IFLA_XDP_ATTACHED,
	linux_IFLA_XDP_FLAGS,
	linux_IFLA_XDP_PROG_ID,
	linux_IFLA_XDP_DRV_PROG_ID,
	linux_IFLA_XDP_SKB_PROG_ID,
	linux_IFLA_XDP_HW_PROG_ID,
	linux__IFLA_XDP_MAX,
#define linux_IFLA_XDP_MAX (linux__IFLA_XDP_MAX - 1)
};

enum
{
	linux_IFLA_EVENT_NONE,
	linux_IFLA_EVENT_REBOOT,
	linux_IFLA_EVENT_FEATURES,
	linux_IFLA_EVENT_BONDING_FAILOVER,
	linux_IFLA_EVENT_NOTIFY_PEERS,
	linux_IFLA_EVENT_IGMP_RESEND,
	linux_IFLA_EVENT_BONDING_OPTIONS,
};

enum
{
	linux_IFLA_TUN_UNSPEC,
	linux_IFLA_TUN_OWNER,
	linux_IFLA_TUN_GROUP,
	linux_IFLA_TUN_TYPE,
	linux_IFLA_TUN_PI,
	linux_IFLA_TUN_VNET_HDR,
	linux_IFLA_TUN_PERSIST,
	linux_IFLA_TUN_MULTI_QUEUE,
	linux_IFLA_TUN_NUM_QUEUES,
	linux_IFLA_TUN_NUM_DISABLED_QUEUES,
	linux__IFLA_TUN_MAX,
#define linux_IFLA_TUN_MAX (linux__IFLA_TUN_MAX - 1)
};

#define linux_RMNET_FLAGS_INGRESS_DEAGGREGATION (1U << 0)
#define linux_RMNET_FLAGS_INGRESS_MAP_COMMANDS  (1U << 1)
#define linux_RMNET_FLAGS_INGRESS_MAP_CKSUMV4   (1U << 2)
#define linux_RMNET_FLAGS_EGRESS_MAP_CKSUMV4    (1U << 3)

enum
{
	linux_IFLA_RMNET_UNSPEC,
	linux_IFLA_RMNET_MUX_ID,
	linux_IFLA_RMNET_FLAGS,
	linux__IFLA_RMNET_MAX,
#define linux_IFLA_RMNET_MAX (linux__IFLA_RMNET_MAX - 1)
};

//-----------------------------------------------------------------------------
// Reliable datagram sockets

#define linux_RDS_IB_ABI_VERSION 0x301

#define linux_RDS_CANCEL_SENT_TO         1
#define linux_RDS_GET_MR                 2
#define linux_RDS_FREE_MR                3
//#define linux_RDS_BARRIER              4
#define linux_RDS_RECVERR                5
#define linux_RDS_CONG_MONITOR           6
#define linux_RDS_GET_MR_FOR_DEST        7
#define linux_SO_RDS_TRANSPORT           8
#define linux_SO_RDS_MSG_RXPATH_LATENCY 10

#define linux_RDS_TRANS_IB    0
#define linux_RDS_TRANS_IWARP 1
#define linux_RDS_TRANS_TCP   2
#define linux_RDS_TRANS_COUNT 3
#define linux_RDS_TRANS_NONE  (~0)

#define linux_SIOCRDSSETTOS (linux_SIOCPROTOPRIVATE)
#define linux_SIOCRDSGETTOS (linux_SIOCPROTOPRIVATE + 1)

#define linux_RDS_CMSG_RDMA_ARGS           1
#define linux_RDS_CMSG_RDMA_DEST           2
#define linux_RDS_CMSG_RDMA_MAP            3
#define linux_RDS_CMSG_RDMA_STATUS         4
#define linux_RDS_CMSG_CONG_UPDATE         5
#define linux_RDS_CMSG_ATOMIC_FADD         6
#define linux_RDS_CMSG_ATOMIC_CSWP         7
#define linux_RDS_CMSG_MASKED_ATOMIC_FADD  8
#define linux_RDS_CMSG_MASKED_ATOMIC_CSWP  9
#define linux_RDS_CMSG_RXPATH_LATENCY     11
#define linux_RDS_CMSG_ZCOPY_COOKIE       12
#define linux_RDS_CMSG_ZCOPY_COMPLETION   13

#define linux_RDS_INFO_FIRST             10000
#define linux_RDS_INFO_COUNTERS          10000
#define linux_RDS_INFO_CONNECTIONS       10001
//#define linux_RDS_INFO_FLOWS           10002
#define linux_RDS_INFO_SEND_MESSAGES     10003
#define linux_RDS_INFO_RETRANS_MESSAGES  10004
#define linux_RDS_INFO_RECV_MESSAGES     10005
#define linux_RDS_INFO_SOCKETS           10006
#define linux_RDS_INFO_TCP_SOCKETS       10007
#define linux_RDS_INFO_IB_CONNECTIONS    10008
#define linux_RDS_INFO_CONNECTION_STATS  10009
#define linux_RDS_INFO_IWARP_CONNECTIONS 10010

#define linux_RDS6_INFO_CONNECTIONS      10011
#define linux_RDS6_INFO_SEND_MESSAGES    10012
#define linux_RDS6_INFO_RETRANS_MESSAGES 10013
#define linux_RDS6_INFO_RECV_MESSAGES    10014
#define linux_RDS6_INFO_SOCKETS          10015
#define linux_RDS6_INFO_TCP_SOCKETS      10016
#define linux_RDS6_INFO_IB_CONNECTIONS   10017

#define linux_RDS_INFO_LAST 10017

#define linux_RDS_INFO_CONNECTION_FLAG_SENDING    0x01
#define linux_RDS_INFO_CONNECTION_FLAG_CONNECTING 0x02
#define linux_RDS_INFO_CONNECTION_FLAG_CONNECTED  0x04

#define linux_TRANSNAMSIZ 16

#define linux_RDS_INFO_MESSAGE_FLAG_ACK      0x01
#define linux_RDS_INFO_MESSAGE_FLAG_FAST_ACK 0x02

#define linux_RDS_IB_GID_LEN 16

enum linux_rds_message_rxpath_latency
{
	linux_RDS_MSG_RX_HDR_TO_DGRAM_START = 0,
	linux_RDS_MSG_RX_DGRAM_REASSEMBLE,
	linux_RDS_MSG_RX_DGRAM_DELIVERED,
	linux_RDS_MSG_RX_DGRAM_TRACE_MAX
};

#define linux_RDS_CONG_MONITOR_SIZE       64
#define linux_RDS_CONG_MONITOR_BIT(port)  (((unsigned int) port) % linux_RDS_CONG_MONITOR_SIZE)
#define linux_RDS_CONG_MONITOR_MASK(port) (1ULL << linux_RDS_CONG_MONITOR_BIT(port))

#define linux_RDS_RDMA_SUCCESS      0
#define linux_RDS_RDMA_REMOTE_ERROR 1
#define linux_RDS_RDMA_CANCELED     2
#define linux_RDS_RDMA_DROPPED      3
#define linux_RDS_RDMA_OTHER_ERROR  4

#define linux_RDS_MAX_ZCOOKIES 8

#define linux_RDS_RDMA_READWRITE  0x0001
#define linux_RDS_RDMA_FENCE      0x0002
#define linux_RDS_RDMA_INVALIDATE 0x0004
#define linux_RDS_RDMA_USE_ONCE   0x0008
#define linux_RDS_RDMA_DONTWAIT   0x0010
#define linux_RDS_RDMA_NOTIFY_ME  0x0020
#define linux_RDS_RDMA_SILENT     0x0040

//-----------------------------------------------------------------------------
// VSOCK

#define linux_SO_VM_SOCKETS_BUFFER_SIZE     0
#define linux_SO_VM_SOCKETS_BUFFER_MIN_SIZE 1
#define linux_SO_VM_SOCKETS_BUFFER_MAX_SIZE 2
#define linux_SO_VM_SOCKETS_PEER_HOST_VM_ID 3
#define linux_SO_VM_SOCKETS_TRUSTED         5
#define linux_SO_VM_SOCKETS_CONNECT_TIMEOUT 6
#define linux_SO_VM_SOCKETS_NONBLOCK_TXRX   7

#define linux_VMADDR_CID_ANY        -1U
#define linux_VMADDR_PORT_ANY       -1U
#define linux_VMADDR_CID_HYPERVISOR  0
#define linux_VMADDR_CID_RESERVED    1
#define linux_VMADDR_CID_HOST        2

#define linux_VM_SOCKETS_INVALID_VERSION   -1U
#define linux_VM_SOCKETS_VERSION_EPOCH(_v) (((_v) & 0xFF000000) >> 24)
#define linux_VM_SOCKETS_VERSION_MAJOR(_v) (((_v) & 0x00FF0000) >> 16)
#define linux_VM_SOCKETS_VERSION_MINOR(_v) (((_v) & 0x0000FFFF))

//=============================================================================
// High-Level Data Link Control (HDLC)

#define linux_GENERIC_HDLC_VERSION 4

#define linux_CLOCK_DEFAULT  0
#define linux_CLOCK_EXT      1
#define linux_CLOCK_INT      2
#define linux_CLOCK_TXINT    3
#define linux_CLOCK_TXFROMRX 4

#define linux_ENCODING_DEFAULT    0
#define linux_ENCODING_NRZ        1
#define linux_ENCODING_NRZI       2
#define linux_ENCODING_FM_MARK    3
#define linux_ENCODING_FM_SPACE   4
#define linux_ENCODING_MANCHESTER 5

#define linux_PARITY_DEFAULT         0
#define linux_PARITY_NONE            1
#define linux_PARITY_CRC16_PR0       2
#define linux_PARITY_CRC16_PR1       3
#define linux_PARITY_CRC16_PR0_CCITT 4
#define linux_PARITY_CRC16_PR1_CCITT 5
#define linux_PARITY_CRC32_PR0_CCITT 6
#define linux_PARITY_CRC32_PR1_CCITT 7

#define linux_LMI_DEFAULT 0
#define linux_LMI_NONE    1
#define linux_LMI_ANSI    2
#define linux_LMI_CCITT   3
#define linux_LMI_CISCO   4

//=============================================================================
// Network devices

#define linux_IFNAMSIZ  16
#define linux_IFALIASZ 256

enum linux_net_device_flags
{
	linux_IFF_UP          = 1<<0,
	linux_IFF_BROADCAST   = 1<<1,
	linux_IFF_DEBUG       = 1<<2,
	linux_IFF_LOOPBACK    = 1<<3,
	linux_IFF_POINTOPOINT = 1<<4,
	linux_IFF_NOTRAILERS  = 1<<5,
	linux_IFF_RUNNING     = 1<<6,
	linux_IFF_NOARP       = 1<<7,
	linux_IFF_PROMISC     = 1<<8,
	linux_IFF_ALLMULTI    = 1<<9,
	linux_IFF_MASTER      = 1<<10,
	linux_IFF_SLAVE       = 1<<11,
	linux_IFF_MULTICAST   = 1<<12,
	linux_IFF_PORTSEL     = 1<<13,
	linux_IFF_AUTOMEDIA   = 1<<14,
	linux_IFF_DYNAMIC     = 1<<15,
	linux_IFF_LOWER_UP    = 1<<16,
	linux_IFF_DORMANT     = 1<<17,
	linux_IFF_ECHO        = 1<<18,
        linux_IFF_VOLATILE    = (linux_IFF_LOOPBACK    |
	                         linux_IFF_POINTOPOINT |
	                         linux_IFF_BROADCAST   |
	                         linux_IFF_ECHO        |
	                         linux_IFF_MASTER      |
	                         linux_IFF_SLAVE       |
	                         linux_IFF_RUNNING     |
	                         linux_IFF_LOWER_UP    |
	                         linux_IFF_DORMANT),
};

#define linux_IF_GET_IFACE 0x0001
#define linux_IF_GET_PROTO 0x0002

#define linux_IF_IFACE_V35         0x1000
#define linux_IF_IFACE_V24         0x1001
#define linux_IF_IFACE_X21         0x1002
#define linux_IF_IFACE_T1          0x1003
#define linux_IF_IFACE_E1          0x1004
#define linux_IF_IFACE_SYNC_SERIAL 0x1005
#define linux_IF_IFACE_X21D        0x1006

#define linux_IF_PROTO_HDLC           0x2000
#define linux_IF_PROTO_PPP            0x2001
#define linux_IF_PROTO_CISCO          0x2002
#define linux_IF_PROTO_FR             0x2003
#define linux_IF_PROTO_FR_ADD_PVC     0x2004
#define linux_IF_PROTO_FR_DEL_PVC     0x2005
#define linux_IF_PROTO_X25            0x2006
#define linux_IF_PROTO_HDLC_ETH       0x2007
#define linux_IF_PROTO_FR_ADD_ETH_PVC 0x2008
#define linux_IF_PROTO_FR_DEL_ETH_PVC 0x2009
#define linux_IF_PROTO_FR_PVC         0x200A
#define linux_IF_PROTO_FR_ETH_PVC     0x200B
#define linux_IF_PROTO_RAW            0x200C

enum
{
	linux_IF_OPER_UNKNOWN,
	linux_IF_OPER_NOTPRESENT,
	linux_IF_OPER_DOWN,
	linux_IF_OPER_LOWERLAYERDOWN,
	linux_IF_OPER_TESTING,
	linux_IF_OPER_DORMANT,
	linux_IF_OPER_UP,
};
enum
{
	linux_IF_LINK_MODE_DEFAULT,
	linux_IF_LINK_MODE_DORMANT,
};

#define linux_IFHWADDRLEN 6

enum linux_netdev_priv_flags
{
	linux_IFF_802_1Q_VLAN           = 1 <<  0,
	linux_IFF_EBRIDGE               = 1 <<  1,
	linux_IFF_BONDING               = 1 <<  2,
	linux_IFF_ISATAP                = 1 <<  3,
	linux_IFF_WAN_HDLC              = 1 <<  4,
	linux_IFF_XMIT_DST_RELEASE      = 1 <<  5,
	linux_IFF_DONT_BRIDGE           = 1 <<  6,
	linux_IFF_DISABLE_NETPOLL       = 1 <<  7,
	linux_IFF_MACVLAN_PORT          = 1 <<  8,
	linux_IFF_BRIDGE_PORT           = 1 <<  9,
	linux_IFF_OVS_DATAPATH          = 1 << 10,
	linux_IFF_TX_SKB_SHARING        = 1 << 11,
	linux_IFF_UNICAST_FLT           = 1 << 12,
	linux_IFF_TEAM_PORT             = 1 << 13,
	linux_IFF_SUPP_NOFCS            = 1 << 14,
	linux_IFF_LIVE_ADDR_CHANGE      = 1 << 15,
	linux_IFF_MACVLAN               = 1 << 16,
	linux_IFF_XMIT_DST_RELEASE_PERM = 1 << 17,
	linux_IFF_L3MDEV_MASTER         = 1 << 18,
	linux_IFF_NO_QUEUE              = 1 << 19,
	linux_IFF_OPENVSWITCH           = 1 << 20,
	linux_IFF_L3MDEV_SLAVE          = 1 << 21,
	linux_IFF_TEAM                  = 1 << 22,
	linux_IFF_RXFH_CONFIGURED       = 1 << 23,
	linux_IFF_PHONY_HEADROOM        = 1 << 24,
	linux_IFF_MACSEC                = 1 << 25,
	linux_IFF_NO_RX_HANDLER         = 1 << 26,
	linux_IFF_FAILOVER              = 1 << 27,
	linux_IFF_FAILOVER_SLAVE        = 1 << 28,
	linux_IFF_L3MDEV_RX_HANDLER     = 1 << 29,
	linux_IFF_LIVE_RENAME_OK        = 1 << 30,
};

//=============================================================================
// stat

#define linux_S_IFMT   00170000
#define linux_S_IFSOCK 00140000
#define linux_S_IFLNK  00120000
#define linux_S_IFREG  00100000
#define linux_S_IFBLK  00060000
#define linux_S_IFDIR  00040000
#define linux_S_IFCHR  00020000
#define linux_S_IFIFO  00010000
#define linux_S_ISUID  00004000
#define linux_S_ISGID  00002000
#define linux_S_ISVTX  00001000

#define linux_S_IRWXU 00700
#define linux_S_IRUSR 00400
#define linux_S_IWUSR 00200
#define linux_S_IXUSR 00100
#define linux_S_IRWXG 00070
#define linux_S_IRGRP 00040
#define linux_S_IWGRP 00020
#define linux_S_IXGRP 00010
#define linux_S_IRWXO 00007
#define linux_S_IROTH 00004
#define linux_S_IWOTH 00002
#define linux_S_IXOTH 00001

//=============================================================================
// statx

#define linux_STATX_TYPE        0x00000001U
#define linux_STATX_MODE        0x00000002U
#define linux_STATX_NLINK       0x00000004U
#define linux_STATX_UID         0x00000008U
#define linux_STATX_GID         0x00000010U
#define linux_STATX_ATIME       0x00000020U
#define linux_STATX_MTIME       0x00000040U
#define linux_STATX_CTIME       0x00000080U
#define linux_STATX_INO         0x00000100U
#define linux_STATX_SIZE        0x00000200U
#define linux_STATX_BLOCKS      0x00000400U
#define linux_STATX_BASIC_STATS 0x000007ffU
#define linux_STATX_BTIME       0x00000800U
#define linux_STATX_ALL         0x00000fffU
#define linux_STATX_RESERVED    0x80000000U

#define linux_STATX_ATTR_COMPRESSED 0x00000004
#define linux_STATX_ATTR_IMMUTABLE  0x00000010
#define linux_STATX_ATTR_APPEND     0x00000020
#define linux_STATX_ATTR_NODUMP     0x00000040
#define linux_STATX_ATTR_ENCRYPTED  0x00000800
#define linux_STATX_ATTR_AUTOMOUNT  0x00001000

//=============================================================================
// select

#define linux_FD_SETSIZE 1024

//=============================================================================
// poll

#define linux_POLLIN     0x0001
#define linux_POLLPRI    0x0002
#define linux_POLLOUT    0x0004
#define linux_POLLERR    0x0008
#define linux_POLLHUP    0x0010
#define linux_POLLNVAL   0x0020
#define linux_POLLRDNORM 0x0040
#define linux_POLLRDBAND 0x0080

#define linux_POLLFREE       (linux_poll_t)0x4000
#define linux_POLL_BUSY_LOOP (linux_poll_t)0x8000

//=============================================================================
// ioctl

#define linux_IOC_NRBITS   8
#define linux_IOC_TYPEBITS 8

#define linux_IOC_NRSHIFT   0
#define linux_IOC_TYPESHIFT (linux_IOC_NRSHIFT   + linux_IOC_NRBITS)
#define linux_IOC_SIZESHIFT (linux_IOC_TYPESHIFT + linux_IOC_TYPEBITS)

#define linux_TIOCPKT_DATA        0
#define linux_TIOCPKT_FLUSHREAD   1
#define linux_TIOCPKT_FLUSHWRITE  2
#define linux_TIOCPKT_STOP        4
#define linux_TIOCPKT_START       8
#define linux_TIOCPKT_NOSTOP     16
#define linux_TIOCPKT_DOSTOP     32
#define TIOCPlinux_KT_IOCTL      64

#define linux_TIOCSER_TEMT 0x01

//=============================================================================
// seccomp

#define linux_SECCOMP_MODE_DISABLED 0
#define linux_SECCOMP_MODE_STRICT   1
#define linux_SECCOMP_MODE_FILTER   2

#define linux_SECCOMP_SET_MODE_STRICT  0
#define linux_SECCOMP_SET_MODE_FILTER  1
#define linux_SECCOMP_GET_ACTION_AVAIL 2
#define linux_SECCOMP_GET_NOTIF_SIZES  3

#define linux_SECCOMP_FILTER_FLAG_TSYNC        (1UL << 0)
#define linux_SECCOMP_FILTER_FLAG_LOG          (1UL << 1)
#define linux_SECCOMP_FILTER_FLAG_SPEC_ALLOW   (1UL << 2)
#define linux_SECCOMP_FILTER_FLAG_NEW_LISTENER (1UL << 3)

#define linux_SECCOMP_RET_KILL_PROCESS 0x80000000U
#define linux_SECCOMP_RET_KILL_THREAD  0x00000000U
#define linux_SECCOMP_RET_KILL         linux_SECCOMP_RET_KILL_THREAD
#define linux_SECCOMP_RET_TRAP         0x00030000U
#define linux_SECCOMP_RET_ERRNO        0x00050000U
#define linux_SECCOMP_RET_USER_NOTIF   0x7fc00000U
#define linux_SECCOMP_RET_TRACE        0x7ff00000U
#define linux_SECCOMP_RET_LOG          0x7ffc0000U
#define linux_SECCOMP_RET_ALLOW        0x7fff0000U

#define linux_SECCOMP_RET_ACTION_FULL 0xffff0000U
#define linux_SECCOMP_RET_ACTION      0x7fff0000U
#define linux_SECCOMP_RET_DATA        0x0000ffffU

#define linux_SECCOMP_IOC_MAGIC      '!'
#define linux_SECCOMP_IO(nr)         linux_IO(linux_SECCOMP_IOC_MAGIC, nr)
#define linux_SECCOMP_IOR(nr, type)  linux_IOR(linux_SECCOMP_IOC_MAGIC, nr, type)
#define linux_SECCOMP_IOW(nr, type)  linux_IOW(linux_SECCOMP_IOC_MAGIC, nr, type)
#define linux_SECCOMP_IOWR(nr, type) linux_IOWR(linux_SECCOMP_IOC_MAGIC, nr, type)

#define linux_SECCOMP_IOCTL_NOTIF_RECV     linux_SECCOMP_IOWR(0, struct linux_seccomp_notif)
#define linux_SECCOMP_IOCTL_NOTIF_SEND     linux_SECCOMP_IOWR(1, struct linux_seccomp_notif_resp)
#define linux_SECCOMP_IOCTL_NOTIF_ID_VALID linux_SECCOMP_IOR(2, uint64_t)

//=============================================================================
// serial

#define linux_ASYNC_CLOSING_WAIT_INF      0
#define linux_ASYNC_CLOSING_WAIT_NONE 65535

#define linux_PORT_UNKNOWN           0
#define linux_PORT_8250              1
#define linux_PORT_16450             2
#define linux_PORT_16550             3
#define linux_PORT_16550A            4
#define linux_PORT_CIRRUS            5
#define linux_PORT_16650             6
#define linux_PORT_16650V2           7
#define linux_PORT_16750             8
#define linux_PORT_STARTECH          9
#define linux_PORT_16C950           10
#define linux_PORT_16654            11
#define linux_PORT_16850            12
#define linux_PORT_RSA              13
#define linux_PORT_NS16550A         14
#define linux_PORT_XSCALE           15
#define linux_PORT_RM9000           16
#define linux_PORT_OCTEON           17
#define linux_PORT_AR7              18
#define linux_PORT_U6_16550A        19
#define linux_PORT_TEGRA            20
#define linux_PORT_XR17D15X         21
#define linux_PORT_LPC3220          22
#define linux_PORT_8250_CIR         23
#define linux_PORT_XR17V35X         24
#define linux_PORT_BRCM_TRUMANAGE   25
#define linux_PORT_ALTR_16550_F32   26
#define linux_PORT_ALTR_16550_F64   27
#define linux_PORT_ALTR_16550_F128  28
#define linux_PORT_RT2880           29
#define linux_PORT_16550A_FSL64     30
#define linux_PORT_PXA              31
#define linux_PORT_AMBA             32
#define linux_PORT_CLPS711X         33
#define linux_PORT_SA1100           34
#define linux_PORT_UART00           35
#define linux_PORT_OWL              36
#define linux_PORT_21285            37
#define linux_PORT_SUNZILOG         38
#define linux_PORT_SUNSAB           39
#define linux_PORT_NPCM             40
#define linux_PORT_TEGRA_TCU        41
#define linux_PORT_PCH_8LINE        44
#define linux_PORT_PCH_2LINE        45
#define linux_PORT_DZ               46
#define linux_PORT_ZS               47
#define linux_PORT_MUX              48
#define linux_PORT_ATMEL            49
#define linux_PORT_MAC_ZILOG        50
#define linux_PORT_PMAC_ZILOG       51
#define linux_PORT_SCI              52
#define linux_PORT_SCIF             53
#define linux_PORT_IRDA             54
#define linux_PORT_S3C2410          55
#define linux_PORT_IP22ZILOG        56
#define linux_PORT_LH7A40X          57
#define linux_PORT_CPM              58
#define linux_PORT_MPC52xx          59
#define linux_PORT_ICOM             60
#define linux_PORT_S3C2440          61
#define linux_PORT_IMX              62
#define linux_PORT_MPSC             63
#define linux_PORT_TXX9             64
#define linux_PORT_VR41XX_SIU       65
#define linux_PORT_VR41XX_DSIU      66
#define linux_PORT_S3C2400          67
#define linux_PORT_M32R_SIO         68
#define linux_PORT_JSM              69
#define linux_PORT_PNX8XXX          70
#define linux_PORT_NETX             71
#define linux_PORT_SUNHV            72
#define linux_PORT_S3C2412          73
#define linux_PORT_UARTLITE         74
#define linux_PORT_BFIN             75
#define linux_PORT_KS8695           76
#define linux_PORT_SB1250_DUART     77
#define linux_PORT_MCF              78
#define linux_PORT_BFIN_SPORT       79
#define linux_PORT_MN10300          80
#define linux_PORT_MN10300_CTS      81
#define linux_PORT_SC26XX           82
#define linux_PORT_SCIFA            83
#define linux_PORT_S3C6400          84
#define linux_PORT_NWPSERIAL        85
#define linux_PORT_MAX3100          86
#define linux_PORT_TIMBUART         87
#define linux_PORT_MSM              88
#define linux_PORT_BCM63XX          89
#define linux_PORT_APBUART          90
#define linux_PORT_ALTERA_JTAGUART  91
#define linux_PORT_ALTERA_UART      92
#define linux_PORT_SCIFB            93
#define linux_PORT_MAX310X          94
#define linux_PORT_DA830            95
#define linux_PORT_OMAP             96
#define linux_PORT_VT8500           97
#define linux_PORT_XUARTPS          98
#define linux_PORT_AR933X           99
#define linux_PORT_EFMUART         100
#define linux_PORT_ARC             101
#define linux_PORT_RP2             102
#define linux_PORT_LPUART          103
#define linux_PORT_HSCIF           104
#define linux_PORT_ASC             105
#define linux_PORT_TILEGX          106
#define linux_PORT_MEN_Z135        107
#define linux_PORT_SC16IS7XX       108
#define linux_PORT_MESON           109
#define linux_PORT_DIGICOLOR       110
#define linux_PORT_SPRD            111
#define linux_PORT_CRIS            112
#define linux_PORT_STM32           113
#define linux_PORT_MVEBU           114
#define linux_PORT_PIC32           115
#define linux_PORT_MPS2UART        116
#define linux_PORT_MTK_BTIF        117
#define linux_PORT_RDA             118

#define linux_SERIAL_IO_PORT    0
#define linux_SERIAL_IO_HUB6    1
#define linux_SERIAL_IO_MEM     2
#define linux_SERIAL_IO_MEM32   3
#define linux_SERIAL_IO_AU      4
#define linux_SERIAL_IO_TSI     5
#define linux_SERIAL_IO_MEM32BE 6
#define linux_SERIAL_IO_MEM16   7

#define linux_UART_CLEAR_FIFO 0x01
#define linux_UART_USE_FIFO   0x02
#define linux_UART_STARTECH   0x04
#define linux_UART_NATSEMI    0x08

#define linux_SER_RS485_ENABLED        (1 << 0)
#define linux_SER_RS485_RTS_ON_SEND    (1 << 1)
#define linux_SER_RS485_RTS_AFTER_SEND (1 << 2)
#define linux_SER_RS485_RX_DURING_TX   (1 << 4)
#define linux_SER_RS485_TERMINATE_BUS  (1 << 5)

#define linux_SER_ISO7816_ENABLED (1 << 0)
#define linux_SER_ISO7816_T_PARAM (0x0f << 4)
#define linux_SER_ISO7816_T(t)    (((t) & 0x0f) << 4)

//=============================================================================
// tty

#define linux_NR_LDISCS 30

// line disciplines
#define linux_N_TTY           0
#define linux_N_SLIP          1
#define linux_N_MOUSE         2
#define linux_N_PPP           3
#define linux_N_STRIP         4
#define linux_N_AX25          5
#define linux_N_X25           6
#define linux_N_6PACK         7
#define linux_N_MASC          8
#define linux_N_R3964         9
#define linux_N_PROFIBUS_FDL 10
#define linux_N_IRDA         11
#define linux_N_SMSBLOCK     12
#define linux_N_HDLC         13
#define linux_N_SYNC_PPP     14
#define linux_N_HCI          15
#define linux_N_GIGASET_M101 16
#define linux_N_SLCAN        17
#define linux_N_PPS          18
#define linux_N_V253         19
#define linux_N_CAIF         20
#define linux_N_GSM0710      21
#define linux_N_TI_WL        22
#define linux_N_TRACESINK    23
#define linux_N_TRACEROUTER  24
#define linux_N_NCI          25
#define linux_N_SPEAKUP      26
#define linux_N_NULL         27

//=============================================================================
// termbits

#define linux_IBSHIFT 16

#define linux_TCOOFF 0
#define linux_TCOON  1
#define linux_TCIOFF 2
#define linux_TCION  3

#define linux_TCIFLUSH  0
#define linux_TCOFLUSH  1
#define linux_TCIOFLUSH 2

//=============================================================================
// epoll

#define linux_EPOLL_CLOEXEC linux_O_CLOEXEC

#define linux_EPOLL_CTL_ADD 1
#define linux_EPOLL_CTL_DEL 2
#define linux_EPOLL_CTL_MOD 3

#define linux_EPOLLIN     (linux_poll_t)0x00000001
#define linux_EPOLLPRI    (linux_poll_t)0x00000002
#define linux_EPOLLOUT    (linux_poll_t)0x00000004
#define linux_EPOLLERR    (linux_poll_t)0x00000008
#define linux_EPOLLHUP    (linux_poll_t)0x00000010
#define linux_EPOLLNVAL   (linux_poll_t)0x00000020
#define linux_EPOLLRDNORM (linux_poll_t)0x00000040
#define linux_EPOLLRDBAND (linux_poll_t)0x00000080
#define linux_EPOLLWRNORM (linux_poll_t)0x00000100
#define linux_EPOLLWRBAND (linux_poll_t)0x00000200
#define linux_EPOLLMSG    (linux_poll_t)0x00000400
#define linux_EPOLLRDHUP  (linux_poll_t)0x00002000

#define linux_EPOLLEXCLUSIVE ((linux_poll_t)(1U << 28))
#define linux_EPOLLWAKEUP    ((linux_poll_t)(1U << 29))
#define linux_EPOLLONESHOT   ((linux_poll_t)(1U << 30))
#define linux_EPOLLET        ((linux_poll_t)(1U << 31))

//=============================================================================
// timerfd

#define linux_TFD_TIMER_ABSTIME       (1 << 0)
#define linux_TFD_TIMER_CANCEL_ON_SET (1 << 1)

//=============================================================================
// VT ioctls

#define linux_MIN_NR_CONSOLES  1
#define linux_MAX_NR_CONSOLES 63

#define linux_VT_OPENQRY       0x5600
#define linux_VT_GETMODE       0x5601
#define linux_VT_SETMODE       0x5602
#define linux_VT_GETSTATE      0x5603
#define linux_VT_SENDSIG       0x5604
#define linux_VT_RELDISP       0x5605
#define linux_VT_ACTIVATE      0x5606
#define linux_VT_WAITACTIVE    0x5607
#define linux_VT_DISALLOCATE   0x5608
#define linux_VT_RESIZE        0x5609
#define linux_VT_RESIZEX       0x560A
#define linux_VT_LOCKSWITCH    0x560B
#define linux_VT_UNLOCKSWITCH  0x560C
#define linux_VT_GETHIFONTMASK 0x560D
#define linux_VT_WAITEVENT     0x560E
#define linux_VT_SETACTIVATE   0x560F

// linux_vt_mode::mode
#define linux_VT_AUTO    0x00
#define linux_VT_PROCESS 0x01
#define linux_VT_ACKACQ  0x02

// linux_vt_event::event
#define linux_VT_EVENT_SWITCH  0x0001
#define linux_VT_EVENT_BLANK   0x0002
#define linux_VT_EVENT_UNBLANK 0x0004
#define linux_VT_EVENT_RESIZE  0x0008
#define linux_VT_MAX_EVENT     0x000F

//=============================================================================
// KD ioctls

#define linux_GIO_FONT       0x4B60
#define linux_PIO_FONT       0x4B61
#define linux_GIO_FONTX      0x4B6B
#define linux_PIO_FONTX      0x4B6C
#define linux_PIO_FONTRESET  0x4B6D
#define linux_GIO_CMAP       0x4B70
#define linux_PIO_CMAP       0x4B71
#define linux_KIOCSOUND      0x4B2F
#define linux_KDMKTONE       0x4B30
#define linux_KDGETLED       0x4B31
#define linux_KDSETLED       0x4B32
#define linux_KDGKBTYPE      0x4B33
#define linux_KDADDIO        0x4B34
#define linux_KDDELIO        0x4B35
#define linux_KDENABIO       0x4B36
#define linux_KDDISABIO      0x4B37
#define linux_KDSETMODE      0x4B3A
#define linux_KDGETMODE      0x4B3B
#define linux_KDMAPDISP      0x4B3C
#define linux_KDUNMAPDISP    0x4B3D
#define linux_GIO_SCRNMAP    0x4B40
#define linux_PIO_SCRNMAP    0x4B41
#define linux_GIO_UNISCRNMAP 0x4B69
#define linux_PIO_UNISCRNMAP 0x4B6A
#define linux_GIO_UNIMAP     0x4B66
#define linux_PIO_UNIMAP     0x4B67
#define linux_PIO_UNIMAPCLR  0x4B68
#define linux_KDGKBMODE      0x4B44
#define linux_KDSKBMODE      0x4B45
#define linux_KDGKBMETA      0x4B62
#define linux_KDSKBMETA      0x4B63
#define linux_KDGKBLED       0x4B64
#define linux_KDSKBLED       0x4B65
#define linux_KDGKBENT       0x4B46
#define linux_KDSKBENT       0x4B47
#define linux_KDGKBSENT      0x4B48
#define linux_KDSKBSENT      0x4B49
#define linux_KDGKBDIACR     0x4B4A
#define linux_KDSKBDIACR     0x4B4B
#define linux_KDGKBDIACRUC   0x4BFA
#define linux_KDSKBDIACRUC   0x4BFB
#define linux_KDGETKEYCODE   0x4B4C
#define linux_KDSETKEYCODE   0x4B4D
#define linux_KDSIGACCEPT    0x4B4E
#define linux_KDKBDREP       0x4B52
#define linux_KDFONTOP       0x4B72

#define linux_KD_FONT_OP_SET         0
#define linux_KD_FONT_OP_GET         1
#define linux_KD_FONT_OP_SET_DEFAULT 2
#define linux_KD_FONT_OP_COPY        3

#define linux_KD_FONT_FLAG_DONT_RECALC 1

#define linux_LED_SCR 0x01
#define linux_LED_NUM 0x02
#define linux_LED_CAP 0x04

#define linux_KB_84    0x01
#define linux_KB_101   0x02
#define linux_KB_OTHER 0x03

#define linux_KD_TEXT     0x00
#define linux_KD_GRAPHICS 0x01
#define linux_KD_TEXT0    0x02
#define linux_KD_TEXT1    0x03

#define linux_E_TABSZ 256

#define linux_UNI_DIRECT_BASE 0xF000
#define linux_UNI_DIRECT_MASK 0x01FF

#define linux_K_RAW       0x00
#define linux_K_XLATE     0x01
#define linux_K_MEDIUMRAW 0x02
#define linux_K_UNICODE   0x03
#define linux_K_OFF       0x04

#define linux_K_METABIT   0x03
#define linux_K_ESCPREFIX 0x04

#define linux_K_SCROLLLOCK 0x01
#define linux_K_NUMLOCK    0x02
#define linux_K_CAPSLOCK   0x04

#define linux_K_NORMTAB     0x00
#define linux_K_SHIFTTAB    0x01
#define linux_K_ALTTAB      0x02
#define linux_K_ALTSHIFTTAB 0x03

//=============================================================================
// keyboard

#define linux_KG_SHIFT     0
#define linux_KG_CTRL      2
#define linux_KG_ALT       3
#define linux_KG_ALTGR     1
#define linux_KG_SHIFTL    4
#define linux_KG_KANASHIFT 4
#define linux_KG_SHIFTR    5
#define linux_KG_CTRLL     6
#define linux_KG_CTRLR     7
#define linux_KG_CAPSSHIFT 8

#define linux_NR_SHIFT     9

#define linux_NR_KEYS                256
#define linux_MAX_NR_KEYMAPS         256
#define linux_MAX_NR_OF_USER_KEYMAPS 256

#define linux_MAX_NR_FUNC 256

#define linux_KT_LATIN   0
#define linux_KT_LETTER 11
#define linux_KT_FN      1
#define linux_KT_SPEC    2
#define linux_KT_PAD     3
#define linux_KT_DEAD    4
#define linux_KT_CONS    5
#define linux_KT_CUR     6
#define linux_KT_SHIFT   7
#define linux_KT_META    8
#define linux_KT_ASCII   9
#define linux_KT_LOCK   10
#define linux_KT_SLOCK  12
#define linux_KT_DEAD2  13
#define linux_KT_BRL    14

#define linux_K(t,v)  (((t) << 8) | (v))
#define linux_KTYP(x) ((x) >> 8)
#define linux_KVAL(x) ((x) & 0xff)

#define linux_K_F1     linux_K(linux_KT_FN,   0)
#define linux_K_F2     linux_K(linux_KT_FN,   1)
#define linux_K_F3     linux_K(linux_KT_FN,   2)
#define linux_K_F4     linux_K(linux_KT_FN,   3)
#define linux_K_F5     linux_K(linux_KT_FN,   4)
#define linux_K_F6     linux_K(linux_KT_FN,   5)
#define linux_K_F7     linux_K(linux_KT_FN,   6)
#define linux_K_F8     linux_K(linux_KT_FN,   7)
#define linux_K_F9     linux_K(linux_KT_FN,   8)
#define linux_K_F10    linux_K(linux_KT_FN,   9)
#define linux_K_F11    linux_K(linux_KT_FN,  10)
#define linux_K_F12    linux_K(linux_KT_FN,  11)
#define linux_K_F13    linux_K(linux_KT_FN,  12)
#define linux_K_F14    linux_K(linux_KT_FN,  13)
#define linux_K_F15    linux_K(linux_KT_FN,  14)
#define linux_K_F16    linux_K(linux_KT_FN,  15)
#define linux_K_F17    linux_K(linux_KT_FN,  16)
#define linux_K_F18    linux_K(linux_KT_FN,  17)
#define linux_K_F19    linux_K(linux_KT_FN,  18)
#define linux_K_F20    linux_K(linux_KT_FN,  19)
#define linux_K_FIND   linux_K(linux_KT_FN,  20)
#define linux_K_INSERT linux_K(linux_KT_FN,  21)
#define linux_K_REMOVE linux_K(linux_KT_FN,  22)
#define linux_K_SELECT linux_K(linux_KT_FN,  23)
#define linux_K_PGUP   linux_K(linux_KT_FN,  24)
#define linux_K_PGDN   linux_K(linux_KT_FN,  25)
#define linux_K_MACRO  linux_K(linux_KT_FN,  26)
#define linux_K_HELP   linux_K(linux_KT_FN,  27)
#define linux_K_DO     linux_K(linux_KT_FN,  28)
#define linux_K_PAUSE  linux_K(linux_KT_FN,  29)
#define linux_K_F21    linux_K(linux_KT_FN,  30)
#define linux_K_F22    linux_K(linux_KT_FN,  31)
#define linux_K_F23    linux_K(linux_KT_FN,  32)
#define linux_K_F24    linux_K(linux_KT_FN,  33)
#define linux_K_F25    linux_K(linux_KT_FN,  34)
#define linux_K_F26    linux_K(linux_KT_FN,  35)
#define linux_K_F27    linux_K(linux_KT_FN,  36)
#define linux_K_F28    linux_K(linux_KT_FN,  37)
#define linux_K_F29    linux_K(linux_KT_FN,  38)
#define linux_K_F30    linux_K(linux_KT_FN,  39)
#define linux_K_F31    linux_K(linux_KT_FN,  40)
#define linux_K_F32    linux_K(linux_KT_FN,  41)
#define linux_K_F33    linux_K(linux_KT_FN,  42)
#define linux_K_F34    linux_K(linux_KT_FN,  43)
#define linux_K_F35    linux_K(linux_KT_FN,  44)
#define linux_K_F36    linux_K(linux_KT_FN,  45)
#define linux_K_F37    linux_K(linux_KT_FN,  46)
#define linux_K_F38    linux_K(linux_KT_FN,  47)
#define linux_K_F39    linux_K(linux_KT_FN,  48)
#define linux_K_F40    linux_K(linux_KT_FN,  49)
#define linux_K_F41    linux_K(linux_KT_FN,  50)
#define linux_K_F42    linux_K(linux_KT_FN,  51)
#define linux_K_F43    linux_K(linux_KT_FN,  52)
#define linux_K_F44    linux_K(linux_KT_FN,  53)
#define linux_K_F45    linux_K(linux_KT_FN,  54)
#define linux_K_F46    linux_K(linux_KT_FN,  55)
#define linux_K_F47    linux_K(linux_KT_FN,  56)
#define linux_K_F48    linux_K(linux_KT_FN,  57)
#define linux_K_F49    linux_K(linux_KT_FN,  58)
#define linux_K_F50    linux_K(linux_KT_FN,  59)
#define linux_K_F51    linux_K(linux_KT_FN,  60)
#define linux_K_F52    linux_K(linux_KT_FN,  61)
#define linux_K_F53    linux_K(linux_KT_FN,  62)
#define linux_K_F54    linux_K(linux_KT_FN,  63)
#define linux_K_F55    linux_K(linux_KT_FN,  64)
#define linux_K_F56    linux_K(linux_KT_FN,  65)
#define linux_K_F57    linux_K(linux_KT_FN,  66)
#define linux_K_F58    linux_K(linux_KT_FN,  67)
#define linux_K_F59    linux_K(linux_KT_FN,  68)
#define linux_K_F60    linux_K(linux_KT_FN,  69)
#define linux_K_F61    linux_K(linux_KT_FN,  70)
#define linux_K_F62    linux_K(linux_KT_FN,  71)
#define linux_K_F63    linux_K(linux_KT_FN,  72)
#define linux_K_F64    linux_K(linux_KT_FN,  73)
#define linux_K_F65    linux_K(linux_KT_FN,  74)
#define linux_K_F66    linux_K(linux_KT_FN,  75)
#define linux_K_F67    linux_K(linux_KT_FN,  76)
#define linux_K_F68    linux_K(linux_KT_FN,  77)
#define linux_K_F69    linux_K(linux_KT_FN,  78)
#define linux_K_F70    linux_K(linux_KT_FN,  79)
#define linux_K_F71    linux_K(linux_KT_FN,  80)
#define linux_K_F72    linux_K(linux_KT_FN,  81)
#define linux_K_F73    linux_K(linux_KT_FN,  82)
#define linux_K_F74    linux_K(linux_KT_FN,  83)
#define linux_K_F75    linux_K(linux_KT_FN,  84)
#define linux_K_F76    linux_K(linux_KT_FN,  85)
#define linux_K_F77    linux_K(linux_KT_FN,  86)
#define linux_K_F78    linux_K(linux_KT_FN,  87)
#define linux_K_F79    linux_K(linux_KT_FN,  88)
#define linux_K_F80    linux_K(linux_KT_FN,  89)
#define linux_K_F81    linux_K(linux_KT_FN,  90)
#define linux_K_F82    linux_K(linux_KT_FN,  91)
#define linux_K_F83    linux_K(linux_KT_FN,  92)
#define linux_K_F84    linux_K(linux_KT_FN,  93)
#define linux_K_F85    linux_K(linux_KT_FN,  94)
#define linux_K_F86    linux_K(linux_KT_FN,  95)
#define linux_K_F87    linux_K(linux_KT_FN,  96)
#define linux_K_F88    linux_K(linux_KT_FN,  97)
#define linux_K_F89    linux_K(linux_KT_FN,  98)
#define linux_K_F90    linux_K(linux_KT_FN,  99)
#define linux_K_F91    linux_K(linux_KT_FN, 100)
#define linux_K_F92    linux_K(linux_KT_FN, 101)
#define linux_K_F93    linux_K(linux_KT_FN, 102)
#define linux_K_F94    linux_K(linux_KT_FN, 103)
#define linux_K_F95    linux_K(linux_KT_FN, 104)
#define linux_K_F96    linux_K(linux_KT_FN, 105)
#define linux_K_F97    linux_K(linux_KT_FN, 106)
#define linux_K_F98    linux_K(linux_KT_FN, 107)
#define linux_K_F99    linux_K(linux_KT_FN, 108)
#define linux_K_F100   linux_K(linux_KT_FN, 109)
#define linux_K_F101   linux_K(linux_KT_FN, 110)
#define linux_K_F102   linux_K(linux_KT_FN, 111)
#define linux_K_F103   linux_K(linux_KT_FN, 112)
#define linux_K_F104   linux_K(linux_KT_FN, 113)
#define linux_K_F105   linux_K(linux_KT_FN, 114)
#define linux_K_F106   linux_K(linux_KT_FN, 115)
#define linux_K_F107   linux_K(linux_KT_FN, 116)
#define linux_K_F108   linux_K(linux_KT_FN, 117)
#define linux_K_F109   linux_K(linux_KT_FN, 118)
#define linux_K_F110   linux_K(linux_KT_FN, 119)
#define linux_K_F111   linux_K(linux_KT_FN, 120)
#define linux_K_F112   linux_K(linux_KT_FN, 121)
#define linux_K_F113   linux_K(linux_KT_FN, 122)
#define linux_K_F114   linux_K(linux_KT_FN, 123)
#define linux_K_F115   linux_K(linux_KT_FN, 124)
#define linux_K_F116   linux_K(linux_KT_FN, 125)
#define linux_K_F117   linux_K(linux_KT_FN, 126)
#define linux_K_F118   linux_K(linux_KT_FN, 127)
#define linux_K_F119   linux_K(linux_KT_FN, 128)
#define linux_K_F120   linux_K(linux_KT_FN, 129)
#define linux_K_F121   linux_K(linux_KT_FN, 130)
#define linux_K_F122   linux_K(linux_KT_FN, 131)
#define linux_K_F123   linux_K(linux_KT_FN, 132)
#define linux_K_F124   linux_K(linux_KT_FN, 133)
#define linux_K_F125   linux_K(linux_KT_FN, 134)
#define linux_K_F126   linux_K(linux_KT_FN, 135)
#define linux_K_F127   linux_K(linux_KT_FN, 136)
#define linux_K_F128   linux_K(linux_KT_FN, 137)
#define linux_K_F129   linux_K(linux_KT_FN, 138)
#define linux_K_F130   linux_K(linux_KT_FN, 139)
#define linux_K_F131   linux_K(linux_KT_FN, 140)
#define linux_K_F132   linux_K(linux_KT_FN, 141)
#define linux_K_F133   linux_K(linux_KT_FN, 142)
#define linux_K_F134   linux_K(linux_KT_FN, 143)
#define linux_K_F135   linux_K(linux_KT_FN, 144)
#define linux_K_F136   linux_K(linux_KT_FN, 145)
#define linux_K_F137   linux_K(linux_KT_FN, 146)
#define linux_K_F138   linux_K(linux_KT_FN, 147)
#define linux_K_F139   linux_K(linux_KT_FN, 148)
#define linux_K_F140   linux_K(linux_KT_FN, 149)
#define linux_K_F141   linux_K(linux_KT_FN, 150)
#define linux_K_F142   linux_K(linux_KT_FN, 151)
#define linux_K_F143   linux_K(linux_KT_FN, 152)
#define linux_K_F144   linux_K(linux_KT_FN, 153)
#define linux_K_F145   linux_K(linux_KT_FN, 154)
#define linux_K_F146   linux_K(linux_KT_FN, 155)
#define linux_K_F147   linux_K(linux_KT_FN, 156)
#define linux_K_F148   linux_K(linux_KT_FN, 157)
#define linux_K_F149   linux_K(linux_KT_FN, 158)
#define linux_K_F150   linux_K(linux_KT_FN, 159)
#define linux_K_F151   linux_K(linux_KT_FN, 160)
#define linux_K_F152   linux_K(linux_KT_FN, 161)
#define linux_K_F153   linux_K(linux_KT_FN, 162)
#define linux_K_F154   linux_K(linux_KT_FN, 163)
#define linux_K_F155   linux_K(linux_KT_FN, 164)
#define linux_K_F156   linux_K(linux_KT_FN, 165)
#define linux_K_F157   linux_K(linux_KT_FN, 166)
#define linux_K_F158   linux_K(linux_KT_FN, 167)
#define linux_K_F159   linux_K(linux_KT_FN, 168)
#define linux_K_F160   linux_K(linux_KT_FN, 169)
#define linux_K_F161   linux_K(linux_KT_FN, 170)
#define linux_K_F162   linux_K(linux_KT_FN, 171)
#define linux_K_F163   linux_K(linux_KT_FN, 172)
#define linux_K_F164   linux_K(linux_KT_FN, 173)
#define linux_K_F165   linux_K(linux_KT_FN, 174)
#define linux_K_F166   linux_K(linux_KT_FN, 175)
#define linux_K_F167   linux_K(linux_KT_FN, 176)
#define linux_K_F168   linux_K(linux_KT_FN, 177)
#define linux_K_F169   linux_K(linux_KT_FN, 178)
#define linux_K_F170   linux_K(linux_KT_FN, 179)
#define linux_K_F171   linux_K(linux_KT_FN, 180)
#define linux_K_F172   linux_K(linux_KT_FN, 181)
#define linux_K_F173   linux_K(linux_KT_FN, 182)
#define linux_K_F174   linux_K(linux_KT_FN, 183)
#define linux_K_F175   linux_K(linux_KT_FN, 184)
#define linux_K_F176   linux_K(linux_KT_FN, 185)
#define linux_K_F177   linux_K(linux_KT_FN, 186)
#define linux_K_F178   linux_K(linux_KT_FN, 187)
#define linux_K_F179   linux_K(linux_KT_FN, 188)
#define linux_K_F180   linux_K(linux_KT_FN, 189)
#define linux_K_F181   linux_K(linux_KT_FN, 190)
#define linux_K_F182   linux_K(linux_KT_FN, 191)
#define linux_K_F183   linux_K(linux_KT_FN, 192)
#define linux_K_F184   linux_K(linux_KT_FN, 193)
#define linux_K_F185   linux_K(linux_KT_FN, 194)
#define linux_K_F186   linux_K(linux_KT_FN, 195)
#define linux_K_F187   linux_K(linux_KT_FN, 196)
#define linux_K_F188   linux_K(linux_KT_FN, 197)
#define linux_K_F189   linux_K(linux_KT_FN, 198)
#define linux_K_F190   linux_K(linux_KT_FN, 199)
#define linux_K_F191   linux_K(linux_KT_FN, 200)
#define linux_K_F192   linux_K(linux_KT_FN, 201)
#define linux_K_F193   linux_K(linux_KT_FN, 202)
#define linux_K_F194   linux_K(linux_KT_FN, 203)
#define linux_K_F195   linux_K(linux_KT_FN, 204)
#define linux_K_F196   linux_K(linux_KT_FN, 205)
#define linux_K_F197   linux_K(linux_KT_FN, 206)
#define linux_K_F198   linux_K(linux_KT_FN, 207)
#define linux_K_F199   linux_K(linux_KT_FN, 208)
#define linux_K_F200   linux_K(linux_KT_FN, 209)
#define linux_K_F201   linux_K(linux_KT_FN, 210)
#define linux_K_F202   linux_K(linux_KT_FN, 211)
#define linux_K_F203   linux_K(linux_KT_FN, 212)
#define linux_K_F204   linux_K(linux_KT_FN, 213)
#define linux_K_F205   linux_K(linux_KT_FN, 214)
#define linux_K_F206   linux_K(linux_KT_FN, 215)
#define linux_K_F207   linux_K(linux_KT_FN, 216)
#define linux_K_F208   linux_K(linux_KT_FN, 217)
#define linux_K_F209   linux_K(linux_KT_FN, 218)
#define linux_K_F210   linux_K(linux_KT_FN, 219)
#define linux_K_F211   linux_K(linux_KT_FN, 220)
#define linux_K_F212   linux_K(linux_KT_FN, 221)
#define linux_K_F213   linux_K(linux_KT_FN, 222)
#define linux_K_F214   linux_K(linux_KT_FN, 223)
#define linux_K_F215   linux_K(linux_KT_FN, 224)
#define linux_K_F216   linux_K(linux_KT_FN, 225)
#define linux_K_F217   linux_K(linux_KT_FN, 226)
#define linux_K_F218   linux_K(linux_KT_FN, 227)
#define linux_K_F219   linux_K(linux_KT_FN, 228)
#define linux_K_F220   linux_K(linux_KT_FN, 229)
#define linux_K_F221   linux_K(linux_KT_FN, 230)
#define linux_K_F222   linux_K(linux_KT_FN, 231)
#define linux_K_F223   linux_K(linux_KT_FN, 232)
#define linux_K_F224   linux_K(linux_KT_FN, 233)
#define linux_K_F225   linux_K(linux_KT_FN, 234)
#define linux_K_F226   linux_K(linux_KT_FN, 235)
#define linux_K_F227   linux_K(linux_KT_FN, 236)
#define linux_K_F228   linux_K(linux_KT_FN, 237)
#define linux_K_F229   linux_K(linux_KT_FN, 238)
#define linux_K_F230   linux_K(linux_KT_FN, 239)
#define linux_K_F231   linux_K(linux_KT_FN, 240)
#define linux_K_F232   linux_K(linux_KT_FN, 241)
#define linux_K_F233   linux_K(linux_KT_FN, 242)
#define linux_K_F234   linux_K(linux_KT_FN, 243)
#define linux_K_F235   linux_K(linux_KT_FN, 244)
#define linux_K_F236   linux_K(linux_KT_FN, 245)
#define linux_K_F237   linux_K(linux_KT_FN, 246)
#define linux_K_F238   linux_K(linux_KT_FN, 247)
#define linux_K_F239   linux_K(linux_KT_FN, 248)
#define linux_K_F240   linux_K(linux_KT_FN, 249)
#define linux_K_F241   linux_K(linux_KT_FN, 250)
#define linux_K_F242   linux_K(linux_KT_FN, 251)
#define linux_K_F243   linux_K(linux_KT_FN, 252)
#define linux_K_F244   linux_K(linux_KT_FN, 253)
#define linux_K_F245   linux_K(linux_KT_FN, 254)
#define linux_K_UNDO   linux_K(linux_KT_FN, 255)

#define linux_K_HOLE         linux_K(linux_KT_SPEC,  0)
#define linux_K_ENTER        linux_K(linux_KT_SPEC,  1)
#define linux_K_SH_REGS      linux_K(linux_KT_SPEC,  2)
#define linux_K_SH_MEM       linux_K(linux_KT_SPEC,  3)
#define linux_K_SH_STAT      linux_K(linux_KT_SPEC,  4)
#define linux_K_BREAK        linux_K(linux_KT_SPEC,  5)
#define linux_K_CONS         linux_K(linux_KT_SPEC,  6)
#define linux_K_CAPS         linux_K(linux_KT_SPEC,  7)
#define linux_K_NUM          linux_K(linux_KT_SPEC,  8)
#define linux_K_HOLD         linux_K(linux_KT_SPEC,  9)
#define linux_K_SCROLLFORW   linux_K(linux_KT_SPEC, 10)
#define linux_K_SCROLLBACK   linux_K(linux_KT_SPEC, 11)
#define linux_K_BOOT         linux_K(linux_KT_SPEC, 12)
#define linux_K_CAPSON       linux_K(linux_KT_SPEC, 13)
#define linux_K_COMPOSE      linux_K(linux_KT_SPEC, 14)
#define linux_K_SAK          linux_K(linux_KT_SPEC, 15)
#define linux_K_DECRCONSOLE  linux_K(linux_KT_SPEC, 16)
#define linux_K_INCRCONSOLE  linux_K(linux_KT_SPEC, 17)
#define linux_K_SPAWNCONSOLE linux_K(linux_KT_SPEC, 18)
#define linux_K_BARENUMLOCK  linux_K(linux_KT_SPEC, 19)

#define linux_K_ALLOCATED linux_K(linux_KT_SPEC, 126)
#define linux_K_NOSUCHMAP linux_K(linux_KT_SPEC, 127)

#define linux_K_P0         linux_K(linux_KT_PAD,  0)
#define linux_K_P1         linux_K(linux_KT_PAD,  1)
#define linux_K_P2         linux_K(linux_KT_PAD,  2)
#define linux_K_P3         linux_K(linux_KT_PAD,  3)
#define linux_K_P4         linux_K(linux_KT_PAD,  4)
#define linux_K_P5         linux_K(linux_KT_PAD,  5)
#define linux_K_P6         linux_K(linux_KT_PAD,  6)
#define linux_K_P7         linux_K(linux_KT_PAD,  7)
#define linux_K_P8         linux_K(linux_KT_PAD,  8)
#define linux_K_P9         linux_K(linux_KT_PAD,  9)
#define linux_K_PPLUS      linux_K(linux_KT_PAD, 10)
#define linux_K_PMINUS     linux_K(linux_KT_PAD, 11)
#define linux_K_PSTAR      linux_K(linux_KT_PAD, 12)
#define linux_K_PSLASH     linux_K(linux_KT_PAD, 13)
#define linux_K_PENTER     linux_K(linux_KT_PAD, 14)
#define linux_K_PCOMMA     linux_K(linux_KT_PAD, 15)
#define linux_K_PDOT       linux_K(linux_KT_PAD, 16)
#define linux_K_PPLUSMINUS linux_K(linux_KT_PAD, 17)
#define linux_K_PPARENL    linux_K(linux_KT_PAD, 18)
#define linux_K_PPARENR    linux_K(linux_KT_PAD, 19)

#define linux_NR_PAD 20

#define linux_K_DGRAVE      linux_K(linux_KT_DEAD,  0)
#define linux_K_DACUTE      linux_K(linux_KT_DEAD,  1)
#define linux_K_DCIRCM      linux_K(linux_KT_DEAD,  2)
#define linux_K_DTILDE      linux_K(linux_KT_DEAD,  3)
#define linux_K_DDIERE      linux_K(linux_KT_DEAD,  4)
#define linux_K_DCEDIL      linux_K(linux_KT_DEAD,  5)
#define linux_K_DMACRON     linux_K(linux_KT_DEAD,  6)
#define linux_K_DBREVE      linux_K(linux_KT_DEAD,  7)
#define linux_K_DABDOT      linux_K(linux_KT_DEAD,  8)
#define linux_K_DABRING     linux_K(linux_KT_DEAD,  9)
#define linux_K_DDBACUTE    linux_K(linux_KT_DEAD, 10)
#define linux_K_DCARON      linux_K(linux_KT_DEAD, 11)
#define linux_K_DOGONEK     linux_K(linux_KT_DEAD, 12)
#define linux_K_DIOTA       linux_K(linux_KT_DEAD, 13)
#define linux_K_DVOICED     linux_K(linux_KT_DEAD, 14)
#define linux_K_DSEMVOICED  linux_K(linux_KT_DEAD, 15)
#define linux_K_DBEDOT      linux_K(linux_KT_DEAD, 16)
#define linux_K_DHOOK       linux_K(linux_KT_DEAD, 17)
#define linux_K_DHORN       linux_K(linux_KT_DEAD, 18)
#define linux_K_DSTROKE     linux_K(linux_KT_DEAD, 19)
#define linux_K_DABCOMMA    linux_K(linux_KT_DEAD, 20)
#define linux_K_DABREVCOMMA linux_K(linux_KT_DEAD, 21)
#define linux_K_DDBGRAVE    linux_K(linux_KT_DEAD, 22)
#define linux_K_DINVBREVE   linux_K(linux_KT_DEAD, 23)
#define linux_K_DBECOMMA    linux_K(linux_KT_DEAD, 24)
#define linux_K_DCURRENCY   linux_K(linux_KT_DEAD, 25)
#define linux_K_DGREEK      linux_K(linux_KT_DEAD, 26)

#define linux_NR_DEAD 27

#define linux_K_DOWN  linux_K(linux_KT_CUR, 0)
#define linux_K_LEFT  linux_K(linux_KT_CUR, 1)
#define linux_K_RIGHT linux_K(linux_KT_CUR, 2)
#define linux_K_UP    linux_K(linux_KT_CUR, 3)

#define linux_K_SHIFT     linux_K(linux_KT_SHIFT, linux_KG_SHIFT)
#define linux_K_CTRL      linux_K(linux_KT_SHIFT, linux_KG_CTRL)
#define linux_K_ALT       linux_K(linux_KT_SHIFT, linux_KG_ALT)
#define linux_K_ALTGR     linux_K(linux_KT_SHIFT, linux_KG_ALTGR)
#define linux_K_SHIFTL    linux_K(linux_KT_SHIFT, linux_KG_SHIFTL)
#define linux_K_SHIFTR    linux_K(linux_KT_SHIFT, linux_KG_SHIFTR)
#define linux_K_CTRLL     linux_K(linux_KT_SHIFT, linux_KG_CTRLL)
#define linux_K_CTRLR     linux_K(linux_KT_SHIFT, linux_KG_CTRLR)
#define linux_K_CAPSSHIFT linux_K(linux_KT_SHIFT, linux_KG_CAPSSHIFT)

#define linux_K_ASC0 linux_K(linux_KT_ASCII,  0)
#define linux_K_ASC1 linux_K(linux_KT_ASCII,  1)
#define linux_K_ASC2 linux_K(linux_KT_ASCII,  2)
#define linux_K_ASC3 linux_K(linux_KT_ASCII,  3)
#define linux_K_ASC4 linux_K(linux_KT_ASCII,  4)
#define linux_K_ASC5 linux_K(linux_KT_ASCII,  5)
#define linux_K_ASC6 linux_K(linux_KT_ASCII,  6)
#define linux_K_ASC7 linux_K(linux_KT_ASCII,  7)
#define linux_K_ASC8 linux_K(linux_KT_ASCII,  8)
#define linux_K_ASC9 linux_K(linux_KT_ASCII,  9)
#define linux_K_HEX0 linux_K(linux_KT_ASCII, 10)
#define linux_K_HEX1 linux_K(linux_KT_ASCII, 11)
#define linux_K_HEX2 linux_K(linux_KT_ASCII, 12)
#define linux_K_HEX3 linux_K(linux_KT_ASCII, 13)
#define linux_K_HEX4 linux_K(linux_KT_ASCII, 14)
#define linux_K_HEX5 linux_K(linux_KT_ASCII, 15)
#define linux_K_HEX6 linux_K(linux_KT_ASCII, 16)
#define linux_K_HEX7 linux_K(linux_KT_ASCII, 17)
#define linux_K_HEX8 linux_K(linux_KT_ASCII, 18)
#define linux_K_HEX9 linux_K(linux_KT_ASCII, 19)
#define linux_K_HEXa linux_K(linux_KT_ASCII, 20)
#define linux_K_HEXb linux_K(linux_KT_ASCII, 21)
#define linux_K_HEXc linux_K(linux_KT_ASCII, 22)
#define linux_K_HEXd linux_K(linux_KT_ASCII, 23)
#define linux_K_HEXe linux_K(linux_KT_ASCII, 24)
#define linux_K_HEXf linux_K(linux_KT_ASCII, 25)

#define linux_NR_ASCII 26

#define linux_K_SHIFTLOCK     linux_K(linux_KT_LOCK, linux_KG_SHIFT)
#define linux_K_CTRLLOCK      linux_K(linux_KT_LOCK, linux_KG_CTRL)
#define linux_K_ALTLOCK       linux_K(linux_KT_LOCK, linux_KG_ALT)
#define linux_K_ALTGRLOCK     linux_K(linux_KT_LOCK, linux_KG_ALTGR)
#define linux_K_SHIFTLLOCK    linux_K(linux_KT_LOCK, linux_KG_SHIFTL)
#define linux_K_SHIFTRLOCK    linux_K(linux_KT_LOCK, linux_KG_SHIFTR)
#define linux_K_CTRLLLOCK     linux_K(linux_KT_LOCK, linux_KG_CTRLL)
#define linux_K_CTRLRLOCK     linux_K(linux_KT_LOCK, linux_KG_CTRLR)
#define linux_K_CAPSSHIFTLOCK linux_K(linux_KT_LOCK, linux_KG_CAPSSHIFT)

#define linux_K_SHIFT_SLOCK     linux_K(linux_KT_SLOCK, linux_KG_SHIFT)
#define linux_K_CTRL_SLOCK      linux_K(linux_KT_SLOCK, linux_KG_CTRL)
#define linux_K_ALT_SLOCK       linux_K(linux_KT_SLOCK, linux_KG_ALT)
#define linux_K_ALTGR_SLOCK     linux_K(linux_KT_SLOCK, linux_KG_ALTGR)
#define linux_K_SHIFTL_SLOCK    linux_K(linux_KT_SLOCK, linux_KG_SHIFTL)
#define linux_K_SHIFTR_SLOCK    linux_K(linux_KT_SLOCK, linux_KG_SHIFTR)
#define linux_K_CTRLL_SLOCK     linux_K(linux_KT_SLOCK, linux_KG_CTRLL)
#define linux_K_CTRLR_SLOCK     linux_K(linux_KT_SLOCK, linux_KG_CTRLR)
#define linux_K_CAPSSHIFT_SLOCK linux_K(linux_KT_SLOCK, linux_KG_CAPSSHIFT)

#define linux_NR_LOCK 9

#define linux_K_BRL_BLANK linux_K(linux_KT_BRL,  0)
#define linux_K_BRL_DOT1  linux_K(linux_KT_BRL,  1)
#define linux_K_BRL_DOT2  linux_K(linux_KT_BRL,  2)
#define linux_K_BRL_DOT3  linux_K(linux_KT_BRL,  3)
#define linux_K_BRL_DOT4  linux_K(linux_KT_BRL,  4)
#define linux_K_BRL_DOT5  linux_K(linux_KT_BRL,  5)
#define linux_K_BRL_DOT6  linux_K(linux_KT_BRL,  6)
#define linux_K_BRL_DOT7  linux_K(linux_KT_BRL,  7)
#define linux_K_BRL_DOT8  linux_K(linux_KT_BRL,  8)
#define linux_K_BRL_DOT9  linux_K(linux_KT_BRL,  9)
#define linux_K_BRL_DOT10 linux_K(linux_KT_BRL, 10)

#define linux_NR_BRL 11

#define linux_MAX_DIACR 256

//=============================================================================
// linux_TIOCLINUX ioctl

#define linux_TIOCL_SETSEL             2
#define linux_TIOCL_PASTESEL           3
#define linux_TIOCL_UNBLANKSCREEN      4
#define linux_TIOCL_SELLOADLUT         5
#define linux_TIOCL_GETSHIFTSTATE      6
#define linux_TIOCL_GETMOUSEREPORTING  7
#define linux_TIOCL_SETVESABLANK      10
#define linux_TIOCL_SETKMSGREDIRECT   11
#define linux_TIOCL_GETFGCONSOLE      12
#define linux_TIOCL_SCROLLCONSOLE     13
#define linux_TIOCL_BLANKSCREEN       14
#define linux_TIOCL_BLANKEDSCREEN     15
#define linux_TIOCL_GETKMSGREDIRECT   17

#define TIOCL_SELCHAR         0
#define TIOCL_SELWORD         1
#define TIOCL_SELLINE         2
#define TIOCL_SELPOINTER      3
#define TIOCL_SELCLEAR        4
#define TIOCL_SELMOUSEREPORT 16
#define TIOCL_SELBUTTONMASK  15

//=============================================================================
// mount

#define linux_MS_RDONLY          1
#define linux_MS_NOSUID          2
#define linux_MS_NODEV           4
#define linux_MS_NOEXEC          8
#define linux_MS_SYNCHRONOUS    16
#define linux_MS_REMOUNT        32
#define linux_MS_MANDLOCK       64
#define linux_MS_DIRSYNC       128
#define linux_MS_NOATIME      1024
#define linux_MS_NODIRATIME   2048
#define linux_MS_BIND         4096
#define linux_MS_MOVE         8192
#define linux_MS_REC         16384
#define linux_MS_VERBOSE     32768
#define linux_MS_SILENT      32768
#define linux_MS_POSIXACL    (1<<16)
#define linux_MS_UNBINDABLE  (1<<17)
#define linux_MS_PRIVATE     (1<<18)
#define linux_MS_SLAVE       (1<<19)
#define linux_MS_SHARED      (1<<20)
#define linux_MS_RELATIME    (1<<21)
#define linux_MS_KERNMOUNT   (1<<22)
#define linux_MS_I_VERSION   (1<<23)
#define linux_MS_STRICTATIME (1<<24)
#define linux_MS_LAZYTIME    (1<<25)

#define linux_MS_RMT_MASK    (linux_MS_RDONLY | linux_MS_SYNCHRONOUS | linux_MS_MANDLOCK | linux_MS_I_VERSION | linux_MS_LAZYTIME)

#define linux_MS_MGC_VAL 0xC0ED0000
#define linux_MS_MGC_MSK 0xffff0000

#define linux_OPEN_TREE_CLONE   1
#define linux_OPEN_TREE_CLOEXEC linux_O_CLOEXEC

#define linux_MOVE_MOUNT_F_SYMLINKS   0x00000001
#define linux_MOVE_MOUNT_F_AUTOMOUNTS 0x00000002
#define linux_MOVE_MOUNT_F_EMPTY_PATH 0x00000004
#define linux_MOVE_MOUNT_T_SYMLINKS   0x00000010
#define linux_MOVE_MOUNT_T_AUTOMOUNTS 0x00000020
#define linux_MOVE_MOUNT_T_EMPTY_PATH 0x00000040
#define linux_MOVE_MOUNT_MASK         0x00000077

#define linux_FSOPEN_CLOEXEC 0x00000001

#define linux_FSPICK_CLOEXEC          0x00000001
#define linux_FSPICK_SYMLINK_NOFOLLOW 0x00000002
#define linux_FSPICK_NO_AUTOMOUNT     0x00000004
#define linux_FSPICK_EMPTY_PATH       0x00000008

enum linux_fsconfig_command
{
	linux_FSCONFIG_SET_FLAG        = 0,
	linux_FSCONFIG_SET_STRING      = 1,
	linux_FSCONFIG_SET_BINARY      = 2,
	linux_FSCONFIG_SET_PATH        = 3,
	linux_FSCONFIG_SET_PATH_EMPTY  = 4,
	linux_FSCONFIG_SET_FD          = 5,
	linux_FSCONFIG_CMD_CREATE      = 6,
	linux_FSCONFIG_CMD_RECONFIGURE = 7,
};

#define linux_FSMOUNT_CLOEXEC		0x00000001

#define linux_MOUNT_ATTR_RDONLY      0x00000001
#define linux_MOUNT_ATTR_NOSUID      0x00000002
#define linux_MOUNT_ATTR_NODEV       0x00000004
#define linux_MOUNT_ATTR_NOEXEC      0x00000008
#define linux_MOUNT_ATTR_ATIME       0x00000070
#define linux_MOUNT_ATTR_RELATIME    0x00000000
#define linux_MOUNT_ATTR_NOATIME     0x00000010
#define linux_MOUNT_ATTR_STRICTATIME 0x00000020
#define linux_MOUNT_ATTR_NODIRATIME  0x00000080

//=============================================================================
// blktrace_api

enum linux_blktrace_cat
{
	linux_BLK_TC_READ     = 1 <<  0,
	linux_BLK_TC_WRITE    = 1 <<  1,
	linux_BLK_TC_FLUSH    = 1 <<  2,
	linux_BLK_TC_SYNC     = 1 <<  3,
	linux_BLK_TC_SYNCIO   = linux_BLK_TC_SYNC,
	linux_BLK_TC_QUEUE    = 1 <<  4,
	linux_BLK_TC_REQUEUE  = 1 <<  5,
	linux_BLK_TC_ISSUE    = 1 <<  6,
	linux_BLK_TC_COMPLETE = 1 <<  7,
	linux_BLK_TC_FS       = 1 <<  8,
	linux_BLK_TC_PC       = 1 <<  9,
	linux_BLK_TC_NOTIFY   = 1 << 10,
	linux_BLK_TC_AHEAD    = 1 << 11,
	linux_BLK_TC_META     = 1 << 12,
	linux_BLK_TC_DISCARD  = 1 << 13,
	linux_BLK_TC_DRV_DATA = 1 << 14,
	linux_BLK_TC_FUA      = 1 << 15,

	linux_BLK_TC_END      = 1 << 15,
};

#define linux_BLK_TC_SHIFT    16
#define linux_BLK_TC_ACT(act) ((act) << linux_BLK_TC_SHIFT)

enum linux_blktrace_act
{
	linux_BLK_TA_QUEUE = 1,
	linux_BLK_TA_BACKMERGE,
	linux_BLK_TA_FRONTMERGE,
	linux_BLK_TA_GETRQ,
	linux_BLK_TA_SLEEPRQ,
	linux_BLK_TA_REQUEUE,
	linux_BLK_TA_ISSUE,
	linux_BLK_TA_COMPLETE,
	linux_BLK_TA_PLUG,
	linux_BLK_TA_UNPLUG_IO,
	linux_BLK_TA_UNPLUG_TIMER,
	linux_BLK_TA_INSERT,
	linux_BLK_TA_SPLIT,
	linux_BLK_TA_BOUNCE,
	linux_BLK_TA_REMAP,
	linux_BLK_TA_ABORT,
	linux_BLK_TA_DRV_DATA,
	linux_BLK_TA_CGROUP = 1 << 8,
};

enum linux_blktrace_notify
{
	linux_BLK_TN_PROCESS = 0,
	linux_BLK_TN_TIMESTAMP,
	linux_BLK_TN_MESSAGE,
	linux_BLK_TN_CGROUP = linux_BLK_TA_CGROUP,
};

#define linux_BLK_TA_QUEUE        (linux_BLK_TA_QUEUE        | linux_BLK_TC_ACT(linux_BLK_TC_QUEUE))
#define linux_BLK_TA_BACKMERGE    (linux_BLK_TA_BACKMERGE    | linux_BLK_TC_ACT(linux_BLK_TC_QUEUE))
#define linux_BLK_TA_FRONTMERGE   (linux_BLK_TA_FRONTMERGE   | linux_BLK_TC_ACT(linux_BLK_TC_QUEUE))
#define linux_BLK_TA_GETRQ        (linux_BLK_TA_GETRQ        | linux_BLK_TC_ACT(linux_BLK_TC_QUEUE))
#define linux_BLK_TA_SLEEPRQ      (linux_BLK_TA_SLEEPRQ      | linux_BLK_TC_ACT(linux_BLK_TC_QUEUE))
#define linux_BLK_TA_REQUEUE      (linux_BLK_TA_REQUEUE      | linux_BLK_TC_ACT(linux_BLK_TC_REQUEUE))
#define linux_BLK_TA_ISSUE        (linux_BLK_TA_ISSUE        | linux_BLK_TC_ACT(linux_BLK_TC_ISSUE))
#define linux_BLK_TA_COMPLETE     (linux_BLK_TA_COMPLETE     | linux_BLK_TC_ACT(linux_BLK_TC_COMPLETE))
#define linux_BLK_TA_PLUG         (linux_BLK_TA_PLUG         | linux_BLK_TC_ACT(linux_BLK_TC_QUEUE))
#define linux_BLK_TA_UNPLUG_IO    (linux_BLK_TA_UNPLUG_IO    | linux_BLK_TC_ACT(linux_BLK_TC_QUEUE))
#define linux_BLK_TA_UNPLUG_TIMER (linux_BLK_TA_UNPLUG_TIMER | linux_BLK_TC_ACT(linux_BLK_TC_QUEUE))
#define linux_BLK_TA_INSERT       (linux_BLK_TA_INSERT       | linux_BLK_TC_ACT(linux_BLK_TC_QUEUE))
#define linux_BLK_TA_SPLIT        (linux_BLK_TA_SPLIT)
#define linux_BLK_TA_BOUNCE       (linux_BLK_TA_BOUNCE)
#define linux_BLK_TA_REMAP        (linux_BLK_TA_REMAP        | linux_BLK_TC_ACT(linux_BLK_TC_QUEUE))
#define linux_BLK_TA_ABORT        (linux_BLK_TA_ABORT        | linux_BLK_TC_ACT(linux_BLK_TC_QUEUE))
#define linux_BLK_TA_DRV_DATA     (linux_BLK_TA_DRV_DATA     | linux_BLK_TC_ACT(linux_BLK_TC_DRV_DATA))

#define linux_BLK_TN_PROCESS   (linux_BLK_TN_PROCESS   | linux_BLK_TC_ACT(linux_BLK_TC_NOTIFY))
#define linux_BLK_TN_TIMESTAMP (linux_BLK_TN_TIMESTAMP | linux_BLK_TC_ACT(linux_BLK_TC_NOTIFY))
#define linux_BLK_TN_MESSAGE   (linux_BLK_TN_MESSAGE   | linux_BLK_TC_ACT(linux_BLK_TC_NOTIFY))

#define linux_BLK_IO_TRACE_MAGIC   0x65617400
#define linux_BLK_IO_TRACE_VERSION 0x07

enum
{
	linux_Blktrace_setup = 1,
	linux_Blktrace_running,
	linux_Blktrace_stopped,
};

#define linux_BLKTRACE_BDEV_SIZE 32

//=============================================================================
// blkpg

#define linux_BLKPG linux_IO(0x12, 105)

#define linux_BLKPG_ADD_PARTITION    1
#define linux_BLKPG_DEL_PARTITION    2
#define linux_BLKPG_RESIZE_PARTITION 3

#define linux_BLKPG_DEVNAMELTH 64
#define linux_BLKPG_VOLNAMELTH 64

//=============================================================================
// fiemap

#define linux_FIEMAP_MAX_OFFSET (~0ULL)

#define linux_FIEMAP_FLAG_SYNC  0x00000001
#define linux_FIEMAP_FLAG_XATTR 0x00000002
#define linux_FIEMAP_FLAG_CACHE 0x00000004

#define linux_FIEMAP_FLAGS_COMPAT (linux_FIEMAP_FLAG_SYNC | linux_FIEMAP_FLAG_XATTR)

#define linux_FIEMAP_EXTENT_LAST           0x00000001
#define linux_FIEMAP_EXTENT_UNKNOWN        0x00000002
#define linux_FIEMAP_EXTENT_DELALLOC       0x00000004
#define linux_FIEMAP_EXTENT_ENCODED        0x00000008
#define linux_FIEMAP_EXTENT_DATA_ENCRYPTED 0x00000080
#define linux_FIEMAP_EXTENT_NOT_ALIGNED    0x00000100
#define linux_FIEMAP_EXTENT_DATA_INLINE    0x00000200
#define linux_FIEMAP_EXTENT_DATA_TAIL      0x00000400
#define linux_FIEMAP_EXTENT_UNWRITTEN      0x00000800
#define linux_FIEMAP_EXTENT_MERGED         0x00001000
#define linux_FIEMAP_EXTENT_SHARED         0x00002000

//=============================================================================
// fs

#define linux_INR_OPEN_CUR 1024
#define linux_INR_OPEN_MAX 4096

#define linux_BLOCK_SIZE_BITS 10
#define linux_BLOCK_SIZE      (1 << linux_BLOCK_SIZE_BITS)

#define linux_SEEK_SET  0
#define linux_SEEK_CUR  1
#define linux_SEEK_END  2
#define linux_SEEK_DATA 3
#define linux_SEEK_HOLE 4
#define linux_SEEK_MAX  linux_SEEK_HOLE

#define linux_RENAME_NOREPLACE (1 << 0)
#define linux_RENAME_EXCHANGE  (1 << 1)
#define linux_RENAME_WHITEOUT  (1 << 2)

#define linux_FILE_DEDUPE_RANGE_SAME    0
#define linux_FILE_DEDUPE_RANGE_DIFFERS 1

#define linux_NR_FILE 8192

#define linux_FS_XFLAG_REALTIME     0x00000001
#define linux_FS_XFLAG_PREALLOC     0x00000002
#define linux_FS_XFLAG_IMMUTABLE    0x00000008
#define linux_FS_XFLAG_APPEND       0x00000010
#define linux_FS_XFLAG_SYNC         0x00000020
#define linux_FS_XFLAG_NOATIME      0x00000040
#define linux_FS_XFLAG_NODUMP       0x00000080
#define linux_FS_XFLAG_RTINHERIT    0x00000100
#define linux_FS_XFLAG_PROJINHERIT  0x00000200
#define linux_FS_XFLAG_NOSYMLINKS   0x00000400
#define linux_FS_XFLAG_EXTSIZE      0x00000800
#define linux_FS_XFLAG_EXTSZINHERIT 0x00001000
#define linux_FS_XFLAG_NODEFRAG     0x00002000
#define linux_FS_XFLAG_FILESTREAM   0x00004000
#define linux_FS_XFLAG_DAX          0x00008000
#define linux_FS_XFLAG_COWEXTSIZE   0x00010000
#define linux_FS_XFLAG_HASATTR      0x80000000

#define linux_BLKROSET         linux_IO(0x12,  93)
#define linux_BLKROGET         linux_IO(0x12,  94)
#define linux_BLKRRPART        linux_IO(0x12,  95)
#define linux_BLKGETSIZE       linux_IO(0x12,  96)
#define linux_BLKFLSBUF        linux_IO(0x12,  97)
#define linux_BLKRASET         linux_IO(0x12,  98)
#define linux_BLKRAGET         linux_IO(0x12,  99)
#define linux_BLKFRASET        linux_IO(0x12, 100)
#define linux_BLKFRAGET        linux_IO(0x12, 101)
#define linux_BLKSECTSET       linux_IO(0x12, 102)
#define linux_BLKSECTGET       linux_IO(0x12, 103)
#define linux_BLKSSZGET        linux_IO(0x12, 104)
// ...
// (105 to 111 are unused)
// ...
#define linux_BLKBSZGET        linux_IOR(0x12, 112, linux_size_t)
#define linux_BLKBSZSET        linux_IOW(0x12, 113, linux_size_t)
#define linux_BLKGETSIZE64     linux_IOR(0x12, 114, linux_size_t)
#define linux_BLKTRACESETUP    linux_IOWR(0x12, 115, struct linux_blk_user_trace_setup)
#define linux_BLKTRACESTART    linux_IO(0x12, 116)
#define linux_BLKTRACESTOP     linux_IO(0x12, 117)
#define linux_BLKTRACETEARDOWN linux_IO(0x12, 118)
#define linux_BLKDISCARD       linux_IO(0x12, 119)
#define linux_BLKIOMIN         linux_IO(0x12, 120)
#define linux_BLKIOOPT         linux_IO(0x12, 121)
#define linux_BLKALIGNOFF      linux_IO(0x12, 122)
#define linux_BLKPBSZGET       linux_IO(0x12, 123)
#define linux_BLKDISCARDZEROES linux_IO(0x12, 124)
#define linux_BLKSECDISCARD    linux_IO(0x12, 125)
#define linux_BLKROTATIONAL    linux_IO(0x12, 126)
#define linux_BLKZEROOUT       linux_IO(0x12, 127)

#define linux_BMAP_IOCTL    1
#define linux_FIBMAP        linux_IO(0x00, 1)
#define linux_FIGETBSZ      linux_IO(0x00, 2)
#define linux_FIFREEZE      linux_IOWR('X', 119, int)
#define linux_FITHAW        linux_IOWR('X', 120, int)
#define linux_FITRIM        linux_IOWR('X', 121, struct linux_fstrim_range)
#define linux_FICLONE       linux_IOW(0x94, 9, int)
#define linux_FICLONERANGE  linux_IOW(0x94, 13, struct linux_file_clone_range)
#define linux_FIDEDUPERANGE linux_IOWR(0x94, 54, struct linux_file_dedupe_range)

#define linux_FSLABEL_MAX 256

#define linux_FS_IOC_GETFLAGS     linux_IOR('f', 1, long)
#define linux_FS_IOC_SETFLAGS     linux_IOW('f', 2, long)
#define linux_FS_IOC_GETVERSION   linux_IOR('v', 1, long)
#define linux_FS_IOC_SETVERSION   linux_IOW('v', 2, long)
#define linux_FS_IOC_FIEMAP       linux_IOWR('f', 11, struct linux_fiemap)
#define linux_FS_IOC32_GETFLAGS   linux_IOR('f', 1, int)
#define linux_FS_IOC32_SETFLAGS   linux_IOW('f', 2, int)
#define linux_FS_IOC32_GETVERSION linux_IOR('v', 1, int)
#define linux_FS_IOC32_SETVERSION linux_IOW('v', 2, int)
#define linux_FS_IOC_FSGETXATTR   linux_IOR('X', 31, struct linux_fsxattr)
#define linux_FS_IOC_FSSETXATTR   linux_IOW('X', 32, struct linux_fsxattr)
#define linux_FS_IOC_GETFSLABEL   linux_IOR(0x94, 49, char[linux_FSLABEL_MAX])
#define linux_FS_IOC_SETFSLABEL   linux_IOW(0x94, 50, char[linux_FSLABEL_MAX])

#define linux_FS_SECRM_FL        0x00000001
#define linux_FS_UNRM_FL         0x00000002
#define linux_FS_COMPR_FL        0x00000004
#define linux_FS_SYNC_FL         0x00000008
#define linux_FS_IMMUTABLE_FL    0x00000010
#define linux_FS_APPEND_FL       0x00000020
#define linux_FS_NODUMP_FL       0x00000040
#define linux_FS_NOATIME_FL      0x00000080
#define linux_FS_DIRTY_FL        0x00000100
#define linux_FS_COMPRBLK_FL     0x00000200
#define linux_FS_NOCOMP_FL       0x00000400
#define linux_FS_ENCRYPT_FL      0x00000800
#define linux_FS_BTREE_FL        0x00001000
#define linux_FS_INDEX_FL        0x00001000
#define linux_FS_IMAGIC_FL       0x00002000
#define linux_FS_JOURNAL_DATA_FL 0x00004000
#define linux_FS_NOTAIL_FL       0x00008000
#define linux_FS_DIRSYNC_FL      0x00010000
#define linux_FS_TOPDIR_FL       0x00020000
#define linux_FS_HUGE_FILE_FL    0x00040000
#define linux_FS_EXTENT_FL       0x00080000
#define linux_FS_VERITY_FL       0x00100000
#define linux_FS_EA_INODE_FL     0x00200000
#define linux_FS_EOFBLOCKS_FL    0x00400000
#define linux_FS_NOCOW_FL        0x00800000
#define linux_FS_INLINE_DATA_FL  0x10000000
#define linux_FS_PROJINHERIT_FL  0x20000000
#define linux_FS_CASEFOLD_FL     0x40000000
#define linux_FS_RESERVED_FL     0x80000000

#define linux_FS_FL_USER_VISIBLE    0x0003DFFF
#define linux_FS_FL_USER_MODIFIABLE 0x000380FF

#define linux_SYNC_FILE_RANGE_WAIT_BEFORE    1
#define linux_SYNC_FILE_RANGE_WRITE          2
#define linux_SYNC_FILE_RANGE_WAIT_AFTER     4
#define linux_SYNC_FILE_RANGE_WRITE_AND_WAIT (linux_SYNC_FILE_RANGE_WRITE | linux_SYNC_FILE_RANGE_WAIT_BEFORE | linux_SYNC_FILE_RANGE_WAIT_AFTER)

// Used by linux_io_submit:
#define linux_RWF_HIPRI     ((linux_rwf_t)0x00000001)
#define linux_RWF_DSYNC     ((linux_rwf_t)0x00000002)
#define linux_RWF_SYNC      ((linux_rwf_t)0x00000004)
#define linux_RWF_NOWAIT    ((linux_rwf_t)0x00000008)
#define linux_RWF_APPEND    ((linux_rwf_t)0x00000010)
#define linux_RWF_SUPPORTED (linux_RWF_HIPRI | linux_RWF_DSYNC | linux_RWF_SYNC | linux_RWF_NOWAIT | linux_RWF_APPEND)

//=============================================================================
// io_uring

enum
{
	linux_IOSQE_FIXED_FILE_BIT,
	linux_IOSQE_IO_DRAIN_BIT,
	linux_IOSQE_IO_LINK_BIT,
	linux_IOSQE_IO_HARDLINK_BIT,
	linux_IOSQE_ASYNC_BIT,
	linux_IOSQE_BUFFER_SELECT_BIT,
};
#define linux_IOSQE_FIXED_FILE    (1U << linux_IOSQE_FIXED_FILE_BIT)
#define linux_IOSQE_IO_DRAIN      (1U << linux_IOSQE_IO_DRAIN_BIT)
#define linux_IOSQE_IO_LINK       (1U << linux_IOSQE_IO_LINK_BIT)
#define linux_IOSQE_IO_HARDLINK   (1U << linux_IOSQE_IO_HARDLINK_BIT)
#define linux_IOSQE_ASYNC         (1U << linux_IOSQE_ASYNC_BIT)
#define linux_IOSQE_BUFFER_SELECT (1U << linux_IOSQE_BUFFER_SELECT_BIT)

#define linux_IORING_SETUP_IOPOLL    (1U << 0)
#define linux_IORING_SETUP_SQPOLL    (1U << 1)
#define linux_IORING_SETUP_SQ_AFF    (1U << 2)
#define linux_IORING_SETUP_CQSIZE    (1U << 3)
#define linux_IORING_SETUP_CLAMP     (1U << 4)
#define linux_IORING_SETUP_ATTACH_WQ (1U << 5)

enum
{
	linux_IORING_OP_NOP,
	linux_IORING_OP_READV,
	linux_IORING_OP_WRITEV,
	linux_IORING_OP_FSYNC,
	linux_IORING_OP_READ_FIXED,
	linux_IORING_OP_WRITE_FIXED,
	linux_IORING_OP_POLL_ADD,
	linux_IORING_OP_POLL_REMOVE,
	linux_IORING_OP_SYNC_FILE_RANGE,
	linux_IORING_OP_SENDMSG,
	linux_IORING_OP_RECVMSG,
	linux_IORING_OP_TIMEOUT,
	linux_IORING_OP_TIMEOUT_REMOVE,
	linux_IORING_OP_ACCEPT,
	linux_IORING_OP_ASYNC_CANCEL,
	linux_IORING_OP_LINK_TIMEOUT,
	linux_IORING_OP_CONNECT,
	linux_IORING_OP_FALLOCATE,
	linux_IORING_OP_OPENAT,
	linux_IORING_OP_CLOSE,
	linux_IORING_OP_FILES_UPDATE,
	linux_IORING_OP_STATX,
	linux_IORING_OP_READ,
	linux_IORING_OP_WRITE,
	linux_IORING_OP_FADVISE,
	linux_IORING_OP_MADVISE,
	linux_IORING_OP_SEND,
	linux_IORING_OP_RECV,
	linux_IORING_OP_OPENAT2,
	linux_IORING_OP_EPOLL_CTL,
	linux_IORING_OP_SPLICE,
	linux_IORING_OP_PROVIDE_BUFFERS,
	linux_IORING_OP_REMOVE_BUFFERS,
	linux_IORING_OP_TEE,

	linux_IORING_OP_LAST,
};

#define linux_IORING_FSYNC_DATASYNC (1U << 0)

#define linux_IORING_TIMEOUT_ABS (1U << 0)

#define linux_SPLICE_F_FD_IN_FIXED (1U << 31)

#define linux_IORING_CQE_F_BUFFER (1U << 0)
enum
{
	linux_IORING_CQE_BUFFER_SHIFT = 16,
};

#define linux_IORING_OFF_SQ_RING 0ULL
#define linux_IORING_OFF_CQ_RING 0x8000000ULL
#define linux_IORING_OFF_SQES    0x10000000ULL

#define linux_IORING_SQ_NEED_WAKEUP (1U << 0)
#define linux_IORING_SQ_CQ_OVERFLOW (1U << 1)

#define linux_IORING_CQ_EVENTFD_DISABLED (1U << 0)

#define linux_IORING_ENTER_GETEVENTS (1U << 0)
#define linux_IORING_ENTER_SQ_WAKEUP (1U << 1)

#define linux_IORING_FEAT_SINGLE_MMAP     (1U << 0)
#define linux_IORING_FEAT_NODROP          (1U << 1)
#define linux_IORING_FEAT_SUBMIT_STABLE   (1U << 2)
#define linux_IORING_FEAT_RW_CUR_POS      (1U << 3)
#define linux_IORING_FEAT_CUR_PERSONALITY (1U << 4)
#define linux_IORING_FEAT_FAST_POLL       (1U << 5)

#define linux_IORING_REGISTER_BUFFERS        0
#define linux_IORING_UNREGISTER_BUFFERS      1
#define linux_IORING_REGISTER_FILES          2
#define linux_IORING_UNREGISTER_FILES        3
#define linux_IORING_REGISTER_EVENTFD        4
#define linux_IORING_UNREGISTER_EVENTFD      5
#define linux_IORING_REGISTER_FILES_UPDATE   6
#define linux_IORING_REGISTER_EVENTFD_ASYNC  7
#define linux_IORING_REGISTER_PROBE          8
#define linux_IORING_REGISTER_PERSONALITY    9
#define linux_IORING_UNREGISTER_PERSONALITY 10

#define linux_IO_URING_OP_SUPPORTED (1U << 0)

//=============================================================================
// Input event codes

#define linux_INPUT_PROP_POINTER        0x00
#define linux_INPUT_PROP_DIRECT         0x01
#define linux_INPUT_PROP_BUTTONPAD      0x02
#define linux_INPUT_PROP_SEMI_MT        0x03
#define linux_INPUT_PROP_TOPBUTTONPAD   0x04
#define linux_INPUT_PROP_POINTING_STICK 0x05
#define linux_INPUT_PROP_ACCELEROMETER  0x06

#define linux_INPUT_PROP_MAX 0x1f
#define linux_INPUT_PROP_CNT (linux_INPUT_PROP_MAX + 1)

#define linux_EV_SYN       0x00
#define linux_EV_KEY       0x01
#define linux_EV_REL       0x02
#define linux_EV_ABS       0x03
#define linux_EV_MSC       0x04
#define linux_EV_SW        0x05
#define linux_EV_LED       0x11
#define linux_EV_SND       0x12
#define linux_EV_REP       0x14
#define linux_EV_FF        0x15
#define linux_EV_PWR       0x16
#define linux_EV_FF_STATUS 0x17
#define linux_EV_MAX       0x1f
#define linux_EV_CNT       (linux_EV_MAX + 1)

#define linux_SYN_REPORT    0
#define linux_SYN_CONFIG    1
#define linux_SYN_MT_REPORT 2
#define linux_SYN_DROPPED   3
#define linux_SYN_MAX       0xf
#define linux_SYN_CNT       (linux_SYN_MAX + 1)

#define linux_KEY_RESERVED    0
#define linux_KEY_ESC         1
#define linux_KEY_1           2
#define linux_KEY_2           3
#define linux_KEY_3           4
#define linux_KEY_4           5
#define linux_KEY_5           6
#define linux_KEY_6           7
#define linux_KEY_7           8
#define linux_KEY_8           9
#define linux_KEY_9          10
#define linux_KEY_0          11
#define linux_KEY_MINUS      12
#define linux_KEY_EQUAL      13
#define linux_KEY_BACKSPACE  14
#define linux_KEY_TAB        15
#define linux_KEY_Q          16
#define linux_KEY_W          17
#define linux_KEY_E          18
#define linux_KEY_R          19
#define linux_KEY_T          20
#define linux_KEY_Y          21
#define linux_KEY_U          22
#define linux_KEY_I          23
#define linux_KEY_O          24
#define linux_KEY_P          25
#define linux_KEY_LEFTBRACE  26
#define linux_KEY_RIGHTBRACE 27
#define linux_KEY_ENTER      28
#define linux_KEY_LEFTCTRL   29
#define linux_KEY_A          30
#define linux_KEY_S          31
#define linux_KEY_D          32
#define linux_KEY_F          33
#define linux_KEY_G          34
#define linux_KEY_H          35
#define linux_KEY_J          36
#define linux_KEY_K          37
#define linux_KEY_L          38
#define linux_KEY_SEMICOLON  39
#define linux_KEY_APOSTROPHE 40
#define linux_KEY_GRAVE      41
#define linux_KEY_LEFTSHIFT  42
#define linux_KEY_BACKSLASH  43
#define linux_KEY_Z          44
#define linux_KEY_X          45
#define linux_KEY_C          46
#define linux_KEY_V          47
#define linux_KEY_B          48
#define linux_KEY_N          49
#define linux_KEY_M          50
#define linux_KEY_COMMA      51
#define linux_KEY_DOT        52
#define linux_KEY_SLASH      53
#define linux_KEY_RIGHTSHIFT 54
#define linux_KEY_KPASTERISK 55
#define linux_KEY_LEFTALT    56
#define linux_KEY_SPACE      57
#define linux_KEY_CAPSLOCK   58
#define linux_KEY_F1         59
#define linux_KEY_F2         60
#define linux_KEY_F3         61
#define linux_KEY_F4         62
#define linux_KEY_F5         63
#define linux_KEY_F6         64
#define linux_KEY_F7         65
#define linux_KEY_F8         66
#define linux_KEY_F9         67
#define linux_KEY_F10        68
#define linux_KEY_NUMLOCK    69
#define linux_KEY_SCROLLLOCK 70
#define linux_KEY_KP7        71
#define linux_KEY_KP8        72
#define linux_KEY_KP9        73
#define linux_KEY_KPMINUS    74
#define linux_KEY_KP4        75
#define linux_KEY_KP5        76
#define linux_KEY_KP6        77
#define linux_KEY_KPPLUS     78
#define linux_KEY_KP1        79
#define linux_KEY_KP2        80
#define linux_KEY_KP3        81
#define linux_KEY_KP0        82
#define linux_KEY_KPDOT      83

#define linux_KEY_ZENKAKUHANKAKU    85
#define linux_KEY_102ND             86
#define linux_KEY_F11               87
#define linux_KEY_F12               88
#define linux_KEY_RO                89
#define linux_KEY_KATAKANA          90
#define linux_KEY_HIRAGANA          91
#define linux_KEY_HENKAN            92
#define linux_KEY_KATAKANAHIRAGANA  93
#define linux_KEY_MUHENKAN          94
#define linux_KEY_KPJPCOMMA         95
#define linux_KEY_KPENTER           96
#define linux_KEY_RIGHTCTRL         97
#define linux_KEY_KPSLASH           98
#define linux_KEY_SYSRQ             99
#define linux_KEY_RIGHTALT         100
#define linux_KEY_LINEFEED         101
#define linux_KEY_HOME             102
#define linux_KEY_UP               103
#define linux_KEY_PAGEUP           104
#define linux_KEY_LEFT             105
#define linux_KEY_RIGHT            106
#define linux_KEY_END              107
#define linux_KEY_DOWN             108
#define linux_KEY_PAGEDOWN         109
#define linux_KEY_INSERT           110
#define linux_KEY_DELETE           111
#define linux_KEY_MACRO            112
#define linux_KEY_MUTE             113
#define linux_KEY_VOLUMEDOWN       114
#define linux_KEY_VOLUMEUP         115
#define linux_KEY_POWER            116
#define linux_KEY_KPEQUAL          117
#define linux_KEY_KPPLUSMINUS      118
#define linux_KEY_PAUSE            119
#define linux_KEY_SCALE            120

#define linux_KEY_KPCOMMA   121
#define linux_KEY_HANGEUL   122
#define linux_KEY_HANGUEL   linux_KEY_HANGEUL
#define linux_KEY_HANJA     123
#define linux_KEY_YEN       124
#define linux_KEY_LEFTMETA  125
#define linux_KEY_RIGHTMETA 126
#define linux_KEY_COMPOSE   127

#define linux_KEY_STOP           128
#define linux_KEY_AGAIN          129
#define linux_KEY_PROPS          130
#define linux_KEY_UNDO           131
#define linux_KEY_FRONT          132
#define linux_KEY_COPY           133
#define linux_KEY_OPEN           134
#define linux_KEY_PASTE          135
#define linux_KEY_FIND           136
#define linux_KEY_CUT            137
#define linux_KEY_HELP           138
#define linux_KEY_MENU           139
#define linux_KEY_CALC           140
#define linux_KEY_SETUP          141
#define linux_KEY_SLEEP          142
#define linux_KEY_WAKEUP         143
#define linux_KEY_FILE           144
#define linux_KEY_SENDFILE       145
#define linux_KEY_DELETEFILE     146
#define linux_KEY_XFER           147
#define linux_KEY_PROG1          148
#define linux_KEY_PROG2          149
#define linux_KEY_WWW            150
#define linux_KEY_MSDOS          151
#define linux_KEY_COFFEE         152
#define linux_KEY_SCREENLOCK     linux_KEY_COFFEE
#define linux_KEY_ROTATE_DISPLAY 153
#define linux_KEY_DIRECTION      linux_KEY_ROTATE_DISPLAY
#define linux_KEY_CYCLEWINDOWS   154
#define linux_KEY_MAIL           155
#define linux_KEY_BOOKMARKS      156
#define linux_KEY_COMPUTER       157
#define linux_KEY_BACK           158
#define linux_KEY_FORWARD        159
#define linux_KEY_CLOSECD        160
#define linux_KEY_EJECTCD        161
#define linux_KEY_EJECTCLOSECD   162
#define linux_KEY_NEXTSONG       163
#define linux_KEY_PLAYPAUSE      164
#define linux_KEY_PREVIOUSSONG   165
#define linux_KEY_STOPCD         166
#define linux_KEY_RECORD         167
#define linux_KEY_REWIND         168
#define linux_KEY_PHONE          169
#define linux_KEY_ISO            170
#define linux_KEY_CONFIG         171
#define linux_KEY_HOMEPAGE       172
#define linux_KEY_REFRESH        173
#define linux_KEY_EXIT           174
#define linux_KEY_MOVE           175
#define linux_KEY_EDIT           176
#define linux_KEY_SCROLLUP       177
#define linux_KEY_SCROLLDOWN     178
#define linux_KEY_KPLEFTPAREN    179
#define linux_KEY_KPRIGHTPAREN   180
#define linux_KEY_NEW            181
#define linux_KEY_REDO           182

#define linux_KEY_F13 183
#define linux_KEY_F14 184
#define linux_KEY_F15 185
#define linux_KEY_F16 186
#define linux_KEY_F17 187
#define linux_KEY_F18 188
#define linux_KEY_F19 189
#define linux_KEY_F20 190
#define linux_KEY_F21 191
#define linux_KEY_F22 192
#define linux_KEY_F23 193
#define linux_KEY_F24 194

#define linux_KEY_PLAYCD         200
#define linux_KEY_PAUSECD        201
#define linux_KEY_PROG3          202
#define linux_KEY_PROG4          203
#define linux_KEY_DASHBOARD      204
#define linux_KEY_SUSPEND        205
#define linux_KEY_CLOSE          206
#define linux_KEY_PLAY           207
#define linux_KEY_FASTFORWARD    208
#define linux_KEY_BASSBOOST      209
#define linux_KEY_PRINT          210
#define linux_KEY_HP             211
#define linux_KEY_CAMERA         212
#define linux_KEY_SOUND          213
#define linux_KEY_QUESTION       214
#define linux_KEY_EMAIL          215
#define linux_KEY_CHAT           216
#define linux_KEY_SEARCH         217
#define linux_KEY_CONNECT        218
#define linux_KEY_FINANCE        219
#define linux_KEY_SPORT          220
#define linux_KEY_SHOP           221
#define linux_KEY_ALTERASE       222
#define linux_KEY_CANCEL         223
#define linux_KEY_BRIGHTNESSDOWN 224
#define linux_KEY_BRIGHTNESSUP   225
#define linux_KEY_MEDIA          226

#define linux_KEY_SWITCHVIDEOMODE 227
#define linux_KEY_KBDILLUMTOGGLE  228
#define linux_KEY_KBDILLUMDOWN    229
#define linux_KEY_KBDILLUMUP      230

#define linux_KEY_SEND        231
#define linux_KEY_REPLY       232
#define linux_KEY_FORWARDMAIL 233
#define linux_KEY_SAVE        234
#define linux_KEY_DOCUMENTS   235

#define linux_KEY_BATTERY 236

#define linux_KEY_BLUETOOTH 237
#define linux_KEY_WLAN      238
#define linux_KEY_UWB       239

#define linux_KEY_UNKNOWN 240

#define linux_KEY_VIDEO_NEXT       241
#define linux_KEY_VIDEO_PREV       242
#define linux_KEY_BRIGHTNESS_CYCLE 243
#define linux_KEY_BRIGHTNESS_AUTO  244
#define linux_KEY_BRIGHTNESS_ZERO  linux_KEY_BRIGHTNESS_AUTO
#define linux_KEY_DISPLAY_OFF      245

#define linux_KEY_WWAN   246
#define linux_KEY_WIMAX  linux_KEY_WWAN
#define linux_KEY_RFKILL 247

#define linux_KEY_MICMUTE 248

#define linux_BTN_MISC 0x100
#define linux_BTN_0    0x100
#define linux_BTN_1    0x101
#define linux_BTN_2    0x102
#define linux_BTN_3    0x103
#define linux_BTN_4    0x104
#define linux_BTN_5    0x105
#define linux_BTN_6    0x106
#define linux_BTN_7    0x107
#define linux_BTN_8    0x108
#define linux_BTN_9    0x109

#define linux_BTN_MOUSE   0x110
#define linux_BTN_LEFT    0x110
#define linux_BTN_RIGHT   0x111
#define linux_BTN_MIDDLE  0x112
#define linux_BTN_SIDE    0x113
#define linux_BTN_EXTRA   0x114
#define linux_BTN_FORWARD 0x115
#define linux_BTN_BACK    0x116
#define linux_BTN_TASK    0x117

#define linux_BTN_JOYSTICK 0x120
#define linux_BTN_TRIGGER  0x120
#define linux_BTN_THUMB    0x121
#define linux_BTN_THUMB2   0x122
#define linux_BTN_TOP      0x123
#define linux_BTN_TOP2     0x124
#define linux_BTN_PINKIE   0x125
#define linux_BTN_BASE     0x126
#define linux_BTN_BASE2    0x127
#define linux_BTN_BASE3    0x128
#define linux_BTN_BASE4    0x129
#define linux_BTN_BASE5    0x12a
#define linux_BTN_BASE6    0x12b
#define linux_BTN_DEAD     0x12f

#define linux_BTN_GAMEPAD 0x130
#define linux_BTN_SOUTH   0x130
#define linux_BTN_A       linux_BTN_SOUTH
#define linux_BTN_EAST    0x131
#define linux_BTN_B       linux_BTN_EAST
#define linux_BTN_C       0x132
#define linux_BTN_NORTH   0x133
#define linux_BTN_X       linux_BTN_NORTH
#define linux_BTN_WEST    0x134
#define linux_BTN_Y       linux_BTN_WEST
#define linux_BTN_Z       0x135
#define linux_BTN_TL      0x136
#define linux_BTN_TR      0x137
#define linux_BTN_TL2     0x138
#define linux_BTN_TR2     0x139
#define linux_BTN_SELECT  0x13a
#define linux_BTN_START   0x13b
#define linux_BTN_MODE    0x13c
#define linux_BTN_THUMBL  0x13d
#define linux_BTN_THUMBR  0x13e

#define linux_BTN_DIGI           0x140
#define linux_BTN_TOOL_PEN       0x140
#define linux_BTN_TOOL_RUBBER    0x141
#define linux_BTN_TOOL_BRUSH     0x142
#define linux_BTN_TOOL_PENCIL    0x143
#define linux_BTN_TOOL_AIRBRUSH  0x144
#define linux_BTN_TOOL_FINGER    0x145
#define linux_BTN_TOOL_MOUSE     0x146
#define linux_BTN_TOOL_LENS      0x147
#define linux_BTN_TOOL_QUINTTAP  0x148
#define linux_BTN_STYLUS3        0x149
#define linux_BTN_TOUCH          0x14a
#define linux_BTN_STYLUS         0x14b
#define linux_BTN_STYLUS2        0x14c
#define linux_BTN_TOOL_DOUBLETAP 0x14d
#define linux_BTN_TOOL_TRIPLETAP 0x14e
#define linux_BTN_TOOL_QUADTAP   0x14f

#define linux_BTN_WHEEL     0x150
#define linux_BTN_GEAR_DOWN 0x150
#define linux_BTN_GEAR_UP   0x151

#define linux_KEY_OK                0x160
#define linux_KEY_SELECT            0x161
#define linux_KEY_GOTO              0x162
#define linux_KEY_CLEAR             0x163
#define linux_KEY_POWER2            0x164
#define linux_KEY_OPTION            0x165
#define linux_KEY_INFO              0x166
#define linux_KEY_TIME              0x167
#define linux_KEY_VENDOR            0x168
#define linux_KEY_ARCHIVE           0x169
#define linux_KEY_PROGRAM           0x16a
#define linux_KEY_CHANNEL           0x16b
#define linux_KEY_FAVORITES         0x16c
#define linux_KEY_EPG               0x16d
#define linux_KEY_PVR               0x16e
#define linux_KEY_MHP               0x16f
#define linux_KEY_LANGUAGE          0x170
#define linux_KEY_TITLE             0x171
#define linux_KEY_SUBTITLE          0x172
#define linux_KEY_ANGLE             0x173
#define linux_KEY_FULL_SCREEN       0x174
#define linux_KEY_ZOOM              linux_KEY_FULL_SCREEN
#define linux_KEY_MODE              0x175
#define linux_KEY_KEYBOARD          0x176
#define linux_KEY_ASPECT_RATIO      0x177
#define linux_KEY_SCREEN            linux_KEY_ASPECT_RATIO
#define linux_KEY_PC                0x178
#define linux_KEY_TV                0x179
#define linux_KEY_TV2               0x17a
#define linux_KEY_VCR               0x17b
#define linux_KEY_VCR2              0x17c
#define linux_KEY_SAT               0x17d
#define linux_KEY_SAT2              0x17e
#define linux_KEY_CD                0x17f
#define linux_KEY_TAPE              0x180
#define linux_KEY_RADIO             0x181
#define linux_KEY_TUNER             0x182
#define linux_KEY_PLAYER            0x183
#define linux_KEY_TEXT              0x184
#define linux_KEY_DVD               0x185
#define linux_KEY_AUX               0x186
#define linux_KEY_MP3               0x187
#define linux_KEY_AUDIO             0x188
#define linux_KEY_VIDEO             0x189
#define linux_KEY_DIRECTORY         0x18a
#define linux_KEY_LIST              0x18b
#define linux_KEY_MEMO              0x18c
#define linux_KEY_CALENDAR          0x18d
#define linux_KEY_RED               0x18e
#define linux_KEY_GREEN             0x18f
#define linux_KEY_YELLOW            0x190
#define linux_KEY_BLUE              0x191
#define linux_KEY_CHANNELUP         0x192
#define linux_KEY_CHANNELDOWN       0x193
#define linux_KEY_FIRST             0x194
#define linux_KEY_LAST              0x195
#define linux_KEY_AB                0x196
#define linux_KEY_NEXT              0x197
#define linux_KEY_RESTART           0x198
#define linux_KEY_SLOW              0x199
#define linux_KEY_SHUFFLE           0x19a
#define linux_KEY_BREAK             0x19b
#define linux_KEY_PREVIOUS          0x19c
#define linux_KEY_DIGITS            0x19d
#define linux_KEY_TEEN              0x19e
#define linux_KEY_TWEN              0x19f
#define linux_KEY_VIDEOPHONE        0x1a0
#define linux_KEY_GAMES             0x1a1
#define linux_KEY_ZOOMIN            0x1a2
#define linux_KEY_ZOOMOUT           0x1a3
#define linux_KEY_ZOOMRESET         0x1a4
#define linux_KEY_WORDPROCESSOR     0x1a5
#define linux_KEY_EDITOR            0x1a6
#define linux_KEY_SPREADSHEET       0x1a7
#define linux_KEY_GRAPHICSEDITOR    0x1a8
#define linux_KEY_PRESENTATION      0x1a9
#define linux_KEY_DATABASE          0x1aa
#define linux_KEY_NEWS              0x1ab
#define linux_KEY_VOICEMAIL         0x1ac
#define linux_KEY_ADDRESSBOOK       0x1ad
#define linux_KEY_MESSENGER         0x1ae
#define linux_KEY_DISPLAYTOGGLE     0x1af
#define linux_KEY_BRIGHTNESS_TOGGLE linux_KEY_DISPLAYTOGGLE
#define linux_KEY_SPELLCHECK        0x1b0
#define linux_KEY_LOGOFF            0x1b1

#define linux_KEY_DOLLAR 0x1b2
#define linux_KEY_EURO   0x1b3

#define linux_KEY_FRAMEBACK      0x1b4
#define linux_KEY_FRAMEFORWARD   0x1b5
#define linux_KEY_CONTEXT_MENU   0x1b6
#define linux_KEY_MEDIA_REPEAT   0x1b7
#define linux_KEY_10CHANNELSUP   0x1b8
#define linux_KEY_10CHANNELSDOWN 0x1b9
#define linux_KEY_IMAGES         0x1ba

#define linux_KEY_DEL_EOL  0x1c0
#define linux_KEY_DEL_EOS  0x1c1
#define linux_KEY_INS_LINE 0x1c2
#define linux_KEY_DEL_LINE 0x1c3

#define linux_KEY_FN     0x1d0
#define linux_KEY_FN_ESC 0x1d1
#define linux_KEY_FN_F1  0x1d2
#define linux_KEY_FN_F2  0x1d3
#define linux_KEY_FN_F3  0x1d4
#define linux_KEY_FN_F4  0x1d5
#define linux_KEY_FN_F5  0x1d6
#define linux_KEY_FN_F6  0x1d7
#define linux_KEY_FN_F7  0x1d8
#define linux_KEY_FN_F8  0x1d9
#define linux_KEY_FN_F9  0x1da
#define linux_KEY_FN_F10 0x1db
#define linux_KEY_FN_F11 0x1dc
#define linux_KEY_FN_F12 0x1dd
#define linux_KEY_FN_1   0x1de
#define linux_KEY_FN_2   0x1df
#define linux_KEY_FN_D   0x1e0
#define linux_KEY_FN_E   0x1e1
#define linux_KEY_FN_F   0x1e2
#define linux_KEY_FN_S   0x1e3
#define linux_KEY_FN_B   0x1e4

#define linux_KEY_BRL_DOT1  0x1f1
#define linux_KEY_BRL_DOT2  0x1f2
#define linux_KEY_BRL_DOT3  0x1f3
#define linux_KEY_BRL_DOT4  0x1f4
#define linux_KEY_BRL_DOT5  0x1f5
#define linux_KEY_BRL_DOT6  0x1f6
#define linux_KEY_BRL_DOT7  0x1f7
#define linux_KEY_BRL_DOT8  0x1f8
#define linux_KEY_BRL_DOT9  0x1f9
#define linux_KEY_BRL_DOT10 0x1fa

#define linux_KEY_NUMERIC_0     0x200
#define linux_KEY_NUMERIC_1     0x201
#define linux_KEY_NUMERIC_2     0x202
#define linux_KEY_NUMERIC_3     0x203
#define linux_KEY_NUMERIC_4     0x204
#define linux_KEY_NUMERIC_5     0x205
#define linux_KEY_NUMERIC_6     0x206
#define linux_KEY_NUMERIC_7     0x207
#define linux_KEY_NUMERIC_8     0x208
#define linux_KEY_NUMERIC_9     0x209
#define linux_KEY_NUMERIC_STAR  0x20a
#define linux_KEY_NUMERIC_POUND 0x20b
#define linux_KEY_NUMERIC_A     0x20c
#define linux_KEY_NUMERIC_B     0x20d
#define linux_KEY_NUMERIC_C     0x20e
#define linux_KEY_NUMERIC_D     0x20f

#define linux_KEY_CAMERA_FOCUS 0x210
#define linux_KEY_WPS_BUTTON   0x211

#define linux_KEY_TOUCHPAD_TOGGLE 0x212
#define linux_KEY_TOUCHPAD_ON     0x213
#define linux_KEY_TOUCHPAD_OFF    0x214

#define linux_KEY_CAMERA_ZOOMIN  0x215
#define linux_KEY_CAMERA_ZOOMOUT 0x216
#define linux_KEY_CAMERA_UP      0x217
#define linux_KEY_CAMERA_DOWN    0x218
#define linux_KEY_CAMERA_LEFT    0x219
#define linux_KEY_CAMERA_RIGHT   0x21a

#define linux_KEY_ATTENDANT_ON     0x21b
#define linux_KEY_ATTENDANT_OFF    0x21c
#define linux_KEY_ATTENDANT_TOGGLE 0x21d
#define linux_KEY_LIGHTS_TOGGLE    0x21e

#define linux_BTN_DPAD_UP    0x220
#define linux_BTN_DPAD_DOWN  0x221
#define linux_BTN_DPAD_LEFT  0x222
#define linux_BTN_DPAD_RIGHT 0x223

#define linux_KEY_ALS_TOGGLE         0x230
#define linux_KEY_ROTATE_LOCK_TOGGLE 0x231

#define linux_KEY_BUTTONCONFIG    0x240
#define linux_KEY_TASKMANAGER     0x241
#define linux_KEY_JOURNAL         0x242
#define linux_KEY_CONTROLPANEL    0x243
#define linux_KEY_APPSELECT       0x244
#define linux_KEY_SCREENSAVER     0x245
#define linux_KEY_VOICECOMMAND    0x246
#define linux_KEY_ASSISTANT       0x247
#define linux_KEY_KBD_LAYOUT_NEXT 0x248

#define linux_KEY_BRIGHTNESS_MIN 0x250
#define linux_KEY_BRIGHTNESS_MAX 0x251

#define linux_KEY_KBDINPUTASSIST_PREV      0x260
#define linux_KEY_KBDINPUTASSIST_NEXT      0x261
#define linux_KEY_KBDINPUTASSIST_PREVGROUP 0x262
#define linux_KEY_KBDINPUTASSIST_NEXTGROUP 0x263
#define linux_KEY_KBDINPUTASSIST_ACCEPT    0x264
#define linux_KEY_KBDINPUTASSIST_CANCEL    0x265

#define linux_KEY_RIGHT_UP   0x266
#define linux_KEY_RIGHT_DOWN 0x267
#define linux_KEY_LEFT_UP    0x268
#define linux_KEY_LEFT_DOWN  0x269

#define linux_KEY_ROOT_MENU             0x26a
#define linux_KEY_MEDIA_TOP_MENU        0x26b
#define linux_KEY_NUMERIC_11            0x26c
#define linux_KEY_NUMERIC_12            0x26d
#define linux_KEY_AUDIO_DESC            0x26e
#define linux_KEY_3D_MODE               0x26f
#define linux_KEY_NEXT_FAVORITE         0x270
#define linux_KEY_STOP_RECORD           0x271
#define linux_KEY_PAUSE_RECORD          0x272
#define linux_KEY_VOD                   0x273
#define linux_KEY_UNMUTE                0x274
#define linux_KEY_FASTREVERSE           0x275
#define linux_KEY_SLOWREVERSE           0x276
#define linux_KEY_DATA                  0x277
#define linux_KEY_ONSCREEN_KEYBOARD     0x278
#define linux_KEY_PRIVACY_SCREEN_TOGGLE 0x279

#define linux_KEY_MACRO1  0x290
#define linux_KEY_MACRO2  0x291
#define linux_KEY_MACRO3  0x292
#define linux_KEY_MACRO4  0x293
#define linux_KEY_MACRO5  0x294
#define linux_KEY_MACRO6  0x295
#define linux_KEY_MACRO7  0x296
#define linux_KEY_MACRO8  0x297
#define linux_KEY_MACRO9  0x298
#define linux_KEY_MACRO10 0x299
#define linux_KEY_MACRO11 0x29a
#define linux_KEY_MACRO12 0x29b
#define linux_KEY_MACRO13 0x29c
#define linux_KEY_MACRO14 0x29d
#define linux_KEY_MACRO15 0x29e
#define linux_KEY_MACRO16 0x29f
#define linux_KEY_MACRO17 0x2a0
#define linux_KEY_MACRO18 0x2a1
#define linux_KEY_MACRO19 0x2a2
#define linux_KEY_MACRO20 0x2a3
#define linux_KEY_MACRO21 0x2a4
#define linux_KEY_MACRO22 0x2a5
#define linux_KEY_MACRO23 0x2a6
#define linux_KEY_MACRO24 0x2a7
#define linux_KEY_MACRO25 0x2a8
#define linux_KEY_MACRO26 0x2a9
#define linux_KEY_MACRO27 0x2aa
#define linux_KEY_MACRO28 0x2ab
#define linux_KEY_MACRO29 0x2ac
#define linux_KEY_MACRO30 0x2ad

#define linux_KEY_MACRO_RECORD_START 0x2b0
#define linux_KEY_MACRO_RECORD_STOP  0x2b1
#define linux_KEY_MACRO_PRESET_CYCLE 0x2b2
#define linux_KEY_MACRO_PRESET1      0x2b3
#define linux_KEY_MACRO_PRESET2      0x2b4
#define linux_KEY_MACRO_PRESET3      0x2b5

#define linux_KEY_KBD_LCD_MENU1 0x2b8
#define linux_KEY_KBD_LCD_MENU2 0x2b9
#define linux_KEY_KBD_LCD_MENU3 0x2ba
#define linux_KEY_KBD_LCD_MENU4 0x2bb
#define linux_KEY_KBD_LCD_MENU5 0x2bc

#define linux_BTN_TRIGGER_HAPPY   0x2c0
#define linux_BTN_TRIGGER_HAPPY1  0x2c0
#define linux_BTN_TRIGGER_HAPPY2  0x2c1
#define linux_BTN_TRIGGER_HAPPY3  0x2c2
#define linux_BTN_TRIGGER_HAPPY4  0x2c3
#define linux_BTN_TRIGGER_HAPPY5  0x2c4
#define linux_BTN_TRIGGER_HAPPY6  0x2c5
#define linux_BTN_TRIGGER_HAPPY7  0x2c6
#define linux_BTN_TRIGGER_HAPPY8  0x2c7
#define linux_BTN_TRIGGER_HAPPY9  0x2c8
#define linux_BTN_TRIGGER_HAPPY10 0x2c9
#define linux_BTN_TRIGGER_HAPPY11 0x2ca
#define linux_BTN_TRIGGER_HAPPY12 0x2cb
#define linux_BTN_TRIGGER_HAPPY13 0x2cc
#define linux_BTN_TRIGGER_HAPPY14 0x2cd
#define linux_BTN_TRIGGER_HAPPY15 0x2ce
#define linux_BTN_TRIGGER_HAPPY16 0x2cf
#define linux_BTN_TRIGGER_HAPPY17 0x2d0
#define linux_BTN_TRIGGER_HAPPY18 0x2d1
#define linux_BTN_TRIGGER_HAPPY19 0x2d2
#define linux_BTN_TRIGGER_HAPPY20 0x2d3
#define linux_BTN_TRIGGER_HAPPY21 0x2d4
#define linux_BTN_TRIGGER_HAPPY22 0x2d5
#define linux_BTN_TRIGGER_HAPPY23 0x2d6
#define linux_BTN_TRIGGER_HAPPY24 0x2d7
#define linux_BTN_TRIGGER_HAPPY25 0x2d8
#define linux_BTN_TRIGGER_HAPPY26 0x2d9
#define linux_BTN_TRIGGER_HAPPY27 0x2da
#define linux_BTN_TRIGGER_HAPPY28 0x2db
#define linux_BTN_TRIGGER_HAPPY29 0x2dc
#define linux_BTN_TRIGGER_HAPPY30 0x2dd
#define linux_BTN_TRIGGER_HAPPY31 0x2de
#define linux_BTN_TRIGGER_HAPPY32 0x2df
#define linux_BTN_TRIGGER_HAPPY33 0x2e0
#define linux_BTN_TRIGGER_HAPPY34 0x2e1
#define linux_BTN_TRIGGER_HAPPY35 0x2e2
#define linux_BTN_TRIGGER_HAPPY36 0x2e3
#define linux_BTN_TRIGGER_HAPPY37 0x2e4
#define linux_BTN_TRIGGER_HAPPY38 0x2e5
#define linux_BTN_TRIGGER_HAPPY39 0x2e6
#define linux_BTN_TRIGGER_HAPPY40 0x2e7

#define linux_KEY_MIN_INTERESTING linux_KEY_MUTE
#define linux_KEY_MAX             0x2ff
#define linux_KEY_CNT             (linux_KEY_MAX + 1)

#define linux_REL_X             0x00
#define linux_REL_Y             0x01
#define linux_REL_Z             0x02
#define linux_REL_RX            0x03
#define linux_REL_RY            0x04
#define linux_REL_RZ            0x05
#define linux_REL_HWHEEL        0x06
#define linux_REL_DIAL          0x07
#define linux_REL_WHEEL         0x08
#define linux_REL_MISC          0x09
#define linux_REL_RESERVED      0x0a
#define linux_REL_WHEEL_HI_RES  0x0b
#define linux_REL_HWHEEL_HI_RES 0x0c
#define linux_REL_MAX           0x0f
#define linux_REL_CNT           (linux_REL_MAX + 1)

#define linux_ABS_X          0x00
#define linux_ABS_Y          0x01
#define linux_ABS_Z          0x02
#define linux_ABS_RX         0x03
#define linux_ABS_RY         0x04
#define linux_ABS_RZ         0x05
#define linux_ABS_THROTTLE   0x06
#define linux_ABS_RUDDER     0x07
#define linux_ABS_WHEEL      0x08
#define linux_ABS_GAS        0x09
#define linux_ABS_BRAKE      0x0a
#define linux_ABS_HAT0X      0x10
#define linux_ABS_HAT0Y      0x11
#define linux_ABS_HAT1X      0x12
#define linux_ABS_HAT1Y      0x13
#define linux_ABS_HAT2X      0x14
#define linux_ABS_HAT2Y      0x15
#define linux_ABS_HAT3X      0x16
#define linux_ABS_HAT3Y      0x17
#define linux_ABS_PRESSURE   0x18
#define linux_ABS_DISTANCE   0x19
#define linux_ABS_TILT_X     0x1a
#define linux_ABS_TILT_Y     0x1b
#define linux_ABS_TOOL_WIDTH 0x1c

#define linux_ABS_VOLUME 0x20

#define linux_ABS_MISC 0x28

#define linux_ABS_RESERVED 0x2e

#define linux_ABS_MT_SLOT        0x2f
#define linux_ABS_MT_TOUCH_MAJOR 0x30
#define linux_ABS_MT_TOUCH_MINOR 0x31
#define linux_ABS_MT_WIDTH_MAJOR 0x32
#define linux_ABS_MT_WIDTH_MINOR 0x33
#define linux_ABS_MT_ORIENTATION 0x34
#define linux_ABS_MT_POSITION_X  0x35
#define linux_ABS_MT_POSITION_Y  0x36
#define linux_ABS_MT_TOOL_TYPE   0x37
#define linux_ABS_MT_BLOB_ID     0x38
#define linux_ABS_MT_TRACKING_ID 0x39
#define linux_ABS_MT_PRESSURE    0x3a
#define linux_ABS_MT_DISTANCE    0x3b
#define linux_ABS_MT_TOOL_X      0x3c
#define linux_ABS_MT_TOOL_Y      0x3d

#define linux_ABS_MAX 0x3f
#define linux_ABS_CNT (linux_ABS_MAX + 1)

#define linux_SW_LID                  0x00
#define linux_SW_TABLET_MODE          0x01
#define linux_SW_HEADPHONE_INSERT     0x02
#define linux_SW_RFKILL_ALL           0x03
#define linux_SW_RADIO                linux_SW_RFKILL_ALL
#define linux_SW_MICROPHONE_INSERT    0x04
#define linux_SW_DOCK                 0x05
#define linux_SW_LINEOUT_INSERT       0x06
#define linux_SW_JACK_PHYSICAL_INSERT 0x07
#define linux_SW_VIDEOOUT_INSERT      0x08
#define linux_SW_CAMERA_LENS_COVER    0x09
#define linux_SW_KEYPAD_SLIDE         0x0a
#define linux_SW_FRONT_PROXIMITY      0x0b
#define linux_SW_ROTATE_LOCK          0x0c
#define linux_SW_LINEIN_INSERT        0x0d
#define linux_SW_MUTE_DEVICE          0x0e
#define linux_SW_PEN_INSERTED         0x0f
#define linux_SW_MAX                  0x0f
#define linux_SW_CNT                  (linux_SW_MAX + 1)

#define linux_MSC_SERIAL    0x00
#define linux_MSC_PULSELED  0x01
#define linux_MSC_GESTURE   0x02
#define linux_MSC_RAW       0x03
#define linux_MSC_SCAN      0x04
#define linux_MSC_TIMESTAMP 0x05
#define linux_MSC_MAX       0x07
#define linux_MSC_CNT       (linux_MSC_MAX + 1)

#define linux_LED_NUML     0x00
#define linux_LED_CAPSL    0x01
#define linux_LED_SCROLLL  0x02
#define linux_LED_COMPOSE  0x03
#define linux_LED_KANA     0x04
#define linux_LED_SLEEP    0x05
#define linux_LED_SUSPEND  0x06
#define linux_LED_MUTE     0x07
#define linux_LED_MISC     0x08
#define linux_LED_MAIL     0x09
#define linux_LED_CHARGING 0x0a
#define linux_LED_MAX      0x0f
#define linux_LED_CNT      (linux_LED_MAX + 1)

#define linux_REP_DELAY  0x00
#define linux_REP_PERIOD 0x01
#define linux_REP_MAX    0x01
#define linux_REP_CNT    (linux_REP_MAX + 1)

#define linux_SND_CLICK 0x00
#define linux_SND_BELL  0x01
#define linux_SND_TONE  0x02
#define linux_SND_MAX   0x07
#define linux_SND_CNT   (linux_SND_MAX + 1)

//=============================================================================
// evdev

#define linux_EV_VERSION 0x010001

#define linux_INPUT_KEYMAP_BY_INDEX (1 << 0)

#define linux_EVIOCGVERSION linux_IOR('E', 0x01, int)
#define linux_EVIOCGID      linux_IOR('E', 0x02, struct linux_input_id)
#define linux_EVIOCGREP     linux_IOR('E', 0x03, unsigned int[2])
#define linux_EVIOCSREP     linux_IOW('E', 0x03, unsigned int[2])

#define linux_EVIOCGKEYCODE    linux_IOR('E', 0x04, unsigned int[2])
#define linux_EVIOCGKEYCODE_V2 linux_IOR('E', 0x04, struct linux_input_keymap_entry)
#define linux_EVIOCSKEYCODE    linux_IOW('E', 0x04, unsigned int[2])
#define linux_EVIOCSKEYCODE_V2 linux_IOW('E', 0x04, struct linux_input_keymap_entry)

#define linux_EVIOCGNAME(len) linux_IOC(linux_IOC_READ, 'E', 0x06, len)
#define linux_EVIOCGPHYS(len) linux_IOC(linux_IOC_READ, 'E', 0x07, len)
#define linux_EVIOCGUNIQ(len) linux_IOC(linux_IOC_READ, 'E', 0x08, len)
#define linux_EVIOCGPROP(len) linux_IOC(linux_IOC_READ, 'E', 0x09, len)

#define linux_EVIOCGMTSLOTS(len) linux_IOC(linux_IOC_READ, 'E', 0x0a, len)

#define linux_EVIOCGKEY(len) linux_IOC(linux_IOC_READ, 'E', 0x18, len)
#define linux_EVIOCGLED(len) linux_IOC(linux_IOC_READ, 'E', 0x19, len)
#define linux_EVIOCGSND(len) linux_IOC(linux_IOC_READ, 'E', 0x1a, len)
#define linux_EVIOCGSW(len)  linux_IOC(linux_IOC_READ, 'E', 0x1b, len)

#define linux_EVIOCGBIT(ev,len) linux_IOC(linux_IOC_READ, 'E', 0x20 + (ev), len)
#define linux_EVIOCGABS(abs)    linux_IOR('E', 0x40 + (abs), struct linux_input_absinfo)
#define linux_EVIOCSABS(abs)    linux_IOW('E', 0xc0 + (abs), struct linux_input_absinfo)

#define linux_EVIOCSFF      linux_IOW('E', 0x80, struct linux_ff_effect)
#define linux_EVIOCRMFF     linux_IOW('E', 0x81, int)
#define linux_EVIOCGEFFECTS linux_IOR('E', 0x84, int)

#define linux_EVIOCGRAB   linux_IOW('E', 0x90, int)
#define linux_EVIOCREVOKE linux_IOW('E', 0x91, int)
#define linux_EVIOCGMASK  linux_IOR('E', 0x92, struct linux_input_mask)
#define linux_EVIOCSMASK  linux_IOW('E', 0x93, struct linux_input_mask)

#define linux_EVIOCSCLOCKID linux_IOW('E', 0xa0, int)

#define linux_ID_BUS     0
#define linux_ID_VENDOR  1
#define linux_ID_PRODUCT 2
#define linux_ID_VERSION 3

#define linux_BUS_PCI       0x01
#define linux_BUS_ISAPNP    0x02
#define linux_BUS_USB       0x03
#define linux_BUS_HIL       0x04
#define linux_BUS_BLUETOOTH 0x05
#define linux_BUS_VIRTUAL   0x06

#define linux_BUS_ISA         0x10
#define linux_BUS_I8042       0x11
#define linux_BUS_XTKBD       0x12
#define linux_BUS_RS232       0x13
#define linux_BUS_GAMEPORT    0x14
#define linux_BUS_PARPORT     0x15
#define linux_BUS_AMIGA       0x16
#define linux_BUS_ADB         0x17
#define linux_BUS_I2C         0x18
#define linux_BUS_HOST        0x19
#define linux_BUS_GSC         0x1A
#define linux_BUS_ATARI       0x1B
#define linux_BUS_SPI         0x1C
#define linux_BUS_RMI         0x1D
#define linux_BUS_CEC         0x1E
#define linux_BUS_INTEL_ISHTP 0x1F

#define linux_MT_TOOL_FINGER 0x00
#define linux_MT_TOOL_PEN    0x01
#define linux_MT_TOOL_PALM   0x02
#define linux_MT_TOOL_DIAL   0x0a
#define linux_MT_TOOL_MAX    0x0f

#define linux_FF_STATUS_STOPPED 0x00
#define linux_FF_STATUS_PLAYING 0x01
#define linux_FF_STATUS_MAX     0x01

#define linux_FF_RUMBLE   0x50
#define linux_FF_PERIODIC 0x51
#define linux_FF_CONSTANT 0x52
#define linux_FF_SPRING   0x53
#define linux_FF_FRICTION 0x54
#define linux_FF_DAMPER   0x55
#define linux_FF_INERTIA  0x56
#define linux_FF_RAMP     0x57

#define linux_FF_EFFECT_MIN linux_FF_RUMBLE
#define linux_FF_EFFECT_MAX linux_FF_RAMP

#define linux_FF_SQUARE   0x58
#define linux_FF_TRIANGLE 0x59
#define linux_FF_SINE     0x5a
#define linux_FF_SAW_UP   0x5b
#define linux_FF_SAW_DOWN 0x5c
#define linux_FF_CUSTOM   0x5d

#define linux_FF_WAVEFORM_MIN linux_FF_SQUARE
#define linux_FF_WAVEFORM_MAX linux_FF_CUSTOM

#define linux_FF_GAIN       0x60
#define linux_FF_AUTOCENTER 0x61

#define linux_FF_MAX_EFFECTS linux_FF_GAIN

#define linux_FF_MAX 0x7f
#define linux_FF_CNT (linux_FF_MAX + 1)

//=============================================================================
// uinput

#define linux_UINPUT_VERSION        5
#define linux_UINPUT_MAX_NAME_SIZE 80

#define linux_UINPUT_IOCTL_BASE   'U'
#define linux_UI_DEV_CREATE       linux_IO(linux_UINPUT_IOCTL_BASE, 1)
#define linux_UI_DEV_DESTROY      linux_IO(linux_UINPUT_IOCTL_BASE, 2)
#define linux_UI_DEV_SETUP        linux_IOW(linux_UINPUT_IOCTL_BASE, 3, struct linux_uinput_setup)
#define linux_UI_ABS_SETUP        linux_IOW(linux_UINPUT_IOCTL_BASE, 4, struct linux_uinput_abs_setup)
#define linux_UI_SET_EVBIT        linux_IOW(linux_UINPUT_IOCTL_BASE, 100, int)
#define linux_UI_SET_KEYBIT       linux_IOW(linux_UINPUT_IOCTL_BASE, 101, int)
#define linux_UI_SET_RELBIT       linux_IOW(linux_UINPUT_IOCTL_BASE, 102, int)
#define linux_UI_SET_ABSBIT       linux_IOW(linux_UINPUT_IOCTL_BASE, 103, int)
#define linux_UI_SET_MSCBIT       linux_IOW(linux_UINPUT_IOCTL_BASE, 104, int)
#define linux_UI_SET_LEDBIT       linux_IOW(linux_UINPUT_IOCTL_BASE, 105, int)
#define linux_UI_SET_SNDBIT       linux_IOW(linux_UINPUT_IOCTL_BASE, 106, int)
#define linux_UI_SET_FFBIT        linux_IOW(linux_UINPUT_IOCTL_BASE, 107, int)
#define linux_UI_SET_PHYS         linux_IOW(linux_UINPUT_IOCTL_BASE, 108, char*)
#define linux_UI_SET_SWBIT        linux_IOW(linux_UINPUT_IOCTL_BASE, 109, int)
#define linux_UI_SET_PROPBIT      linux_IOW(linux_UINPUT_IOCTL_BASE, 110, int)
#define linux_UI_BEGIN_FF_UPLOAD  linux_IOWR(linux_UINPUT_IOCTL_BASE, 200, struct linux_uinput_ff_upload)
#define linux_UI_END_FF_UPLOAD    linux_IOW(linux_UINPUT_IOCTL_BASE, 201, struct linux_uinput_ff_upload)
#define linux_UI_BEGIN_FF_ERASE   linux_IOWR(linux_UINPUT_IOCTL_BASE, 202, struct linux_uinput_ff_erase)
#define linux_UI_END_FF_ERASE     linux_IOW(linux_UINPUT_IOCTL_BASE, 203, struct linux_uinput_ff_erase)
#define linux_UI_GET_SYSNAME(len) linux_IOC(linux_IOC_READ, linux_UINPUT_IOCTL_BASE, 44, len)
#define linux_UI_GET_VERSION      linux_IOR(linux_UINPUT_IOCTL_BASE, 45, unsigned int)

#define linux_EV_UINPUT    0x0101
#define linux_UI_FF_UPLOAD 1
#define linux_UI_FF_ERASE  2

//=============================================================================
// Architecture specific

#if defined(LINUX_ARCH_ARM_EABI)
#include "arm-eabi/constants.h"
#elif defined(LINUX_ARCH_ARM64)
#include "arm64/constants.h"
#elif defined(LINUX_ARCH_RISCV32)
#include "riscv32/constants.h"
#elif defined(LINUX_ARCH_RISCV64)
#include "riscv64/constants.h"
#elif defined(LINUX_ARCH_X86)
#include "x86/constants.h"
#elif defined(LINUX_ARCH_X32)
#include "x32/constants.h"
#elif defined(LINUX_ARCH_X86_64)
#include "x86_64/constants.h"
#endif

//=============================================================================
// Architecture dependent

#define linux_SOCK_CLOEXEC linux_O_CLOEXEC

#define linux_SCM_TIMESTAMP    linux_SO_TIMESTAMP
#define linux_SCM_TIMESTAMPNS  linux_SO_TIMESTAMPNS
#define linux_SCM_TIMESTAMPING linux_SO_TIMESTAMPING

#define linux_IOC_DIRSHIFT (linux_IOC_SIZESHIFT + linux_IOC_SIZEBITS)

#define linux_IOC(dir, type, nr, size)    \
	(((dir) << linux_IOC_DIRSHIFT)  | \
	((type) << linux_IOC_TYPESHIFT) | \
	((nr)   << linux_IOC_NRSHIFT)   | \
	((size) << linux_IOC_SIZESHIFT))

#define linux_IO(type, nr)         linux_IOC(linux_IOC_NONE, (type), (nr), 0)
#define linux_IOR(type, nr, size)  linux_IOC(linux_IOC_READ, (type), (nr), sizeof(size))
#define linux_IOW(type, nr, size)  linux_IOC(linux_IOC_WRITE, (type), (nr), sizeof(size))
#define linux_IOWR(type, nr, size) linux_IOC(linux_IOC_READ | linux_IOC_WRITE, (type), (nr), sizeof(size))

//=============================================================================
// Architecture dependent auxval

#ifndef linux_AT_VECTOR_SIZE_ARCH
#define linux_AT_VECTOR_SIZE_ARCH 0
#endif
#define linux_AT_VECTOR_SIZE (2*(linux_AT_VECTOR_SIZE_ARCH + linux_AT_VECTOR_SIZE_BASE + 1))

//=============================================================================
// Architecture dependent timerfd

#define linux_TFD_CLOEXEC  linux_O_CLOEXEC
#define linux_TFD_NONBLOCK linux_O_NONBLOCK

#define linux_TFD_IOC_SET_TICKS linux_IOW('T', 0, uint64_t)

#endif // !HEADER_LIBLINUX_CONSTANTS_H_INCLUDED
