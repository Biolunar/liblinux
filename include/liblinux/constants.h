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
// sigaction handler

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

//=============================================================================
// memory

//-----------------------------------------------------------------------------
// mlock

#define linux_MLOCK_ONFAULT 0x01

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
#define linux_SCHED_FLAG_ALL           (linux_SCHED_FLAG_RESET_ON_FORK | \
                                        linux_SCHED_FLAG_RECLAIM       | \
                                        linux_SCHED_FLAG_DL_OVERRUN)

//=============================================================================
// interval timer

#define	linux_ITIMER_REAL    0
#define	linux_ITIMER_VIRTUAL 1
#define	linux_ITIMER_PROF    2

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
// architecture specific

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

#endif // !HEADER_LIBLINUX_CONSTANTS_H_INCLUDED
