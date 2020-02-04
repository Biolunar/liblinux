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

#ifndef HEADER_LIBLINUX_CONSTANTS_H_INCLUDED
#define HEADER_LIBLINUX_CONSTANTS_H_INCLUDED

#include "version.h"
#include "arch.h"
#include "endian.h"

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
// access

enum // Kernel sources do not explicitly define these constants. They correspond to S_IXOTH, S_IWOTH and S_IROTH.
{
	linux_F_OK = 0,
	linux_X_OK = 1,
	linux_W_OK = 2,
	linux_R_OK = 4,
};

//=============================================================================
// signals

#define linux_NSIG    64

#define linux_SIG_DFL ((linux_sighandler_t)0)
#define linux_SIG_IGN ((linux_sighandler_t)1)
#define linux_SIG_ERR ((linux_sighandler_t)-1)

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
#define linux_AT_REMOVEDIR          0x0200
#define linux_AT_SYMLINK_FOLLOW     0x0400
#define linux_AT_NO_AUTOMOUNT       0x0800
#define linux_AT_EMPTY_PATH         0x1000
#define linux_AT_STATX_SYNC_TYPE    0x6000
#define linux_AT_STATX_SYNC_AS_STAT 0x0000
#define linux_AT_STATX_FORCE_SYNC   0x2000
#define linux_AT_STATX_DONT_SYNC    0x4000

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

#define linux_INADDR_ANY               ((unsigned long int)0x00000000)
#define linux_INADDR_BROADCAST         ((unsigned long int)0xffffffff)
#define linux_INADDR_NONE              ((unsigned long int)0xffffffff)
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
// aio

enum
{
	linux_IOCB_CMD_PREAD   = 0,
	linux_IOCB_CMD_PWRITE  = 1,
	linux_IOCB_CMD_FSYNC   = 2,
	linux_IOCB_CMD_FDSYNC  = 3,
	linux_IOCB_CMD_POLL    = 5,
	linux_IOCB_CMD_NOOP    = 6,
	linux_IOCB_CMD_PREADV  = 7,
	linux_IOCB_CMD_PWRITEV = 8,
};

#define linux_IOCB_FLAG_RESFD  (1 << 0)
#define linux_IOCB_FLAG_IOPRIO (1 << 1)

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

#define linux_RWF_HIPRI     ((linux_kernel_rwf_t)0x00000001)
#define linux_RWF_DSYNC     ((linux_kernel_rwf_t)0x00000002)
#define linux_RWF_SYNC      ((linux_kernel_rwf_t)0x00000004)
#define linux_RWF_NOWAIT    ((linux_kernel_rwf_t)0x00000008)
#define linux_RWF_APPEND    ((linux_kernel_rwf_t)0x00000010)
#define linux_RWF_SUPPORTED (linux_RWF_HIPRI | linux_RWF_DSYNC | linux_RWF_SYNC | linux_RWF_NOWAIT | linux_RWF_APPEND)

//=============================================================================
// io_uring

#define linux_IOSQE_FIXED_FILE  (1U << 0)
#define linux_IOSQE_IO_DRAIN    (1U << 1)
#define linux_IOSQE_IO_LINK     (1U << 2)
#define linux_IOSQE_IO_HARDLINK (1U << 3)

#define linux_IORING_SETUP_IOPOLL (1U << 0)
#define linux_IORING_SETUP_SQPOLL (1U << 1)
#define linux_IORING_SETUP_SQ_AFF (1U << 2)
#define linux_IORING_SETUP_CQSIZE (1U << 3)

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

	linux_IORING_OP_LAST,
};

#define linux_IORING_FSYNC_DATASYNC (1U << 0)

#define linux_IORING_TIMEOUT_ABS (1U << 0)

#define linux_IORING_OFF_SQ_RING 0ULL
#define linux_IORING_OFF_CQ_RING 0x8000000ULL
#define linux_IORING_OFF_SQES    0x10000000ULL

#define linux_IORING_SQ_NEED_WAKEUP (1U << 0)

#define linux_IORING_ENTER_GETEVENTS (1U << 0)
#define linux_IORING_ENTER_SQ_WAKEUP (1U << 1)

#define linux_IORING_FEAT_SINGLE_MMAP   (1U << 0)
#define linux_IORING_FEAT_NODROP        (1U << 1)
#define linux_IORING_FEAT_SUBMIT_STABLE (1U << 2)

#define linux_IORING_REGISTER_BUFFERS      0
#define linux_IORING_UNREGISTER_BUFFERS    1
#define linux_IORING_REGISTER_FILES        2
#define linux_IORING_UNREGISTER_FILES      3
#define linux_IORING_REGISTER_EVENTFD      4
#define linux_IORING_UNREGISTER_EVENTFD    5
#define linux_IORING_REGISTER_FILES_UPDATE 6

//=============================================================================
// Architecture specific

#if defined(LINUX_ARCH_ARM_EABI)
#include "arm-eabi/constants.h"
#elif defined(LINUX_ARCH_ARM64)
#include "arm64/constants.h"
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
