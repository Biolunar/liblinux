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

#ifndef HEADER_LIBLINUX_LINUX_H_INCLUDED
#define HEADER_LIBLINUX_LINUX_H_INCLUDED

#include "version.h"
#include "arch.h"
#include "endian.h"
#include "syscall.h"
#include "names.h"
#include "constants.h"

#include <stdint.h>
#include <stdalign.h>

// TODO: Add arm-eabi thumb mode.
// TODO: Check if x32 takes syscall arguments as 32 bit or 64 bit (why is there no truncate64?).
// TODO: I changed (u)long to (u)word_t in all signatures. Is this also necessary for the struct members? TODO: also change the typedefs?

// Type replacements
// -----------------
// long -> linux_word_t
// unsigned long -> linux_uword_t

//=============================================================================
// Generic types

typedef int                      linux_kernel_key_t;
typedef int                      linux_kernel_mqd_t;
typedef unsigned int             linux_kernel_uid32_t;
typedef unsigned int             linux_kernel_gid32_t;
typedef int                      linux_kernel_pid_t;
typedef long long                linux_kernel_loff_t;
typedef long long                linux_kernel_time64_t;
typedef unsigned short           linux_kernel_sa_family_t;
typedef int                      linux_kernel_timer_t;
typedef int                      linux_kernel_rwf_t;
typedef int                      linux_kernel_clockid_t;
typedef int                      linux_kernel_timer_t;
typedef unsigned short           linux_umode_t;
typedef unsigned int             linux_poll_t;
typedef int32_t                  linux_key_serial_t;
typedef linux_kernel_key_t       linux_key_t;
typedef linux_kernel_pid_t       linux_pid_t;
typedef linux_kernel_loff_t      linux_loff_t;
typedef linux_kernel_sa_family_t linux_sa_family_t;
typedef linux_kernel_uid32_t     linux_uid_t;
typedef linux_kernel_gid32_t     linux_gid_t;
typedef linux_kernel_uid32_t     linux_qid_t;
typedef linux_kernel_rwf_t       linux_rwf_t;
typedef linux_kernel_clockid_t   linux_clockid_t;
typedef linux_kernel_timer_t     linux_timer_t;
typedef linux_kernel_mqd_t       linux_mqd_t;
typedef void                     linux_signalfn_t(int);
typedef void                     linux_restorefn_t(void);
typedef linux_restorefn_t*       linux_sigrestore_t;

typedef struct
{
	unsigned long fds_bits[1024 / (8 * sizeof(long))];
} linux_kernel_fd_set;
struct linux_pollfd
{
	int fd;
	short events;
	short revents;
};
typedef struct
{
	unsigned long sig[64 / LINUX_BITS_PER_LONG];
} linux_sigset_t; // Defined in a bunch of different architectures but all those agree on the definition. So assume it's generic.
typedef union linux_sigval
{
	int sival_int;
	void* sival_ptr;
} linux_sigval_t;
struct linux_io_event
{
	uint64_t data;
	uint64_t obj;
	int64_t res;
	int64_t res2;
};
struct linux_iocb
{
	uint64_t aio_data;
#ifdef LINUX_ENDIAN_LITTE
	uint32_t aio_key;
	linux_kernel_rwf_t aio_rw_flags;
#else
	linux_kernel_rwf_t aio_rw_flags;
	uint32_t aio_key;
#endif
	uint16_t aio_lio_opcode;
	int16_t aio_reqprio;
	uint32_t aio_fildes;
	uint64_t aio_buf;
	uint64_t aio_nbytes;
	int64_t aio_offset;
	uint64_t aio_reserved2;
	uint32_t aio_flags;
	uint32_t aio_resfd;
};
struct linux_dirent64
{
	uint64_t d_ino;
	int64_t d_off;
	unsigned short d_reclen;
	unsigned char d_type;
	char d_name[];
};
struct linux_statx_timestamp
{
	int64_t tv_sec;
	uint32_t tv_nsec;
	int32_t _reserved;
};
struct linux_statx
{
	uint32_t stx_mask;
	uint32_t stx_blksize;
	uint64_t stx_attributes;
	uint32_t stx_nlink;
	uint32_t stx_uid;
	uint32_t stx_gid;
	uint16_t stx_mode;
	uint16_t _spare0[1];
	uint64_t stx_ino;
	uint64_t stx_size;
	uint64_t stx_blocks;
	uint64_t stx_attributes_mask;
	struct linux_statx_timestamp stx_atime;
	struct linux_statx_timestamp stx_btime;
	struct linux_statx_timestamp stx_ctime;
	struct linux_statx_timestamp stx_mtime;
	uint32_t stx_rdev_major;
	uint32_t stx_rdev_minor;
	uint32_t stx_dev_major;
	uint32_t stx_dev_minor;
	uint64_t _spare2[14];
};
struct linux_robust_list
{
	struct linux_robust_list* next;
};
struct linux_robust_list_head
{
	struct linux_robust_list list;
	long futex_offset;
	struct linux_robust_list* list_op_pending;
};
struct linux_perf_event_attr
{
	uint32_t type;
	uint32_t size;
	uint64_t config;
	union
	{
		uint64_t sample_period;
		uint64_t sample_freq;
	};
	uint64_t sample_type;
	uint64_t read_format;
	uint64_t disabled:                  1,
	         inherit:                   1,
	         pinned:                    1,
	         exclusive:                 1,
	         exclude_user:              1,
	         exclude_kernel:            1,
	         exclude_hv:                1,
	         exclude_idle:              1,
	         mmap:                      1,
	         comm:                      1,
	         freq:                      1,
	         inherit_stat:              1,
	         enable_on_exec:            1,
	         task:                      1,
	         watermark:                 1,
	         precise_ip:                2,
	         mmap_data:                 1,
	         sample_id_all:             1,
	         exclude_host:              1,
	         exclude_guest:             1,
	         exclude_callchain_kernel:  1,
	         exclude_callchain_user:    1,
	         mmap2:                     1,
	         comm_exec:                 1,
	         use_clockid:               1,
	         context_switch:            1,
	         write_backward:            1,
	         namespaces:                1,
	         _reserved1:               35;
	union
	{
		uint32_t wakeup_events;
		uint32_t wakeup_watermark;
	};
	uint32_t bp_type;
	union
	{
		uint64_t bp_addr;
		uint64_t kprobe_func;
		uint64_t uprobe_path;
		uint64_t config1;
	};
	union
	{
		uint64_t bp_len;
		uint64_t kprobe_addr;
		uint64_t probe_offset;
		uint64_t config2;
	};
	uint64_t branch_sample_type;
	uint64_t sample_regs_user;
	uint32_t sample_stack_user;
	int32_t clockid;
	uint64_t sample_regs_intr;
	uint32_t aux_watermark;
	uint16_t sample_max_stack;
	uint16_t _reserved2;
};
struct linux_rlimit64
{
	uint64_t rlim_cur;
	uint64_t rlim_max;
};
struct linux_file_handle
{
	uint32_t handle_bytes;
	int handle_type;
	unsigned char f_handle[];
};
struct linux_getcpu_cache
{
	unsigned long blob[128 / sizeof(long)];
};
struct linux_sched_attr
{
	uint32_t size;
	uint32_t sched_policy;
	uint64_t sched_flags;
	int32_t sched_nice;
	uint32_t sched_priority;
	uint64_t sched_runtime;
	uint64_t sched_deadline;
	uint64_t sched_period;
};
union linux_bpf_attr
{
	alignas(8) struct
	{
		uint32_t map_type;
		uint32_t key_size;
		uint32_t value_size;
		uint32_t max_entries;
		uint32_t map_flags;
		uint32_t inner_map_fd;
		uint32_t numa_node;
		char map_name[16];
		uint32_t map_ifindex;
		uint32_t btf_fd;
		uint32_t btf_key_type_id;
		uint32_t btf_value_type_id;
	};
	struct
	{
		uint32_t map_fd;
		alignas(8) uint64_t key;
		union
		{
			alignas(8) uint64_t value;
			alignas(8) uint64_t next_key;
		};
		uint64_t flags;
	};
	struct
	{
		uint32_t prog_type;
		uint32_t insn_cnt;
		alignas(8) uint64_t insns;
		alignas(8) uint64_t license;
		uint32_t log_level;
		uint32_t log_size;
		alignas(8) uint64_t log_buf;
		uint32_t kern_version;
		uint32_t prog_flags;
		char prog_name[16];
		uint32_t prog_ifindex;
		uint32_t expected_attach_type;
	};
	struct
	{
		alignas(8) uint64_t pathname;
		uint32_t bpf_fd;
		uint32_t file_flags;
	};
	struct
	{
		uint32_t target_fd;
		uint32_t attach_bpf_fd;
		uint32_t attach_type;
		uint32_t attach_flags;
	};
	struct
	{
		uint32_t prog_fd;
		uint32_t retval;
		uint32_t data_size_in;
		uint32_t data_size_out;
		alignas(8) uint64_t data_in;
		alignas(8) uint64_t data_out;
		uint32_t repeat;
		uint32_t duration;
	} test;
	struct
	{
		union
		{
			uint32_t start_id;
			uint32_t prog_id;
			uint32_t map_id;
			uint32_t btf_id;
		};
		uint32_t next_id;
		uint32_t open_flags;
	};
	struct
	{
		uint32_t bpf_fd;
		uint32_t info_len;
		alignas(8) uint64_t info;
	} info;
	struct
	{
		uint32_t target_fd;
		uint32_t attach_type;
		uint32_t query_flags;
		uint32_t attach_flags;
		alignas(8) uint64_t prog_ids;
		uint32_t prog_cnt;
	} query;
	struct
	{
		uint64_t name;
		uint32_t prog_fd;
	} raw_tracepoint;
	struct
	{
		alignas(8) uint64_t btf;
		alignas(8) uint64_t btf_log_buf;
		uint32_t btf_size;
		uint32_t btf_log_size;
		uint32_t btf_log_level;
	};
	struct
	{
		uint32_t pid;
		uint32_t fd;
		uint32_t flags;
		uint32_t buf_len;
		alignas(8) uint64_t buf;
		uint32_t prog_id;
		uint32_t fd_type;
		uint64_t probe_offset;
		uint64_t probe_addr;
	} task_fd_query;
};
_Static_assert(alignof(union linux_bpf_attr) == 8, "union linux_bpf_attr is misaligned");
struct linux_rseq_cs
{
	alignas(4 * sizeof(uint64_t)) uint32_t version;
	uint32_t flags;
	uint64_t start_ip;
	uint64_t post_commit_offset;
	uint64_t abort_ip;
};
_Static_assert(alignof(struct linux_rseq_cs) == (4 * sizeof(uint64_t)), "struct linux_rseq_cs is misaligned");
struct linux_rseq
{
	alignas(4 * sizeof(uint64_t)) uint32_t cpu_id_start;
	uint32_t cpu_id;
	union
	{
		uint64_t ptr64;
#if (LINUX_BITS_PER_LONG == 64)
		uint64_t ptr;
#else
		struct
		{
#ifdef LINUX_ENDIAN_BIG
			uint32_t padding;
			uint32_t ptr32;
#else
			uint32_t ptr32;
			uint32_t padding;
#endif
		} ptr;
#endif
	} rseq_cs;
	uint32_t flags;
};
_Static_assert(alignof(struct linux_rseq) == (4 * sizeof(uint64_t)), "struct linux_rseq is misaligned");

#if defined(LINUX_ARCH_X86)
struct linux_oldold_utsname
{
	char sysname[9];
	char nodename[9];
	char release[9];
	char version[9];
	char machine[9];
};
struct linux_old_linux_dirent
{
	unsigned long d_ino;
	unsigned long d_offset;
	unsigned short d_namlen;
	char d_name[];
};
struct linux_mmap_arg_struct
{
	unsigned long addr;
	unsigned long len;
	unsigned long prot;
	unsigned long flags;
	unsigned long fd;
	unsigned long offset;
};
struct linux_old_utsname
{
	char sysname[65];
	char nodename[65];
	char release[65];
	char version[65];
	char machine[65];
};
#endif

typedef linux_kernel_fd_set linux_fd_set;

//=============================================================================
// Architecture specific types

#if defined(LINUX_ARCH_ARM_EABI)
#include "arm-eabi/types.h"
#elif defined(LINUX_ARCH_ARM64)
#include "arm64/types.h"
#elif defined(LINUX_ARCH_X86)
#include "x86/types.h"
#elif defined(LINUX_ARCH_X32)
#include "x32/types.h"
#elif defined(LINUX_ARCH_X86_64)
#include "x86_64/types.h"
#endif

//=============================================================================
// Architecture dependent types

typedef linux_kernel_long_t  linux_kernel_off_t;
typedef linux_kernel_long_t  linux_kernel_time_t;
typedef linux_kernel_long_t  linux_kernel_clock_t;
typedef linux_kernel_size_t  linux_size_t;
typedef linux_kernel_ssize_t linux_ssize_t;
typedef linux_kernel_off_t   linux_off_t;
typedef linux_kernel_time_t  linux_time_t;
typedef linux_kernel_ulong_t linux_aio_context_t;

#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_X86)
typedef linux_kernel_old_uid_t linux_old_uid_t;
typedef linux_kernel_old_gid_t linux_old_gid_t;
#endif

#if defined(LINUX_ARCH_ARM_EABI)
#include "arm-eabi/structs.h"
#elif defined(LINUX_ARCH_ARM64)
#include "arm64/structs.h"
#elif defined(LINUX_ARCH_X86)
#include "x86/structs.h"
#elif defined(LINUX_ARCH_X32)
#include "x32/structs.h"
#elif defined(LINUX_ARCH_X86_64)
#include "x86_64/structs.h"
#endif

struct linux_kernel_timespec // TODO: Check this definition in regards to CONFIG_64BIT_TIME.
{
	linux_kernel_time64_t tv_sec;
	long long tv_nsec;
};
struct linux_kernel_itimerspec // TODO: Check this definition in regards to CONFIG_64BIT_TIME.
{
	struct linux_kernel_timespec it_interval;
	struct linux_kernel_timespec it_value;
};
struct linux_iovec
{
	void* iov_base;
	linux_kernel_size_t iov_len;
};
struct linux_new_utsname
{
	char sysname[65];
	char nodename[65];
	char release[65];
	char version[65];
	char machine[65];
	char domainname[65];
};
struct linux_timeval
{
	linux_kernel_time_t tv_sec;
	linux_kernel_suseconds_t tv_usec;
};
struct linux_timezone
{
	int tz_minuteswest;
	int tz_dsttime;
};
struct linux_itimerval
{
	struct linux_timeval it_interval;
	struct linux_timeval it_value;
};
struct linux_sockaddr
{
	linux_sa_family_t sa_family;
	char sa_data[14];
};
struct linux_user_msghdr
{
	void* msg_name;
	int msg_namelen;
	struct linux_iovec* msg_iov;
	linux_kernel_size_t msg_iovlen;
	void* msg_control;
	linux_kernel_size_t msg_controllen;
	unsigned int msg_flags;
};
struct linux_mmsghdr
{
	struct linux_user_msghdr msg_hdr;
	unsigned int msg_len;
};
struct linux_rusage
{
	struct linux_timeval ru_utime;
	struct linux_timeval ru_stime;
	linux_kernel_long_t ru_maxrss;
	linux_kernel_long_t ru_ixrss;
	linux_kernel_long_t ru_idrss;
	linux_kernel_long_t ru_isrss;
	linux_kernel_long_t ru_minflt;
	linux_kernel_long_t ru_majflt;
	linux_kernel_long_t ru_nswap;
	linux_kernel_long_t ru_inblock;
	linux_kernel_long_t ru_oublock;
	linux_kernel_long_t ru_msgsnd;
	linux_kernel_long_t ru_msgrcv;
	linux_kernel_long_t ru_nsignals;
	linux_kernel_long_t ru_nvcsw;
	linux_kernel_long_t ru_nivcsw;
};
struct linux_sembuf
{
	unsigned short sem_num;
	short sem_op;
	short sem_flg;
};
struct linux_msgbuf
{
	linux_kernel_long_t mtype;
	char mtext[];
};
struct linux_dirent
{
	unsigned long d_ino;
	unsigned long d_off;
	unsigned short d_reclen;
	char d_name[];
};
struct linux_rlimit
{
	linux_kernel_ulong_t rlim_cur;
	linux_kernel_ulong_t rlim_max;
};
struct linux_tms
{
	linux_kernel_clock_t tms_utime;
	linux_kernel_clock_t tms_stime;
	linux_kernel_clock_t tms_cutime;
	linux_kernel_clock_t tms_cstime;
};
typedef struct linux_user_cap_header_struct
{
	uint32_t version;
	int pid;
} *linux_cap_user_header_t;
typedef struct linux_user_cap_data_struct
{
	uint32_t effective;
	uint32_t permitted;
	uint32_t inheritable;
} *linux_cap_user_data_t;
struct linux_utimbuf
{
	linux_kernel_time_t actime;
	linux_kernel_time_t modtime;
};
struct linux_ustat
{
	linux_kernel_daddr_t f_tfree;
	linux_kernel_ino_t f_tinode;
	char f_fname[6];
	char f_fpack[6];
};
struct linux_sched_param
{
	int sched_priority;
};
struct linux_sysctl_args
{
	int* name;
	int nlen;
	void* oldval;
	linux_size_t* oldlenp;
	void* newval;
	linux_size_t newlen;
	unsigned long _unused[4];
};
struct linux_timex
{
	unsigned int modes;
	linux_kernel_long_t offset;
	linux_kernel_long_t freq;
	linux_kernel_long_t maxerror;
	linux_kernel_long_t esterror;
	int status;
	linux_kernel_long_t constant;
	linux_kernel_long_t precision;
	linux_kernel_long_t tolerance;
	struct linux_timeval time;
	linux_kernel_long_t tick;
	linux_kernel_long_t ppsfreq;
	linux_kernel_long_t jitter;
	int shift;
	linux_kernel_long_t stabil;
	linux_kernel_long_t jitcnt;
	linux_kernel_long_t calcnt;
	linux_kernel_long_t errcnt;
	linux_kernel_long_t stbcnt;
	int tai;

	int: 32; int: 32; int: 32; int: 32;
	int: 32; int: 32; int: 32; int: 32;
	int: 32; int: 32; int: 32;
};
struct linux_timespec
{
	linux_kernel_time_t tv_sec;
	long tv_nsec;
};
struct linux_aio_sigset
{
	linux_sigset_t const* sigmask;
	linux_size_t sigsetsize;
};
typedef struct linux_sigevent
{
	linux_sigval_t sigev_value;
	int sigev_signo;
	int sigev_notify;
	union
	{
		int _pad[(64 - (sizeof(int) * 2 + sizeof(linux_sigval_t))) / sizeof(int)];
		int tid;
		struct
		{
			void (*function)(linux_sigval_t);
			void *attribute;
		} sigev_thread;
	} sigev_un;
} linux_sigevent_t;
struct linux_mq_attr
{
	linux_kernel_long_t mq_flags;
	linux_kernel_long_t mq_maxmsg;
	linux_kernel_long_t mq_msgsize;
	linux_kernel_long_t mq_curmsgs;
	linux_kernel_long_t _reserved[4];
};
struct linux_kexec_segment
{
	void const* buf;
	linux_size_t bufsz;
	void const* mem;
	linux_size_t memsz;
};

//=============================================================================
// Deprecated types

#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_X86)
struct linux_old_sigaction
{
	linux_sighandler_t sa_handler;
	linux_old_sigset_t sa_mask;
	unsigned long sa_flags;
	linux_sigrestore_t sa_restorer;
};
#endif
#if defined(LINUX_ARCH_X86)
struct linux_sel_arg_struct
{
	unsigned long n;
	linux_fd_set *inp, *outp, *exp;
	struct linux_timeval* tvp;
};
#endif

//=============================================================================
// Generic syscalls

//-----------------------------------------------------------------------------
// aio

inline LINUX_DEFINE_SYSCALL2_NORET(io_setup, unsigned int, nr_events, linux_aio_context_t*, ctxp)
inline LINUX_DEFINE_SYSCALL1_NORET(io_destroy, linux_aio_context_t, ctx)
inline LINUX_DEFINE_SYSCALL3_RET(io_submit, linux_aio_context_t, ctx_id, linux_word_t, nr, struct linux_iocb**, iocbpp, linux_word_t)
inline LINUX_DEFINE_SYSCALL3_NORET(io_cancel, linux_aio_context_t, ctx_id, struct linux_iocb*, iocb, struct linux_io_event*, result)
inline LINUX_DEFINE_SYSCALL5_RET(io_getevents, linux_aio_context_t, ctx_id, linux_word_t, min_nr, linux_word_t, nr, struct linux_io_event*, events, struct linux_timespec*, timeout, linux_word_t)
inline LINUX_DEFINE_SYSCALL6_RET(io_pgetevents, linux_aio_context_t, ctx_id, linux_word_t, min_nr, linux_word_t, nr, struct linux_io_event*, events, struct linux_timespec*, timeout, struct linux_aio_sigset const*, usig, linux_word_t)

//-----------------------------------------------------------------------------
// xattr

inline LINUX_DEFINE_SYSCALL5_NORET(setxattr, char const*, pathname, char const*, name, void const*, value, linux_size_t, size, int, flags)
inline LINUX_DEFINE_SYSCALL5_NORET(lsetxattr, char const*, pathname, char const*, name, void const*, value, linux_size_t, size, int, flags)
inline LINUX_DEFINE_SYSCALL5_NORET(fsetxattr, int, fd, char const*, name, void const*,value, linux_size_t, size, int, flags)
inline LINUX_DEFINE_SYSCALL4_RET(getxattr, char const*, pathname, char const*, name, void*, value, linux_size_t, size, linux_ssize_t)
inline LINUX_DEFINE_SYSCALL4_RET(lgetxattr, char const*, pathname, char const*, name, void*, value, linux_size_t, size, linux_ssize_t)
inline LINUX_DEFINE_SYSCALL4_RET(fgetxattr, int, fd, char const*, name, void*, value, linux_size_t, size, linux_ssize_t)
inline LINUX_DEFINE_SYSCALL3_RET(listxattr, char const*, pathname, char*, list, linux_size_t, size, linux_ssize_t)
inline LINUX_DEFINE_SYSCALL3_RET(llistxattr, char const*, pathname, char*, list, linux_size_t, size, linux_ssize_t)
inline LINUX_DEFINE_SYSCALL3_RET(flistxattr, int, fd, char*, list, linux_size_t, size, linux_ssize_t)
inline LINUX_DEFINE_SYSCALL2_NORET(removexattr, char const*, pathname, char const*, name)
inline LINUX_DEFINE_SYSCALL2_NORET(lremovexattr, char const*, pathname, char const*, name)
inline LINUX_DEFINE_SYSCALL2_NORET(fremovexattr, int, fd, char const*, name)

//-----------------------------------------------------------------------------
// polling

inline LINUX_DEFINE_SYSCALL1_RET(epoll_create1, int, flags, int)
inline LINUX_DEFINE_SYSCALL4_NORET(epoll_ctl, int, epfd, int, op, int, fd, struct linux_epoll_event*, event)
inline LINUX_DEFINE_SYSCALL6_RET(epoll_pwait, int, epfd, struct linux_epoll_event*, events, int, maxevents, int, timeout, linux_sigset_t const*, sigmask, linux_size_t, sigsetsize, int)
inline LINUX_DEFINE_SYSCALL6_RET(pselect6, int, n, linux_fd_set*, inp, linux_fd_set*, outp, linux_fd_set*, exp, struct linux_timespec*, tsp, void*, sig, linux_word_t)
inline LINUX_DEFINE_SYSCALL5_RET(ppoll, struct linux_pollfd*, ufds, unsigned int, nfds, struct linux_timespec*, tsp, linux_sigset_t const*, sigmask, linux_size_t, sigsetsize, int)

//-----------------------------------------------------------------------------
// file decriptors

inline LINUX_DEFINE_SYSCALL1_RET(dup, unsigned int, fildes, int)
inline LINUX_DEFINE_SYSCALL3_RET(dup3, unsigned int, oldfd, unsigned int, newfd, int, flags, int)
inline LINUX_DEFINE_SYSCALL3_RET(fcntl, unsigned int, fd, unsigned int, cmd, linux_uword_t, arg, linux_word_t)
inline LINUX_DEFINE_SYSCALL3_RET(ioctl, unsigned int, fd, unsigned int, cmd, linux_uword_t, arg, int)
inline LINUX_DEFINE_SYSCALL2_NORET(flock, unsigned int, fd, unsigned int, cmd)
inline LINUX_DEFINE_SYSCALL1_NORET(close, unsigned int, fd)

//-----------------------------------------------------------------------------
// inotify

inline LINUX_DEFINE_SYSCALL1_RET(inotify_init1, int, flags, int)
inline LINUX_DEFINE_SYSCALL3_RET(inotify_add_watch, int, fd, char const*, pathname, uint32_t, mask, int)
inline LINUX_DEFINE_SYSCALL2_NORET(inotify_rm_watch, int, fd, int32_t, wd)

//-----------------------------------------------------------------------------
// filesystem

inline LINUX_DEFINE_SYSCALL4_NORET(mknodat, int, dfd, char const*, filename, linux_umode_t, mode, unsigned int, dev)
inline LINUX_DEFINE_SYSCALL3_NORET(mkdirat, int, dfd, char const*, pathname, linux_umode_t, mode)
inline LINUX_DEFINE_SYSCALL3_NORET(unlinkat, int, dfd, char const*, pathname, int, flag)
inline LINUX_DEFINE_SYSCALL3_NORET(symlinkat, char const*, oldname, int, newdfd, char const*, newname)
inline LINUX_DEFINE_SYSCALL5_NORET(linkat, int, olddfd, char const*, oldname, int, newdfd, char const*, newname, int, flags)
inline LINUX_DEFINE_SYSCALL4_NORET(renameat, int, olddfd, char const*, oldname, int, newdfd, char const*, newname)
inline LINUX_DEFINE_SYSCALL2_NORET(statfs, char const*, pathname, struct linux_statfs*, buf)
inline LINUX_DEFINE_SYSCALL2_NORET(fstatfs, unsigned int, fd, struct linux_statfs*, buf)
inline LINUX_DEFINE_SYSCALL3_RET(getdents64, unsigned int, fd, struct linux_dirent64*, dirent, unsigned int, count, int)
inline LINUX_DEFINE_SYSCALL4_RET(readlinkat, int, dfd, char const*, pathname, char*, buf, int, bufsiz, int)
inline LINUX_DEFINE_SYSCALL5_NORET(renameat2, int, olddfd, char const*, oldname, int, newdfd, char const*, newname, unsigned int, flags)

//-----------------------------------------------------------------------------
// real files

inline LINUX_DEFINE_SYSCALL2_NORET(truncate, char const*, path, linux_word_t, length)
inline LINUX_DEFINE_SYSCALL2_NORET(ftruncate, unsigned int, fd, linux_uword_t, length)
inline enum linux_error_t linux_fallocate(int const fd, int const mode, linux_loff_t const offset, linux_loff_t const len)
{
#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall6(LINUX_PARAM(fd), LINUX_PARAM(mode), LINUX_EXPAND(offset), LINUX_EXPAND(len), linux_syscall_name_fallocate);
#else
	linux_word_t const ret = linux_syscall4(LINUX_PARAM(fd), LINUX_PARAM(mode), LINUX_PARAM(offset), LINUX_PARAM(len), linux_syscall_name_fallocate);
#endif
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline LINUX_DEFINE_SYSCALL3_NORET(faccessat, int, dfd, char const*, filename, int, mode)
inline LINUX_DEFINE_SYSCALL2_NORET(fchmod, unsigned int, fd, linux_umode_t, mode)
inline LINUX_DEFINE_SYSCALL3_NORET(fchmodat, int, dfd, char const*, filename, linux_umode_t, mode)
inline LINUX_DEFINE_SYSCALL5_NORET(fchownat, int, dfd, char const*, filename, linux_uid_t, user, linux_gid_t, group, int, flag)
inline LINUX_DEFINE_SYSCALL3_NORET(fchown, unsigned int, fd, linux_uid_t, user, linux_gid_t, group)
inline LINUX_DEFINE_SYSCALL4_RET(openat, int, dfd, char const*, filename, int, flags, linux_umode_t, mode, linux_word_t)
inline LINUX_DEFINE_SYSCALL5_NORET(name_to_handle_at, int, dfd, char const*, name, struct linux_file_handle*, handle, int*, mnt_id, int, flag)
inline LINUX_DEFINE_SYSCALL3_RET(open_by_handle_at, int, mountdirfd, struct linux_file_handle*, handle, int, flags, linux_word_t)
inline LINUX_DEFINE_SYSCALL2_NORET(newfstat, unsigned int, fd, struct linux_stat*, statbuf)
inline LINUX_DEFINE_SYSCALL5_NORET(statx, int, dfd, char const*, filename, unsigned, flags, unsigned int, mask, struct linux_statx*, buffer)

//-----------------------------------------------------------------------------
// read/write

inline LINUX_DEFINE_SYSCALL3_RET(lseek, unsigned int, fd, linux_off_t, offset, unsigned int, whence, linux_off_t)
inline LINUX_DEFINE_SYSCALL3_RET(read, unsigned int, fd, char*, buf, linux_size_t, count, linux_ssize_t)
inline LINUX_DEFINE_SYSCALL3_RET(write, unsigned int, fd, char const*, buf, linux_size_t, count, linux_ssize_t)
inline LINUX_DEFINE_SYSCALL3_RET(readv, linux_uword_t, fd, struct linux_iovec const*, vec, linux_uword_t, vlen, linux_ssize_t)
inline LINUX_DEFINE_SYSCALL3_RET(writev, linux_uword_t, fd, struct linux_iovec const*, vec, linux_uword_t, vlen, linux_ssize_t)
inline enum linux_error_t linux_pread64(unsigned int const fd, char* const buf, linux_size_t const count, linux_loff_t const pos, linux_ssize_t* const result)
{
#if defined(LINUX_ARCH_ARM_EABI)
	linux_word_t const ret = linux_syscall6(LINUX_PARAM(fd), LINUX_PARAM(buf), LINUX_PARAM(count), 0, LINUX_EXPAND(pos), linux_syscall_name_pread64);
#elif defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall5(LINUX_PARAM(fd), LINUX_PARAM(buf), LINUX_PARAM(count), LINUX_EXPAND(pos), linux_syscall_name_pread64);
#else
	linux_word_t const ret = linux_syscall4(LINUX_PARAM(fd), LINUX_PARAM(buf), LINUX_PARAM(count), LINUX_PARAM(pos), linux_syscall_name_pread64);
#endif
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_ssize_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_pwrite64(unsigned int const fd, char const* const buf, linux_size_t const count, linux_loff_t const pos, linux_ssize_t* const result)
{
#if defined(LINUX_ARCH_ARM_EABI)
	linux_word_t const ret = linux_syscall6(LINUX_PARAM(fd), LINUX_PARAM(buf), LINUX_PARAM(count), 0, LINUX_EXPAND(pos), linux_syscall_name_pwrite64);
#elif defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall5(LINUX_PARAM(fd), LINUX_PARAM(buf), LINUX_PARAM(count), LINUX_EXPAND(pos), linux_syscall_name_pwrite64);
#else
	linux_word_t const ret = linux_syscall4(LINUX_PARAM(fd), LINUX_PARAM(buf), LINUX_PARAM(count), LINUX_PARAM(pos), linux_syscall_name_pwrite64);
#endif
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_ssize_t)ret;
	return linux_error_none;
}
inline LINUX_DEFINE_SYSCALL5_RET(preadv, linux_uword_t, fd, struct linux_iovec const*, vec, linux_uword_t, vlen, linux_uword_t, pos_l, linux_uword_t, pos_h, linux_ssize_t)
inline LINUX_DEFINE_SYSCALL5_RET(pwritev, linux_uword_t, fd, struct linux_iovec const*, vec, linux_uword_t, vlen, linux_uword_t, pos_l, linux_uword_t, pos_h, linux_ssize_t)
inline LINUX_DEFINE_SYSCALL4_RET(sendfile64, int, out_fd, int, in_fd, linux_loff_t*, offset, linux_size_t, count, linux_ssize_t)
inline LINUX_DEFINE_SYSCALL4_RET(vmsplice, int, fd, struct linux_iovec const*, uiov, linux_uword_t, nr_segs, unsigned int, flags, linux_word_t)
inline LINUX_DEFINE_SYSCALL6_RET(splice, int, fd_in, linux_loff_t*, off_in, int, fd_out, linux_loff_t*, off_out, linux_size_t, len, unsigned int, flags, linux_word_t)
inline LINUX_DEFINE_SYSCALL4_RET(tee, int, fdin, int, fdout, linux_size_t, len, unsigned int, flags, int)
inline enum linux_error_t linux_readahead(int const fd, linux_loff_t const offset, linux_size_t const count)
{
#if defined(LINUX_ARCH_ARM_EABI)
	linux_word_t const ret = linux_syscall5(LINUX_PARAM(fd), 0, LINUX_EXPAND(offset), LINUX_PARAM(count), linux_syscall_name_readahead);
#elif defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall4(LINUX_PARAM(fd), LINUX_EXPAND(offset), LINUX_PARAM(count), linux_syscall_name_readahead);
#else
	linux_word_t const ret = linux_syscall3(LINUX_PARAM(fd), LINUX_PARAM(offset), LINUX_PARAM(count), linux_syscall_name_readahead);
#endif
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline LINUX_DEFINE_SYSCALL6_RET(process_vm_readv, linux_pid_t, pid, struct linux_iovec const*, lvec, linux_uword_t, liovcnt, struct linux_iovec const*, rvec, linux_uword_t, riovcnt, linux_uword_t, flags, linux_ssize_t)
inline LINUX_DEFINE_SYSCALL6_RET(process_vm_writev, linux_pid_t, pid, struct linux_iovec const*, lvec, linux_uword_t, liovcnt, struct linux_iovec const*, rvec, linux_uword_t, riovcnt, linux_uword_t, flags, linux_ssize_t)
inline LINUX_DEFINE_SYSCALL6_RET(copy_file_range, int, fd_in, linux_loff_t*, off_in, int, fd_out, linux_loff_t*, off_out, linux_size_t, len, unsigned int, flags, linux_ssize_t)
inline LINUX_DEFINE_SYSCALL6_RET(preadv2, linux_uword_t, fd, struct linux_iovec const*, vec, linux_uword_t, vlen, linux_uword_t, pos_l, linux_uword_t, pos_h, linux_rwf_t, flags, linux_ssize_t)
inline LINUX_DEFINE_SYSCALL6_RET(pwritev2, linux_uword_t, fd, struct linux_iovec const*, vec, linux_uword_t, vlen, linux_uword_t, pos_l, linux_uword_t, pos_h, linux_rwf_t, flags, linux_ssize_t)

//-----------------------------------------------------------------------------
// timerfd

inline LINUX_DEFINE_SYSCALL2_RET(timerfd_create, int, clockid, int, flags, int)
inline LINUX_DEFINE_SYSCALL4_NORET(timerfd_settime, int, ufd, int, flags, struct linux_kernel_itimerspec const*, utmr, struct linux_kernel_itimerspec*, otmr)
inline LINUX_DEFINE_SYSCALL2_NORET(timerfd_gettime, int, ufd, struct linux_kernel_itimerspec*, otmr)

//-----------------------------------------------------------------------------
// capabilities

inline LINUX_DEFINE_SYSCALL2_NORET(capget, linux_cap_user_header_t, header, struct linux_user_cap_data_struct*, dataptr)
inline LINUX_DEFINE_SYSCALL2_NORET(capset, linux_cap_user_header_t, header, struct linux_user_cap_data_struct const*, data)

//-----------------------------------------------------------------------------
// futexes

inline LINUX_DEFINE_SYSCALL6_RET(futex, uint32_t*, uaddr, int, op, uint32_t, val, struct linux_timespec*, utime, uint32_t*, uaddr2, uint32_t, val3, linux_word_t)
inline LINUX_DEFINE_SYSCALL3_NORET(get_robust_list, int, pid, struct linux_robust_list_head**, head_ptr, linux_size_t*, len_ptr)
inline LINUX_DEFINE_SYSCALL2_NORET(set_robust_list, struct linux_robust_list_head*, head, linux_size_t, len)

//-----------------------------------------------------------------------------
// interval timer

inline LINUX_DEFINE_SYSCALL2_NORET(getitimer, int, which, struct linux_itimerval*, value)
inline LINUX_DEFINE_SYSCALL3_NORET(setitimer, int, which, struct linux_itimerval*, value, struct linux_itimerval*, ovalue)

//-----------------------------------------------------------------------------
// kernel

inline LINUX_DEFINE_SYSCALL4_NORET(kexec_load, linux_uword_t, entry, linux_uword_t, nr_segments, struct linux_kexec_segment*, segments, linux_uword_t, flags)
inline LINUX_DEFINE_SYSCALL3_NORET(init_module, void*, umod, linux_uword_t, len, char const*, uargs)
inline LINUX_DEFINE_SYSCALL2_NORET(delete_module, char const*, name_user, unsigned int, flags)
inline LINUX_DEFINE_SYSCALL4_NORET(reboot, int, magic1, int, magic2, unsigned int, cmd, void*, arg)
inline LINUX_DEFINE_SYSCALL3_NORET(finit_module, int, fd, char const*, uargs, int, flags)

//-----------------------------------------------------------------------------
// timer

inline LINUX_DEFINE_SYSCALL3_NORET(timer_create, linux_clockid_t, which_clock, struct linux_sigevent*, timer_event_spec, linux_timer_t*, created_timer_id)
inline LINUX_DEFINE_SYSCALL2_NORET(timer_gettime, linux_timer_t, timer_id, struct linux_kernel_itimerspec*, setting)
inline LINUX_DEFINE_SYSCALL1_RET(timer_getoverrun, linux_timer_t, timer_id, int)
inline LINUX_DEFINE_SYSCALL4_NORET(timer_settime, linux_timer_t, timer_id, int, flags, struct linux_kernel_itimerspec const*, new_setting, struct linux_kernel_itimerspec*, old_setting)
inline LINUX_DEFINE_SYSCALL1_NORET(timer_delete, linux_timer_t, timer_id)

//-----------------------------------------------------------------------------
// clock

inline LINUX_DEFINE_SYSCALL2_NORET(clock_settime, linux_clockid_t, which_clock, struct linux_kernel_timespec const*, tp)
inline LINUX_DEFINE_SYSCALL2_NORET(clock_gettime, linux_clockid_t, which_clock, struct linux_kernel_timespec*, tp)
inline LINUX_DEFINE_SYSCALL2_NORET(clock_getres, linux_clockid_t, which_clock, struct linux_kernel_timespec*, tp)
inline LINUX_DEFINE_SYSCALL4_NORET(clock_nanosleep, linux_clockid_t, which_clock, int, flags, struct linux_kernel_timespec const*, rqtp, struct linux_kernel_timespec*, rmtp)
inline LINUX_DEFINE_SYSCALL2_RET(clock_adjtime, linux_clockid_t, which_clock, struct linux_timex*, utx, int)

//-----------------------------------------------------------------------------
// scheduler

inline LINUX_DEFINE_SYSCALL3_NORET(ioprio_set, int, which, int, who, int, ioprio)
inline LINUX_DEFINE_SYSCALL2_RET(ioprio_get, int, which, int, who, int)
inline LINUX_DEFINE_SYSCALL2_NORET(sched_setparam, linux_pid_t, pid, struct linux_sched_param*, param)
inline LINUX_DEFINE_SYSCALL3_NORET(sched_setscheduler, linux_pid_t, pid, int, policy, struct linux_sched_param*, param)
inline LINUX_DEFINE_SYSCALL1_RET(sched_getscheduler, linux_pid_t, pid, int)
inline LINUX_DEFINE_SYSCALL2_NORET(sched_getparam, linux_pid_t, pid, struct linux_sched_param*, param)
inline LINUX_DEFINE_SYSCALL3_NORET(sched_setaffinity, linux_pid_t, pid, unsigned int, len, linux_uword_t*, user_mask_ptr)
inline LINUX_DEFINE_SYSCALL3_NORET(sched_getaffinity, linux_pid_t, pid, unsigned int, len, linux_uword_t*, user_mask_ptr)
inline LINUX_DEFINE_SYSCALL0_NORET(sched_yield)
inline LINUX_DEFINE_SYSCALL1_RET(sched_get_priority_max, int, policy, int)
inline LINUX_DEFINE_SYSCALL1_RET(sched_get_priority_min, int, policy, int)
inline LINUX_DEFINE_SYSCALL2_NORET(sched_rr_get_interval, linux_pid_t, pid, struct linux_kernel_timespec*, interval)
inline LINUX_DEFINE_SYSCALL3_NORET(setpriority, int, which, int, who, int, niceval)
inline LINUX_DEFINE_SYSCALL2_RET(getpriority, int, which, int, who, linux_word_t)
inline LINUX_DEFINE_SYSCALL3_NORET(sched_setattr, linux_pid_t, pid, struct linux_sched_attr*, uattr, unsigned int, flags)
inline LINUX_DEFINE_SYSCALL4_NORET(sched_getattr, linux_pid_t, pid, struct linux_sched_attr*, uattr, unsigned int, size, unsigned int, flags)

//-----------------------------------------------------------------------------
// signals

inline LINUX_DEFINE_SYSCALL4_RET(signalfd4, int, ufd, linux_sigset_t*, user_mask, linux_size_t, sizemask, int, flags, int)
inline LINUX_DEFINE_SYSCALL2_NORET(kill, linux_pid_t, pid, int, sig)
inline LINUX_DEFINE_SYSCALL2_NORET(tkill, linux_pid_t, pid, int, sig)
inline LINUX_DEFINE_SYSCALL3_NORET(tgkill, linux_pid_t, tgid, linux_pid_t, pid, int, sig)
inline LINUX_DEFINE_SYSCALL2_NORET(sigaltstack, linux_stack_t const*, uss, linux_stack_t*, uoss)
inline LINUX_DEFINE_SYSCALL2_NORET(rt_sigsuspend, linux_sigset_t*, unewset, linux_size_t, sigsetsize)
inline LINUX_DEFINE_SYSCALL4_NORET(rt_sigaction, int, sig, struct linux_sigaction const*, act, struct linux_sigaction*, oact, linux_size_t, sigsetsize)
inline LINUX_DEFINE_SYSCALL4_NORET(rt_sigprocmask, int, how, linux_sigset_t*, nset, linux_sigset_t*, oset, linux_size_t, sigsetsize)
inline LINUX_DEFINE_SYSCALL2_NORET(rt_sigpending, linux_sigset_t*, uset, linux_size_t, sigsetsize)
inline LINUX_DEFINE_SYSCALL4_RET(rt_sigtimedwait, linux_sigset_t const*, uthese, linux_siginfo_t*, uinfo, struct linux_kernel_timespec const*, uts, linux_size_t, sigsetsize, int)
inline LINUX_DEFINE_SYSCALL3_NORET(rt_sigqueueinfo, linux_pid_t, pid, int, sig, linux_siginfo_t*, uinfo)
inline LINUX_DEFINE_SYSCALL4_NORET(rt_tgsigqueueinfo, linux_pid_t, tgid, linux_pid_t, pid, int, sig, linux_siginfo_t*, uinfo)

//-----------------------------------------------------------------------------
// process user/group id

inline LINUX_DEFINE_SYSCALL1_NORET(setuid, linux_uid_t, uid)
inline LINUX_DEFINE_SYSCALL1_NORET(setgid, linux_gid_t, gid)
inline LINUX_DEFINE_SYSCALL2_NORET(setreuid, linux_uid_t, ruid, linux_uid_t, euid)
inline LINUX_DEFINE_SYSCALL2_NORET(setregid, linux_gid_t, rgid, linux_gid_t, egid)
inline LINUX_DEFINE_SYSCALL3_NORET(setresuid, linux_uid_t, ruid, linux_uid_t, euid, linux_uid_t, suid)
inline LINUX_DEFINE_SYSCALL3_NORET(setresgid, linux_gid_t, rgid, linux_gid_t, egid, linux_gid_t, sgid)
inline LINUX_DEFINE_SYSCALL1_RET(setfsuid, linux_uid_t, uid, linux_word_t)
inline LINUX_DEFINE_SYSCALL1_RET(setfsgid, linux_gid_t, gid, linux_word_t)
inline LINUX_DEFINE_SYSCALL0_RET(getuid, linux_uid_t)
inline LINUX_DEFINE_SYSCALL0_RET(getgid, linux_gid_t)
inline LINUX_DEFINE_SYSCALL0_RET(geteuid, linux_uid_t)
inline LINUX_DEFINE_SYSCALL0_RET(getegid, linux_gid_t)
inline LINUX_DEFINE_SYSCALL3_NORET(getresuid, linux_uid_t*, ruidp, linux_uid_t*, euidp, linux_uid_t*, suidp)
inline LINUX_DEFINE_SYSCALL3_NORET(getresgid, linux_gid_t*, rgidp, linux_gid_t*, egidp, linux_gid_t*, sgidp)

//-----------------------------------------------------------------------------
// process/process group/session id

inline LINUX_DEFINE_SYSCALL2_NORET(setpgid, linux_pid_t, pid, linux_pid_t, pgid)
inline LINUX_DEFINE_SYSCALL0_RET(setsid, int)
inline LINUX_DEFINE_SYSCALL1_RET(getpgid, linux_pid_t, pid, int)
inline LINUX_DEFINE_SYSCALL1_RET(getsid, linux_pid_t, pid, int)
inline LINUX_DEFINE_SYSCALL0_RET(getpid, linux_pid_t)
inline LINUX_DEFINE_SYSCALL0_RET(getppid, int)
inline LINUX_DEFINE_SYSCALL0_RET(gettid, linux_pid_t)

//-----------------------------------------------------------------------------
// system time

inline LINUX_DEFINE_SYSCALL2_NORET(gettimeofday, struct linux_timeval*, tv, struct linux_timezone*, tz)
inline LINUX_DEFINE_SYSCALL2_NORET(settimeofday, struct linux_timeval*, tv, struct linux_timezone*, tz)
inline LINUX_DEFINE_SYSCALL1_RET(adjtimex, struct linux_timex*, txc_p, int)

//-----------------------------------------------------------------------------
// message queue

inline LINUX_DEFINE_SYSCALL4_RET(mq_open, char const*, u_name, int, oflag, linux_umode_t, mode, struct linux_mq_attr*, u_attr, int)
inline LINUX_DEFINE_SYSCALL1_NORET(mq_unlink, char const*, u_name)
inline LINUX_DEFINE_SYSCALL5_NORET(mq_timedsend, linux_mqd_t, mqdes, char const*, u_msg_ptr, linux_size_t, msg_len, unsigned int, msg_prio, struct linux_kernel_timespec const*, u_abs_timeout)
inline LINUX_DEFINE_SYSCALL5_RET(mq_timedreceive, linux_mqd_t, mqdes, char*, u_msg_ptr, linux_size_t, msg_len, unsigned int*, u_msg_prio, struct linux_kernel_timespec const*, u_abs_timeout, int)
inline LINUX_DEFINE_SYSCALL2_NORET(mq_notify, linux_mqd_t, mqdes, struct linux_sigevent const*, u_notification)
inline LINUX_DEFINE_SYSCALL3_NORET(mq_getsetattr, linux_mqd_t, mqdes, struct linux_mq_attr const*, u_mqstat, struct linux_mq_attr*, u_omqstat)

//-----------------------------------------------------------------------------
// socket

inline LINUX_DEFINE_SYSCALL3_RET(socket, int, family, int, type, int, protocol, int)
inline LINUX_DEFINE_SYSCALL4_NORET(socketpair, int, family, int, type, int, protocol, int*, usockvec)
inline LINUX_DEFINE_SYSCALL3_NORET(bind, int, fd, struct linux_sockaddr*, umyaddr, int, addrlen)
inline LINUX_DEFINE_SYSCALL2_NORET(listen, int, fd, int, backlog)
inline LINUX_DEFINE_SYSCALL3_NORET(connect, int, fd, struct linux_sockaddr*, uservaddr, int, addrlen)
inline LINUX_DEFINE_SYSCALL3_NORET(getsockname, int, fd, struct linux_sockaddr*, usockaddr, int*, usockaddr_len)
inline LINUX_DEFINE_SYSCALL3_NORET(getpeername, int, fd, struct linux_sockaddr*, usockaddr, int*, usockaddr_len)
inline LINUX_DEFINE_SYSCALL6_RET(sendto, int, fd, void*, buff, linux_size_t, len, unsigned int, flags, struct linux_sockaddr*, addr, int, addr_le, int)
inline LINUX_DEFINE_SYSCALL6_RET(recvfrom, int, fd, void*, ubuf, linux_size_t, size, unsigned int, flags, struct linux_sockaddr*, addr, int*, addr_len, int)
inline LINUX_DEFINE_SYSCALL5_NORET(setsockopt, int, fd, int, level, int, optname, char*, optval, int, optlen)
inline LINUX_DEFINE_SYSCALL5_NORET(getsockopt, int, fd, int, level, int, optname, char*, optval, int*, optlen)
inline LINUX_DEFINE_SYSCALL2_NORET(shutdown, int, fd, int, how)
inline LINUX_DEFINE_SYSCALL3_RET(sendmsg, int, fd, struct linux_user_msghdr*, msg, unsigned int, flags, int)
inline LINUX_DEFINE_SYSCALL3_RET(recvmsg, int, fd, struct linux_user_msghdr*, msg, unsigned int, flags, int)
inline LINUX_DEFINE_SYSCALL4_RET(accept4, int, fd, struct linux_sockaddr*, upeer_sockaddr, int*, upeer_addrlen, int, flags, int)
inline LINUX_DEFINE_SYSCALL5_RET(recvmmsg, int, fd, struct linux_mmsghdr*, mmsg, unsigned int, vlen, unsigned int, flags, struct linux_kernel_timespec*, timeout, int)
inline LINUX_DEFINE_SYSCALL4_RET(sendmmsg, int, fd, struct linux_mmsghdr*, mmsg, unsigned int, vlen, unsigned int, flags, int)

//-----------------------------------------------------------------------------
// memory

inline LINUX_DEFINE_SYSCALL1_RET(brk, linux_uword_t, brk, linux_uword_t)
inline LINUX_DEFINE_SYSCALL2_NORET(munmap, linux_uword_t, addr, linux_size_t, len)
inline LINUX_DEFINE_SYSCALL5_RET(mremap, linux_uword_t, addr, linux_uword_t, old_len, linux_uword_t, new_len, linux_uword_t, flags, linux_uword_t, new_addr, linux_uword_t)
inline LINUX_DEFINE_SYSCALL3_NORET(mprotect, linux_uword_t, start, linux_size_t, len, linux_uword_t, prot)
inline LINUX_DEFINE_SYSCALL3_NORET(msync, linux_uword_t, start, linux_size_t, len, int, flags)
inline LINUX_DEFINE_SYSCALL2_NORET(mlock, linux_uword_t, start, linux_size_t, len)
inline LINUX_DEFINE_SYSCALL2_NORET(munlock, linux_uword_t, start, linux_size_t, len)
inline LINUX_DEFINE_SYSCALL1_NORET(mlockall, int, flags)
inline LINUX_DEFINE_SYSCALL0_NORET(munlockall)
inline LINUX_DEFINE_SYSCALL3_NORET(mincore, linux_uword_t, start, linux_size_t, len, unsigned char*, vec)
inline LINUX_DEFINE_SYSCALL3_NORET(madvise, linux_uword_t, start, linux_size_t, len_in, int, behavior)
inline LINUX_DEFINE_SYSCALL5_NORET(remap_file_pages, linux_uword_t, start, linux_uword_t, size, linux_uword_t, prot, linux_uword_t, pgoff, linux_uword_t, flags)
inline LINUX_DEFINE_SYSCALL6_NORET(mbind, linux_uword_t, start, linux_uword_t, len, linux_uword_t, mode, linux_uword_t const*, nmask, linux_uword_t, maxnode, unsigned int, flags)
inline LINUX_DEFINE_SYSCALL5_NORET(get_mempolicy, int*, policy, linux_uword_t*, nmask, linux_uword_t, maxnode, linux_uword_t, addr, linux_uword_t, flags)
inline LINUX_DEFINE_SYSCALL3_NORET(set_mempolicy, int, mode, linux_uword_t const*, nmask, linux_uword_t, maxnode)
inline LINUX_DEFINE_SYSCALL6_NORET(move_pages, linux_pid_t, pid, linux_uword_t, nr_pages, void const**, pages, int const*, nodes, int*, status, int, flags)
inline LINUX_DEFINE_SYSCALL2_RET(membarrier, int, cmd, int, flags, int)
inline LINUX_DEFINE_SYSCALL3_NORET(mlock2, linux_uword_t, start, linux_size_t, len, int, flags)
inline LINUX_DEFINE_SYSCALL4_NORET(pkey_mprotect, linux_uword_t, start, linux_size_t, len, linux_uword_t, prot, int, pkey)
inline LINUX_DEFINE_SYSCALL2_RET(pkey_alloc, linux_uword_t, flags, linux_uword_t, init_val, int)
inline LINUX_DEFINE_SYSCALL1_NORET(pkey_free, int, pkey)

//-----------------------------------------------------------------------------
// keys management

inline LINUX_DEFINE_SYSCALL5_RET(add_key, char const*, type, char const*, description, void const*, payload, linux_size_t, plen, linux_key_serial_t, ringid, linux_word_t)
inline LINUX_DEFINE_SYSCALL4_RET(request_key, char const*, type, char const*, description, char const*, callout_info, linux_key_serial_t, destringid, linux_word_t)
inline LINUX_DEFINE_SYSCALL5_RET(keyctl, int, option, linux_uword_t, arg2, linux_uword_t, arg3, linux_uword_t, arg4, linux_uword_t, arg5, linux_word_t)

//-----------------------------------------------------------------------------
// process creation

inline LINUX_DEFINE_SYSCALL5_NORET(waitid, int, which, linux_pid_t, upid, struct linux_siginfo*, infop, int, options, struct linux_rusage*, ru)
inline LINUX_DEFINE_SYSCALL5_RET(clone, linux_uword_t, clone_flags, linux_uword_t, newsp, int*, parent_tidptr, int*, child_tidptr, linux_uword_t, tls, linux_word_t)
inline LINUX_DEFINE_SYSCALL3_NORET(execve, char const*, filename, char const* const*, argv, char const* const*, envp)
inline LINUX_DEFINE_SYSCALL4_RET(wait4, linux_pid_t, upid, int*, stat_addr, int, options, struct linux_rusage*, ru, linux_word_t)
inline LINUX_DEFINE_SYSCALL5_NORET(execveat, int, fd, char const*, filename, char const* const*, argv, char const* const*, envp, int, flags)

//-----------------------------------------------------------------------------
// fanotify

inline LINUX_DEFINE_SYSCALL2_RET(fanotify_init, unsigned int, flags, unsigned int, event_f_flags, int)
inline enum linux_error_t linux_fanotify_mark(int const fanotify_fd, unsigned int const flags, uint64_t const mask, int const dfd, char const* const pathname)
{
#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall6(LINUX_PARAM(fanotify_fd), LINUX_PARAM(flags), LINUX_EXPAND(mask), LINUX_PARAM(dfd), LINUX_PARAM(pathname), linux_syscall_name_fanotify_mark);
#else
	linux_word_t const ret = linux_syscall5(LINUX_PARAM(fanotify_fd), LINUX_PARAM(flags), LINUX_PARAM(mask), LINUX_PARAM(dfd), LINUX_PARAM(pathname), linux_syscall_name_fanotify_mark);
#endif
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// misc file descriptors

inline LINUX_DEFINE_SYSCALL2_RET(eventfd2, unsigned int, count, int, flags, int)
inline LINUX_DEFINE_SYSCALL2_RET(memfd_create, char const*, uname, unsigned int, flags, int)
inline LINUX_DEFINE_SYSCALL1_RET(userfaultfd, int, flags, int)

//-----------------------------------------------------------------------------
// misc

inline LINUX_DEFINE_SYSCALL2_RET(getcwd, char*, buf, linux_uword_t, size, int)
inline enum linux_error_t linux_lookup_dcookie(uint64_t const cookie64, char* const buf, linux_size_t const len, int* const result)
{
#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall4(LINUX_EXPAND(cookie64), LINUX_PARAM(buf), LINUX_PARAM(len), linux_syscall_name_fanotify_mark);
#else
	linux_word_t const ret = linux_syscall3(LINUX_PARAM(cookie64), LINUX_PARAM(buf), LINUX_PARAM(len), linux_syscall_name_fanotify_mark);
#endif
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline LINUX_DEFINE_SYSCALL2_NORET(umount, char*, name, int, flags)
inline LINUX_DEFINE_SYSCALL5_NORET(mount, char*, dev_name, char*, dir_name, char*, type, linux_uword_t, flags, void*, data)
inline LINUX_DEFINE_SYSCALL2_NORET(pivot_root, char const*, new_root, char const*, put_old)
inline LINUX_DEFINE_SYSCALL1_NORET(chdir, char const*, filename)
inline LINUX_DEFINE_SYSCALL1_NORET(fchdir, unsigned int, fd)
inline LINUX_DEFINE_SYSCALL1_NORET(chroot, char const*, filename)
inline LINUX_DEFINE_SYSCALL0_NORET(vhangup)
inline LINUX_DEFINE_SYSCALL2_NORET(pipe2, int*, fildes, int, flags)
inline LINUX_DEFINE_SYSCALL4_NORET(quotactl, unsigned int, cmd, char const*, special, linux_qid_t, id, void*, addr)
inline LINUX_DEFINE_SYSCALL0_NORET(sync)
inline LINUX_DEFINE_SYSCALL1_NORET(fsync, unsigned int, fd)
inline LINUX_DEFINE_SYSCALL1_NORET(fdatasync, unsigned int, fd)
inline LINUX_DEFINE_SYSCALL4_NORET(utimensat, int, dfd, char const*, filename, struct linux_kernel_timespec*, utimes, int, flags)
inline LINUX_DEFINE_SYSCALL1_NORET(acct, char const*, name)
inline LINUX_DEFINE_SYSCALL1_RET(personality, unsigned int, personality, unsigned int)
inline LINUX_DEFINE_SYSCALL1_RET(set_tid_address, int*, tidptr, linux_pid_t)
inline LINUX_DEFINE_SYSCALL1_NORET(unshare, linux_uword_t, unshare_flags)
inline LINUX_DEFINE_SYSCALL2_NORET(nanosleep, struct linux_kernel_timespec*, rqtp, struct linux_kernel_timespec*, rmtp)
inline LINUX_DEFINE_SYSCALL3_RET(syslog, int, type, char*, buf, int, len, int)
inline LINUX_DEFINE_SYSCALL4_RET(ptrace, linux_word_t, request, linux_word_t, pid, linux_uword_t, addr, linux_uword_t, data, linux_word_t)
inline LINUX_DEFINE_SYSCALL1_RET(times, struct linux_tms*, tbuf, linux_word_t)
inline LINUX_DEFINE_SYSCALL2_RET(getgroups, int, gidsetsize, linux_gid_t*, grouplis, int)
inline LINUX_DEFINE_SYSCALL2_NORET(setgroups, int, gidsetsize, linux_gid_t*, grouplist)
inline LINUX_DEFINE_SYSCALL1_NORET(newuname, struct linux_new_utsname*, name)
inline LINUX_DEFINE_SYSCALL2_NORET(sethostname, char*, name, int, len)
inline LINUX_DEFINE_SYSCALL2_NORET(setdomainname, char*, name, int, len)
inline LINUX_DEFINE_SYSCALL2_NORET(getrlimit, unsigned int, resource, struct linux_rlimit*, rlim)
inline LINUX_DEFINE_SYSCALL2_NORET(setrlimit, unsigned int, resource, struct linux_rlimit*, rlim)
inline LINUX_DEFINE_SYSCALL2_NORET(getrusage, int, who, struct linux_rusage*, ru)
inline LINUX_DEFINE_SYSCALL1_RET(umask, int, mask, int)
inline LINUX_DEFINE_SYSCALL5_RET(prctl, int, option, linux_uword_t, arg2, linux_uword_t, arg3, linux_uword_t, arg4, linux_uword_t, arg5, linux_word_t)
inline LINUX_DEFINE_SYSCALL3_NORET(getcpu, unsigned int*, cpup, unsigned int*, nodep, struct linux_getcpu_cache*, unused)
inline LINUX_DEFINE_SYSCALL1_NORET(sysinfo, struct linux_sysinfo*, info)
inline LINUX_DEFINE_SYSCALL2_NORET(swapon, char const*, specialfile, int, swap_flags)
inline LINUX_DEFINE_SYSCALL1_NORET(swapoff, char const*, specialfile)
inline LINUX_DEFINE_SYSCALL5_RET(perf_event_open, struct linux_perf_event_attr*, attr_uptr, linux_pid_t, pid, int, cpu, int, group_fd, linux_uword_t, flags, int)
inline LINUX_DEFINE_SYSCALL4_NORET(prlimit64, linux_pid_t, pid, unsigned int, resource, struct linux_rlimit64 const*, new_rlim, struct linux_rlimit64*, old_rlim)
inline LINUX_DEFINE_SYSCALL1_NORET(syncfs, int, fd)
inline LINUX_DEFINE_SYSCALL2_NORET(setns, int, fd, int, nstype)
inline LINUX_DEFINE_SYSCALL5_RET(kcmp, linux_pid_t, pid1, linux_pid_t, pid2, int, type, linux_uword_t, idx1, linux_uword_t, idx2, int)
inline LINUX_DEFINE_SYSCALL3_RET(seccomp, unsigned int, op, unsigned int, flags, char const*, uargs, linux_word_t)
inline LINUX_DEFINE_SYSCALL3_RET(getrandom, char*, buf, linux_size_t, count, unsigned int, flags, linux_ssize_t)
inline LINUX_DEFINE_SYSCALL3_RET(bpf, int, cmd, union linux_bpf_attr*, uattr, unsigned int, size, int)
inline LINUX_DEFINE_SYSCALL4_NORET(rseq, struct linux_rseq*, rseq, uint32_t, rseq_len, int, flags, uint32_t, sig)

//=============================================================================
// Architecture specific syscalls

#if defined(LINUX_ARCH_ARM64) || defined(LINUX_ARCH_X86) || defined(LINUX_ARCH_X32) || defined(LINUX_ARCH_X86_64)
inline enum linux_error_t linux_sync_file_range(int const fd, linux_loff_t const offset, linux_loff_t const nbytes, unsigned int const flags)
{
#if defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall6(LINUX_PARAM(fd), LINUX_EXPAND(offset), LINUX_EXPAND(nbytes), LINUX_PARAM(flags), linux_syscall_name_sync_file_range);
#else
	linux_word_t const ret = linux_syscall4(LINUX_PARAM(fd), LINUX_PARAM(offset), LINUX_PARAM(nbytes), LINUX_PARAM(flags), linux_syscall_name_sync_file_range);
#endif
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline LINUX_DEFINE_SYSCALL4_RET(migrate_pages, linux_pid_t, pid, linux_uword_t, maxnode, linux_uword_t const*, old_nodes, linux_uword_t const*, new_nodes, int)
#endif

#if defined(LINUX_ARCH_ARM_EABI)
inline enum linux_error_t linux_sync_file_range2(int const fd, unsigned int const flags, linux_loff_t const offset, linux_loff_t const nbytes)
{
	linux_word_t const ret = linux_syscall6(LINUX_PARAM(fd), LINUX_PARAM(flags), LINUX_EXPAND(offset), LINUX_EXPAND(nbytes), linux_syscall_name_sync_file_range2);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_arm_fadvise64_64(int const fd, int const advice, linux_loff_t const offset, linux_loff_t const len)
{
	linux_word_t const ret = linux_syscall6(LINUX_PARAM(fd), LINUX_PARAM(advice), LINUX_EXPAND(offset), LINUX_EXPAND(len), linux_syscall_name_arm_fadvise64_64);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline LINUX_DEFINE_SYSCALL3_RET(pciconfig_iobase, linux_word_t, which, linux_uword_t, bus, linux_uword_t, devfn, linux_word_t)
inline LINUX_DEFINE_SYSCALL5_NORET(pciconfig_read, linux_uword_t, bus, linux_uword_t, dfn, linux_uword_t, off, linux_uword_t, len, void*, buf)
inline LINUX_DEFINE_SYSCALL5_NORET(pciconfig_write, linux_uword_t, bus, linux_uword_t, dfn, linux_uword_t, off, linux_uword_t, len, void*, buf)
inline LINUX_DEFINE_SYSCALL4_RET(send, int, fd, void*, buff, linux_size_t, len, unsigned int, flags, int)
inline LINUX_DEFINE_SYSCALL4_RET(recv, int, fd, void*, ubuf, linux_size_t, size, unsigned int, flags, int)
inline LINUX_DEFINE_SYSCALL0_NORET(breakpoint)
inline LINUX_DEFINE_SYSCALL3_NORET(cacheflush, linux_uword_t, start, linux_uword_t, end, int, flags)
inline LINUX_DEFINE_SYSCALL0_NORET(usr26)
inline LINUX_DEFINE_SYSCALL0_NORET(usr32)
inline LINUX_DEFINE_SYSCALL1_NORET(set_tls, linux_uword_t, val)
inline LINUX_DEFINE_SYSCALL0_RET(get_tls, linux_uword_t)
#endif

#if defined(LINUX_ARCH_ARM64) || defined(LINUX_ARCH_X86)
inline enum linux_error_t linux_fadvise64_64(int const fd, linux_loff_t const offset, linux_loff_t const len, int const advice)
{
#if defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall6(LINUX_PARAM(fd), LINUX_EXPAND(offset), LINUX_EXPAND(len), LINUX_PARAM(advice), linux_syscall_name_fadvise64_64);
#else
	linux_word_t const ret = linux_syscall4(LINUX_PARAM(fd), LINUX_PARAM(offset), LINUX_PARAM(len), LINUX_PARAM(advice), linux_syscall_name_fadvise64_64);
#endif
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
#endif

#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_ARM64) || defined(LINUX_ARCH_X32) || defined(LINUX_ARCH_X86_64)
inline LINUX_DEFINE_SYSCALL2_RET(msgget, linux_key_t, key, int, msgflg, linux_word_t)
inline LINUX_DEFINE_SYSCALL3_RET(msgctl, int, msqid, int, cmd, struct linux_msqid64_ds*, buf, linux_word_t)
inline LINUX_DEFINE_SYSCALL5_RET(msgrcv, int, msqid, struct linux_msgbuf*, msgp, linux_size_t, msgsz, linux_word_t, msgtyp, int, msgflg, linux_word_t)
inline LINUX_DEFINE_SYSCALL4_NORET(msgsnd, int, msqid, struct linux_msgbuf*, msgp, linux_size_t, msgsz, int, msgflg)
inline LINUX_DEFINE_SYSCALL3_RET(semget, linux_key_t, key, int, nsems, int, semflg, linux_word_t)
inline LINUX_DEFINE_SYSCALL4_RET(semctl, int, semid, int, semnum, int, cmd, linux_uword_t, arg, linux_word_t)
inline LINUX_DEFINE_SYSCALL4_NORET(semtimedop, int, semid, struct linux_sembuf*, tsops, unsigned int, nsops, struct linux_kernel_timespec const*, timeout)
inline LINUX_DEFINE_SYSCALL3_NORET(semop, int, semid, struct linux_sembuf*, tsops, unsigned, nsops)
inline LINUX_DEFINE_SYSCALL3_RET(shmget, linux_key_t, key, linux_size_t, size, int, shmflg, linux_word_t)
inline LINUX_DEFINE_SYSCALL3_RET(shmctl, int, shmid, int, cmd, struct linux_shmid64_ds*, buf, linux_word_t)
inline LINUX_DEFINE_SYSCALL3_RET(shmat, int, shmid, char*, shmaddr, int, shmflg, linux_word_t)
inline LINUX_DEFINE_SYSCALL1_NORET(shmdt, char*, shmaddr)
inline LINUX_DEFINE_SYSCALL3_RET(accept, int, fd, struct linux_sockaddr*, upeer_sockaddr, int*, upeer_addrlen, int)
#endif

#if defined(LINUX_ARCH_ARM64) || defined(LINUX_ARCH_X32) || defined(LINUX_ARCH_X86_64)
inline LINUX_DEFINE_SYSCALL4_NORET(newfstatat, int, dfd, char const*, filename, struct linux_stat*, statbuf, int, flag)
inline LINUX_DEFINE_SYSCALL6_RET(mmap, linux_uword_t, addr, linux_uword_t, len, linux_uword_t, prot, linux_uword_t, flags, linux_uword_t, fd, linux_uword_t, off, linux_uword_t)
#endif

#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_X86) || defined(LINUX_ARCH_X32) || defined(LINUX_ARCH_X86_64)
inline LINUX_DEFINE_SYSCALL3_RET(signalfd, int, ufd, linux_sigset_t*, user_mask, linux_size_t, sizemask, int)
inline LINUX_DEFINE_SYSCALL0_RET(fork, linux_word_t)
inline LINUX_DEFINE_SYSCALL3_RET(open, char const*, filename, int, flags, linux_umode_t, mode, linux_word_t)
inline LINUX_DEFINE_SYSCALL2_RET(creat, char const*, pathname, linux_umode_t, mode, linux_word_t)
inline LINUX_DEFINE_SYSCALL2_NORET(link, char const*, oldname, char const*, newname)
inline LINUX_DEFINE_SYSCALL1_NORET(unlink, char const*, pathname)
inline LINUX_DEFINE_SYSCALL3_NORET(mknod, char const*, filename, linux_umode_t, mode, unsigned, dev)
inline LINUX_DEFINE_SYSCALL2_NORET(chmod, char const*, filename, linux_umode_t, mode)
inline LINUX_DEFINE_SYSCALL0_NORET(pause)
inline LINUX_DEFINE_SYSCALL2_NORET(access, char const*, filename, int, mode)
inline LINUX_DEFINE_SYSCALL2_NORET(rename, char const*, oldname, char const*, newname)
inline LINUX_DEFINE_SYSCALL2_NORET(mkdir, char const*, pathname, linux_umode_t, mode)
inline LINUX_DEFINE_SYSCALL1_NORET(rmdir, char const*, pathname)
inline LINUX_DEFINE_SYSCALL1_NORET(pipe, int*, fildes)
inline LINUX_DEFINE_SYSCALL2_NORET(ustat, unsigned int, dev, struct linux_ustat*, ubuf)
inline LINUX_DEFINE_SYSCALL2_RET(dup2, unsigned int, oldfd, unsigned int, newfd, int)
inline LINUX_DEFINE_SYSCALL0_RET(getpgrp, int)
inline LINUX_DEFINE_SYSCALL2_NORET(symlink, char const*, oldname, char const*, newname)
inline LINUX_DEFINE_SYSCALL3_RET(readlink, char const*, path, char*, buf, int, bufsiz, int)
inline LINUX_DEFINE_SYSCALL2_NORET(newstat, char const*, filename, struct linux_stat*, statbuf)
inline LINUX_DEFINE_SYSCALL2_NORET(newlstat, char const*, filename, struct linux_stat*, statbuf)
inline LINUX_DEFINE_SYSCALL3_RET(sysfs, int, option, linux_uword_t, arg1, linux_uword_t, arg2, int)
inline LINUX_DEFINE_SYSCALL3_RET(getdents, unsigned int, fd, struct linux_dirent*, dirent, unsigned int, count, int)
inline LINUX_DEFINE_SYSCALL5_RET(select, int, n, linux_fd_set*, inp, linux_fd_set*, outp, linux_fd_set*, exp, struct linux_timeval*, tvp, int)
inline LINUX_DEFINE_SYSCALL1_NORET(sysctl, struct linux_sysctl_args*, args)
inline LINUX_DEFINE_SYSCALL3_RET(poll, struct linux_pollfd*, ufds, unsigned int, nfds, int, timeout_msecs, int)
inline LINUX_DEFINE_SYSCALL0_RET(vfork, linux_word_t)
inline LINUX_DEFINE_SYSCALL3_NORET(lchown, char const*, filename, linux_uid_t, user, linux_gid_t, group)
inline LINUX_DEFINE_SYSCALL3_NORET(chown, char const*, filename, linux_uid_t, user, linux_gid_t, group)
inline LINUX_DEFINE_SYSCALL1_RET(epoll_create, int, size, int)
inline LINUX_DEFINE_SYSCALL4_RET(epoll_wait, int, epfd, struct linux_epoll_event*, events, int, maxevents, int, timeout, int)
inline LINUX_DEFINE_SYSCALL2_NORET(utimes, char*, filename, struct linux_timeval*, utimes)
inline LINUX_DEFINE_SYSCALL0_RET(inotify_init, int)
inline LINUX_DEFINE_SYSCALL3_NORET(futimesat, int, dfd, char const*, filename, struct linux_timeval*, utimes)
inline LINUX_DEFINE_SYSCALL1_RET(eventfd, unsigned int, count, int)
#endif

#if defined(LINUX_ARCH_X86) || defined(LINUX_ARCH_X32) || defined(LINUX_ARCH_X86_64)
inline LINUX_DEFINE_SYSCALL1_RET(alarm, unsigned int, seconds, unsigned int)
inline LINUX_DEFINE_SYSCALL2_NORET(utime, char*, filename, struct linux_utimbuf*, times)
inline enum linux_error_t linux_modify_ldt(int const func, void* const ptr, linux_uword_t const bytecount, int* const result)
{
	int const ret = (int)linux_syscall3(LINUX_PARAM(func), LINUX_PARAM(ptr), LINUX_PARAM(bytecount), linux_syscall_name_modify_ldt);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline LINUX_DEFINE_SYSCALL2_NORET(arch_prctl, int, option, linux_uword_t, arg2)
inline LINUX_DEFINE_SYSCALL1_NORET(iopl, unsigned int, level)
inline LINUX_DEFINE_SYSCALL3_NORET(ioperm, linux_uword_t, from, linux_uword_t, num, int, turn_on)
inline LINUX_DEFINE_SYSCALL1_RET(time, linux_time_t*, tloc, linux_time_t)
inline enum linux_error_t linux_fadvise64(int const fd, linux_loff_t const offset, linux_size_t const len, int const advice)
{
#if defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall5(LINUX_PARAM(fd), LINUX_EXPAND(offset), LINUX_PARAM(len), LINUX_PARAM(advice), linux_syscall_name_fadvise64);
#else
	linux_word_t const ret = linux_syscall4(LINUX_PARAM(fd), LINUX_PARAM(offset), LINUX_PARAM(len), LINUX_PARAM(advice), linux_syscall_name_fadvise64);
#endif
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
#endif

#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_X86)
inline LINUX_DEFINE_SYSCALL3_RET(fcntl64, unsigned int, fd, unsigned int, cmd, linux_uword_t, arg, linux_word_t)
inline LINUX_DEFINE_SYSCALL3_NORET(statfs64, char const*, pathname, linux_size_t, sz, struct linux_statfs64*, buf)
inline LINUX_DEFINE_SYSCALL3_NORET(fstatfs64, unsigned int, fd, linux_size_t, sz, struct linux_statfs64*, buf)
inline enum linux_error_t linux_truncate64(char const* const path, linux_loff_t const length)
{
#if defined(LINUX_ARCH_ARM_EABI)
	linux_word_t const ret = linux_syscall4(LINUX_PARAM(path), 0, LINUX_EXPAND(length), linux_syscall_name_truncate64);
#elif defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall3(LINUX_PARAM(path), LINUX_EXPAND(length), linux_syscall_name_truncate64);
#else
	linux_word_t const ret = linux_syscall2(LINUX_PARAM(path), LINUX_PARAM(length), linux_syscall_name_truncate64);
#endif
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_ftruncate64(unsigned int const fd, linux_loff_t const length)
{
#if defined(LINUX_ARCH_ARM_EABI)
	linux_word_t const ret = linux_syscall4(LINUX_PARAM(fd), 0, LINUX_EXPAND(length), linux_syscall_name_ftruncate64);
#elif defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall3(LINUX_PARAM(fd), LINUX_EXPAND(length), linux_syscall_name_ftruncate64);
#else
	linux_word_t const ret = linux_syscall2(LINUX_PARAM(fd), LINUX_PARAM(length), linux_syscall_name_ftruncate64);
#endif
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline LINUX_DEFINE_SYSCALL5_NORET(llseek, unsigned int, fd, linux_uword_t, offset_high, linux_uword_t, offset_low, linux_loff_t*, result, unsigned int, whence)
inline LINUX_DEFINE_SYSCALL4_RET(sendfile, int, out_fd, int, in_fd, linux_off_t*, offset, linux_size_t, count, linux_ssize_t)
inline LINUX_DEFINE_SYSCALL2_NORET(fstat64, linux_uword_t, fd, struct linux_stat64*, statbuf)
inline LINUX_DEFINE_SYSCALL4_NORET(fstatat64, int, dfd, char const*, filename, struct linux_stat64*, statbuf, int, flag)
inline LINUX_DEFINE_SYSCALL3_NORET(lchown16, char const*, filename, linux_old_uid_t, user, linux_old_gid_t, group)
inline LINUX_DEFINE_SYSCALL1_NORET(setuid16, linux_old_uid_t, uid)
inline LINUX_DEFINE_SYSCALL0_RET(getuid16, linux_old_uid_t)
inline LINUX_DEFINE_SYSCALL1_RET(nice, int, increment, linux_word_t)
inline LINUX_DEFINE_SYSCALL1_NORET(setgid16, linux_old_gid_t, gid)
inline LINUX_DEFINE_SYSCALL0_RET(getgid16, linux_old_gid_t)
inline LINUX_DEFINE_SYSCALL0_RET(geteuid16, linux_old_uid_t)
inline LINUX_DEFINE_SYSCALL0_RET(getegid16, linux_old_gid_t)
inline LINUX_DEFINE_SYSCALL3_NORET(sigaction, int, sig, struct linux_old_sigaction const*, act, struct linux_old_sigaction*, oact)
inline LINUX_DEFINE_SYSCALL2_NORET(setreuid16, linux_old_uid_t, ruid, linux_old_uid_t, euid)
inline LINUX_DEFINE_SYSCALL2_NORET(setregid16, linux_old_gid_t, rgid, linux_old_gid_t, egid)
inline LINUX_DEFINE_SYSCALL3_NORET(sigsuspend, int, unused1, int, unused2, linux_old_sigset_t, mask)
inline LINUX_DEFINE_SYSCALL1_NORET(sigpending, linux_old_sigset_t*, uset)
inline LINUX_DEFINE_SYSCALL2_RET(getgroups16, int, gidsetsize, linux_old_gid_t*, grouplist, int)
inline LINUX_DEFINE_SYSCALL2_NORET(setgroups16, int, gidsetsize, linux_old_gid_t*, grouplist)
inline LINUX_DEFINE_SYSCALL1_NORET(uselib, char const*, library)
inline LINUX_DEFINE_SYSCALL3_NORET(fchown16, unsigned int, fd, linux_old_uid_t, user, linux_old_gid_t, group)
inline LINUX_DEFINE_SYSCALL3_NORET(sigprocmask, int, how, linux_old_sigset_t*, nset, linux_old_sigset_t*, oset)
inline LINUX_DEFINE_SYSCALL2_NORET(bdflush, int, func, linux_word_t, data)
inline LINUX_DEFINE_SYSCALL1_RET(setfsuid16, linux_old_uid_t, uid, linux_word_t)
inline LINUX_DEFINE_SYSCALL1_RET(setfsgid16, linux_old_gid_t, gid, linux_word_t)
inline LINUX_DEFINE_SYSCALL3_NORET(setresuid16, linux_old_uid_t, ruid, linux_old_uid_t, euid, linux_old_uid_t, suid)
inline LINUX_DEFINE_SYSCALL3_NORET(getresuid16, linux_old_uid_t*, ruidp, linux_old_uid_t*, euidp, linux_old_uid_t*, suidp)
inline LINUX_DEFINE_SYSCALL3_NORET(setresgid16, linux_old_gid_t, rgid, linux_old_gid_t, egid, linux_old_gid_t, sgid)
inline LINUX_DEFINE_SYSCALL3_NORET(getresgid16, linux_old_gid_t*, rgidp, linux_old_gid_t*, egidp, linux_old_gid_t*, sgidp)
inline LINUX_DEFINE_SYSCALL3_NORET(chown16, char const*, filename, linux_old_uid_t, user, linux_old_gid_t, group)
inline LINUX_DEFINE_SYSCALL6_RET(mmap_pgoff, linux_uword_t, addr, linux_uword_t, len, linux_uword_t, prot, linux_uword_t, flags, linux_uword_t, fd, linux_uword_t, pgoff, linux_uword_t)
inline LINUX_DEFINE_SYSCALL2_NORET(stat64, char const*, filename, struct linux_stat64*, statbuf)
inline LINUX_DEFINE_SYSCALL2_NORET(lstat64, char const*, filename, struct linux_stat64*, statbuf)
#endif

#if defined(LINUX_ARCH_X86)
inline LINUX_DEFINE_SYSCALL3_RET(waitpid, linux_pid_t, pid, int*, stat_addr, int, options, linux_word_t)
inline LINUX_DEFINE_SYSCALL2_NORET(stat, char const*, filename, struct linux_old_kernel_stat*, statbuf)
inline LINUX_DEFINE_SYSCALL1_NORET(oldumount, char*, name)
inline LINUX_DEFINE_SYSCALL1_NORET(stime, linux_time_t*, tptr)
inline LINUX_DEFINE_SYSCALL2_NORET(fstat, unsigned int, fd, struct linux_old_kernel_stat*, statbuf)
inline LINUX_DEFINE_SYSCALL2_RET(signal, int, sig, linux_sighandler_t, handler, linux_uword_t)
inline LINUX_DEFINE_SYSCALL1_NORET(olduname, struct linux_oldold_utsname*, name)
inline LINUX_DEFINE_SYSCALL0_RET(sgetmask, int)
inline LINUX_DEFINE_SYSCALL1_RET(ssetmask, int, newmask, int)
inline LINUX_DEFINE_SYSCALL2_NORET(old_getrlimit, unsigned int, resource, struct linux_rlimit*, rlim)
inline LINUX_DEFINE_SYSCALL1_RET(old_select, struct linux_sel_arg_struct*, arg, int)
inline LINUX_DEFINE_SYSCALL2_NORET(lstat, char const*, filename, struct linux_old_kernel_stat*, statbuf)
inline LINUX_DEFINE_SYSCALL3_NORET(old_readdir, unsigned int, fd, struct linux_old_linux_dirent*, dirent, unsigned int, count)
inline LINUX_DEFINE_SYSCALL1_RET(old_mmap, struct linux_mmap_arg_struct*, arg, linux_uword_t)
inline LINUX_DEFINE_SYSCALL2_RET(socketcall, int, call, linux_uword_t*, args, int)
inline LINUX_DEFINE_SYSCALL1_NORET(uname, struct linux_old_utsname*, name)
inline LINUX_DEFINE_SYSCALL1_NORET(vm86old, struct linux_vm86_struct*, user_vm86)
inline LINUX_DEFINE_SYSCALL6_RET(ipc, unsigned int, call, int, first, linux_uword_t, second, linux_uword_t, third, void*, ptr, linux_word_t, fifth, linux_word_t)
inline LINUX_DEFINE_SYSCALL2_NORET(vm86, linux_uword_t, cmd, linux_uword_t, arg)
inline LINUX_DEFINE_SYSCALL1_NORET(set_thread_area, struct linux_user_desc*, u_info)
inline LINUX_DEFINE_SYSCALL1_NORET(get_thread_area, struct linux_user_desc*, u_info)
#endif

#if defined(LINUX_ARCH_ARM64) || defined(LINUX_ARCH_X32) || defined(LINUX_ARCH_X86_64)
inline LINUX_DEFINE_SYSCALL5_NORET(kexec_file_load, int, kernel_fd, int, initrd_fd, linux_uword_t, cmdline_len, char const*, cmdline_ptr, linux_uword_t, flags)
#endif

//=============================================================================
// X86 vsyscalls

#if defined(LINUX_ARCH_X86)
// TODO: Add vsyscalls for x86.
#endif

#endif // !HEADER_LIBLINUX_LINUX_H_INCLUDED
