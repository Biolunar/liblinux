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

#ifndef HEADER_LIBLINUX_ARM64_CONSTANTS_H_INCLUDED
#define HEADER_LIBLINUX_ARM64_CONSTANTS_H_INCLUDED

#include <stdint.h>

//=============================================================================
// poll

#define linux_POLLWRNORM UINT16_C(0x0100)
#define linux_POLLWRBAND UINT16_C(0x0200)
#define linux_POLLMSG    UINT16_C(0x0400)
#define linux_POLLREMOVE UINT16_C(0x1000)
#define linux_POLLRDHUP  UINT16_C(0x2000)

//=============================================================================
// signal

#define linux_NSIG UINT32_C(64)

//-----------------------------------------------------------------------------
// signals

#define linux_SIGBUS    UINT32_C( 7)
#define linux_SIGUSR1   UINT32_C(10)
#define linux_SIGUSR2   UINT32_C(12)
#define linux_SIGSTKFLT UINT32_C(16)
#define linux_SIGCHLD   UINT32_C(17)
#define linux_SIGCONT   UINT32_C(18)
#define linux_SIGSTOP   UINT32_C(19)
#define linux_SIGTSTP   UINT32_C(20)
#define linux_SIGTTIN   UINT32_C(21)
#define linux_SIGTTOU   UINT32_C(22)
#define linux_SIGURG    UINT32_C(23)
#define linux_SIGXCPU   UINT32_C(24)
#define linux_SIGXFSZ   UINT32_C(25)
#define linux_SIGVTALRM UINT32_C(26)
#define linux_SIGPROF   UINT32_C(27)
#define linux_SIGWINCH  UINT32_C(28)
#define linux_SIGIO     UINT32_C(29)
#define linux_SIGPWR    UINT32_C(30)
#define linux_SIGSYS    UINT32_C(31)
#define linux_SIGUNUSED UINT32_C(31)

#define linux_SIGRTMAX  linux_NSIG

//-----------------------------------------------------------------------------
// sigaction

#define linux_SA_NOCLDSTOP UINT32_C(0x00000001)
#define linux_SA_NOCLDWAIT UINT32_C(0x00000002)
#define linux_SA_SIGINFO   UINT32_C(0x00000004)
#define linux_SA_RESTORER  UINT32_C(0x04000000)
#define linux_SA_ONSTACK   UINT32_C(0x08000000)
#define linux_SA_RESTART   UINT32_C(0x10000000)
#define linux_SA_NODEFER   UINT32_C(0x40000000)
#define linux_SA_RESETHAND UINT32_C(0x80000000)
#define linux_SA_ONESHOT   linux_SA_RESETHAND

//-----------------------------------------------------------------------------
// sigaltstack

#define linux_MINSIGSTKSZ ((linux_size_t) 5120)
#define linux_SIGSTKSZ    ((linux_size_t)16384)

#define linux_SS_ONSTACK UINT32_C(1)
#define linux_SS_DISABLE UINT32_C(2)

#define linux_SS_AUTODISARM UINT32_C(0x80000000)
#define linux_SS_FLAG_BITS  linux_SS_AUTODISARM

//-----------------------------------------------------------------------------
// sigprocmask

#define linux_SIG_BLOCK   UINT32_C(0)
#define linux_SIG_UNBLOCK UINT32_C(1)
#define linux_SIG_SETMASK UINT32_C(2)

//-----------------------------------------------------------------------------
// siginfo

#define linux_SI_TIMER   INT32_C(-2)
#define linux_SI_MESGQ   INT32_C(-3)
#define linux_SI_ASYNCIO INT32_C(-4)

#define linux_SEGV_PKUERR INT32_C(4)

#define linux_ARCH_SIGEV_PREAMBLE_SIZE (sizeof(uint32_t) * 2 + sizeof(linux_sigval_t))

//=============================================================================
// TODO

#if !defined(linux_PAGE_SHIFT)
// 12 for  4K page size (default)
// 14 for 16K page size
// 16 for 64K page size
#define linux_PAGE_SHIFT 12
#endif
#define linux_PAGE_SIZE  (1 << linux_PAGE_SHIFT)
#define linux_PAGE_MASK  (~(linux_PAGE_SIZE - 1))

//=============================================================================
// auxvec

#define linux_AT_SYSINFO_EHDR 33
#define linux_AT_MINSIGSTKSZ  51

#define linux_AT_VECTOR_SIZE_ARCH 2

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

#define linux_MAP_SHARED          0x0000001
#define linux_MAP_PRIVATE         0x0000002
#define linux_MAP_SHARED_VALIDATE 0x0000003
#define linux_MAP_TYPE            0x000000f
#define linux_MAP_FIXED           0x0000010
#define linux_MAP_ANONYMOUS       0x0000020
#define linux_MAP_GROWSDOWN       0x0000100
#define linux_MAP_DENYWRITE       0x0000800
#define linux_MAP_EXECUTABLE      0x0001000
#define linux_MAP_LOCKED          0x0002000
#define linux_MAP_NORESERVE       0x0004000
#define linux_MAP_POPULATE        0x0008000
#define linux_MAP_NONBLOCK        0x0010000
#define linux_MAP_STACK           0x0020000
#define linux_MAP_HUGETLB         0x0040000
#define linux_MAP_SYNC            0x0080000
#define linux_MAP_FIXED_NOREPLACE 0x0100000
#define linux_MAP_UNINITIALIZED   0x4000000
#define linux_MAP_FILE            0x0000000

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
#define linux_O_DIRECTORY     000040000
#define linux_O_NOFOLLOW      000100000
#define linux_O_DIRECT        000200000
#define linux_O_LARGEFILE     000400000
#define linux_O_NOATIME       001000000
#define linux_O_CLOEXEC       002000000
#define linux_O_SYNC         (004000000 | linux_O_DSYNC)
#define linux_O_PATH          010000000
#define linux_O_TMPFILE      (020000000 | linux_O_DIRECTORY)
#define linux_O_TMPFILE_MASK (020000000 | linux_O_DIRECTORY | linux_O_CREAT)      
#define linux_O_NDELAY        linux_O_NONBLOCK

//=============================================================================
// fcntl

#define linux_F_GETLK   5
#define linux_F_SETLK   6
#define linux_F_SETLKW  7
#define linux_F_SETOWN  8
#define linux_F_GETOWN  9
#define linux_F_SETSIG 10
#define linux_F_GETSIG 11

#define linux_F_RDLCK 0
#define linux_F_WRLCK 1
#define linux_F_UNLCK 2

#define linux_F_EXLCK 4
#define linux_F_SHLCK 8

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

//=============================================================================
// ioctl

#define linux_IOC_SIZEBITS 14
#define linux_IOC_DIRBITS   2

#define linux_IOC_NONE  0U
#define linux_IOC_WRITE 1U
#define linux_IOC_READ  2U

#define linux_TCGETS          0x5401
#define linux_TCSETS          0x5402
#define linux_TCSETSW         0x5403
#define linux_TCSETSF         0x5404
#define linux_TCGETA          0x5405
#define linux_TCSETA          0x5406
#define linux_TCSETAW         0x5407
#define linux_TCSETAF         0x5408
#define linux_TCSBRK          0x5409
#define linux_TCXONC          0x540A
#define linux_TCFLSH          0x540B
#define linux_TIOCEXCL        0x540C
#define linux_TIOCNXCL        0x540D
#define linux_TIOCSCTTY       0x540E
#define linux_TIOCGPGRP       0x540F
#define linux_TIOCSPGRP       0x5410
#define linux_TIOCOUTQ        0x5411
#define linux_TIOCSTI         0x5412
#define linux_TIOCGWINSZ      0x5413
#define linux_TIOCSWINSZ      0x5414
#define linux_TIOCMGET        0x5415
#define linux_TIOCMBIS        0x5416
#define linux_TIOCMBIC        0x5417
#define linux_TIOCMSET        0x5418
#define linux_TIOCGSOFTCAR    0x5419
#define linux_TIOCSSOFTCAR    0x541A
#define linux_FIONREAD        0x541B
#define linux_TIOCINQ         linux_FIONREAD
#define linux_TIOCLINUX       0x541C
#define linux_TIOCCONS        0x541D
#define linux_TIOCGSERIAL     0x541E
#define linux_TIOCSSERIAL     0x541F
#define linux_TIOCPKT         0x5420
#define linux_FIONBIO         0x5421
#define linux_TIOCNOTTY       0x5422
#define linux_TIOCSETD        0x5423
#define linux_TIOCGETD        0x5424
#define linux_TCSBRKP         0x5425
#define linux_TIOCSBRK        0x5427
#define linux_TIOCCBRK        0x5428
#define linux_TIOCGSID        0x5429
#define linux_TCGETS2         linux_IOR('T', 0x2A, struct linux_termios2)
#define linux_TCSETS2         linux_IOW('T', 0x2B, struct linux_termios2)
#define linux_TCSETSW2        linux_IOW('T', 0x2C, struct linux_termios2)
#define linux_TCSETSF2        linux_IOW('T', 0x2D, struct linux_termios2)
#define linux_TIOCGRS485      0x542E
#define linux_TIOCSRS485      0x542F
#define linux_TIOCGPTN        linux_IOR('T', 0x30, unsigned int)
#define linux_TIOCSPTLCK      linux_IOW('T', 0x31, int)
#define linux_TIOCGDEV        linux_IOR('T', 0x32, unsigned int)
#define linux_TCGETX          0x5432
#define linux_TCSETX          0x5433
#define linux_TCSETXF         0x5434
#define linux_TCSETXW         0x5435
#define linux_TIOCSIG         linux_IOW('T', 0x36, int)
#define linux_TIOCVHANGUP     0x5437
#define linux_TIOCGPKT        linux_IOR('T', 0x38, int)
#define linux_TIOCGPTLCK      linux_IOR('T', 0x39, int)
#define linux_TIOCGEXCL       linux_IOR('T', 0x40, int)
#define linux_TIOCGPTPEER     linux_IO('T', 0x41)
#define linux_TIOCGISO7816    linux_IOR('T', 0x42, struct linux_serial_iso7816)
#define linux_TIOCSISO7816    linux_IOWR('T', 0x43, struct linux_serial_iso7816)
#define linux_FIONCLEX        0x5450
#define linux_FIOCLEX         0x5451
#define linux_FIOASYNC        0x5452
#define linux_TIOCSERCONFIG   0x5453
#define linux_TIOCSERGWILD    0x5454
#define linux_TIOCSERSWILD    0x5455
#define linux_TIOCGLCKTRMIOS  0x5456
#define linux_TIOCSLCKTRMIOS  0x5457
#define linux_TIOCSERGSTRUCT  0x5458
#define linux_TIOCSERGETLSR   0x5459
#define linux_TIOCSERGETMULTI 0x545A
#define linux_TIOCSERSETMULTI 0x545B
#define linux_TIOCMIWAIT      0x545C
#define linux_TIOCGICOUNT     0x545D
#define linux_FIOQSIZE        0x5460

//=============================================================================
// termbits

#define linux_NCCS 19

#define linux_VINTR     0
#define linux_VQUIT     1
#define linux_VERASE    2
#define linux_VKILL     3
#define linux_VEOF      4
#define linux_VTIME     5
#define linux_VMIN      6
#define linux_VSWTC     7
#define linux_VSTART    8
#define linux_VSTOP     9
#define linux_VSUSP    10
#define linux_VEOL     11
#define linux_VREPRINT 12
#define linux_VDISCARD 13
#define linux_VWERASE  14
#define linux_VLNEXT   15
#define linux_VEOL2    16

#define linux_IGNBRK  0000001
#define linux_BRKINT  0000002
#define linux_IGNPAR  0000004
#define linux_PARMRK  0000010
#define linux_INPCK   0000020
#define linux_ISTRIP  0000040
#define linux_INLCR   0000100
#define linux_IGNCR   0000200
#define linux_ICRNL   0000400
#define linux_IUCLC   0001000
#define linux_IXON    0002000
#define linux_IXANY   0004000
#define linux_IXOFF   0010000
#define linux_IMAXBEL 0020000
#define linux_IUTF8   0040000

#define linux_OPOST  0000001
#define linux_OLCUC  0000002
#define linux_ONLCR  0000004
#define linux_OCRNL  0000010
#define linux_ONOCR  0000020
#define linux_ONLRET 0000040
#define linux_OFILL  0000100
#define linux_OFDEL  0000200
#define linux_NLDLY  0000400
#define linux_CRDLY  0003000
#define linux_TABDLY 0014000
#define linux_BSDLY  0020000
#define linux_VTDLY  0040000
#define linux_FFDLY  0100000

#define linux_NL0 0000000
#define linux_NL1 0000400

#define linux_CR0 0000000
#define linux_CR1 0001000
#define linux_CR2 0002000
#define linux_CR3 0003000

#define linux_TAB0  0000000
#define linux_TAB1  0004000
#define linux_TAB2  0010000
#define linux_TAB3  0014000
#define linux_XTABS 0014000

#define linux_BS0 0000000
#define linux_BS1 0020000

#define linux_VT0 0000000
#define linux_VT1 0040000

#define linux_FF0 0000000
#define linux_FF1 0100000

#define linux_CBAUD   0010017
#define linux_EXTA    linux_B19200
#define linux_EXTB    linux_B38400
#define linux_CSIZE   0000060
#define linux_CSTOPB  0000100
#define linux_CREAD   0000200
#define linux_PARENB  0000400
#define linux_PARODD  0001000
#define linux_HUPCL   0002000
#define linux_CLOCAL  0004000
#define linux_CBAUDEX 0010000
#define linux_CIBAUD  002003600000
#define linux_CMSPAR  010000000000
#define linux_CRTSCTS 020000000000

#define linux_B0     0000000
#define linux_B50    0000001
#define linux_B75    0000002
#define linux_B110   0000003
#define linux_B134   0000004
#define linux_B150   0000005
#define linux_B200   0000006
#define linux_B300   0000007
#define linux_B600   0000010
#define linux_B1200  0000011
#define linux_B1800  0000012
#define linux_B2400  0000013
#define linux_B4800  0000014
#define linux_B9600  0000015
#define linux_B19200 0000016
#define linux_B38400 0000017

#define linux_CS5 0000000
#define linux_CS6 0000020
#define linux_CS7 0000040
#define linux_CS8 0000060

#define linux_BOTHER   0010000
#define linux_B57600   0010001
#define linux_B115200  0010002
#define linux_B230400  0010003
#define linux_B460800  0010004
#define linux_B500000  0010005
#define linux_B576000  0010006
#define linux_B921600  0010007
#define linux_B1000000 0010010
#define linux_B1152000 0010011
#define linux_B1500000 0010012
#define linux_B2000000 0010013
#define linux_B2500000 0010014
#define linux_B3000000 0010015
#define linux_B3500000 0010016
#define linux_B4000000 0010017

#define linux_ISIG    0000001
#define linux_ICANON  0000002
#define linux_XCASE   0000004
#define linux_ECHO    0000010
#define linux_ECHOE   0000020
#define linux_ECHOK   0000040
#define linux_ECHONL  0000100
#define linux_NOFLSH  0000200
#define linux_TOSTOP  0000400
#define linux_ECHOCTL 0001000
#define linux_ECHOPRT 0002000
#define linux_ECHOKE  0004000
#define linux_FLUSHO  0010000
#define linux_PENDIN  0040000
#define linux_IEXTEN  0100000
#define linux_EXTPROC 0200000

#define linux_TCSANOW   0
#define linux_TCSADRAIN 1
#define linux_TCSAFLUSH 2

//=============================================================================
// termios

#define linux_NCC 8

#define linux_TIOCM_LE   0x0001
#define linux_TIOCM_DTR  0x0002
#define linux_TIOCM_RTS  0x0004
#define linux_TIOCM_ST   0x0008
#define linux_TIOCM_SR   0x0010
#define linux_TIOCM_CTS  0x0020
#define linux_TIOCM_CAR  0x0040
#define linux_TIOCM_RNG  0x0080
#define linux_TIOCM_DSR  0x0100
#define linux_TIOCM_CD   linux_TIOCM_CAR
#define linux_TIOCM_RI   linux_IOCM_RNG
#define linux_TIOCM_OUT1 0x2000
#define linux_TIOCM_OUT2 0x4000
#define linux_TIOCM_LOOP 0x8000

//=============================================================================
// termiox

#define linux_NFF 5

#define	linux_RTSXOFF 0x0001
#define	linux_CTSXON  0x0002
#define	linux_DTRXOFF 0x0004
#define linux_DSRXON  0x0008

#endif // !HEADER_LIBLINUX_ARM64_CONSTANTS_H_INCLUDED
