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

// TODO: Sign extension while casting the return value?

#include "version.h"
#include "arch.h"
#include "endian.h"
#include "syscall.h"
#include "names.h"
#include "constants.h"

#include <stdint.h>
#include <stdalign.h>

// TODO: I changed (u)long to (u)word_t in all signatures. Is this also necessary for the struct members (I don't think so)? TODO: also change the typedefs?

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
#ifdef LINUX_ENDIAN_LITTLE
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

inline enum linux_error_t linux_io_setup(unsigned int const nr_events, linux_aio_context_t* const ctxp)
{
	linux_word_t const ret = linux_syscall2(nr_events, (uintptr_t)ctxp, linux_syscall_name_io_setup);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_io_destroy(linux_aio_context_t const ctx)
{
	linux_word_t const ret = linux_syscall1(ctx, linux_syscall_name_io_destroy);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_io_submit(linux_aio_context_t const ctx_id, linux_word_t const nr, struct linux_iocb** const iocbpp, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall3(ctx_id, (linux_uword_t)nr, (uintptr_t)iocbpp, linux_syscall_name_io_submit);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_io_cancel(linux_aio_context_t const ctx_id, struct linux_iocb* const iocb, struct linux_io_event* const result)
{
	linux_word_t const ret = linux_syscall3(ctx_id, (uintptr_t)iocb, (uintptr_t)result, linux_syscall_name_io_cancel);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_io_getevents(linux_aio_context_t const ctx_id, linux_word_t const min_nr, linux_word_t const nr, struct linux_io_event* const events, struct linux_timespec* const timeout, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall5(ctx_id, (linux_uword_t)min_nr, (linux_uword_t)nr, (uintptr_t)events, (uintptr_t)timeout, linux_syscall_name_io_getevents);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_io_pgetevents(linux_aio_context_t const ctx_id, linux_word_t const min_nr, linux_word_t const nr, struct linux_io_event* const events, struct linux_timespec* const timeout, struct linux_aio_sigset const* const usig, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall6(ctx_id, (linux_uword_t)min_nr, (linux_uword_t)nr, (uintptr_t)events, (uintptr_t)timeout, (uintptr_t)usig, linux_syscall_name_io_pgetevents);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// xattr

inline enum linux_error_t linux_setxattr(char const* const pathname, char const* const name, void const* const value, linux_size_t const size, int const flags)
{
	linux_word_t const ret = linux_syscall5((uintptr_t)pathname, (uintptr_t)name, (uintptr_t)value, size, (unsigned int)flags, linux_syscall_name_setxattr);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_lsetxattr(char const* const pathname, char const* const name, void const* const value, linux_size_t const size, int const flags)
{
	linux_word_t const ret = linux_syscall5((uintptr_t)pathname, (uintptr_t)name, (uintptr_t)value, size, (unsigned int)flags, linux_syscall_name_lsetxattr);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_fsetxattr(int const fd, char const* const name, void const* const value, linux_size_t const size, int const flags)
{
	linux_word_t const ret = linux_syscall5((unsigned int)fd, (uintptr_t)name, (uintptr_t)value, size, (unsigned int)flags, linux_syscall_name_fsetxattr);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_getxattr(char const* const pathname, char const* const name, void* const value, linux_size_t const size, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall4((uintptr_t)pathname, (uintptr_t)name, (uintptr_t)value, size, linux_syscall_name_getxattr);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_ssize_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_lgetxattr(char const* const pathname, char const* const name, void* const value, linux_size_t const size, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall4((uintptr_t)pathname, (uintptr_t)name, (uintptr_t)value, size, linux_syscall_name_lgetxattr);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_ssize_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_fgetxattr(int const fd, char const* const name, void* const value, linux_size_t const size, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall4((unsigned int)fd, (uintptr_t)name, (uintptr_t)value, size, linux_syscall_name_fgetxattr);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_ssize_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_listxattr(char const* const pathname, char* const list, linux_size_t const size, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)pathname, (uintptr_t)list, size, linux_syscall_name_listxattr);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_ssize_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_llistxattr(char const* const pathname, char* const list, linux_size_t const size, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)pathname, (uintptr_t)list, size, linux_syscall_name_llistxattr);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_ssize_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_flistxattr(int const fd, char* const list, linux_size_t const size, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)fd, (uintptr_t)list, size, linux_syscall_name_flistxattr);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_ssize_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_removexattr(char const* const pathname, char const* const name)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)pathname, (uintptr_t)name, linux_syscall_name_removexattr);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_lremovexattr(char const* const pathname, char const* const name)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)pathname, (uintptr_t)name, linux_syscall_name_lremovexattr);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_fremovexattr(int const fd, char const* const name)
{
	linux_word_t const ret = linux_syscall2((unsigned int)fd, (uintptr_t)name, linux_syscall_name_fremovexattr);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// polling

inline enum linux_error_t linux_epoll_create1(int const flags, int* const result)
{
	linux_word_t const ret = linux_syscall1((unsigned int)flags, linux_syscall_name_epoll_create1);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_epoll_ctl(int const epfd, int const op, int const fd, struct linux_epoll_event* const event)
{
	linux_word_t const ret = linux_syscall4((unsigned int)epfd, (unsigned int)op, (unsigned int)fd, (uintptr_t)event, linux_syscall_name_epoll_ctl);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_epoll_pwait(int const epfd, struct linux_epoll_event* const events, int const maxevents, int const timeout, linux_sigset_t const* const sigmask, linux_size_t const sigsetsize, int* const result)
{
	linux_word_t const ret = linux_syscall6((unsigned int)epfd, (uintptr_t)events, (unsigned int)maxevents, (unsigned int)timeout, (uintptr_t)sigmask, sigsetsize, linux_syscall_name_epoll_pwait);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_pselect6(int const n, linux_fd_set* const inp, linux_fd_set* const outp, linux_fd_set* const exp, struct linux_timespec* const tsp, void* const sig, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall6((unsigned int)n, (uintptr_t)inp, (uintptr_t)outp, (uintptr_t)exp, (uintptr_t)tsp, (uintptr_t)sig, linux_syscall_name_pselect6);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_ppoll(struct linux_pollfd* const ufds, unsigned int const nfds, struct linux_timespec* const tsp, linux_sigset_t const* const sigmask, linux_size_t const sigsetsize, int* const result)
{
	linux_word_t const ret = linux_syscall5((uintptr_t)ufds, nfds, (uintptr_t)tsp, (uintptr_t)sigmask, sigsetsize, linux_syscall_name_ppoll);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// file decriptors

inline enum linux_error_t linux_dup(unsigned int const fildes, int* const result)
{
	linux_word_t const ret = linux_syscall1(fildes, linux_syscall_name_dup);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_dup3(unsigned int const oldfd, unsigned int const newfd, int const flags, int* const result)
{
	linux_word_t const ret = linux_syscall3(oldfd, newfd, (unsigned int)flags, linux_syscall_name_dup3);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_fcntl(unsigned int const fd, unsigned int const cmd, linux_uword_t const arg, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall3(fd, cmd, arg, linux_syscall_name_fcntl);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_ioctl(unsigned int const fd, unsigned int const cmd, linux_uword_t const arg, int* const result)
{
	linux_word_t const ret = linux_syscall3(fd, cmd, arg, linux_syscall_name_ioctl);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_flock(unsigned int const fd, unsigned int const cmd)
{
	linux_word_t const ret = linux_syscall2(fd, cmd, linux_syscall_name_flock);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_close(unsigned int const fd)
{
	linux_word_t const ret = linux_syscall1(fd, linux_syscall_name_close);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// inotify

inline enum linux_error_t linux_inotify_init1(int const flags, int* const result)
{
	linux_word_t const ret = linux_syscall1((unsigned int)flags, linux_syscall_name_inotify_init1);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_inotify_add_watch(int const fd, char const* const pathname, uint32_t const mask, int* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)fd, (uintptr_t)pathname, mask, linux_syscall_name_inotify_add_watch);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_inotify_rm_watch(int const fd, int32_t const wd)
{
	linux_word_t const ret = linux_syscall2((unsigned int)fd, (unsigned int)wd, linux_syscall_name_inotify_rm_watch);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// filesystem

inline enum linux_error_t linux_mknodat(int const dfd, char const* const filename, linux_umode_t const mode, unsigned int const dev)
{
	linux_word_t const ret = linux_syscall4((unsigned int)dfd, (uintptr_t)filename, mode, dev, linux_syscall_name_mknodat);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_mkdirat(int const dfd, char const* const pathname, linux_umode_t const mode)
{
	linux_word_t const ret = linux_syscall3((unsigned int)dfd, (uintptr_t)pathname, mode, linux_syscall_name_mkdirat);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_unlinkat(int const dfd, char const* const pathname, int const flag)
{
	linux_word_t const ret = linux_syscall3((unsigned int)dfd, (uintptr_t)pathname, (unsigned int)flag, linux_syscall_name_unlinkat);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_symlinkat(char const* const oldname, int const newdfd, char const* const newname)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)oldname, (unsigned int)newdfd, (uintptr_t)newname, linux_syscall_name_symlinkat);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_linkat(int const olddfd, char const* const oldname, int const newdfd, char const* const newname, int const flags)
{
	linux_word_t const ret = linux_syscall5((unsigned int)olddfd, (uintptr_t)oldname, (unsigned int)newdfd, (uintptr_t)newname, (unsigned int)flags, linux_syscall_name_linkat);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_renameat(int const olddfd, char const* const oldname, int const newdfd, char const* const newname)
{
	linux_word_t const ret = linux_syscall4((unsigned int)olddfd, (uintptr_t)oldname, (unsigned int)newdfd, (uintptr_t)newname, linux_syscall_name_renameat);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_statfs(char const* const pathname, struct linux_statfs* const buf)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)pathname, (uintptr_t)buf, linux_syscall_name_statfs);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_fstatfs(unsigned int const fd, struct linux_statfs* const buf)
{
	linux_word_t const ret = linux_syscall2(fd, (uintptr_t)buf, linux_syscall_name_fstatfs);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_getdents64(unsigned int const fd, struct linux_dirent64* const dirent, unsigned int const count, int* const result)
{
	linux_word_t const ret = linux_syscall3(fd, (uintptr_t)dirent, count, linux_syscall_name_getdents64);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_readlinkat(int const dfd, char const* const pathname, char* const buf, int const bufsiz, int* const result)
{
	linux_word_t const ret = linux_syscall4((unsigned int)dfd, (uintptr_t)pathname, (uintptr_t)buf, (unsigned int)bufsiz, linux_syscall_name_readlinkat);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_renameat2(int const olddfd, char const* const oldname, int const newdfd, char const* const newname, unsigned int const flags)
{
	linux_word_t const ret = linux_syscall5((unsigned int)olddfd, (uintptr_t)oldname, (unsigned int)newdfd, (uintptr_t)newname, flags, linux_syscall_name_renameat2);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// real files

inline enum linux_error_t linux_truncate(char const* const path, linux_word_t const length)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)path, (linux_uword_t)length, linux_syscall_name_truncate);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_ftruncate(unsigned int const fd, linux_uword_t const length)
{
	linux_word_t const ret = linux_syscall2(fd, length, linux_syscall_name_ftruncate);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_fallocate(int const fd, int const mode, linux_loff_t const offset, linux_loff_t const len)
{
#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall6((unsigned int)fd, (unsigned int)mode, LINUX_EXPAND(offset), LINUX_EXPAND(len), linux_syscall_name_fallocate);
#else
	linux_word_t const ret = linux_syscall4((unsigned int)fd, (unsigned int)mode, (uint64_t)offset, (uint64_t)len, linux_syscall_name_fallocate);
#endif
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_faccessat(int const dfd, char const* const filename, int const mode)
{
	linux_word_t const ret = linux_syscall3((unsigned int)dfd, (uintptr_t)filename, (unsigned int)mode, linux_syscall_name_faccessat);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_fchmod(unsigned int const fd, linux_umode_t const mode)
{
	linux_word_t const ret = linux_syscall2(fd, mode, linux_syscall_name_fchmod);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_fchmodat(int const dfd, char const* const filename, linux_umode_t const mode)
{
	linux_word_t const ret = linux_syscall3((unsigned int)dfd, (uintptr_t)filename, mode, linux_syscall_name_fchmodat);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_fchownat(int const dfd, char const* const filename, linux_uid_t const user, linux_gid_t const group, int const flag)
{
	linux_word_t const ret = linux_syscall5((unsigned int)dfd, (uintptr_t)filename, user, group, (unsigned int)flag, linux_syscall_name_fchownat);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_fchown(unsigned int const fd, linux_uid_t const user, linux_gid_t const group)
{
	linux_word_t const ret = linux_syscall3(fd, user, group, linux_syscall_name_fchown);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_openat(int const dfd, char const* const filename, int const flags, linux_umode_t const mode, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall4((unsigned int)dfd, (uintptr_t)filename, (unsigned int)flags, mode, linux_syscall_name_openat);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_name_to_handle_at(int const dfd, char const* const name, struct linux_file_handle* const handle, int* const mnt_id, int const flag)
{
	linux_word_t const ret = linux_syscall5((unsigned int)dfd, (uintptr_t)name, (uintptr_t)handle, (uintptr_t)mnt_id, (unsigned int)flag, linux_syscall_name_name_to_handle_at);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_open_by_handle_at(int const mountdirfd, struct linux_file_handle* const handle, int const flags, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)mountdirfd, (uintptr_t)handle, (unsigned int)flags, linux_syscall_name_open_by_handle_at);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_newfstat(unsigned int const fd, struct linux_stat* const statbuf)
{
	linux_word_t const ret = linux_syscall2((unsigned int)fd, (uintptr_t)statbuf, linux_syscall_name_newfstat);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_statx(int const dfd, char const* const filename, unsigned int const flags, unsigned int const mask, struct linux_statx* const buffer)
{
	linux_word_t const ret = linux_syscall5((unsigned int)dfd, (uintptr_t)filename, flags, mask, (uintptr_t)buffer, linux_syscall_name_statx);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// read/write

inline enum linux_error_t linux_lseek(unsigned int const fd, linux_off_t const offset, unsigned int const whence, linux_off_t* const result)
{
	linux_word_t const ret = linux_syscall3(fd, (linux_kernel_ulong_t)offset, whence, linux_syscall_name_lseek);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_off_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_read(unsigned int const fd, char* const buf, linux_size_t const count, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall3(fd, (uintptr_t)buf, count, linux_syscall_name_read);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_ssize_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_write(unsigned int const fd, char const* const buf, linux_size_t const count, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall3(fd, (uintptr_t)buf, count, linux_syscall_name_write);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_ssize_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_readv(linux_uword_t const fd, struct linux_iovec const* const vec, linux_uword_t const vlen, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall3(fd, (uintptr_t)vec, vlen, linux_syscall_name_readv);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_ssize_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_writev(linux_uword_t const fd, struct linux_iovec const* const vec, linux_uword_t const vlen, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall3(fd, (uintptr_t)vec, vlen, linux_syscall_name_writev);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_ssize_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_pread64(unsigned int const fd, char* const buf, linux_size_t const count, linux_loff_t const pos, linux_ssize_t* const result)
{
#if defined(LINUX_ARCH_ARM_EABI)
	linux_word_t const ret = linux_syscall6(fd, (uintptr_t)buf, count, 0, LINUX_EXPAND(pos), linux_syscall_name_pread64);
#elif defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall5(fd, (uintptr_t)buf, count, LINUX_EXPAND(pos), linux_syscall_name_pread64);
#else
	linux_word_t const ret = linux_syscall4(fd, (uintptr_t)buf, count, (uint64_t)pos, linux_syscall_name_pread64);
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
	linux_word_t const ret = linux_syscall6(fd, (uintptr_t)buf, count, 0, LINUX_EXPAND(pos), linux_syscall_name_pwrite64);
#elif defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall5(fd, (uintptr_t)buf, count, LINUX_EXPAND(pos), linux_syscall_name_pwrite64);
#else
	linux_word_t const ret = linux_syscall4(fd, (uintptr_t)buf, count, (uint64_t)pos, linux_syscall_name_pwrite64);
#endif
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_ssize_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_preadv(linux_uword_t const fd, struct linux_iovec const* const vec, linux_uword_t const vlen, linux_uword_t const pos_l, linux_uword_t const pos_h, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall5(fd, (uintptr_t)vec, vlen, pos_l, pos_h, linux_syscall_name_preadv);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_ssize_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_pwritev(linux_uword_t const fd, struct linux_iovec const* const vec, linux_uword_t const vlen, linux_uword_t const pos_l, linux_uword_t const pos_h, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall5(fd, (uintptr_t)vec, vlen, pos_l, pos_h, linux_syscall_name_pwritev);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_ssize_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_sendfile64(int const out_fd, int const in_fd, linux_loff_t* const offset, linux_size_t const count, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall4((unsigned int)out_fd, (unsigned int)in_fd, (uintptr_t)offset, count, linux_syscall_name_sendfile64);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_ssize_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_vmsplice(int const fd, struct linux_iovec const* const uiov, linux_uword_t const nr_segs, unsigned int const flags, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall4((unsigned int)fd, (uintptr_t)uiov, nr_segs, flags, linux_syscall_name_vmsplice);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_splice(int const fd_in, linux_loff_t* const off_in, int const fd_out, linux_loff_t* const off_out, linux_size_t const len, unsigned int const flags, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall6((unsigned int)fd_in, (uintptr_t)off_in, (unsigned int)fd_out, (uintptr_t)off_out, len, flags, linux_syscall_name_splice);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_tee(int const fdin, int const fdout, linux_size_t const len, unsigned int const flags, int* const result)
{
	linux_word_t const ret = linux_syscall4((unsigned int)fdin, (unsigned int)fdout, len, flags, linux_syscall_name_tee);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_readahead(int const fd, linux_loff_t const offset, linux_size_t const count)
{
#if defined(LINUX_ARCH_ARM_EABI)
	linux_word_t const ret = linux_syscall5((unsigned int)fd, 0, LINUX_EXPAND(offset), count, linux_syscall_name_readahead);
#elif defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall4((unsigned int)fd, LINUX_EXPAND(offset), count, linux_syscall_name_readahead);
#else
	linux_word_t const ret = linux_syscall3((unsigned int)fd, (uint64_t)offset, count, linux_syscall_name_readahead);
#endif
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_process_vm_readv(linux_pid_t const pid, struct linux_iovec const* const lvec, linux_uword_t const liovcnt, struct linux_iovec const* const rvec, linux_uword_t const riovcnt, linux_uword_t const flags, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall6((unsigned int)pid, (uintptr_t)lvec, liovcnt, (uintptr_t)rvec, riovcnt, flags, linux_syscall_name_process_vm_readv);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_ssize_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_process_vm_writev(linux_pid_t const pid, struct linux_iovec const* const lvec, linux_uword_t const liovcnt, struct linux_iovec const* const rvec, linux_uword_t const riovcnt, linux_uword_t const flags, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall6((unsigned int)pid, (uintptr_t)lvec, liovcnt, (uintptr_t)rvec, riovcnt, flags, linux_syscall_name_process_vm_writev);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_ssize_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_copy_file_range(int const fd_in, linux_loff_t* const off_in, int const fd_out, linux_loff_t* const off_out, linux_size_t const len, unsigned int const flags, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall6((unsigned int)fd_in, (uintptr_t)off_in, (unsigned int)fd_out, (uintptr_t)off_out, len, flags, linux_syscall_name_copy_file_range);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_ssize_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_preadv2(linux_uword_t const fd, struct linux_iovec const* const vec, linux_uword_t const vlen, linux_uword_t const pos_l, linux_uword_t const pos_h, linux_rwf_t const flags, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall6(fd, (uintptr_t)vec, vlen, pos_l, pos_h, (unsigned int)flags, linux_syscall_name_preadv2);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_ssize_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_pwritev2(linux_uword_t const fd, struct linux_iovec const* const vec, linux_uword_t const vlen, linux_uword_t const pos_l, linux_uword_t const pos_h, linux_rwf_t const flags, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall6(fd, (uintptr_t)vec, vlen, pos_l, pos_h, (unsigned int)flags, linux_syscall_name_pwritev2);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_ssize_t)ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// timerfd

inline enum linux_error_t linux_timerfd_create(int const clockid, int const flags, int* const result)
{
	linux_word_t const ret = linux_syscall2((unsigned int)clockid, (unsigned int)flags, linux_syscall_name_timerfd_create);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_timerfd_settime(int const ufd, int const flags, struct linux_kernel_itimerspec const* const utmr, struct linux_kernel_itimerspec* const otmr)
{
	linux_word_t const ret = linux_syscall4((unsigned int)ufd, (unsigned int)flags, (uintptr_t)utmr, (uintptr_t)otmr, linux_syscall_name_timerfd_settime);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_timerfd_gettime(int const ufd, struct linux_kernel_itimerspec* const otmr)
{
	linux_word_t const ret = linux_syscall2((unsigned int)ufd, (uintptr_t)otmr, linux_syscall_name_timerfd_gettime);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// capabilities

inline enum linux_error_t linux_capget(linux_cap_user_header_t const header, struct linux_user_cap_data_struct* const dataptr)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)header, (uintptr_t)dataptr, linux_syscall_name_capget);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_capset(linux_cap_user_header_t const header, struct linux_user_cap_data_struct const* const data)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)header, (uintptr_t)data, linux_syscall_name_capset);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// futexes

inline enum linux_error_t linux_futex(uint32_t* const uaddr, int const op, uint32_t const val, struct linux_timespec* const utime, uint32_t* const uaddr2, uint32_t const val3, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall6((uintptr_t)uaddr, (unsigned int)op, val, (uintptr_t)utime, (uintptr_t)uaddr2, val3, linux_syscall_name_futex);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_get_robust_list(int const pid, struct linux_robust_list_head** const head_ptr, linux_size_t* const len_ptr)
{
	linux_word_t const ret = linux_syscall3((unsigned int)pid, (uintptr_t)head_ptr, (uintptr_t)len_ptr, linux_syscall_name_get_robust_list);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_set_robust_list(struct linux_robust_list_head* const head, linux_size_t const len)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)head, len, linux_syscall_name_set_robust_list);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// interval timer

inline enum linux_error_t linux_getitimer(int const which, struct linux_itimerval* const value)
{
	linux_word_t const ret = linux_syscall2((unsigned int)which, (uintptr_t)value, linux_syscall_name_getitimer);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_setitimer(int const which, struct linux_itimerval* const value, struct linux_itimerval* const ovalue)
{
	linux_word_t const ret = linux_syscall3((unsigned int)which, (uintptr_t)value, (uintptr_t)ovalue, linux_syscall_name_setitimer);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// kernel

inline enum linux_error_t linux_kexec_load(linux_uword_t const entry, linux_uword_t const nr_segments, struct linux_kexec_segment* const segments, linux_uword_t const flags)
{
	linux_word_t const ret = linux_syscall4(entry, nr_segments, (uintptr_t)segments, flags, linux_syscall_name_kexec_load);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_init_module(void* const umod, linux_uword_t const len, char const* const uargs)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)umod, len, (uintptr_t)uargs, linux_syscall_name_init_module);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_delete_module(char const* const name_user, unsigned int const flags)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)name_user, flags, linux_syscall_name_delete_module);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_reboot(int const magic1, int const magic2, unsigned int const cmd, void* const arg)
{
	linux_word_t const ret = linux_syscall4((unsigned int)magic1, (unsigned int)magic2, cmd, (uintptr_t)arg, linux_syscall_name_reboot);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_finit_module(int const fd, char const* const uargs, int const flags)
{
	linux_word_t const ret = linux_syscall3((unsigned int)fd, (uintptr_t)uargs, (unsigned int)flags, linux_syscall_name_finit_module);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// timer

inline enum linux_error_t linux_timer_create(linux_clockid_t const which_clock, struct linux_sigevent* const timer_event_spec, linux_timer_t* const created_timer_id)
{
	linux_word_t const ret = linux_syscall3((unsigned int)which_clock, (uintptr_t)timer_event_spec, (uintptr_t)created_timer_id, linux_syscall_name_timer_create);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_timer_gettime(linux_timer_t const timer_id, struct linux_kernel_itimerspec* const setting)
{
	linux_word_t const ret = linux_syscall2((unsigned int)timer_id, (uintptr_t)setting, linux_syscall_name_timer_gettime);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_timer_getoverrun(linux_timer_t const timer_id, int* const result)
{
	linux_word_t const ret = linux_syscall1((unsigned int)timer_id, linux_syscall_name_timer_getoverrun);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_timer_settime(linux_timer_t const timer_id, int const flags, struct linux_kernel_itimerspec const* const new_setting, struct linux_kernel_itimerspec* const old_setting)
{
	linux_word_t const ret = linux_syscall4((unsigned int)timer_id, (unsigned int)flags, (uintptr_t)new_setting, (uintptr_t)old_setting, linux_syscall_name_timer_settime);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_timer_delete(linux_timer_t const timer_id)
{
	linux_word_t const ret = linux_syscall1((unsigned int)timer_id, linux_syscall_name_timer_delete);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// clock

inline enum linux_error_t linux_clock_settime(linux_clockid_t const which_clock, struct linux_kernel_timespec const* const tp)
{
	linux_word_t const ret = linux_syscall2((unsigned int)which_clock, (uintptr_t)tp, linux_syscall_name_clock_settime);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_clock_gettime(linux_clockid_t const which_clock, struct linux_kernel_timespec* const tp)
{
	linux_word_t const ret = linux_syscall2((unsigned int)which_clock, (uintptr_t)tp, linux_syscall_name_clock_gettime);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_clock_getres(linux_clockid_t const which_clock, struct linux_kernel_timespec* const tp)
{
	linux_word_t const ret = linux_syscall2((unsigned int)which_clock, (uintptr_t)tp, linux_syscall_name_clock_getres);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_clock_nanosleep(linux_clockid_t const which_clock, int const flags, struct linux_kernel_timespec const* const rqtp, struct linux_kernel_timespec* const rmtp)
{
	linux_word_t const ret = linux_syscall4((unsigned int)which_clock, (unsigned int)flags, (uintptr_t)rqtp, (uintptr_t)rmtp, linux_syscall_name_clock_nanosleep);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_clock_adjtime(linux_clockid_t const which_clock, struct linux_timex* const utx, int* const result)
{
	linux_word_t const ret = linux_syscall2((unsigned int)which_clock, (uintptr_t)utx, linux_syscall_name_clock_adjtime);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// scheduler

inline enum linux_error_t linux_ioprio_set(int const which, int const who, int const ioprio)
{
	linux_word_t const ret = linux_syscall3((unsigned int)which, (unsigned int)who, (unsigned int)ioprio, linux_syscall_name_ioprio_set);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_ioprio_get(int const which, int const who, int* const result)
{
	linux_word_t const ret = linux_syscall2((unsigned int)which, (unsigned int)who, linux_syscall_name_ioprio_get);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_sched_setparam(linux_pid_t const pid, struct linux_sched_param* const param)
{
	linux_word_t const ret = linux_syscall2((unsigned int)pid, (uintptr_t)param, linux_syscall_name_sched_setparam);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_sched_setscheduler(linux_pid_t const pid, int const policy, struct linux_sched_param* const param)
{
	linux_word_t const ret = linux_syscall3((unsigned int)pid, (unsigned int)policy, (uintptr_t)param, linux_syscall_name_sched_setscheduler);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_sched_getscheduler(linux_pid_t const pid, int* const result)
{
	linux_word_t const ret = linux_syscall1((unsigned int)pid, linux_syscall_name_sched_getscheduler);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_sched_getparam(linux_pid_t const pid, struct linux_sched_param* const param)
{
	linux_word_t const ret = linux_syscall2((unsigned int)pid, (uintptr_t)param, linux_syscall_name_sched_getparam);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_sched_setaffinity(linux_pid_t const pid, unsigned int const len, linux_uword_t* const user_mask_ptr)
{
	linux_word_t const ret = linux_syscall3((unsigned int)pid, len, (uintptr_t)user_mask_ptr, linux_syscall_name_sched_setaffinity);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_sched_getaffinity(linux_pid_t const pid, unsigned int const len, linux_uword_t* const user_mask_ptr)
{
	linux_word_t const ret = linux_syscall3((unsigned int)pid, len, (uintptr_t)user_mask_ptr, linux_syscall_name_sched_getaffinity);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_sched_yield(void)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_sched_yield);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_sched_get_priority_max(int const policy, int* const result)
{
	linux_word_t const ret = linux_syscall1((unsigned int)policy, linux_syscall_name_sched_get_priority_max);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_sched_get_priority_min(int const policy, int* const result)
{
	linux_word_t const ret = linux_syscall1((unsigned int)policy, linux_syscall_name_sched_get_priority_min);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_sched_rr_get_interval(linux_pid_t const pid, struct linux_kernel_timespec* const interval)
{
	linux_word_t const ret = linux_syscall2((unsigned int)pid, (uintptr_t)interval, linux_syscall_name_sched_rr_get_interval);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_setpriority(int const which, int const who, int const niceval)
{
	linux_word_t const ret = linux_syscall3((unsigned int)which, (unsigned int)who, (unsigned int)niceval, linux_syscall_name_setpriority);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_getpriority(int const which, int const who, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall2((unsigned int)which, (unsigned int)who, linux_syscall_name_getpriority);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_sched_setattr(linux_pid_t const pid, struct linux_sched_attr* const uattr, unsigned int const flags)
{
	linux_word_t const ret = linux_syscall3((unsigned int)pid, (uintptr_t)uattr, flags, linux_syscall_name_sched_setattr);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_sched_getattr(linux_pid_t const pid, struct linux_sched_attr* const uattr, unsigned int const size, unsigned int const flags)
{
	linux_word_t const ret = linux_syscall4((unsigned int)pid, (uintptr_t)uattr, size, flags, linux_syscall_name_sched_getattr);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// signals

inline enum linux_error_t linux_signalfd4(int const ufd, linux_sigset_t* const user_mask, linux_size_t const sizemask, int const flags, int* const result)
{
	linux_word_t const ret = linux_syscall4((unsigned int)ufd, (uintptr_t)user_mask, sizemask, (unsigned int)flags, linux_syscall_name_signalfd4);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_kill(linux_pid_t const pid, int const sig)
{
	linux_word_t const ret = linux_syscall2((unsigned int)pid, (unsigned int)sig, linux_syscall_name_kill);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_tkill(linux_pid_t const pid, int const sig)
{
	linux_word_t const ret = linux_syscall2((unsigned int)pid, (unsigned int)sig, linux_syscall_name_tkill);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_tgkill(linux_pid_t const tgid, linux_pid_t const pid, int const sig)
{
	linux_word_t const ret = linux_syscall3((unsigned int)tgid, (unsigned int)pid, (unsigned int)sig, linux_syscall_name_tgkill);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_sigaltstack(linux_stack_t const* const uss, linux_stack_t* const uoss)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)uss, (uintptr_t)uoss, linux_syscall_name_sigaltstack);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_rt_sigsuspend(linux_sigset_t* const unewset, linux_size_t const sigsetsize)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)unewset, sigsetsize, linux_syscall_name_rt_sigsuspend);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_rt_sigaction(int const sig, struct linux_sigaction const* const act, struct linux_sigaction* const oact, linux_size_t const sigsetsize)
{
	linux_word_t const ret = linux_syscall4((unsigned int)sig, (uintptr_t)act, (uintptr_t)oact, sigsetsize, linux_syscall_name_rt_sigaction);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_rt_sigprocmask(int const how, linux_sigset_t* const nset, linux_sigset_t* const oset, linux_size_t const sigsetsize)
{
	linux_word_t const ret = linux_syscall4((unsigned int)how, (uintptr_t)nset, (uintptr_t)oset, sigsetsize, linux_syscall_name_rt_sigprocmask);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_rt_sigpending(linux_sigset_t* const uset, linux_size_t const sigsetsize)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)uset, sigsetsize, linux_syscall_name_rt_sigpending);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_rt_sigtimedwait(linux_sigset_t const* const uthese, linux_siginfo_t* const uinfo, struct linux_kernel_timespec const* const uts, linux_size_t const sigsetsize, int* const result)
{
	linux_word_t const ret = linux_syscall4((uintptr_t)uthese, (uintptr_t)uinfo, (uintptr_t)uts, sigsetsize, linux_syscall_name_rt_sigtimedwait);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_rt_sigqueueinfo(linux_pid_t const pid, int const sig, linux_siginfo_t* const uinfo)
{
	linux_word_t const ret = linux_syscall3((unsigned int)pid, (unsigned int)sig, (uintptr_t)uinfo, linux_syscall_name_rt_sigqueueinfo);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_rt_tgsigqueueinfo(linux_pid_t const tgid, linux_pid_t const pid, int const sig, linux_siginfo_t* const uinfo)
{
	linux_word_t const ret = linux_syscall4((unsigned int)tgid, (unsigned int)pid, (unsigned int)sig, (uintptr_t)uinfo, linux_syscall_name_rt_tgsigqueueinfo);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// process user/group id

inline enum linux_error_t linux_setuid(linux_uid_t const uid)
{
	linux_word_t const ret = linux_syscall1(uid, linux_syscall_name_setuid);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_setgid(linux_gid_t const gid)
{
	linux_word_t const ret = linux_syscall1(gid, linux_syscall_name_setgid);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_setreuid(linux_uid_t const ruid, linux_uid_t const euid)
{
	linux_word_t const ret = linux_syscall2(ruid, euid, linux_syscall_name_setreuid);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_setregid(linux_gid_t const rgid, linux_gid_t const egid)
{
	linux_word_t const ret = linux_syscall2(rgid, egid, linux_syscall_name_setregid);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_setresuid(linux_uid_t const ruid, linux_uid_t const euid, linux_uid_t const suid)
{
	linux_word_t const ret = linux_syscall3(ruid, euid, suid, linux_syscall_name_setresuid);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_setresgid(linux_gid_t const rgid, linux_gid_t const egid, linux_gid_t const sgid)
{
	linux_word_t const ret = linux_syscall3(rgid, egid, sgid, linux_syscall_name_setresgid);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_setfsuid(linux_uid_t const uid, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall1(uid, linux_syscall_name_setfsuid);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_setfsgid(linux_gid_t const gid, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall1(gid, linux_syscall_name_setfsgid);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_getuid(linux_uid_t* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_getuid);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_uid_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_getgid(linux_gid_t* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_getgid);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_gid_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_geteuid(linux_uid_t* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_geteuid);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_uid_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_getegid(linux_gid_t* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_getegid);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_gid_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_getresuid(linux_uid_t* const ruidp, linux_uid_t* const euidp, linux_uid_t* const suidp)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)ruidp, (uintptr_t)euidp, (uintptr_t)suidp, linux_syscall_name_getresuid);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_getresgid(linux_gid_t* const rgidp, linux_gid_t* const egidp, linux_gid_t* const sgidp)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)rgidp, (uintptr_t)egidp, (uintptr_t)sgidp, linux_syscall_name_getresgid);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// process/process group/session id

inline enum linux_error_t linux_setpgid(linux_pid_t const pid, linux_pid_t const pgid)
{
	linux_word_t const ret = linux_syscall2((unsigned int)pid, (unsigned int)pgid, linux_syscall_name_setpgid);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_setsid(int* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_setsid);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_getpgid(linux_pid_t const pid, int* const result)
{
	linux_word_t const ret = linux_syscall1((unsigned int)pid, linux_syscall_name_getpgid);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_getsid(linux_pid_t const pid, int* const result)
{
	linux_word_t const ret = linux_syscall1((unsigned int)pid, linux_syscall_name_getsid);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_getpid(linux_pid_t* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_getpid);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_pid_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_getppid(int* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_getppid);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_gettid(linux_pid_t* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_gettid);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_pid_t)ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// system time

inline enum linux_error_t linux_gettimeofday(struct linux_timeval* const tv, struct linux_timezone* const tz)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)tv, (uintptr_t)tz, linux_syscall_name_gettimeofday);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_settimeofday(struct linux_timeval* const tv, struct linux_timezone* const tz)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)tv, (uintptr_t)tz, linux_syscall_name_settimeofday);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_adjtimex(struct linux_timex* const txc_p, int* const result)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)txc_p, linux_syscall_name_adjtimex);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// message queue

inline enum linux_error_t linux_mq_open(char const* const u_name, int const oflag, linux_umode_t const mode, struct linux_mq_attr* const u_attr, int* const result)
{
	linux_word_t const ret = linux_syscall4((uintptr_t)u_name, (unsigned int)oflag, mode, (uintptr_t)u_attr, linux_syscall_name_mq_open);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_mq_unlink(char const* const u_name)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)u_name, linux_syscall_name_mq_unlink);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_mq_timedsend(linux_mqd_t const mqdes, char const* const u_msg_ptr, linux_size_t const msg_len, unsigned int const msg_prio, struct linux_kernel_timespec const* const u_abs_timeout)
{
	linux_word_t const ret = linux_syscall5((unsigned int)mqdes, (uintptr_t)u_msg_ptr, msg_len, msg_prio, (uintptr_t)u_abs_timeout, linux_syscall_name_mq_timedsend);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_mq_timedreceive(linux_mqd_t const mqdes, char* const u_msg_ptr, linux_size_t const msg_len, unsigned int* const u_msg_prio, struct linux_kernel_timespec const* const u_abs_timeout, int* const result)
{
	linux_word_t const ret = linux_syscall5((unsigned int)mqdes, (uintptr_t)u_msg_ptr, msg_len, (uintptr_t)u_msg_prio, (uintptr_t)u_abs_timeout, linux_syscall_name_mq_timedreceive);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_mq_notify(linux_mqd_t const mqdes, struct linux_sigevent const* const u_notification)
{
	linux_word_t const ret = linux_syscall2((unsigned int)mqdes, (uintptr_t)u_notification, linux_syscall_name_mq_notify);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_mq_getsetattr(linux_mqd_t const mqdes, struct linux_mq_attr const* const u_mqstat, struct linux_mq_attr* const u_omqstat)
{
	linux_word_t const ret = linux_syscall3((unsigned int)mqdes, (uintptr_t)u_mqstat, (uintptr_t)u_omqstat, linux_syscall_name_mq_getsetattr);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// System V IPC - message

inline enum linux_error_t linux_msgget(linux_key_t const key, int const msgflg, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall2((unsigned int)key, (unsigned int)msgflg, linux_syscall_name_msgget);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_msgctl(int const msqid, int const cmd, struct linux_msqid64_ds* const buf, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)msqid, (unsigned int)cmd, (uintptr_t)buf, linux_syscall_name_msgctl);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_msgrcv(int const msqid, struct linux_msgbuf* const msgp, linux_size_t const msgsz, linux_word_t const msgtyp, int const msgflg, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall5((unsigned int)msqid, (uintptr_t)msgp, msgsz, (linux_uword_t)msgtyp, (unsigned int)msgflg, linux_syscall_name_msgrcv);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_msgsnd(int const msqid, struct linux_msgbuf* const msgp, linux_size_t const msgsz, int const msgflg)
{
	linux_word_t const ret = linux_syscall4((unsigned int)msqid, (uintptr_t)msgp, msgsz, (unsigned int)msgflg, linux_syscall_name_msgsnd);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// System V IPC - semaphore

inline enum linux_error_t linux_semget(linux_key_t const key, int const nsems, int const semflg, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)key, (unsigned int)nsems, (unsigned int)semflg, linux_syscall_name_semget);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_semctl(int const semid, int const semnum, int const cmd, linux_uword_t const arg, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall4((unsigned int)semid, (unsigned int)semnum, (unsigned int)cmd, arg, linux_syscall_name_semctl);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// System V IPC - memory

inline enum linux_error_t linux_shmget(linux_key_t const key, linux_size_t const size, int const shmflg, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)key, size, (unsigned int)shmflg, linux_syscall_name_shmget);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_shmctl(int const shmid, int const cmd, struct linux_shmid64_ds* const buf, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)shmid, (unsigned int)cmd, (uintptr_t)buf, linux_syscall_name_shmctl);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_shmat(int const shmid, char* const shmaddr, int const shmflg, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)shmid, (uintptr_t)shmaddr, (unsigned int)shmflg, linux_syscall_name_shmat);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_shmdt(char* const shmaddr)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)shmaddr, linux_syscall_name_shmdt);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// socket

inline enum linux_error_t linux_socket(int const family, int const type, int const protocol, int* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)family, (unsigned int)type, (unsigned int)protocol, linux_syscall_name_socket);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_socketpair(int const family, int const type, int const protocol, int* const usockvec)
{
	linux_word_t const ret = linux_syscall4((unsigned int)family, (unsigned int)type, (unsigned int)protocol, (uintptr_t)usockvec, linux_syscall_name_socketpair);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_bind(int const fd, struct linux_sockaddr* const umyaddr, int const addrlen)
{
	linux_word_t const ret = linux_syscall3((unsigned int)fd, (uintptr_t)umyaddr, (unsigned int)addrlen, linux_syscall_name_bind);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_listen(int const fd, int const backlog)
{
	linux_word_t const ret = linux_syscall2((unsigned int)fd, (unsigned int)backlog, linux_syscall_name_listen);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_connect(int const fd, struct linux_sockaddr* const uservaddr, int const addrlen)
{
	linux_word_t const ret = linux_syscall3((unsigned int)fd, (uintptr_t)uservaddr, (unsigned int)addrlen, linux_syscall_name_connect);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_getsockname(int const fd, struct linux_sockaddr* const usockaddr, int* const usockaddr_len)
{
	linux_word_t const ret = linux_syscall3((unsigned int)fd, (uintptr_t)usockaddr, (uintptr_t)usockaddr_len, linux_syscall_name_getsockname);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_getpeername(int const fd, struct linux_sockaddr* const usockaddr, int* const usockaddr_len)
{
	linux_word_t const ret = linux_syscall3((unsigned int)fd, (uintptr_t)usockaddr, (uintptr_t)usockaddr_len, linux_syscall_name_getpeername);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_sendto(int const fd, void* const buff, linux_size_t const len, unsigned int const flags, struct linux_sockaddr* const addr, int const addr_le, int* const result)
{
	linux_word_t const ret = linux_syscall6((unsigned int)fd, (uintptr_t)buff, len, flags, (uintptr_t)addr, (unsigned int)addr_le, linux_syscall_name_sendto);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_recvfrom(int const fd, void* const ubuf, linux_size_t const size, unsigned int const flags, struct linux_sockaddr* const addr, int* const addr_len, int* const result)
{
	linux_word_t const ret = linux_syscall6((unsigned int)fd, (uintptr_t)ubuf, size, flags, (uintptr_t)addr, (uintptr_t)addr_len, linux_syscall_name_recvfrom);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_setsockopt(int const fd, int const level, int const optname, char* const optval, int const optlen)
{
	linux_word_t const ret = linux_syscall5((unsigned int)fd, (unsigned int)level, (unsigned int)optname, (uintptr_t)optval, (unsigned int)optlen, linux_syscall_name_setsockopt);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_getsockopt(int const fd, int const level, int const optname, char* const optval, int* const optlen)
{
	linux_word_t const ret = linux_syscall5((unsigned int)fd, (unsigned int)level, (unsigned int)optname, (uintptr_t)optval, (uintptr_t)optlen, linux_syscall_name_getsockopt);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_shutdown(int const fd, int const how)
{
	linux_word_t const ret = linux_syscall2((unsigned int)fd, (unsigned int)how, linux_syscall_name_shutdown);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_sendmsg(int const fd, struct linux_user_msghdr* const msg, unsigned int const flags, int* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)fd, (uintptr_t)msg, flags, linux_syscall_name_sendmsg);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_recvmsg(int const fd, struct linux_user_msghdr* const msg, unsigned int const flags, int* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)fd, (uintptr_t)msg, flags, linux_syscall_name_recvmsg);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_accept4(int const fd, struct linux_sockaddr* const upeer_sockaddr, int* const upeer_addrlen, int const flags, int* const result)
{
	linux_word_t const ret = linux_syscall4((unsigned int)fd, (uintptr_t)upeer_sockaddr, (uintptr_t)upeer_addrlen, (unsigned int)flags, linux_syscall_name_accept4);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_recvmmsg(int const fd, struct linux_mmsghdr* const mmsg, unsigned int const vlen, unsigned int const flags, struct linux_kernel_timespec* const timeout, int* const result)
{
	linux_word_t const ret = linux_syscall5((unsigned int)fd, (uintptr_t)mmsg, vlen, flags, (uintptr_t)timeout, linux_syscall_name_recvmmsg);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_sendmmsg(int const fd, struct linux_mmsghdr* const mmsg, unsigned int const vlen, unsigned int const flags, int* const result)
{
	linux_word_t const ret = linux_syscall4((unsigned int)fd, (uintptr_t)mmsg, vlen, flags, linux_syscall_name_sendmmsg);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// memory

inline enum linux_error_t linux_brk(linux_uword_t const brk, linux_uword_t* const result)
{
	linux_word_t const ret = linux_syscall1(brk, linux_syscall_name_brk);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_uword_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_munmap(linux_uword_t const addr, linux_size_t const len)
{
	linux_word_t const ret = linux_syscall2(addr, len, linux_syscall_name_munmap);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_mremap(linux_uword_t const addr, linux_uword_t const old_len, linux_uword_t const new_len, linux_uword_t const flags, linux_uword_t const new_addr, linux_uword_t* const result)
{
	linux_word_t const ret = linux_syscall5(addr, old_len, new_len, flags, new_addr, linux_syscall_name_mremap);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_uword_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_mprotect(linux_uword_t const start, linux_size_t const len, linux_uword_t const prot)
{
	linux_word_t const ret = linux_syscall3(start, len, prot, linux_syscall_name_mprotect);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_msync(linux_uword_t const start, linux_size_t const len, int const flags)
{
	linux_word_t const ret = linux_syscall3(start, len, (unsigned int)flags, linux_syscall_name_msync);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_mlock(linux_uword_t const start, linux_size_t const len)
{
	linux_word_t const ret = linux_syscall2(start, len, linux_syscall_name_mlock);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_munlock(linux_uword_t const start, linux_size_t const len)
{
	linux_word_t const ret = linux_syscall2(start, len, linux_syscall_name_munlock);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_mlockall(int const flags)
{
	linux_word_t const ret = linux_syscall1((unsigned int)flags, linux_syscall_name_mlockall);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_munlockall(void)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_munlockall);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_mincore(linux_uword_t const start, linux_size_t const len, unsigned char* const vec)
{
	linux_word_t const ret = linux_syscall3(start, len, (uintptr_t)vec, linux_syscall_name_mincore);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_madvise(linux_uword_t const start, linux_size_t const len_in, int const behavior)
{
	linux_word_t const ret = linux_syscall3(start, len_in, (unsigned int)behavior, linux_syscall_name_madvise);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_remap_file_pages(linux_uword_t const start, linux_uword_t const size, linux_uword_t const prot, linux_uword_t const pgoff, linux_uword_t const flags)
{
	linux_word_t const ret = linux_syscall5(start, size, prot, pgoff, flags, linux_syscall_name_remap_file_pages);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_mbind(linux_uword_t const start, linux_uword_t const len, linux_uword_t const mode, linux_uword_t const* const nmask, linux_uword_t const maxnode, unsigned int const flags)
{
	linux_word_t const ret = linux_syscall6(start, len, mode, (uintptr_t)nmask, maxnode, flags, linux_syscall_name_mbind);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_get_mempolicy(int* const policy, linux_uword_t* const nmask, linux_uword_t const maxnode, linux_uword_t const addr, linux_uword_t const flags)
{
	linux_word_t const ret = linux_syscall5((uintptr_t)policy, (uintptr_t)nmask, maxnode, addr, flags, linux_syscall_name_get_mempolicy);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_set_mempolicy(int const mode, linux_uword_t const* const nmask, linux_uword_t const maxnode)
{
	linux_word_t const ret = linux_syscall3((unsigned int)mode, (uintptr_t)nmask, maxnode, linux_syscall_name_set_mempolicy);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_migrate_pages(linux_pid_t const pid, linux_uword_t const maxnode, linux_uword_t const* const old_nodes, linux_uword_t const* const new_nodes, int* const result)
{
	linux_word_t const ret = linux_syscall4((unsigned int)pid, maxnode, (uintptr_t)old_nodes, (uintptr_t)new_nodes, linux_syscall_name_migrate_pages);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_move_pages(linux_pid_t const pid, linux_uword_t const nr_pages, void const** const pages, int const* const nodes, int* const status, int const flags)
{
	linux_word_t const ret = linux_syscall6((unsigned int)pid, nr_pages, (uintptr_t)pages, (uintptr_t)nodes, (uintptr_t)status, (unsigned int)flags, linux_syscall_name_move_pages);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_membarrier(int const cmd, int const flags, int* const result)
{
	linux_word_t const ret = linux_syscall2((unsigned int)cmd, (unsigned int)flags, linux_syscall_name_membarrier);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_mlock2(linux_uword_t const start, linux_size_t const len, int const flags)
{
	linux_word_t const ret = linux_syscall3(start, len, (unsigned int)flags, linux_syscall_name_mlock2);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_pkey_mprotect(linux_uword_t const start, linux_size_t const len, linux_uword_t const prot, int const pkey)
{
	linux_word_t const ret = linux_syscall4(start, len, prot, (unsigned int)pkey, linux_syscall_name_pkey_mprotect);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_pkey_alloc(linux_uword_t const flags, linux_uword_t const init_val, int* const result)
{
	linux_word_t const ret = linux_syscall2(flags, init_val, linux_syscall_name_pkey_alloc);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_pkey_free(int const pkey)
{
	linux_word_t const ret = linux_syscall1((unsigned int)pkey, linux_syscall_name_pkey_free);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// key management

inline enum linux_error_t linux_add_key(char const* const type, char const* const description, void const* const payload, linux_size_t const plen, linux_key_serial_t const ringid, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall5((uintptr_t)type, (uintptr_t)description, (uintptr_t)payload, plen, (uint32_t)ringid, linux_syscall_name_add_key);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_request_key(char const* const type, char const* const description, char const* const callout_info, linux_key_serial_t const destringid, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall4((uintptr_t)type, (uintptr_t)description, (uintptr_t)callout_info, (uint32_t)destringid, linux_syscall_name_request_key);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_keyctl(int const option, linux_uword_t const arg2, linux_uword_t const arg3, linux_uword_t const arg4, linux_uword_t const arg5, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall5((unsigned int)option, arg2, arg3, arg4, arg5, linux_syscall_name_keyctl);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// process creation

inline enum linux_error_t linux_waitid(int const which, linux_pid_t const upid, struct linux_siginfo* const infop, int const options, struct linux_rusage* const ru)
{
	linux_word_t const ret = linux_syscall5((unsigned int)which, (unsigned int)upid, (uintptr_t)infop, (unsigned int)options, (uintptr_t)ru, linux_syscall_name_waitid);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_clone(linux_uword_t const clone_flags, linux_uword_t const newsp, int* const parent_tidptr, int* const child_tidptr, linux_uword_t const tls, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall5(clone_flags, newsp, (uintptr_t)parent_tidptr, (uintptr_t)child_tidptr, tls, linux_syscall_name_clone);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_execve(char const* const filename, char const* const* const argv, char const* const* const envp)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)filename, (uintptr_t)argv, (uintptr_t)envp, linux_syscall_name_execve);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_wait4(linux_pid_t const upid, int* const stat_addr, int const options, struct linux_rusage* const ru, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall4((unsigned int)upid, (uintptr_t)stat_addr, (unsigned int)options, (uintptr_t)ru, linux_syscall_name_wait4);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_execveat(int const fd, char const* const filename, char const* const* const argv, char const* const* const envp, int const flags)
{
	linux_word_t const ret = linux_syscall5((unsigned int)fd, (uintptr_t)filename, (uintptr_t)argv, (uintptr_t)envp, (unsigned int)flags, linux_syscall_name_execveat);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// fanotify

inline enum linux_error_t linux_fanotify_init(unsigned int const flags, unsigned int const event_f_flags, int* const result)
{
	linux_word_t const ret = linux_syscall2(flags, event_f_flags, linux_syscall_name_fanotify_init);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_fanotify_mark(int const fanotify_fd, unsigned int const flags, uint64_t const mask, int const dfd, char const* const pathname)
{
#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall6((unsigned int)fanotify_fd, flags, LINUX_EXPAND(mask), (unsigned int)dfd, (uintptr_t)pathname, linux_syscall_name_fanotify_mark);
#else
	linux_word_t const ret = linux_syscall5((unsigned int)fanotify_fd, flags, mask, (unsigned int)dfd, (uintptr_t)pathname, linux_syscall_name_fanotify_mark);
#endif
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// misc file descriptors

inline enum linux_error_t linux_eventfd2(unsigned int const count, int const flags, int* const result)
{
	linux_word_t const ret = linux_syscall2(count, (unsigned int)flags, linux_syscall_name_eventfd2);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_memfd_create(char const* const uname, unsigned int const flags, int* const result)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)uname, flags, linux_syscall_name_memfd_create);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_userfaultfd(int const flags, int* const result)
{
	linux_word_t const ret = linux_syscall1((unsigned int)flags, linux_syscall_name_userfaultfd);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}

//-----------------------------------------------------------------------------
// misc

inline enum linux_error_t linux_getcwd(char* const buf, linux_uword_t const size, int* const result)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)buf, size, linux_syscall_name_getcwd);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_lookup_dcookie(uint64_t const cookie64, char* const buf, linux_size_t const len, int* const result)
{
#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall4(LINUX_EXPAND(cookie64), (uintptr_t)buf, len, linux_syscall_name_fanotify_mark);
#else
	linux_word_t const ret = linux_syscall3(cookie64, (uintptr_t)buf, len, linux_syscall_name_fanotify_mark);
#endif
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_umount(char* const name, int const flags)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)name, (unsigned int)flags, linux_syscall_name_umount);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_mount(char* const dev_name, char* const dir_name, char* const type, linux_uword_t const flags, void* const data)
{
	linux_word_t const ret = linux_syscall5((uintptr_t)dev_name, (uintptr_t)dir_name, (uintptr_t)type, flags, (uintptr_t)data, linux_syscall_name_mount);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_pivot_root(char const* const new_root, char const* const put_old)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)new_root, (uintptr_t)put_old, linux_syscall_name_pivot_root);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_chdir(char const* const filename)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)filename, linux_syscall_name_chdir);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_fchdir(unsigned int const fd)
{
	linux_word_t const ret = linux_syscall1(fd, linux_syscall_name_fchdir);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_chroot(char const* const filename)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)filename, linux_syscall_name_chroot);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_vhangup(void)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_vhangup);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_pipe2(int* const fildes, int const flags)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)fildes, (unsigned int)flags, linux_syscall_name_pipe2);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_quotactl(unsigned int const cmd, char const* const special, linux_qid_t const id, void* const addr)
{
	linux_word_t const ret = linux_syscall4(cmd, (uintptr_t)special, id, (uintptr_t)addr, linux_syscall_name_quotactl);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_sync(void)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_sync);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_fsync(unsigned int const fd)
{
	linux_word_t const ret = linux_syscall1(fd, linux_syscall_name_fsync);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_fdatasync(unsigned int const fd)
{
	linux_word_t const ret = linux_syscall1(fd, linux_syscall_name_fdatasync);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_utimensat(int const dfd, char const* const filename, struct linux_kernel_timespec* const utimes, int const flags)
{
	linux_word_t const ret = linux_syscall4((unsigned int)dfd, (uintptr_t)filename, (uintptr_t)utimes, (unsigned int)flags, linux_syscall_name_utimensat);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_acct(char const* const name)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)name, linux_syscall_name_acct);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_personality(unsigned int const personality, unsigned int* const result)
{
	linux_word_t const ret = linux_syscall1(personality, linux_syscall_name_personality);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (unsigned int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_set_tid_address(int* const tidptr, linux_pid_t* const result)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)tidptr, linux_syscall_name_set_tid_address);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_pid_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_unshare(linux_uword_t const unshare_flags)
{
	linux_word_t const ret = linux_syscall1(unshare_flags, linux_syscall_name_unshare);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_nanosleep(struct linux_kernel_timespec* const rqtp, struct linux_kernel_timespec* const rmtp)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)rqtp, (uintptr_t)rmtp, linux_syscall_name_nanosleep);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_syslog(int const type, char* const buf, int const len, int* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)type, (uintptr_t)buf, (unsigned int)len, linux_syscall_name_syslog);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_ptrace(linux_word_t const request, linux_word_t const pid, linux_uword_t const addr, linux_uword_t const data, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall4((linux_uword_t)request, (linux_uword_t)pid, addr, data, linux_syscall_name_ptrace);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_times(struct linux_tms* const tbuf, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)tbuf, linux_syscall_name_times);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_getgroups(int const gidsetsize, linux_gid_t* const grouplis, int* const result)
{
	linux_word_t const ret = linux_syscall2((unsigned int)gidsetsize, (uintptr_t)grouplis, linux_syscall_name_getgroups);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_setgroups(int const gidsetsize, linux_gid_t* const grouplist)
{
	linux_word_t const ret = linux_syscall2((unsigned int)gidsetsize, (uintptr_t)grouplist, linux_syscall_name_setgroups);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_newuname(struct linux_new_utsname* const name)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)name, linux_syscall_name_newuname);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_sethostname(char* const name, int const len)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)name, (unsigned int)len, linux_syscall_name_sethostname);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_setdomainname(char* const name, int const len)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)name, (unsigned int)len, linux_syscall_name_setdomainname);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_getrlimit(unsigned int const resource, struct linux_rlimit* const rlim)
{
	linux_word_t const ret = linux_syscall2(resource, (uintptr_t)rlim, linux_syscall_name_getrlimit);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_setrlimit(unsigned int const resource, struct linux_rlimit* const rlim)
{
	linux_word_t const ret = linux_syscall2(resource, (uintptr_t)rlim, linux_syscall_name_setrlimit);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_getrusage(int const who, struct linux_rusage* const ru)
{
	linux_word_t const ret = linux_syscall2((unsigned int)who, (uintptr_t)ru, linux_syscall_name_getrusage);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_umask(int const mask, int* const result)
{
	linux_word_t const ret = linux_syscall1((unsigned int)mask, linux_syscall_name_umask);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_prctl(int const option, linux_uword_t const arg2, linux_uword_t const arg3, linux_uword_t const arg4, linux_uword_t const arg5, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall5((unsigned int)option, arg2, arg3, arg4, arg5, linux_syscall_name_prctl);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_getcpu(unsigned int* const cpup, unsigned int* const nodep, struct linux_getcpu_cache* const unused)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)cpup, (uintptr_t)nodep, (uintptr_t)unused, linux_syscall_name_getcpu);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_sysinfo(struct linux_sysinfo* const info)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)info, linux_syscall_name_sysinfo);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_swapon(char const* const specialfile, int const swap_flags)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)specialfile, (unsigned int)swap_flags, linux_syscall_name_swapon);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_swapoff(char const* const specialfile)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)specialfile, linux_syscall_name_swapoff);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_perf_event_open(struct linux_perf_event_attr* const attr_uptr, linux_pid_t const pid, int const cpu, int const group_fd, linux_uword_t const flags, int* const result)
{
	linux_word_t const ret = linux_syscall5((uintptr_t)attr_uptr, (unsigned int)pid, (unsigned int)cpu, (unsigned int)group_fd, flags, linux_syscall_name_perf_event_open);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_prlimit64(linux_pid_t const pid, unsigned int const resource, struct linux_rlimit64 const* const new_rlim, struct linux_rlimit64* const old_rlim)
{
	linux_word_t const ret = linux_syscall4((unsigned int)pid, resource, (uintptr_t)new_rlim, (uintptr_t)old_rlim, linux_syscall_name_prlimit64);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_syncfs(int const fd)
{
	linux_word_t const ret = linux_syscall1((unsigned int)fd, linux_syscall_name_syncfs);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_setns(int const fd, int const nstype)
{
	linux_word_t const ret = linux_syscall2((unsigned int)fd, (unsigned int)nstype, linux_syscall_name_setns);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_kcmp(linux_pid_t const pid1, linux_pid_t const pid2, int const type, linux_uword_t const idx1, linux_uword_t const idx2, int* const result)
{
	linux_word_t const ret = linux_syscall5((unsigned int)pid1, (unsigned int)pid2, (unsigned int)type, idx1, idx2, linux_syscall_name_kcmp);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_seccomp(unsigned int const op, unsigned int const flags, char const* const uargs, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall3(op, flags, (uintptr_t)uargs, linux_syscall_name_seccomp);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_getrandom(char* const buf, linux_size_t const count, unsigned int const flags, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)buf, count, flags, linux_syscall_name_getrandom);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_ssize_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_bpf(int const cmd, union linux_bpf_attr* const uattr, unsigned int const size, int* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)cmd, (uintptr_t)uattr, size, linux_syscall_name_bpf);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_rseq(struct linux_rseq* const rseq, uint32_t const rseq_len, int const flags, uint32_t const sig)
{
	linux_word_t const ret = linux_syscall4((uintptr_t)rseq, rseq_len, (unsigned int)flags, sig, linux_syscall_name_rseq);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}

//=============================================================================
// Architecture specific syscalls

#if defined(LINUX_ARCH_ARM64) || defined(LINUX_ARCH_X86) || defined(LINUX_ARCH_X32) || defined(LINUX_ARCH_X86_64)
inline enum linux_error_t linux_sync_file_range(int const fd, linux_loff_t const offset, linux_loff_t const nbytes, unsigned int const flags)
{
#if defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall6((unsigned int)fd, LINUX_EXPAND(offset), LINUX_EXPAND(nbytes), flags, linux_syscall_name_sync_file_range);
#else
	linux_word_t const ret = linux_syscall4((unsigned int)fd, (uint64_t)offset, (uint64_t)nbytes, flags, linux_syscall_name_sync_file_range);
#endif
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
#endif

#if defined(LINUX_ARCH_ARM_EABI)
inline enum linux_error_t linux_sync_file_range2(int const fd, unsigned int const flags, linux_loff_t const offset, linux_loff_t const nbytes)
{
	linux_word_t const ret = linux_syscall6((unsigned int)fd, flags, LINUX_EXPAND(offset), LINUX_EXPAND(nbytes), linux_syscall_name_sync_file_range2);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_arm_fadvise64_64(int const fd, int const advice, linux_loff_t const offset, linux_loff_t const len)
{
	linux_word_t const ret = linux_syscall6((unsigned int)fd, (unsigned int)advice, LINUX_EXPAND(offset), LINUX_EXPAND(len), linux_syscall_name_arm_fadvise64_64);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_pciconfig_iobase(linux_word_t const which, linux_uword_t const bus, linux_uword_t const devfn, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall3((linux_uword_t)which, bus, devfn, linux_syscall_name_pciconfig_iobase);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_pciconfig_read(linux_uword_t const bus, linux_uword_t const dfn, linux_uword_t const off, linux_uword_t const len, void* const buf)
{
	linux_word_t const ret = linux_syscall5(bus, dfn, off, len, (uintptr_t)buf, linux_syscall_name_pciconfig_read);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_pciconfig_write(linux_uword_t const bus, linux_uword_t const dfn, linux_uword_t const off, linux_uword_t const len, void* const buf)
{
	linux_word_t const ret = linux_syscall5(bus, dfn, off, len, (uintptr_t)buf, linux_syscall_name_pciconfig_write);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_send(int const fd, void* const buff, linux_size_t const len, unsigned int const flags, int* const result)
{
	linux_word_t const ret = linux_syscall4((unsigned int)fd, (uintptr_t)buff, len, flags, linux_syscall_name_send);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_recv(int const fd, void* const ubuf, linux_size_t const size, unsigned int const flags, int* const result)
{
	linux_word_t const ret = linux_syscall4((unsigned int)fd, (uintptr_t)ubuf, size, flags, linux_syscall_name_recv);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_breakpoint(void)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_breakpoint);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_cacheflush(linux_uword_t const start, linux_uword_t const end, int const flags)
{
	linux_word_t const ret = linux_syscall3(start, end, (unsigned int)flags, linux_syscall_name_cacheflush);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_usr26(void)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_usr26);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_usr32(void)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_usr32);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_set_tls(linux_uword_t const val)
{
	linux_word_t const ret = linux_syscall1(val, linux_syscall_name_set_tls);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_get_tls(linux_uword_t* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_get_tls);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_uword_t)ret;
	return linux_error_none;
}
#endif

#if defined(LINUX_ARCH_ARM64) || defined(LINUX_ARCH_X86)
inline enum linux_error_t linux_fadvise64_64(int const fd, linux_loff_t const offset, linux_loff_t const len, int const advice)
{
#if defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall6((unsigned int)fd, LINUX_EXPAND(offset), LINUX_EXPAND(len), (unsigned int)advice, linux_syscall_name_fadvise64_64);
#else
	linux_word_t const ret = linux_syscall4((unsigned int)fd, (uint64_t)offset, (uint64_t)len, (unsigned int)advice, linux_syscall_name_fadvise64_64);
#endif
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
#endif

#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_ARM64) || defined(LINUX_ARCH_X32) || defined(LINUX_ARCH_X86_64)
inline enum linux_error_t linux_semtimedop(int const semid, struct linux_sembuf* const tsops, unsigned int const nsops, struct linux_kernel_timespec const* const timeout)
{
	linux_word_t const ret = linux_syscall4((unsigned int)semid, (uintptr_t)tsops, nsops, (uintptr_t)timeout, linux_syscall_name_semtimedop);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_semop(int const semid, struct linux_sembuf* const tsops, unsigned int const nsops)
{
	linux_word_t const ret = linux_syscall3((unsigned int)semid, (uintptr_t)tsops, nsops, linux_syscall_name_semop);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_accept(int const fd, struct linux_sockaddr* const upeer_sockaddr, int* const upeer_addrlen, int* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)fd, (uintptr_t)upeer_sockaddr, (uintptr_t)upeer_addrlen, linux_syscall_name_accept);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_kexec_file_load(int const kernel_fd, int const initrd_fd, linux_uword_t const cmdline_len, char const* const cmdline_ptr, linux_uword_t const flags)
{
	linux_word_t const ret = linux_syscall5((unsigned int)kernel_fd, (unsigned int)initrd_fd, cmdline_len, (uintptr_t)cmdline_ptr, flags, linux_syscall_name_kexec_file_load);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
#endif

#if defined(LINUX_ARCH_ARM64) || defined(LINUX_ARCH_X32) || defined(LINUX_ARCH_X86_64)
inline enum linux_error_t linux_newfstatat(int const dfd, char const* const filename, struct linux_stat* const statbuf, int const flag)
{
	linux_word_t const ret = linux_syscall4((unsigned int)dfd, (uintptr_t)filename, (uintptr_t)statbuf, (unsigned int)flag, linux_syscall_name_newfstatat);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_mmap(linux_uword_t const addr, linux_uword_t const len, linux_uword_t const prot, linux_uword_t const flags, linux_uword_t const fd, linux_uword_t const off, linux_uword_t* const result)
{
	linux_word_t const ret = linux_syscall6(addr, len, prot, flags, fd, off, linux_syscall_name_mmap);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_uword_t)ret;
	return linux_error_none;
}
#endif

#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_X86) || defined(LINUX_ARCH_X32) || defined(LINUX_ARCH_X86_64)
inline enum linux_error_t linux_signalfd(int const ufd, linux_sigset_t* const user_mask, linux_size_t const sizemask, int* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)ufd, (uintptr_t)user_mask, sizemask, linux_syscall_name_signalfd);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_fork(linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_fork);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_open(char const* const filename, int const flags, linux_umode_t const mode, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)filename, (unsigned int)flags, mode, linux_syscall_name_open);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_creat(char const* const pathname, linux_umode_t const mode, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)pathname, mode, linux_syscall_name_creat);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_link(char const* const oldname, char const* const newname)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)oldname, (uintptr_t)newname, linux_syscall_name_link);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_unlink(char const* const pathname)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)pathname, linux_syscall_name_unlink);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_mknod(char const* const filename, linux_umode_t const mode, unsigned int const dev)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)filename, mode, dev, linux_syscall_name_mknod);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_chmod(char const* const filename, linux_umode_t const mode)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)filename, mode, linux_syscall_name_chmod);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_pause(void)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_pause);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_access(char const* const filename, int const mode)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)filename, (unsigned int)mode, linux_syscall_name_access);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_rename(char const* const oldname, char const* const newname)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)oldname, (uintptr_t)newname, linux_syscall_name_rename);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_mkdir(char const* const pathname, linux_umode_t const mode)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)pathname, mode, linux_syscall_name_mkdir);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_rmdir(char const* const pathname)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)pathname, linux_syscall_name_rmdir);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_pipe(int* const fildes)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)fildes, linux_syscall_name_pipe);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_ustat(unsigned int const dev, struct linux_ustat* const ubuf)
{
	linux_word_t const ret = linux_syscall2(dev, (uintptr_t)ubuf, linux_syscall_name_ustat);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_dup2(unsigned int const oldfd, unsigned int const newfd, int* const result)
{
	linux_word_t const ret = linux_syscall2(oldfd, newfd, linux_syscall_name_dup2);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_getpgrp(int* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_getpgrp);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_symlink(char const* const oldname, char const* const newname)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)oldname, (uintptr_t)newname, linux_syscall_name_symlink);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_readlink(char const* const path, char* const buf, int const bufsiz, int* const result)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)path, (uintptr_t)buf, (unsigned int)bufsiz, linux_syscall_name_readlink);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_newstat(char const* const filename, struct linux_stat* const statbuf)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)filename, (uintptr_t)statbuf, linux_syscall_name_newstat);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_newlstat(char const* const filename, struct linux_stat* const statbuf)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)filename, (uintptr_t)statbuf, linux_syscall_name_newlstat);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_sysfs(int const option, linux_uword_t const arg1, linux_uword_t const arg2, int* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)option, arg1, arg2, linux_syscall_name_sysfs);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_getdents(unsigned int const fd, struct linux_dirent* const dirent, unsigned int const count, int* const result)
{
	linux_word_t const ret = linux_syscall3(fd, (uintptr_t)dirent, count, linux_syscall_name_getdents);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_select(int const n, linux_fd_set* const inp, linux_fd_set* const outp, linux_fd_set* const exp, struct linux_timeval* const tvp, int* const result)
{
	linux_word_t const ret = linux_syscall5((unsigned int)n, (uintptr_t)inp, (uintptr_t)outp, (uintptr_t)exp, (uintptr_t)tvp, linux_syscall_name_select);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_sysctl(struct linux_sysctl_args* const args)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)args, linux_syscall_name_sysctl);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_poll(struct linux_pollfd* const ufds, unsigned int const nfds, int const timeout_msecs, int* const result)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)ufds, nfds, (unsigned int)timeout_msecs, linux_syscall_name_poll);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_vfork(linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_vfork);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_lchown(char const* const filename, linux_uid_t const user, linux_gid_t const group)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)filename, user, group, linux_syscall_name_lchown);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_chown(char const* const filename, linux_uid_t const user, linux_gid_t const group)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)filename, user, group, linux_syscall_name_chown);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_epoll_create(int const size, int* const result)
{
	linux_word_t const ret = linux_syscall1((unsigned int)size, linux_syscall_name_epoll_create);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_epoll_wait(int const epfd, struct linux_epoll_event* const events, int const maxevents, int const timeout, int* const result)
{
	linux_word_t const ret = linux_syscall4((unsigned int)epfd, (uintptr_t)events, (unsigned int)maxevents, (unsigned int)timeout, linux_syscall_name_epoll_wait);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_utimes(char* const filename, struct linux_timeval* const utimes)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)filename, (uintptr_t)utimes, linux_syscall_name_utimes);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_inotify_init(int* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_inotify_init);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_futimesat(int const dfd, char const* const filename, struct linux_timeval* const utimes)
{
	linux_word_t const ret = linux_syscall3((unsigned int)dfd, (uintptr_t)filename, (uintptr_t)utimes, linux_syscall_name_futimesat);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_eventfd(unsigned int const count, int* const result)
{
	linux_word_t const ret = linux_syscall1(count, linux_syscall_name_eventfd);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
#endif

#if defined(LINUX_ARCH_X86) || defined(LINUX_ARCH_X32) || defined(LINUX_ARCH_X86_64)
inline enum linux_error_t linux_alarm(unsigned int const seconds, unsigned int* const result)
{
	linux_word_t const ret = linux_syscall1(seconds, linux_syscall_name_alarm);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (unsigned int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_utime(char* const filename, struct linux_utimbuf* const times)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)filename, (uintptr_t)times, linux_syscall_name_utime);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_modify_ldt(int const func, void* const ptr, linux_uword_t const bytecount, int* const result)
{
	int const ret = (int)linux_syscall3((unsigned int)func, (uintptr_t)ptr, bytecount, linux_syscall_name_modify_ldt);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_arch_prctl(int const option, linux_uword_t const arg2)
{
	linux_word_t const ret = linux_syscall2((unsigned int)option, arg2, linux_syscall_name_arch_prctl);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_iopl(unsigned int const level)
{
	linux_word_t const ret = linux_syscall1(level, linux_syscall_name_iopl);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_ioperm(linux_uword_t const from, linux_uword_t const num, int const turn_on)
{
	linux_word_t const ret = linux_syscall3(from, num, (unsigned int)turn_on, linux_syscall_name_ioperm);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_time(linux_time_t* const tloc, linux_time_t* const result)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)tloc, linux_syscall_name_time);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_time_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_fadvise64(int const fd, linux_loff_t const offset, linux_size_t const len, int const advice)
{
#if defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall5((unsigned int)fd, LINUX_EXPAND(offset), len, (unsigned int)advice, linux_syscall_name_fadvise64);
#else
	linux_word_t const ret = linux_syscall4((unsigned int)fd, (uint64_t)offset, len, (unsigned int)advice, linux_syscall_name_fadvise64);
#endif
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
#endif

#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_X86)
inline enum linux_error_t linux_fcntl64(unsigned int const fd, unsigned int const cmd, linux_uword_t const arg, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall3(fd, cmd, arg, linux_syscall_name_fcntl64);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_statfs64(char const* const pathname, linux_size_t const sz, struct linux_statfs64* const buf)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)pathname, sz, (uintptr_t)buf, linux_syscall_name_statfs64);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_fstatfs64(unsigned int const fd, linux_size_t const sz, struct linux_statfs64* const buf)
{
	linux_word_t const ret = linux_syscall3(fd, sz, (uintptr_t)buf, linux_syscall_name_fstatfs64);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_truncate64(char const* const path, linux_loff_t const length)
{
#if defined(LINUX_ARCH_ARM_EABI)
	linux_word_t const ret = linux_syscall4((uintptr_t)path, 0, LINUX_EXPAND(length), linux_syscall_name_truncate64);
#elif defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall3((uintptr_t)path, LINUX_EXPAND(length), linux_syscall_name_truncate64);
#else
	linux_word_t const ret = linux_syscall2((uintptr_t)path, (uint64_t)length, linux_syscall_name_truncate64);
#endif
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_ftruncate64(unsigned int const fd, linux_loff_t const length)
{
#if defined(LINUX_ARCH_ARM_EABI)
	linux_word_t const ret = linux_syscall4(fd, 0, LINUX_EXPAND(length), linux_syscall_name_ftruncate64);
#elif defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall3(fd, LINUX_EXPAND(length), linux_syscall_name_ftruncate64);
#else
	linux_word_t const ret = linux_syscall2(fd, (uint64_t)length, linux_syscall_name_ftruncate64);
#endif
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_llseek(unsigned int const fd, linux_uword_t const offset_high, linux_uword_t const offset_low, linux_loff_t* const result, unsigned int const whence)
{
	linux_word_t const ret = linux_syscall5(fd, offset_high, offset_low, (uintptr_t)result, whence, linux_syscall_name_llseek);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_sendfile(int const out_fd, int const in_fd, linux_off_t* const offset, linux_size_t const count, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall4((unsigned int)out_fd, (unsigned int)in_fd, (uintptr_t)offset, count, linux_syscall_name_sendfile);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_ssize_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_fstat64(linux_uword_t const fd, struct linux_stat64* const statbuf)
{
	linux_word_t const ret = linux_syscall2(fd, (uintptr_t)statbuf, linux_syscall_name_fstat64);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_fstatat64(int const dfd, char const* const filename, struct linux_stat64* const statbuf, int const flag)
{
	linux_word_t const ret = linux_syscall4((unsigned int)dfd, (uintptr_t)filename, (uintptr_t)statbuf, (unsigned int)flag, linux_syscall_name_fstatat64);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_lchown16(char const* const filename, linux_old_uid_t const user, linux_old_gid_t const group)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)filename, user, group, linux_syscall_name_lchown16);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_setuid16(linux_old_uid_t const uid)
{
	linux_word_t const ret = linux_syscall1(uid, linux_syscall_name_setuid16);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_getuid16(linux_old_uid_t* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_getuid16);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_old_uid_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_nice(int const increment, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall1((unsigned int)increment, linux_syscall_name_nice);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_setgid16(linux_old_gid_t const gid)
{
	linux_word_t const ret = linux_syscall1(gid, linux_syscall_name_setgid16);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_getgid16(linux_old_gid_t* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_getgid16);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_old_gid_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_geteuid16(linux_old_uid_t* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_geteuid16);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_old_uid_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_getegid16(linux_old_gid_t* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_getegid16);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_old_gid_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_sigaction(int const sig, struct linux_old_sigaction const* const act, struct linux_old_sigaction* const oact)
{
	linux_word_t const ret = linux_syscall3((unsigned int)sig, (uintptr_t)act, (uintptr_t)oact, linux_syscall_name_sigaction);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_setreuid16(linux_old_uid_t const ruid, linux_old_uid_t const euid)
{
	linux_word_t const ret = linux_syscall2(ruid, euid, linux_syscall_name_setreuid16);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_setregid16(linux_old_gid_t const rgid, linux_old_gid_t const egid)
{
	linux_word_t const ret = linux_syscall2(rgid, egid, linux_syscall_name_setregid16);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_sigsuspend(int const unused1, int const unused2, linux_old_sigset_t const mask)
{
	linux_word_t const ret = linux_syscall3((unsigned int)unused1, (unsigned int)unused2, mask, linux_syscall_name_sigsuspend);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_sigpending(linux_old_sigset_t* const uset)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)uset, linux_syscall_name_sigpending);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_getgroups16(int const gidsetsize, linux_old_gid_t* const grouplist, int* const result)
{
	linux_word_t const ret = linux_syscall2((unsigned int)gidsetsize, (uintptr_t)grouplist, linux_syscall_name_getgroups16);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_setgroups16(int const gidsetsize, linux_old_gid_t* const grouplist)
{
	linux_word_t const ret = linux_syscall2((unsigned int)gidsetsize, (uintptr_t)grouplist, linux_syscall_name_setgroups16);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_uselib(char const* const library)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)library, linux_syscall_name_uselib);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_fchown16(unsigned int const fd, linux_old_uid_t const user, linux_old_gid_t const group)
{
	linux_word_t const ret = linux_syscall3(fd, user, group, linux_syscall_name_fchown16);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_sigprocmask(int const how, linux_old_sigset_t* const nset, linux_old_sigset_t* const oset)
{
	linux_word_t const ret = linux_syscall3((unsigned int)how, (uintptr_t)nset, (uintptr_t)oset, linux_syscall_name_sigprocmask);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_bdflush(int const func, linux_word_t const data)
{
	linux_word_t const ret = linux_syscall2((unsigned int)func, (linux_uword_t)data, linux_syscall_name_bdflush);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_setfsuid16(linux_old_uid_t const uid, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall1(uid, linux_syscall_name_setfsuid16);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_setfsgid16(linux_old_gid_t const gid, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall1(gid, linux_syscall_name_setfsgid16);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_setresuid16(linux_old_uid_t const ruid, linux_old_uid_t const euid, linux_old_uid_t const suid)
{
	linux_word_t const ret = linux_syscall3(ruid, euid, suid, linux_syscall_name_setresuid16);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_getresuid16(linux_old_uid_t* const ruidp, linux_old_uid_t* const euidp, linux_old_uid_t* const suidp)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)ruidp, (uintptr_t)euidp, (uintptr_t)suidp, linux_syscall_name_getresuid16);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_setresgid16(linux_old_gid_t const rgid, linux_old_gid_t const egid, linux_old_gid_t const sgid)
{
	linux_word_t const ret = linux_syscall3(rgid, egid, sgid, linux_syscall_name_setresgid16);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_getresgid16(linux_old_gid_t* const rgidp, linux_old_gid_t* const egidp, linux_old_gid_t* const sgidp)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)rgidp, (uintptr_t)egidp, (uintptr_t)sgidp, linux_syscall_name_getresgid16);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_chown16(char const* const filename, linux_old_uid_t const user, linux_old_gid_t const group)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)filename, user, group, linux_syscall_name_chown16);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_mmap_pgoff(linux_uword_t const addr, linux_uword_t const len, linux_uword_t const prot, linux_uword_t const flags, linux_uword_t const fd, linux_uword_t const pgoff, linux_uword_t* const result)
{
	linux_word_t const ret = linux_syscall6(addr, len, prot, flags, fd, pgoff, linux_syscall_name_mmap_pgoff);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_uword_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_stat64(char const* const filename, struct linux_stat64* const statbuf)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)filename, (uintptr_t)statbuf, linux_syscall_name_stat64);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_lstat64(char const* const filename, struct linux_stat64* const statbuf)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)filename, (uintptr_t)statbuf, linux_syscall_name_lstat64);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
#endif

#if defined(LINUX_ARCH_X86)
inline enum linux_error_t linux_waitpid(linux_pid_t const pid, int* const stat_addr, int const options, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)pid, (uintptr_t)stat_addr, (unsigned int)options, linux_syscall_name_waitpid);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_stat(char const* const filename, struct linux_old_kernel_stat* const statbuf)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)filename, (uintptr_t)statbuf, linux_syscall_name_stat);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_oldumount(char* const name)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)name, linux_syscall_name_oldumount);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_stime(linux_time_t* const tptr)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)tptr, linux_syscall_name_stime);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_fstat(unsigned int const fd, struct linux_old_kernel_stat* const statbuf)
{
	linux_word_t const ret = linux_syscall2(fd, (uintptr_t)statbuf, linux_syscall_name_fstat);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_signal(int const sig, linux_sighandler_t const handler, linux_uword_t* const result)
{
	linux_word_t const ret = linux_syscall2((unsigned int)sig, (uintptr_t)handler, linux_syscall_name_signal);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_uword_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_olduname(struct linux_oldold_utsname* const name)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)name, linux_syscall_name_olduname);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_sgetmask(int* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_sgetmask);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_ssetmask(int const newmask, int* const result)
{
	linux_word_t const ret = linux_syscall1((unsigned int)newmask, linux_syscall_name_ssetmask);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_old_getrlimit(unsigned int const resource, struct linux_rlimit* const rlim)
{
	linux_word_t const ret = linux_syscall2(resource, (uintptr_t)rlim, linux_syscall_name_old_getrlimit);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_old_select(struct linux_sel_arg_struct* const arg, int* const result)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)arg, linux_syscall_name_old_select);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_lstat(char const* const filename, struct linux_old_kernel_stat* const statbuf)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)filename, (uintptr_t)statbuf, linux_syscall_name_lstat);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_old_readdir(unsigned int const fd, struct linux_old_linux_dirent* const dirent, unsigned int const count)
{
	linux_word_t const ret = linux_syscall3(fd, (uintptr_t)dirent, count, linux_syscall_name_old_readdir);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_old_mmap(struct linux_mmap_arg_struct* const arg, linux_uword_t* const result)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)arg, linux_syscall_name_old_mmap);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_uword_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_socketcall(int const call, linux_uword_t* const args, int* const result)
{
	linux_word_t const ret = linux_syscall2((unsigned int)call, (uintptr_t)args, linux_syscall_name_socketcall);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (int)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_uname(struct linux_old_utsname* const name)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)name, linux_syscall_name_uname);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_vm86old(struct linux_vm86_struct* const user_vm86)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)user_vm86, linux_syscall_name_vm86old);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_ipc(unsigned int const call, int const first, linux_uword_t const second, linux_uword_t const third, void* const ptr, linux_word_t const fifth, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall6(call, (unsigned int)first, second, third, (uintptr_t)ptr, (linux_uword_t)fifth, linux_syscall_name_ipc);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	if (result)
		*result = (linux_word_t)ret;
	return linux_error_none;
}
inline enum linux_error_t linux_vm86(linux_uword_t const cmd, linux_uword_t const arg)
{
	linux_word_t const ret = linux_syscall2(cmd, arg, linux_syscall_name_vm86);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_set_thread_area(struct linux_user_desc* const u_info)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)u_info, linux_syscall_name_set_thread_area);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
inline enum linux_error_t linux_get_thread_area(struct linux_user_desc* const u_info)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)u_info, linux_syscall_name_get_thread_area);
	if (linux_syscall_returned_error(ret))
		return (enum linux_error_t)-ret;
	return linux_error_none;
}
#endif

//=============================================================================
// x86 vsyscalls

#if defined(LINUX_ARCH_X86)
// TODO: Add vsyscalls for x86.
#endif

#endif // !HEADER_LIBLINUX_LINUX_H_INCLUDED
