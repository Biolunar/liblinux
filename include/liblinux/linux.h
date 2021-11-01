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

#ifndef HEADER_LIBLINUX_LINUX_H_INCLUDED
#define HEADER_LIBLINUX_LINUX_H_INCLUDED

#include "version.h"
#include "endian.h"
#include "arch.h"
#include "error.h"
#include "asm.h"
#include "unistd.h"
#include "constants.h"

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdalign.h>

// TODO: I changed (u)long to (u)word_t in all signatures. TODO: also change that in structures that are passed to syscalls. TODO: also change the typedefs?
// TODO: Replace primitive types and signed types with appropriate fixed types in syscall signatures.
// TODO: find a good and future proof way to name all syscalls. Currently I'm using the names from the unterlying kernel functions.
// TODO: Some architectures have unique types and constants. Make them stand out more?

//=============================================================================
// Generic types

#include "types.h"

//=============================================================================
// TODO

typedef int32_t        linux_wd_t;
typedef linux_word_t   linux_old_time_t;
typedef unsigned short linux_umode_t;
typedef int32_t        linux_key_serial_t;
typedef int            linux_key_t;
typedef int            linux_mqd_t;
typedef linux_word_t   linux_off_t;
typedef long long      linux_loff_t;
typedef unsigned int   linux_uid_t;
typedef unsigned int   linux_gid_t;
typedef linux_uid_t    linux_qid_t;
typedef int            linux_clockid_t;
typedef linux_word_t   linux_clock_t;
typedef int            linux_timer_t;
typedef unsigned char  linux_cc_t;
typedef unsigned int   linux_speed_t;

//=============================================================================
// time

typedef int64_t linux_time_t;

struct linux_timespec
{
	linux_time_t tv_sec;
	int64_t      tv_nsec;
};

struct linux_itimerspec
{
	struct linux_timespec it_interval;
	struct linux_timespec it_value;
};

#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_X86)
typedef int32_t linux_time32_t;

struct linux_timespec32
{
	linux_time32_t tv_sec;
	int32_t        tv_nsec;
};

struct linux_itimerspec32
{
	struct linux_timespec32 it_interval;
	struct linux_timespec32 it_value;
};
#endif

//=============================================================================
// aio

typedef linux_uword_t linux_aio_context_t;

struct linux_io_event
{
	uint64_t data;
	uint64_t obj;
	int64_t  res;
	int64_t  res2;
};

struct linux_iocb
{
	uint64_t    aio_data;
#ifdef LINUX_ENDIAN_LITTLE
	uint32_t    aio_key;
	linux_rwf_t aio_rw_flags;
#else
	linux_rwf_t aio_rw_flags;
	uint32_t    aio_key;
#endif
	uint16_t    aio_lio_opcode;
	int16_t     aio_reqprio;
	uint32_t    aio_fildes;
	uint64_t    aio_buf;
	uint64_t    aio_nbytes;
	int64_t     aio_offset;
	uint64_t    aio_reserved2;
	uint32_t    aio_flags;
	uint32_t    aio_resfd;
};

//=============================================================================
// polling

typedef struct
{
	linux_uword_t fds_bits[linux_FD_SETSIZE / (8 * sizeof(linux_uword_t))];
} linux_fd_set;

struct linux_pollfd
{
	linux_fd_t fd;
	int16_t    events;
	int16_t    revents;
};

//=============================================================================
// signal

typedef struct
{
	unsigned long sig[linux_NSIG / LINUX_BITS_PER_LONG];
} linux_sigset_t;

typedef union linux_sigval
{
	int32_t sival_int;
	void*   sival_ptr;
} linux_sigval_t;

typedef struct linux_sigevent
{
	linux_sigval_t sigev_value;
	uint32_t       sigev_signo;
	uint32_t       sigev_notify;
	union
	{
		uint32_t    _pad[linux_SIGEV_PAD_SIZE];
		linux_pid_t sigev_notify_thread_id;
		struct
		{
			void  (*sigev_notify_function)(linux_sigval_t);
			void*   sigev_notify_attributes;
		};
	};
} linux_sigevent_t;

struct linux_signalfd_siginfo
{
	uint32_t ssi_signo;
	int32_t  ssi_errno;
	int32_t  ssi_code;
	uint32_t ssi_pid;
	uint32_t ssi_uid;
	int32_t  ssi_fd;
	uint32_t ssi_tid;
	uint32_t ssi_band;
	uint32_t ssi_overrun;
	uint32_t ssi_trapno;
	int32_t  ssi_status;
	int32_t  ssi_int;
	uint64_t ssi_ptr;
	uint64_t ssi_utime;
	uint64_t ssi_stime;
	uint64_t ssi_addr;
	uint16_t ssi_addr_lsb;
	uint16_t _pad2;
	int32_t  ssi_syscall;
	uint64_t ssi_call_addr;
	uint32_t ssi_arch;
	uint8_t  _pad[28];
};

//=============================================================================
// landlock

struct linux_landlock_ruleset_attr
{
	uint64_t handled_access_fs;
};

struct linux_landlock_path_beneath_attr
{
	unsigned char data[sizeof(uint64_t) + sizeof(linux_fd_t)];
	//uint64_t allowed_access;
	//linux_fd_t parent_fd;
};
_Static_assert(sizeof(struct linux_landlock_path_beneath_attr) == (sizeof(uint64_t) + sizeof(linux_fd_t)), "struct linux_landlock_path_beneath_attr is not tightly packed");

//=============================================================================
// TODO

struct linux_mount_attr
{
	uint64_t attr_set;
	uint64_t attr_clr;
	uint64_t propagation;
	uint64_t userns_fd;
};
struct linux_utimbuf
{
	linux_old_time_t actime;
	linux_old_time_t modtime;
};
struct linux_old_timespec
{
	linux_old_time_t tv_sec;
	linux_word_t tv_nsec;
};
struct linux_sched_param
{
	int sched_priority;
};
struct linux_mq_attr
{
	linux_word_t mq_flags;
	linux_word_t mq_maxmsg;
	linux_word_t mq_msgsize;
	linux_word_t mq_curmsgs;
	linux_word_t _reserved[4];
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
struct linux_timezone
{
	int tz_minuteswest;
	int tz_dsttime;
};
struct linux_sembuf
{
	unsigned short sem_num;
	short sem_op;
	short sem_flg;
};
struct linux_msgbuf
{
	linux_word_t mtype;
	char mtext[];
};
struct linux_dirent
{
	linux_uword_t d_ino;
	linux_uword_t d_off;
	unsigned short d_reclen;
	char d_name[];
};
struct linux_rlimit
{
	linux_uword_t rlim_cur;
	linux_uword_t rlim_max;
};
struct linux_tms
{
	linux_clock_t tms_utime;
	linux_clock_t tms_stime;
	linux_clock_t tms_cutime;
	linux_clock_t tms_cstime;
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
typedef struct
{
	int val[2];
} linux_fsid_t;
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
struct linux_timex_timeval
{
	linux_time_t tv_sec;
	long long tv_usec;
};
struct linux_timex
{
	unsigned int modes;
	int :32;
	long long offset;
	long long freq;
	long long maxerror;
	long long esterror;
	int status;
	int :32;
	long long constant;
	long long precision;
	long long tolerance;
	struct linux_timex_timeval time;
	long long tick;
	long long ppsfreq;
	long long jitter;
	int shift;
	int :32;
	long long stabil;
	long long jitcnt;
	long long calcnt;
	long long errcnt;
	long long stbcnt;
	int tai;
	int :32; int :32; int :32; int :32;
	int :32; int :32; int :32; int :32;
	int :32; int :32; int :32;
};
struct linux_robust_list
{
	struct linux_robust_list* next;
};
struct linux_robust_list_head
{
	struct linux_robust_list list;
	linux_word_t futex_offset;
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
	linux_uword_t blob[128 / sizeof(linux_uword_t)];
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
struct linux_io_uring_sqe
{
	uint8_t opcode;
	uint8_t flags;
	uint16_t ioprio;
	int32_t fd;
	union
	{
		uint64_t off;
		uint64_t addr2;
	};
	union
	{
		uint64_t addr;
		uint64_t splice_off_in;
	};
	uint32_t len;
	union
	{
		linux_rwf_t rw_flags;
		uint32_t fsync_flags;
		uint16_t poll_events;
		uint32_t sync_range_flags;
		uint32_t msg_flags;
		uint32_t timeout_flags;
		uint32_t accept_flags;
		uint32_t cancel_flags;
		uint32_t open_flags;
		uint32_t statx_flags;
		uint32_t fadvise_advice;
		uint32_t splice_flags;
	};
	uint64_t user_data;
	union
	{
		struct
		{
			union
			{
				uint16_t buf_index;
				uint16_t buf_group;
			};
			uint16_t personality;
			int32_t splice_fd_in;
		};
		uint64_t _pad2[3];
	};
};
struct linux_io_uring_cqe
{
	uint64_t user_data;
	int32_t res;
	uint32_t flags;
};
struct linux_io_sqring_offsets
{
	uint32_t head;
	uint32_t tail;
	uint32_t ring_mask;
	uint32_t ring_entries;
	uint32_t flags;
	uint32_t dropped;
	uint32_t array;
	uint32_t _resv1;
	uint64_t _resv2;
};
struct linux_io_cqring_offsets
{
	uint32_t head;
	uint32_t tail;
	uint32_t ring_mask;
	uint32_t ring_entries;
	uint32_t overflow;
	uint32_t cqes;
	uint32_t flags;
	uint32_t _resv1;
	uint64_t _resv2;
};
struct linux_io_uring_params
{
	uint32_t sq_entries;
	uint32_t cq_entries;
	uint32_t flags;
	uint32_t sq_thread_cpu;
	uint32_t sq_thread_idle;
	uint32_t features;
	uint32_t wq_fd;
	uint32_t _resv[3];
	struct linux_io_sqring_offsets sq_off;
	struct linux_io_cqring_offsets cq_off;
};
struct linux_io_uring_files_update
{
	uint32_t offset;
	uint32_t resv;
	alignas(8) uint64_t fds;
};
struct linux_io_uring_probe_op
{
	uint8_t op;
	uint8_t resv;
	uint16_t flags;
	uint32_t _resv2;
};
struct linux_io_uring_probe
{
	uint8_t last_op;
	uint8_t ops_len;
	uint16_t _resv;
	uint32_t _resv2[3];
	struct linux_io_uring_probe_op ops[];
};
struct linux_winsize
{
	unsigned short ws_row;
	unsigned short ws_col;
	unsigned short ws_xpixel;
	unsigned short ws_ypixel;
};
struct linux_clone_args
{
	alignas(8) uint64_t flags;
	alignas(8) uint64_t pidfd;
	alignas(8) uint64_t child_tid;
	alignas(8) uint64_t parent_tid;
	alignas(8) uint64_t exit_signal;
	alignas(8) uint64_t stack;
	alignas(8) uint64_t stack_size;
	alignas(8) uint64_t tls;
	alignas(8) uint64_t set_tid;
	alignas(8) uint64_t set_tid_size;
};

#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_X86)
struct linux_timeval32
{
	linux_time32_t tv_sec;
	int32_t tv_usec;
};
struct linux_utimbuf32
{
	linux_time32_t actime;
	linux_time32_t modtime;
};
struct linux_timex32
{
	uint32_t modes;
	int32_t offset;
	int32_t freq;
	int32_t maxerror;
	int32_t esterror;
	int32_t status;
	int32_t constant;
	int32_t precision;
	int32_t tolerance;
	struct linux_timeval32 time;
	int32_t tick;
	int32_t ppsfreq;
	int32_t jitter;
	int32_t shift;
	int32_t stabil;
	int32_t jitcnt;
	int32_t calcnt;
	int32_t errcnt;
	int32_t stbcnt;
	int32_t tai;
	int32_t :32; int32_t :32; int32_t :32; int32_t :32;
	int32_t :32; int32_t :32; int32_t :32; int32_t :32;
	int32_t :32; int32_t :32; int32_t :32;
};
#endif

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
	linux_uword_t d_ino;
	linux_uword_t d_offset;
	unsigned short d_namlen;
	char d_name[];
};
struct linux_mmap_arg_struct
{
	linux_uword_t addr;
	linux_uword_t len;
	linux_uword_t prot;
	linux_uword_t flags;
	linux_uword_t fd;
	linux_uword_t offset;
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

//=============================================================================
// KD ioctls

typedef char linux_scrnmap_t;

struct linux_consolefontdesc
{
	unsigned short charcount;
	unsigned short charheight;
	char* chardata;
};
struct linux_unipair
{
	unsigned short unicode;
	unsigned short fontpos;
};
struct linux_unimapdesc
{
	unsigned short entry_ct;
	struct linux_unipair* entries;
};
struct linux_unimapinit
{
	unsigned short advised_hashsize;
	unsigned short advised_hashstep;
	unsigned short advised_hashlevel;
};
struct linux_kbentry
{
	unsigned char kb_table;
	unsigned char kb_index;
	unsigned short kb_value;
};
struct linux_kbsentry
{
	unsigned char kb_func;
	unsigned char kb_string[512];
};
struct linux_kbdiacr
{
        unsigned char diacr;
	unsigned char base;
	unsigned char result;
};
struct linux_kbdiacrs
{
        unsigned int kb_cnt;
	struct linux_kbdiacr kbdiacr[256];
};
struct linux_kbdiacruc
{
	unsigned int diacr;
	unsigned int base;
	unsigned int result;
};
struct linux_kbdiacrsuc
{
        unsigned int kb_cnt;
	struct linux_kbdiacruc kbdiacruc[256];
};
struct linux_kbkeycode
{
	unsigned int scancode;
	unsigned int keycode;
};
struct linux_kbd_repeat
{
	int delay;
	int period;
};
struct linux_console_font_op
{
	unsigned int op;
	unsigned int flags;
	unsigned int width;
	unsigned int height;
	unsigned int charcount;
	unsigned char* data;
};
struct linux_console_font
{
	unsigned int width;
	unsigned int height;
	unsigned int charcount;
	unsigned char* data;
};

//=============================================================================
// VT ioctls

struct linux_vt_mode
{
	char mode;
	char waitv;
	short relsig;
	short acqsig;
	short frsig;
};
struct linux_vt_stat
{
	unsigned short v_active;
	unsigned short v_signal;
	unsigned short v_state;
};
struct linux_vt_sizes
{
	unsigned short v_rows;
	unsigned short v_cols;
	unsigned short v_scrollsize;
};
struct linux_vt_consize
{
	unsigned short v_rows;
	unsigned short v_cols;
	unsigned short v_vlin;
	unsigned short v_clin;
	unsigned short v_vcol;
	unsigned short v_ccol;
};
struct linux_vt_event
{
	unsigned int event;
	unsigned int oldev;
	unsigned int newev;
	unsigned int _pad[4];
};
struct linux_vt_setactivate
{
	unsigned int console;
	struct linux_vt_mode mode;
};

//=============================================================================
// linux_TIOCLINUX ioctl

struct linux_tiocl_selection
{
	unsigned short xs;
	unsigned short ys;
	unsigned short xe;
	unsigned short ye;
	unsigned short sel_mode;
};

//=============================================================================
// blktrace_api

struct linux_blk_io_trace
{
	uint32_t magic;
	uint32_t sequence;
	uint64_t time;
	uint64_t sector;
	uint32_t bytes;
	uint32_t action;
	uint32_t pid;
	uint32_t device;
	uint32_t cpu;
	uint16_t error;
	uint16_t pdu_len;
};
struct linux_blk_io_trace_remap
{
	uint32_t device_from; // big endian
	uint32_t device_to; // big endian
	uint64_t sector_from; // big endian
};
struct linux_blk_user_trace_setup
{
	char name[linux_BLKTRACE_BDEV_SIZE];
	uint16_t act_mask;
	uint32_t buf_size;
	uint32_t buf_nr;
	uint64_t start_lba;
	uint64_t end_lba;
	uint32_t pid;
};

//=============================================================================
// blkpg

struct linux_blkpg_ioctl_arg
{
	int op;
	int flags;
	int datalen;
	void* data;
};
struct linux_blkpg_partition
{
	long long start;
	long long length;
	int pno;
	char devname[linux_BLKPG_DEVNAMELTH];
	char volname[linux_BLKPG_VOLNAMELTH];
};

//=============================================================================
// fiemap

struct linux_fiemap_extent
{
	uint64_t fe_logical;
	uint64_t fe_physical;
	uint64_t fe_length;
	uint64_t fe_reserved64[2];
	uint32_t fe_flags;
	uint32_t fe_reserved[3];
};
struct linux_fiemap
{
	uint64_t fm_start;
	uint64_t fm_length;
	uint32_t fm_flags;
	uint32_t fm_mapped_extents;
	uint32_t fm_extent_count;
	uint32_t fm_reserved;
	struct linux_fiemap_extent fm_extents[];
};

//=============================================================================
// fs

struct linux_file_clone_range
{
	int64_t src_fd;
	uint64_t src_offset;
	uint64_t src_length;
	uint64_t dest_offset;
};
struct linux_fstrim_range
{
	uint64_t start;
	uint64_t len;
	uint64_t minlen;
};
struct linux_file_dedupe_range_info
{
	int64_t dest_fd;
	uint64_t dest_offset;
	uint64_t bytes_deduped;
	int32_t status;
	uint32_t reserved;
};
struct linux_file_dedupe_range
{
	uint64_t src_offset;
	uint64_t src_length;
	uint16_t dest_count;
	uint16_t reserved1;
	uint32_t reserved2;
	struct linux_file_dedupe_range_info info[];
};
struct linux_fsxattr
{
	uint32_t fsx_xflags;
	uint32_t fsx_extsize;
	uint32_t fsx_nextents;
	uint32_t fsx_projid;
	uint32_t fsx_cowextsize;
	unsigned char fsx_pad[8];
};
struct linux_open_how
{
	uint64_t flags;
	uint64_t mode;
	uint64_t resolve;
};

//=============================================================================
// Architecture specific types

#if defined(LINUX_ARCH_ARM_EABI)
#include "arm-eabi/types.h"
#elif defined(LINUX_ARCH_ARM64)
#include "arm64/types.h"
#elif defined(LINUX_ARCH_RISCV32)
#include "riscv32/types.h"
#elif defined(LINUX_ARCH_RISCV64)
#include "riscv64/types.h"
#elif defined(LINUX_ARCH_X86)
#include "x86/types.h"
#elif defined(LINUX_ARCH_X32)
#include "x32/types.h"
#elif defined(LINUX_ARCH_X86_64)
#include "x86_64/types.h"
#endif

//=============================================================================
// Architecture dependent types

#include "drm/drm.h"
#include "drm/drm_mode.h"
#include "drm/drm_fourcc.h"

//-----------------------------------------------------------------------------
// aio

struct linux_aio_sigset
{
	linux_sigset_t const* sigmask;
	linux_size_t          sigsetsize;
};

//-----------------------------------------------------------------------------
// TODO

struct linux_old_timeval
{
	linux_word_t tv_sec;
	linux_suseconds_t tv_usec;
};
struct linux_old_itimerval
{
	struct linux_old_timeval it_interval;
	struct linux_old_timeval it_value;
};
struct linux_iovec
{
	void* iov_base;
	linux_size_t iov_len;
};
struct linux_ustat
{
	linux_daddr_t f_tfree;
	linux_ino_t f_tinode;
	char f_fname[6];
	char f_fpack[6];
};
struct linux_kexec_segment
{
	void const* buf;
	linux_size_t bufsz;
	void const* mem;
	linux_size_t memsz;
};
struct linux_rusage
{
	struct linux_old_timeval ru_utime;
	struct linux_old_timeval ru_stime;
	linux_word_t ru_maxrss;
	linux_word_t ru_ixrss;
	linux_word_t ru_idrss;
	linux_word_t ru_isrss;
	linux_word_t ru_minflt;
	linux_word_t ru_majflt;
	linux_word_t ru_nswap;
	linux_word_t ru_inblock;
	linux_word_t ru_oublock;
	linux_word_t ru_msgsnd;
	linux_word_t ru_msgrcv;
	linux_word_t ru_nsignals;
	linux_word_t ru_nvcsw;
	linux_word_t ru_nivcsw;
};

#if defined(LINUX_ARCH_ARM_EABI)
#include "arm-eabi/structs.h"
#elif defined(LINUX_ARCH_ARM64)
#include "arm64/structs.h"
#elif defined(LINUX_ARCH_RISCV32)
#include "riscv32/structs.h"
#elif defined(LINUX_ARCH_RISCV64)
#include "riscv64/structs.h"
#elif defined(LINUX_ARCH_X86)
#include "x86/structs.h"
#elif defined(LINUX_ARCH_X32)
#include "x32/structs.h"
#elif defined(LINUX_ARCH_X86_64)
#include "x86_64/structs.h"
#endif

//=============================================================================
// Deprecated types

#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_X86)
struct linux_old_sigaction
{
	linux_sighandler_t sa_handler;
	linux_old_sigset_t sa_mask;
	linux_uword_t sa_flags;
	linux_sigrestore_t sa_restorer;
};
#endif
#if defined(LINUX_ARCH_X86)
struct linux_sel_arg_struct
{
	uint32_t n;
	linux_fd_set *inp, *outp, *exp;
	struct linux_old_timeval* tvp;
};
#endif

//=============================================================================
// Socket

typedef unsigned short linux_sa_family_t;

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
	linux_size_t msg_iovlen;
	void* msg_control;
	linux_size_t msg_controllen;
	unsigned int msg_flags;
};
struct linux_mmsghdr
{
	struct linux_user_msghdr msg_hdr;
	unsigned int msg_len;
};

//-----------------------------------------------------------------------------
// Unix

struct linux_sockaddr_un
{
	linux_sa_family_t sun_family;
	char sun_path[108];
};

//-----------------------------------------------------------------------------
// IPv4

struct linux_in_addr
{
	uint32_t s_addr;
};
struct linux_ip_mreq
{
	struct linux_in_addr imr_multiaddr;
	struct linux_in_addr imr_interface;
};
struct linux_ip_mreqn
{
	struct linux_in_addr imr_multiaddr;
	struct linux_in_addr imr_address;
	int imr_ifindex;
};
struct linux_ip_mreq_source
{
	uint32_t imr_multiaddr;
	uint32_t imr_interface;
	uint32_t imr_sourceaddr;
};
struct linux_ip_msfilter
{
	uint32_t imsf_multiaddr;
	uint32_t imsf_interface;
	uint32_t imsf_fmode;
	uint32_t imsf_numsrc;
	uint32_t imsf_slist[];
};
struct linux_sockaddr_storage
{
	alignas(struct linux_sockaddr*) linux_sa_family_t ss_family;
	char _data[128 - sizeof(linux_sa_family_t)];
};
_Static_assert(alignof(struct linux_sockaddr_storage) == alignof(struct linux_sockaddr*), "struct linux_sockaddr_storage is misaligned");
struct linux_group_req
{
	uint32_t gr_interface;
	struct linux_sockaddr_storage gr_group;
};
struct linux_group_source_req
{
	uint32_t gsr_interface;
	struct linux_sockaddr_storage gsr_group;
	struct linux_sockaddr_storage gsr_source;
};
struct linux_group_filter
{
	uint32_t gf_interface;
	struct linux_sockaddr_storage gf_group;
	uint32_t gf_fmode;
	uint32_t gf_numsrc;
	struct linux_sockaddr_storage gf_slist[];
};
struct linux_in_pktinfo
{
	int ipi_ifindex;
	struct linux_in_addr ipi_spec_dst;
	struct linux_in_addr ipi_addr;
};
struct linux_sockaddr_in
{
	linux_sa_family_t sin_family;
	uint16_t sin_port;
	struct linux_in_addr sin_addr;
	unsigned char _pad[sizeof(struct linux_sockaddr) - sizeof(linux_sa_family_t) - sizeof(uint16_t) - sizeof(struct linux_in_addr)];
};
_Static_assert(sizeof(struct linux_sockaddr_in) == sizeof(struct linux_sockaddr), "struct linux_sockaddr_in has wrong size");
struct linux_sock_extended_err
{
	uint32_t ee_errno;
	uint8_t ee_origin;
	uint8_t ee_type;
	uint8_t ee_code;
	uint8_t ee_pad;
	uint32_t ee_info;
	uint32_t ee_data;
};
struct linux_scm_timestamping
{
	struct linux_old_timespec ts[3];
};
struct linux_scm_timestamping64
{
	struct linux_timespec ts[3];
};

//-----------------------------------------------------------------------------
// IPv6

struct linux_in6_addr
{
	union
	{
		uint8_t u6_addr8[16];
		uint16_t u6_addr16[8];
		uint32_t u6_addr32[4];
	} in6_u;
};
struct linux_sockaddr_in6
{
	unsigned short int sin6_family;
	uint16_t sin6_port;
	uint32_t sin6_flowinfo;
	struct linux_in6_addr sin6_addr;
	uint32_t sin6_scope_id;
};
struct linux_ipv6_mreq
{
	struct linux_in6_addr ipv6mr_multiaddr;
	int ipv6mr_ifindex;
};
struct linux_in6_flowlabel_req
{
	struct linux_in6_addr flr_dst;
	uint32_t flr_label;
	uint8_t flr_action;
	uint8_t flr_share;
	uint16_t flr_flags;
	uint16_t flr_expires;
	uint16_t flr_linger;
	uint32_t _flr_pad;
};
struct linux_in6_rtmsg
{
	struct linux_in6_addr rtmsg_dst;
	struct linux_in6_addr rtmsg_src;
	struct linux_in6_addr rtmsg_gateway;
	uint32_t rtmsg_type;
	uint16_t rtmsg_dst_len;
	uint16_t rtmsg_src_len;
	uint32_t rtmsg_metric;
	linux_uword_t rtmsg_info;
	uint32_t rtmsg_flags;
	int rtmsg_ifindex;
};
struct linux_in6_pktinfo
{
	struct linux_in6_addr ipi6_addr;
	int ipi6_ifindex;
};
struct linux_ip6_mtuinfo
{
	struct linux_sockaddr_in6 ip6m_addr;
	uint32_t ip6m_mtu;
};
struct linux_in6_ifreq
{
	struct linux_in6_addr ifr6_addr;
	uint32_t ifr6_prefixlen;
	int ifr6_ifindex;
};
struct linux_ipv6_rt_hdr
{
	uint8_t nexthdr;
	uint8_t hdrlen;
	uint8_t type;
	uint8_t segments_left;
};
struct linux_ipv6_opt_hdr
{
	uint8_t nexthdr;
	uint8_t hdrlen;
};
_Static_assert(sizeof(struct linux_ipv6_opt_hdr) == 2*sizeof(uint8_t), "struct linux_ipv6_opt_hdr has padding");
struct linux_rt0_hdr
{
	struct linux_ipv6_rt_hdr rt_hdr;
	uint32_t reserved;
	struct linux_in6_addr addr[];
};
struct linux_rt2_hdr
{
	struct linux_ipv6_rt_hdr rt_hdr;
	uint32_t reserved;
	struct linux_in6_addr addr;
};
struct linux_ipv6_destopt_hao
{
	/*
	 * This structures must not have padding, but that's not possible to force in standard C.
	 * That's why you have to do the work yourself.
	 */
	uint8_t type;
	uint8_t length;
	unsigned char addr[sizeof(struct linux_in6_addr)]; // struct linux_in6_addr
};
_Static_assert(sizeof(struct linux_ipv6_destopt_hao) == 2*sizeof(uint8_t)+sizeof(struct linux_in6_addr), "struct linux_ipv6_destopt_hao has padding");
struct linux_ipv6hdr
{
#if defined(LINUX_ENDIAN_LITTLE)
	uint8_t priority :4,
	        version  :4;
#elif defined(LINUX_ENDIAN_BIG)
	uint8_t version  :4,
	        priority :4;
#endif
	uint8_t flow_lbl[3];
	uint16_t payload_len;
	uint8_t nexthdr;
	uint8_t hop_limit;
	struct linux_in6_addr saddr;
	struct linux_in6_addr daddr;
};
struct linux_ip6_tnl_parm
{
	char name[linux_IFNAMSIZ];
	int link;
	uint8_t proto;
	uint8_t encap_limit;
	uint8_t hop_limit;
	uint32_t flowinfo;
	uint32_t flags;
	struct linux_in6_addr laddr;
	struct linux_in6_addr raddr;
};
struct linux_ip6_tnl_parm2 {
	char name[linux_IFNAMSIZ];
	int link;
	uint8_t proto;
	uint8_t encap_limit;
	uint8_t hop_limit;
	uint32_t flowinfo;
	uint32_t flags;
	struct linux_in6_addr laddr;
	struct linux_in6_addr raddr;
	uint16_t i_flags;
	uint16_t o_flags;
	uint32_t i_key;
	uint32_t o_key;
};

//-----------------------------------------------------------------------------
// AppleTalk

struct linux_atalk_addr
{
	uint16_t s_net;
	uint8_t s_node;
};
struct linux_sockaddr_at
{
	linux_sa_family_t sat_family;
	uint8_t sat_port;
	struct linux_atalk_addr sat_addr;
	char sat_zero[8];
};
struct linux_atalk_netrange
{
	uint8_t nr_phase;
	uint16_t nr_firstnet;
	uint16_t nr_lastnet;
};

//-----------------------------------------------------------------------------
// Packet

struct linux_sockaddr_pkt
{
	unsigned short spkt_family;
	unsigned char spkt_device[14];
	uint16_t spkt_protocol;
};
struct linux_sockaddr_ll
{
	unsigned short sll_family;
	uint16_t sll_protocol;
	int sll_ifindex;
	unsigned short sll_hatype;
	unsigned char sll_pkttype;
	unsigned char sll_halen;
	unsigned char sll_addr[8];
};
struct linux_tpacket_stats
{
	unsigned int tp_packets;
	unsigned int tp_drops;
};
struct linux_tpacket_stats_v3
{
	unsigned int tp_packets;
	unsigned int tp_drops;
	unsigned int tp_freeze_q_cnt;
};
struct linux_tpacket_rollover_stats
{
	alignas(8) uint64_t tp_all;
	alignas(8) uint64_t tp_huge;
	alignas(8) uint64_t tp_failed;
};
union linux_tpacket_stats_u
{
	struct linux_tpacket_stats stats1;
	struct linux_tpacket_stats_v3 stats3;
};
struct linux_tpacket_auxdata
{
	uint32_t tp_status;
	uint32_t tp_len;
	uint32_t tp_snaplen;
	uint16_t tp_mac;
	uint16_t tp_net;
	uint16_t tp_vlan_tci;
	uint16_t tp_vlan_tpid;
};
struct linux_tpacket_hdr
{
	linux_uword_t tp_status;
	unsigned int tp_len;
	unsigned int tp_snaplen;
	unsigned short tp_mac;
	unsigned short tp_net;
	unsigned int tp_sec;
	unsigned int tp_usec;
};
struct linux_tpacket2_hdr
{
	uint32_t tp_status;
	uint32_t tp_len;
	uint32_t tp_snaplen;
	uint16_t tp_mac;
	uint16_t tp_net;
	uint32_t tp_sec;
	uint32_t tp_nsec;
	uint16_t tp_vlan_tci;
	uint16_t tp_vlan_tpid;
	uint8_t tp_padding[4];
};
struct linux_tpacket_hdr_variant1
{
	uint32_t tp_rxhash;
	uint32_t tp_vlan_tci;
	uint16_t tp_vlan_tpid;
	uint16_t tp_padding;
};
struct linux_tpacket3_hdr
{
	uint32_t tp_next_offset;
	uint32_t tp_sec;
	uint32_t tp_nsec;
	uint32_t tp_snaplen;
	uint32_t tp_len;
	uint32_t tp_status;
	uint16_t tp_mac;
	uint16_t tp_net;
	union
	{
		struct linux_tpacket_hdr_variant1 hv1;
	};
	uint8_t tp_padding[8];
};
struct linux_tpacket_bd_ts
{
	unsigned int ts_sec;
	union
	{
		unsigned int ts_usec;
		unsigned int ts_nsec;
	};
};
struct linux_tpacket_hdr_v1
{
	uint32_t block_status;
	uint32_t num_pkts;
	uint32_t offset_to_first_pkt;
	uint32_t blk_len;
	alignas(8) uint64_t seq_num;
	struct linux_tpacket_bd_ts ts_first_pkt, ts_last_pkt;
};
union linux_tpacket_bd_header_u
{
	struct linux_tpacket_hdr_v1 bh1;
};
struct linux_tpacket_block_desc
{
	uint32_t version;
	uint32_t offset_to_priv;
	union linux_tpacket_bd_header_u hdr;
};
struct linux_tpacket_req
{
	unsigned int tp_block_size;
	unsigned int tp_block_nr;
	unsigned int tp_frame_size;
	unsigned int tp_frame_nr;
};
struct linux_tpacket_req3
{
	unsigned int tp_block_size;
	unsigned int tp_block_nr;
	unsigned int tp_frame_size;
	unsigned int tp_frame_nr;
	unsigned int tp_retire_blk_tov;
	unsigned int tp_sizeof_priv;
	unsigned int tp_feature_req_word;
};
union linux_tpacket_req_u
{
	struct linux_tpacket_req req;
	struct linux_tpacket_req3 req3;
};
struct linux_packet_mreq
{
	int mr_ifindex;
	unsigned short mr_type;
	unsigned short mr_alen;
	unsigned char mr_address[8];
};

//-----------------------------------------------------------------------------
// ax25

typedef struct
{
	char ax25_call[7];
} linux_ax25_address;
struct linux_sockaddr_ax25
{
	linux_sa_family_t sax25_family;
	linux_ax25_address sax25_call;
	int sax25_ndigis;
};
struct linux_full_sockaddr_ax25
{
	struct linux_sockaddr_ax25 fsa_ax25;
	linux_ax25_address fsa_digipeater[linux_AX25_MAX_DIGIS];
};
struct linux_ax25_routes_struct
{
	linux_ax25_address port_addr;
	linux_ax25_address dest_addr;
	unsigned char digi_count;
	linux_ax25_address digi_addr[linux_AX25_MAX_DIGIS];
};
struct linux_ax25_route_opt_struct
{
	linux_ax25_address port_addr;
	linux_ax25_address dest_addr;
	int cmd;
	int arg;
};
struct linux_ax25_ctl_struct
{
	linux_ax25_address port_addr;
	linux_ax25_address source_addr;
	linux_ax25_address dest_addr;
	unsigned int cmd;
	linux_uword_t arg;
	unsigned char digi_count;
	linux_ax25_address digi_addr[linux_AX25_MAX_DIGIS];
};
struct linux_ax25_info_struct_deprecated
{
	unsigned int n2, n2count;
	unsigned int t1, t1timer;
	unsigned int t2, t2timer;
	unsigned int t3, t3timer;
	unsigned int idle, idletimer;
	unsigned int state;
	unsigned int rcv_q, snd_q;
};
struct linux_ax25_info_struct
{
	unsigned int n2, n2count;
	unsigned int t1, t1timer;
	unsigned int t2, t2timer;
	unsigned int t3, t3timer;
	unsigned int idle, idletimer;
	unsigned int state;
	unsigned int rcv_q, snd_q;
	unsigned int vs, vr, va, vs_max;
	unsigned int paclen;
	unsigned int window;
};
struct linux_ax25_fwd_struct
{
	linux_ax25_address port_from;
	linux_ax25_address port_to;
};

//-----------------------------------------------------------------------------
// x25

struct linux_x25_address
{
	char x25_addr[16];
};
struct linux_sockaddr_x25
{
	linux_sa_family_t sx25_family;
	struct linux_x25_address sx25_addr;
};
struct linux_x25_subscrip_struct
{
	char device[200-sizeof(linux_uword_t)];
	linux_uword_t global_facil_mask;
	unsigned int extended;
};
struct linux_x25_route_struct
{
	struct linux_x25_address address;
	unsigned int sigdigits;
	char device[200];
};
struct linux_x25_facilities
{
	unsigned int winsize_in, winsize_out;
	unsigned int pacsize_in, pacsize_out;
	unsigned int throughput;
	unsigned int reverse;
};
struct linux_x25_dte_facilities
{
	uint16_t delay_cumul;
	uint16_t delay_target;
	uint16_t delay_max;
	uint8_t min_throughput;
	uint8_t expedited;
	uint8_t calling_len;
	uint8_t called_len;
	uint8_t calling_ae[20];
	uint8_t called_ae[20];
};
struct linux_x25_calluserdata
{
	unsigned int cudlength;
	unsigned char cuddata[128];
};
struct linux_x25_causediag
{
	unsigned char cause;
	unsigned char diagnostic;
};
struct linux_x25_subaddr
{
	unsigned int cudmatchlength;
};

//-----------------------------------------------------------------------------
// Netlink

struct linux_sockaddr_nl
{
	linux_sa_family_t nl_family;
	unsigned short nl_pad;
	uint32_t nl_pid;
	uint32_t nl_groups;
};
struct linux_nlmsghdr
{
	uint32_t nlmsg_len;
	uint16_t nlmsg_type;
	uint16_t nlmsg_flags;
	uint32_t nlmsg_seq;
	uint32_t nlmsg_pid;
};
struct linux_nlmsgerr
{
	int error;
	struct linux_nlmsghdr msg;
};
struct linux_nl_pktinfo
{
	uint32_t group;
};
struct linux_nl_mmap_req
{
	unsigned int nm_block_size;
	unsigned int nm_block_nr;
	unsigned int nm_frame_size;
	unsigned int nm_frame_nr;
};
struct linux_nl_mmap_hdr
{
	unsigned int nm_status;
	unsigned int nm_len;
	uint32_t nm_group;
	uint32_t nm_pid;
	uint32_t nm_uid;
	uint32_t nm_gid;
};
struct linux_nlattr
{
	uint16_t nla_len;
	uint16_t nla_type;
};
struct linux_nla_bitfield32
{
	uint32_t value;
	uint32_t selector;
};

//-----------------------------------------------------------------------------
// rtnetlink

struct linux_rtattr
{
	unsigned short rta_len;
	unsigned short rta_type;
};
struct linux_rtmsg
{
	unsigned char rtm_family;
	unsigned char rtm_dst_len;
	unsigned char rtm_src_len;
	unsigned char rtm_tos;
	unsigned char rtm_table;
	unsigned char rtm_protocol;
	unsigned char rtm_scope;
	unsigned char rtm_type;
	unsigned int rtm_flags;
};
struct linux_rtnexthop
{
	unsigned short rtnh_len;
	unsigned char rtnh_flags;
	unsigned char rtnh_hops;
	int rtnh_ifindex;
};
struct linux_rtvia
{
	linux_sa_family_t rtvia_family;
	uint8_t rtvia_addr[];
};
struct linux_rta_cacheinfo
{
	uint32_t rta_clntref;
	uint32_t rta_lastuse;
	int32_t rta_expires;
	uint32_t rta_error;
	uint32_t rta_used;
	uint32_t rta_id;
	uint32_t rta_ts;
	uint32_t rta_tsage;
};
struct linux_rta_session
{
	uint8_t proto;
	uint8_t _pad1;
	uint16_t _pad2;
	union
	{
		struct
		{
			uint16_t sport;
			uint16_t dport;
		} ports;
		struct
		{
			uint8_t type;
			uint8_t code;
			uint16_t ident;
		} icmpt;
		uint32_t spi;
	} u;
};
struct linux_rta_mfc_stats
{
	uint64_t mfcs_packets;
	uint64_t mfcs_bytes;
	uint64_t mfcs_wrong_if;
};
struct linux_rtgenmsg
{
	unsigned char rtgen_family;
};
struct linux_ifinfomsg
{
	unsigned char ifi_family;
	unsigned char _ifi_pad;
	unsigned short ifi_type;
	int ifi_index;
	unsigned int ifi_flags;
	unsigned int ifi_change;
};
struct linux_prefixmsg
{
	unsigned char prefix_family;
	unsigned char _prefix_pad1;
	unsigned short _prefix_pad2;
	int prefix_ifindex;
	unsigned char prefix_type;
	unsigned char prefix_len;
	unsigned char prefix_flags;
	unsigned char _prefix_pad3;
};
struct linux_prefix_cacheinfo
{
	uint32_t preferred_time;
	uint32_t valid_time;
};
struct linux_tcmsg
{
	unsigned char tcm_family;
	unsigned char tcm__pad1;
	unsigned short tcm__pad2;
	int tcm_ifindex;
	uint32_t tcm_handle;
	uint32_t tcm_parent;
	uint32_t tcm_info;
};
struct linux_nduseroptmsg
{
	unsigned char nduseropt_family;
	unsigned char _nduseropt_pad1;
	unsigned short nduseropt_opts_len;
	int nduseropt_ifindex;
	uint8_t nduseropt_icmp_type;
	uint8_t nduseropt_icmp_code;
	unsigned short _nduseropt_pad2;
	unsigned int _nduseropt_pad3;
};
struct linux_tcamsg
{
	unsigned char tca_family;
	unsigned char _tca_pad1;
	unsigned short _tca_pad2;
};

//-----------------------------------------------------------------------------
// if_addr

struct linux_ifaddrmsg
{
	uint8_t ifa_family;
	uint8_t ifa_prefixlen;
	uint8_t ifa_flags;
	uint8_t ifa_scope;
	uint32_t ifa_index;
};
struct linux_ifa_cacheinfo
{
	uint32_t ifa_prefered;
	uint32_t ifa_valid;
	uint32_t cstamp;
	uint32_t tstamp;
};

//-----------------------------------------------------------------------------
// if_link

struct linux_rtnl_link_stats
{
	uint32_t rx_packets;
	uint32_t tx_packets;
	uint32_t rx_bytes;
	uint32_t tx_bytes;
	uint32_t rx_errors;
	uint32_t tx_errors;
	uint32_t rx_dropped;
	uint32_t tx_dropped;
	uint32_t multicast;
	uint32_t collisions;
	uint32_t rx_length_errors;
	uint32_t rx_over_errors;
	uint32_t rx_crc_errors;
	uint32_t rx_frame_errors;
	uint32_t rx_fifo_errors;
	uint32_t rx_missed_errors;
	uint32_t tx_aborted_errors;
	uint32_t tx_carrier_errors;
	uint32_t tx_fifo_errors;
	uint32_t tx_heartbeat_errors;
	uint32_t tx_window_errors;
	uint32_t rx_compressed;
	uint32_t tx_compressed;
	uint32_t rx_nohandler;
};
struct linux_rtnl_link_stats64
{
	uint64_t rx_packets;
	uint64_t tx_packets;
	uint64_t rx_bytes;
	uint64_t tx_bytes;
	uint64_t rx_errors;
	uint64_t tx_errors;
	uint64_t rx_dropped;
	uint64_t tx_dropped;
	uint64_t multicast;
	uint64_t collisions;
	uint64_t rx_length_errors;
	uint64_t rx_over_errors;
	uint64_t rx_crc_errors;
	uint64_t rx_frame_errors;
	uint64_t rx_fifo_errors;
	uint64_t rx_missed_errors;
	uint64_t tx_aborted_errors;
	uint64_t tx_carrier_errors;
	uint64_t tx_fifo_errors;
	uint64_t tx_heartbeat_errors;
	uint64_t tx_window_errors;
	uint64_t rx_compressed;
	uint64_t tx_compressed;
	uint64_t rx_nohandler;
};
struct linux_rtnl_link_ifmap
{
	uint64_t mem_start;
	uint64_t mem_end;
	uint64_t base_addr;
	uint16_t irq;
	uint8_t dma;
	uint8_t port;
};
struct linux_ifla_bridge_id
{
	uint8_t prio[2];
	uint8_t addr[6];
};
struct linux_ifla_cacheinfo
{
	uint32_t max_reasm_len;
	uint32_t tstamp;
	uint32_t reachable_time;
	uint32_t retrans_time;
};
struct linux_ifla_vlan_flags
{
	uint32_t flags;
	uint32_t mask;
};
struct linux_ifla_vlan_qos_mapping
{
	uint32_t from;
	uint32_t to;
};
struct linux_ifla_vxlan_port_range
{
	uint16_t low; // Big endian
	uint16_t high; // Big endian
};
struct linux_ifla_vf_mac
{
	uint32_t vf;
	uint8_t mac[32];
};
struct linux_ifla_vf_broadcast
{
	uint8_t broadcast[32];
};
struct linux_ifla_vf_vlan
{
	uint32_t vf;
	uint32_t vlan;
	uint32_t qos;
};
struct linux_ifla_vf_vlan_info
{
	uint32_t vf;
	uint32_t vlan;
	uint32_t qos;
	uint16_t vlan_proto; // Big endian
};
struct linux_ifla_vf_tx_rate
{
	uint32_t vf;
	uint32_t rate;
};
struct linux_ifla_vf_rate
{
	uint32_t vf;
	uint32_t min_tx_rate;
	uint32_t max_tx_rate;
};
struct linux_ifla_vf_spoofchk
{
	uint32_t vf;
	uint32_t setting;
};
struct linux_ifla_vf_guid
{
	uint32_t vf;
	uint64_t guid;
};
struct linux_ifla_vf_link_state
{
	uint32_t vf;
	uint32_t link_state;
};
struct linux_ifla_vf_rss_query_en
{
	uint32_t vf;
	uint32_t setting;
};
struct linux_ifla_vf_trust
{
	uint32_t vf;
	uint32_t setting;
};
struct linux_ifla_port_vsi
{
	uint8_t vsi_mgr_id;
	uint8_t vsi_type_id[3];
	uint8_t vsi_type_version;
	uint8_t _pad[3];
};
struct linux_if_stats_msg
{
	uint8_t family;
	uint8_t _pad1;
	uint16_t _pad2;
	uint32_t ifindex;
	uint32_t filter_mask;
};
struct linux_ifla_rmnet_flags
{
	uint32_t flags;
	uint32_t mask;
};

//-----------------------------------------------------------------------------
// Reliable datagram sockets

typedef uint8_t  linux_rds_tos_t;
typedef uint64_t linux_rds_rdma_cookie_t;

struct linux_rds_info_counter
{
	uint8_t name[32];
	uint64_t value;
};
_Static_assert(sizeof(struct linux_rds_info_counter) == sizeof(uint64_t)+32*sizeof(uint8_t), "struct linux_rds_info_counter has padding");
struct linux_rds_info_connection
{
	/*
	 * This structures must not have padding, but that's not possible to force in standard C.
	 * That's why you have to do the work yourself.
	 */
	unsigned char next_tx_seq[sizeof(uint64_t)]; // uint64_t
	unsigned char next_rx_seq[sizeof(uint64_t)]; // uint64_t
	unsigned char laddr[sizeof(uint32_t)]; // uint32_t
	unsigned char faddr[sizeof(uint32_t)]; // uint32_t
	uint8_t transport[linux_TRANSNAMSIZ];
	uint8_t flags;
	uint8_t tos;
};
_Static_assert(sizeof(struct linux_rds_info_connection) == 2*sizeof(uint64_t)+2*sizeof(uint32_t)+(linux_TRANSNAMSIZ+2)*sizeof(uint8_t), "struct linux_rds_info_connection has padding");
struct linux_rds6_info_connection
{
	/*
	 * This structures must not have padding, but that's not possible to force in standard C.
	 * That's why you have to do the work yourself.
	 */
	unsigned char next_tx_seq[sizeof(uint64_t)]; // uint64_t
	unsigned char next_rx_seq[sizeof(uint64_t)]; // uint64_t
	unsigned char laddr[sizeof(struct linux_in6_addr)]; // struct linux_in6_addr
	unsigned char faddr[sizeof(struct linux_in6_addr)]; // struct linux_in6_addr
	uint8_t transport[linux_TRANSNAMSIZ];
	uint8_t flags;
};
_Static_assert(sizeof(struct linux_rds6_info_connection) == 2*sizeof(uint64_t)+(linux_TRANSNAMSIZ+1)*sizeof(uint8_t)+2*sizeof(struct linux_in6_addr), "struct linux_rds6_info_connection has padding");
struct linux_rds_info_message
{
	/*
	 * This structures must not have padding, but that's not possible to force in standard C.
	 * That's why you have to do the work yourself.
	 */
	unsigned char seq[sizeof(uint64_t)]; // uint64_t
	unsigned char len[sizeof(uint32_t)]; // uint32_t
	unsigned char laddr[sizeof(uint32_t)]; // uint32_t
	unsigned char faddr[sizeof(uint32_t)]; // uint32_t
	unsigned char lport[sizeof(uint16_t)]; // uint16_t
	unsigned char fport[sizeof(uint16_t)]; // uint16_t
	uint8_t flags;
	uint8_t tos;
};
_Static_assert(sizeof(struct linux_rds_info_message) == sizeof(uint64_t)+3*sizeof(uint32_t)+2*sizeof(uint16_t)+2*sizeof(uint8_t), "struct linux_rds_info_message has padding");
struct linux_rds6_info_message
{
	/*
	 * This structures must not have padding, but that's not possible to force in standard C.
	 * That's why you have to do the work yourself.
	 */
	unsigned char seq[sizeof(uint64_t)]; // uint64_t
	unsigned char len[sizeof(uint32_t)]; // uint32_t
	unsigned char laddr[sizeof(struct linux_in6_addr)]; // struct linux_in6_addr
	unsigned char faddr[sizeof(struct linux_in6_addr)]; // struct linux_in6_addr
	unsigned char lport[sizeof(uint16_t)]; // uint16_t
	unsigned char fport[sizeof(uint16_t)]; // uint16_t
	uint8_t flags;
	uint8_t tos;
};
_Static_assert(sizeof(struct linux_rds6_info_message) == sizeof(uint64_t)+sizeof(uint32_t)+2*sizeof(uint16_t)+2*sizeof(uint8_t)+2*sizeof(struct linux_in6_addr), "struct linux_rds6_info_message has padding");
struct linux_rds_info_socket
{
	/*
	 * This structures must not have padding, but that's not possible to force in standard C.
	 * That's why you have to do the work yourself.
	 */
	unsigned char sndbuf[sizeof(uint32_t)]; // uint32_t
	unsigned char bound_addr[sizeof(uint32_t)]; // uint32_t
	unsigned char connected_addr[sizeof(uint32_t)]; // uint32_t
	unsigned char bound_port[sizeof(uint32_t)]; // uint16_t
	unsigned char connected_port[sizeof(uint32_t)]; // uint16_t
	unsigned char rcvbuf[sizeof(uint32_t)]; // uint32_t
	unsigned char inum[sizeof(uint32_t)]; // uint64_t
};
_Static_assert(sizeof(struct linux_rds_info_socket) == sizeof(uint64_t)+4*sizeof(uint32_t)+2*sizeof(uint16_t), "struct linux_rds_info_socket has padding");
struct linux_rds6_info_socket
{
	/*
	 * This structures must not have padding, but that's not possible to force in standard C.
	 * That's why you have to do the work yourself.
	 */
	unsigned char sndbuf[sizeof(uint32_t)]; // uint32_t
	unsigned char bound_addr[sizeof(struct linux_in6_addr)]; // struct linux_in6_addr
	unsigned char connected_addr[sizeof(struct linux_in6_addr)]; // struct linux_in6_addr
	unsigned char bound_port[sizeof(uint16_t)]; // uint16_t
	unsigned char connected_port[sizeof(uint16_t)]; // uint16_t
	unsigned char rcvbuf[sizeof(uint32_t)]; // uint32_t
	unsigned char inum[sizeof(uint64_t)]; // uint64_t
};
_Static_assert(sizeof(struct linux_rds6_info_socket) == sizeof(uint64_t)+2*sizeof(uint32_t)+2*sizeof(uint16_t)+2*sizeof(struct linux_in6_addr), "struct linux_rds6_info_socket has padding");
struct linux_rds_info_tcp_socket
{
	/*
	 * This structures must not have padding, but that's not possible to force in standard C.
	 * That's why you have to do the work yourself.
	 */
	unsigned char local_addr[sizeof(uint32_t)]; // uint32_t
	unsigned char local_port[sizeof(uint16_t)]; // uint16_t
	unsigned char peer_addr[sizeof(uint32_t)]; // uint32_t
	unsigned char peer_port[sizeof(uint16_t)]; // uint16_t
	unsigned char hdr_rem[sizeof(uint64_t)]; // uint64_t
	unsigned char data_rem[sizeof(uint64_t)]; // uint64_t
	unsigned char last_sent_nxt[sizeof(uint32_t)]; // uint32_t
	unsigned char last_expected_una[sizeof(uint32_t)]; // uint32_t
	unsigned char last_seen_una[sizeof(uint32_t)]; // uint32_t
	uint8_t tos;
};
_Static_assert(sizeof(struct linux_rds_info_tcp_socket) == 2*sizeof(uint64_t)+5*sizeof(uint32_t)+2*sizeof(uint16_t)+sizeof(uint8_t), "struct linux_rds_info_tcp_socket has padding");
struct linux_rds6_info_tcp_socket
{
	unsigned char local_addr[sizeof(struct linux_in6_addr)]; // struct linux_in6_addr
	unsigned char local_port[sizeof(uint16_t)]; // uint16_t
	unsigned char peer_addr[sizeof(struct linux_in6_addr)]; // struct linux_in6_addr
	unsigned char peer_port[sizeof(uint16_t)]; // uint16_t
	unsigned char hdr_rem[sizeof(uint64_t)]; // uint64_t
	unsigned char data_rem[sizeof(uint64_t)]; // uint64_t
	unsigned char last_sent_nxt[sizeof(uint32_t)]; // uint32_t
	unsigned char last_expected_una[sizeof(uint32_t)]; // uint32_t
	unsigned char last_seen_una[sizeof(uint32_t)]; // uint32_t
};
_Static_assert(sizeof(struct linux_rds6_info_tcp_socket) == 2*sizeof(uint64_t)+3*sizeof(uint32_t)+2*sizeof(uint16_t)+2*sizeof(struct linux_in6_addr), "struct linux_rds6_info_tcp_socket has padding");
struct linux_rds_info_rdma_connection
{
	uint32_t src_addr;
	uint32_t dst_addr;
	uint8_t src_gid[linux_RDS_IB_GID_LEN];
	uint8_t dst_gid[linux_RDS_IB_GID_LEN];
	uint32_t max_send_wr;
	uint32_t max_recv_wr;
	uint32_t max_send_sge;
	uint32_t rdma_mr_max;
	uint32_t rdma_mr_size;
	uint8_t tos;
};
struct linux_rds6_info_rdma_connection
{
	struct linux_in6_addr src_addr;
	struct linux_in6_addr dst_addr;
	uint8_t src_gid[linux_RDS_IB_GID_LEN];
	uint8_t dst_gid[linux_RDS_IB_GID_LEN];
	uint32_t max_send_wr;
	uint32_t max_recv_wr;
	uint32_t max_send_sge;
	uint32_t rdma_mr_max;
	uint32_t rdma_mr_size;
	uint8_t tos;
};
struct linux_rds_rx_trace_so
{
	uint8_t rx_traces;
	uint8_t rx_trace_pos[linux_RDS_MSG_RX_DGRAM_TRACE_MAX];
};
struct linux_rds_cmsg_rx_trace
{
	uint8_t rx_traces;
	uint8_t rx_trace_pos[linux_RDS_MSG_RX_DGRAM_TRACE_MAX];
	uint64_t rx_trace[linux_RDS_MSG_RX_DGRAM_TRACE_MAX];
};
struct linux_rds_iovec
{
	uint64_t addr;
	uint64_t bytes;
};
struct linux_rds_get_mr_args
{
	struct linux_rds_iovec vec;
	uint64_t cookie_addr;
	uint64_t flags;
};
struct linux_rds_get_mr_for_dest_args
{
	struct linux_sockaddr_storage dest_addr;
	struct linux_rds_iovec vec;
	uint64_t cookie_addr;
	uint64_t flags;
};
struct linux_rds_free_mr_args
{
	linux_rds_rdma_cookie_t cookie;
	uint64_t flags;
};
struct linux_rds_rdma_args
{
	linux_rds_rdma_cookie_t cookie;
	struct linux_rds_iovec remote_vec;
	uint64_t local_vec_addr;
	uint64_t nr_local;
	uint64_t flags;
	uint64_t user_token;
};
struct linux_rds_atomic_args
{
	linux_rds_rdma_cookie_t cookie;
	uint64_t local_addr;
	uint64_t remote_addr;
	union
	{
		struct
		{
			uint64_t compare;
			uint64_t swap;
		} cswp;
		struct
		{
			uint64_t add;
		} fadd;
		struct
		{
			uint64_t compare;
			uint64_t swap;
			uint64_t compare_mask;
			uint64_t swap_mask;
		} m_cswp;
		struct
		{
			uint64_t add;
			uint64_t nocarry_mask;
		} m_fadd;
	};
	uint64_t flags;
	uint64_t user_token;
};
struct linux_rds_rdma_notify
{
	uint64_t user_token;
	int32_t status;
};
struct linux_rds_zcopy_cookies
{
	uint32_t num;
	uint32_t cookies[linux_RDS_MAX_ZCOOKIES];
};

//-----------------------------------------------------------------------------
// VSOCK

struct linux_sockaddr_vm
{
	linux_sa_family_t svm_family;
	unsigned short svm_reserved1;
	unsigned int svm_port;
	unsigned int svm_cid;
	unsigned char svm_zero[sizeof(struct linux_sockaddr) - sizeof(linux_sa_family_t) - sizeof(unsigned short) - sizeof(unsigned int) - sizeof(unsigned int)];
};
struct linux_vsock_diag_req
{
	uint8_t sdiag_family;
	uint8_t sdiag_protocol;
	uint16_t _pad;
	uint32_t vdiag_states;
	uint32_t vdiag_ino;
	uint32_t vdiag_show;
	uint32_t vdiag_cookie[2];
};
struct linux_vsock_diag_msg
{
	uint8_t vdiag_family;
	uint8_t vdiag_type;
	uint8_t vdiag_state;
	uint8_t vdiag_shutdown;
	uint32_t vdiag_src_cid;
	uint32_t vdiag_src_port;
	uint32_t vdiag_dst_cid;
	uint32_t vdiag_dst_port;
	uint32_t vdiag_ino;
	uint32_t vdiag_cookie[2];
};

//=============================================================================
// High-Level Data Link Control (HDLC)

typedef struct
{
	unsigned int clock_rate;
	unsigned int clock_type;
	unsigned short loopback;
} linux_sync_serial_settings;
typedef struct
{
	unsigned int clock_rate;
	unsigned int clock_type;
	unsigned short loopback;
	unsigned int slot_map;
} linux_te1_settings;
typedef struct
{
	unsigned short encoding;
	unsigned short parity;
} linux_raw_hdlc_proto;
typedef struct
{
	unsigned int t391;
	unsigned int t392;
	unsigned int n391;
	unsigned int n392;
	unsigned int n393;
	unsigned short lmi;
	unsigned short dce;
} linux_fr_proto;
typedef struct
{
	unsigned int dlci;
} linux_fr_proto_pvc;
typedef struct
{
	unsigned int dlci;
	char master[linux_IFNAMSIZ];
} linux_fr_proto_pvc_info;
typedef struct
{
	unsigned int interval;
	unsigned int timeout;
} linux_cisco_proto;

//=============================================================================
// Network devices

struct linux_ifmap
{
	linux_uword_t mem_start;
	linux_uword_t mem_end;
	unsigned short base_addr;
	unsigned char irq;
	unsigned char dma;
	unsigned char port;
};
struct linux_if_settings
{
	unsigned int type;
	unsigned int size;
	union
	{
		linux_raw_hdlc_proto* raw_hdlc;
		linux_cisco_proto* cisco;
		linux_fr_proto* fr;
		linux_fr_proto_pvc* fr_pvc;
		linux_fr_proto_pvc_info* fr_pvc_info;
		linux_sync_serial_settings* sync;
		linux_te1_settings* te1;
	} ifs_ifsu;
};
struct linux_ifreq
{
	union
	{
		char ifrn_name[linux_IFNAMSIZ];
	} ifr_ifrn;
	union
	{
		struct linux_sockaddr ifru_addr;
		struct linux_sockaddr ifru_dstaddr;
		struct linux_sockaddr ifru_broadaddr;
		struct linux_sockaddr ifru_netmask;
		struct linux_sockaddr ifru_hwaddr;
		short ifru_flags;
		int ifru_ivalue;
		int ifru_mtu;
		struct linux_ifmap ifru_map;
		char ifru_slave[linux_IFNAMSIZ];
		char ifru_newname[linux_IFNAMSIZ];
		void* ifru_data;
		struct linux_if_settings ifru_settings;
	} ifr_ifru;
};
struct linux_ifconf
{
	int ifc_len;
	union
	{
		char* ifcu_buf;
		struct linux_ifreq* ifcu_req;
	} ifc_ifcu;
};

//=============================================================================
// seccomp

struct linux_seccomp_data
{
	int nr;
	uint32_t arch;
	uint64_t instruction_pointer;
	uint64_t args[6];
};
struct linux_seccomp_notif_sizes
{
	uint16_t seccomp_notif;
	uint16_t seccomp_notif_resp;
	uint16_t seccomp_data;
};
struct linux_seccomp_notif
{
	uint64_t id;
	uint32_t pid;
	uint32_t flags;
	struct linux_seccomp_data data;
};
struct linux_seccomp_notif_resp
{
	uint64_t id;
	int64_t val;
	int32_t error;
	uint32_t flags;
};

//=============================================================================
// serial

struct linux_serial_struct
{
	int type;
	int line;
	unsigned int port;
	int irq;
	int flags;
	int xmit_fifo_size;
	int custom_divisor;
	int baud_base;
	unsigned short close_delay;
	char io_type;
	char reserved_char[1];
	int hub6;
	unsigned short closing_wait;
	unsigned short closing_wait2;
	unsigned char* iomem_base;
	unsigned short iomem_reg_shift;
	unsigned int port_high;
	linux_uword_t iomap_base;
};
struct linux_serial_multiport_struct
{
	int irq;
	int port1;
	unsigned char mask1, match1;
	int port2;
	unsigned char mask2, match2;
	int port3;
	unsigned char mask3, match3;
	int port4;
	unsigned char mask4, match4;
	int port_monitor;
	int reserved[32];
};
struct linux_serial_icounter_struct
{
	int cts, dsr, rng, dcd;
	int rx, tx;
	int frame, overrun, parity, brk;
	int buf_overrun;
	int reserved[9];
};
struct linux_serial_rs485
{
	uint32_t flags;
	uint32_t delay_rts_before_send;
	uint32_t delay_rts_after_send;
	uint32_t padding[5];
};
struct linux_serial_iso7816
{
	uint32_t flags;
	uint32_t tg;
	uint32_t sc_fi;
	uint32_t sc_di;
	uint32_t clk;
	uint32_t reserved[5];
};

//=============================================================================
// fcntl

struct linux_f_owner_ex
{
	int type;
	linux_pid_t pid;
};

//=============================================================================
// evdev

struct linux_input_id
{
	uint16_t bustype;
	uint16_t vendor;
	uint16_t product;
	uint16_t version;
};
struct linux_input_absinfo
{
	int32_t value;
	int32_t minimum;
	int32_t maximum;
	int32_t fuzz;
	int32_t flat;
	int32_t resolution;
};
struct linux_input_keymap_entry
{
	uint8_t flags;
	uint8_t len;
	uint16_t index;
	uint32_t keycode;
	uint8_t scancode[32];
};
struct linux_input_mask
{
	uint32_t type;
	uint32_t codes_size;
	uint64_t codes_ptr;
};
struct linux_ff_replay
{
	uint16_t length;
	uint16_t delay;
};
struct linux_ff_trigger
{
	uint16_t button;
	uint16_t interval;
};
struct linux_ff_envelope
{
	uint16_t attack_length;
	uint16_t attack_level;
	uint16_t fade_length;
	uint16_t fade_level;
};
struct linux_ff_constant_effect
{
	int16_t level;
	struct linux_ff_envelope envelope;
};
struct linux_ff_ramp_effect
{
	int16_t start_level;
	int16_t end_level;
	struct linux_ff_envelope envelope;
};
struct linux_ff_condition_effect
{
	uint16_t right_saturation;
	uint16_t left_saturation;
	int16_t right_coeff;
	int16_t left_coeff;
	uint16_t deadband;
	int16_t center;
};
struct linux_ff_periodic_effect
{
	uint16_t waveform;
	uint16_t period;
	int16_t magnitude;
	int16_t offset;
	uint16_t phase;
	struct linux_ff_envelope envelope;
	uint32_t custom_len;
	int16_t* custom_data;
};
struct linux_ff_rumble_effect
{
	uint16_t strong_magnitude;
	uint16_t weak_magnitude;
};
struct linux_ff_effect
{
	uint16_t type;
	int16_t id;
	uint16_t direction;
	struct linux_ff_trigger trigger;
	struct linux_ff_replay replay;
	union
	{
		struct linux_ff_constant_effect constant;
		struct linux_ff_ramp_effect ramp;
		struct linux_ff_periodic_effect periodic;
		struct linux_ff_condition_effect condition[2];
		struct linux_ff_rumble_effect rumble;
	} u;
};

//=============================================================================
// uinput

struct linux_uinput_ff_upload
{
	uint32_t request_id;
	int32_t retval;
	struct linux_ff_effect effect;
	struct linux_ff_effect old;
};
struct linux_uinput_ff_erase
{
	uint32_t request_id;
	int32_t retval;
	uint32_t effect_id;
};
struct linux_uinput_setup
{
	struct linux_input_id id;
	char name[linux_UINPUT_MAX_NAME_SIZE];
	uint32_t ff_effects_max;
};
struct linux_uinput_abs_setup
{
	uint16_t code;
	struct linux_input_absinfo absinfo;
};
struct linux_uinput_user_dev
{
	char name[linux_UINPUT_MAX_NAME_SIZE];
	struct linux_input_id id;
	uint32_t ff_effects_max;
	int32_t absmax[linux_ABS_CNT];
	int32_t absmin[linux_ABS_CNT];
	int32_t absfuzz[linux_ABS_CNT];
	int32_t absflat[linux_ABS_CNT];
};

//=============================================================================
// Helper functions

static inline bool linux_SI_FROMUSER(linux_siginfo_t const* si)
{
	return si->si_code <= 0;
}

static inline bool linux_SI_FROMKERNEL(linux_siginfo_t const* si)
{
	return si->si_code > 0;
}

//=============================================================================
// Generic syscalls

//-----------------------------------------------------------------------------
// aio

inline linux_error_t linux_io_setup(unsigned int const nr_events, linux_aio_context_t* const ctxp)
{
	linux_word_t const ret = linux_syscall2(nr_events, (uintptr_t)ctxp, linux_syscall_name_io_setup);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_io_destroy(linux_aio_context_t const ctx)
{
	linux_word_t const ret = linux_syscall1(ctx, linux_syscall_name_io_destroy);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_io_submit(linux_aio_context_t const ctx_id, linux_word_t const nr, struct linux_iocb** const iocbpp, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall3(ctx_id, (linux_uword_t)nr, (uintptr_t)iocbpp, linux_syscall_name_io_submit);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}

inline linux_error_t linux_io_cancel(linux_aio_context_t const ctx_id, struct linux_iocb* const iocb, struct linux_io_event* const result)
{
	linux_word_t const ret = linux_syscall3(ctx_id, (uintptr_t)iocb, (uintptr_t)result, linux_syscall_name_io_cancel);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_io_pgetevents(linux_aio_context_t const ctx_id, linux_word_t const min_nr, linux_word_t const nr, struct linux_io_event* const events, struct linux_timespec* const timeout, struct linux_aio_sigset const* const usig, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall6(ctx_id, (linux_uword_t)min_nr, (linux_uword_t)nr, (uintptr_t)events, (uintptr_t)timeout, (uintptr_t)usig, linux_syscall_name_io_pgetevents);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}

#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_X86)
inline linux_error_t linux_io_getevents_time32(linux_aio_context_t const ctx_id, linux_word_t const min_nr, linux_word_t const nr, struct linux_io_event* const events, struct linux_timespec32* const timeout, int* const result) // DEPRECATED: use linux_io_pgetevents
{
	linux_word_t const ret = linux_syscall5(ctx_id, (linux_uword_t)min_nr, (linux_uword_t)nr, (uintptr_t)events, (uintptr_t)timeout, linux_syscall_name_io_getevents_time32);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
#endif

#if defined(LINUX_ARCH_ARM64) || defined(LINUX_ARCH_RISCV64) || defined(LINUX_ARCH_X32) || defined(LINUX_ARCH_X86_64)
inline linux_error_t linux_io_getevents(linux_aio_context_t const ctx_id, linux_word_t const min_nr, linux_word_t const nr, struct linux_io_event* const events, struct linux_timespec* const timeout, int* const result) // DEPRECATED: use linux_io_pgetevents
{
	linux_word_t const ret = linux_syscall5(ctx_id, (linux_uword_t)min_nr, (linux_uword_t)nr, (uintptr_t)events, (uintptr_t)timeout, linux_syscall_name_io_getevents);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
#endif

#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_X86)
inline linux_error_t linux_io_pgetevents_time32(linux_aio_context_t const ctx_id, linux_word_t const min_nr, linux_word_t const nr, struct linux_io_event* const events, struct linux_timespec32* const timeout, struct linux_aio_sigset const* const usig, int* const result) // DEPRECATED: use linux_io_pgetevents
{
	linux_word_t const ret = linux_syscall6(ctx_id, (linux_uword_t)min_nr, (linux_uword_t)nr, (uintptr_t)events, (uintptr_t)timeout, (uintptr_t)usig, linux_syscall_name_io_pgetevents_time32);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
#endif

#if defined(LINUX_ARCH_X86)
inline linux_error_t linux_io_setup_v(unsigned int const nr_events, linux_aio_context_t* const ctxp)
{
	linux_word_t const ret = linux_syscall2_v(nr_events, (uintptr_t)ctxp, linux_syscall_name_io_setup);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_io_destroy_v(linux_aio_context_t const ctx)
{
	linux_word_t const ret = linux_syscall1_v(ctx, linux_syscall_name_io_destroy);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_io_submit_v(linux_aio_context_t const ctx_id, linux_word_t const nr, struct linux_iocb** const iocbpp, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall3_v(ctx_id, (linux_uword_t)nr, (uintptr_t)iocbpp, linux_syscall_name_io_submit);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}

inline linux_error_t linux_io_cancel_v(linux_aio_context_t const ctx_id, struct linux_iocb* const iocb, struct linux_io_event* const result)
{
	linux_word_t const ret = linux_syscall3_v(ctx_id, (uintptr_t)iocb, (uintptr_t)result, linux_syscall_name_io_cancel);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_io_pgetevents_v(linux_aio_context_t const ctx_id, linux_word_t const min_nr, linux_word_t const nr, struct linux_io_event* const events, struct linux_timespec* const timeout, struct linux_aio_sigset const* const usig, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall6_v(ctx_id, (linux_uword_t)min_nr, (linux_uword_t)nr, (uintptr_t)events, (uintptr_t)timeout, (uintptr_t)usig, linux_syscall_name_io_pgetevents);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}

inline linux_error_t linux_io_getevents_time32_v(linux_aio_context_t const ctx_id, linux_word_t const min_nr, linux_word_t const nr, struct linux_io_event* const events, struct linux_timespec32* const timeout, int* const result) // DEPRECATED: use linux_io_pgetevents_v
{
	linux_word_t const ret = linux_syscall5_v(ctx_id, (linux_uword_t)min_nr, (linux_uword_t)nr, (uintptr_t)events, (uintptr_t)timeout, linux_syscall_name_io_getevents_time32);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}

inline linux_error_t linux_io_pgetevents_time32_v(linux_aio_context_t const ctx_id, linux_word_t const min_nr, linux_word_t const nr, struct linux_io_event* const events, struct linux_timespec32* const timeout, struct linux_aio_sigset const* const usig, int* const result) // DEPRECATED: use linux_io_pgetevents_v
{
	linux_word_t const ret = linux_syscall6_v(ctx_id, (linux_uword_t)min_nr, (linux_uword_t)nr, (uintptr_t)events, (uintptr_t)timeout, (uintptr_t)usig, linux_syscall_name_io_pgetevents_time32);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
#endif

//-----------------------------------------------------------------------------
// xattr

inline linux_error_t linux_setxattr(char const* const pathname, char const* const name, void const* const value, linux_size_t const size, int const flags)
{
	linux_word_t const ret = linux_syscall5((uintptr_t)pathname, (uintptr_t)name, (uintptr_t)value, size, (unsigned int)flags, linux_syscall_name_setxattr);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_lsetxattr(char const* const pathname, char const* const name, void const* const value, linux_size_t const size, int const flags)
{
	linux_word_t const ret = linux_syscall5((uintptr_t)pathname, (uintptr_t)name, (uintptr_t)value, size, (unsigned int)flags, linux_syscall_name_lsetxattr);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_fsetxattr(linux_fd_t const fd, char const* const name, void const* const value, linux_size_t const size, int const flags)
{
	linux_word_t const ret = linux_syscall5((uint32_t)fd, (uintptr_t)name, (uintptr_t)value, size, (unsigned int)flags, linux_syscall_name_fsetxattr);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_getxattr(char const* const pathname, char const* const name, void* const value, linux_size_t const size, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall4((uintptr_t)pathname, (uintptr_t)name, (uintptr_t)value, size, linux_syscall_name_getxattr);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_ssize_t)ret;
	return err;
}

inline linux_error_t linux_lgetxattr(char const* const pathname, char const* const name, void* const value, linux_size_t const size, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall4((uintptr_t)pathname, (uintptr_t)name, (uintptr_t)value, size, linux_syscall_name_lgetxattr);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_ssize_t)ret;
	return err;
}

inline linux_error_t linux_fgetxattr(linux_fd_t const fd, char const* const name, void* const value, linux_size_t const size, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall4((uint32_t)fd, (uintptr_t)name, (uintptr_t)value, size, linux_syscall_name_fgetxattr);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_ssize_t)ret;
	return err;
}

inline linux_error_t linux_listxattr(char const* const pathname, char* const list, linux_size_t const size, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)pathname, (uintptr_t)list, size, linux_syscall_name_listxattr);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_ssize_t)ret;
	return err;
}

inline linux_error_t linux_llistxattr(char const* const pathname, char* const list, linux_size_t const size, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)pathname, (uintptr_t)list, size, linux_syscall_name_llistxattr);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_ssize_t)ret;
	return err;
}

inline linux_error_t linux_flistxattr(linux_fd_t const fd, char* const list, linux_size_t const size, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall3((uint32_t)fd, (uintptr_t)list, size, linux_syscall_name_flistxattr);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_ssize_t)ret;
	return err;
}

inline linux_error_t linux_removexattr(char const* const pathname, char const* const name)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)pathname, (uintptr_t)name, linux_syscall_name_removexattr);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_lremovexattr(char const* const pathname, char const* const name)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)pathname, (uintptr_t)name, linux_syscall_name_lremovexattr);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_fremovexattr(linux_fd_t const fd, char const* const name)
{
	linux_word_t const ret = linux_syscall2((uint32_t)fd, (uintptr_t)name, linux_syscall_name_fremovexattr);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

#if defined(LINUX_ARCH_X86)
inline linux_error_t linux_setxattr_v(char const* const pathname, char const* const name, void const* const value, linux_size_t const size, int const flags)
{
	linux_word_t const ret = linux_syscall5_v((uintptr_t)pathname, (uintptr_t)name, (uintptr_t)value, size, (unsigned int)flags, linux_syscall_name_setxattr);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_lsetxattr_v(char const* const pathname, char const* const name, void const* const value, linux_size_t const size, int const flags)
{
	linux_word_t const ret = linux_syscall5_v((uintptr_t)pathname, (uintptr_t)name, (uintptr_t)value, size, (unsigned int)flags, linux_syscall_name_lsetxattr);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_fsetxattr_v(linux_fd_t const fd, char const* const name, void const* const value, linux_size_t const size, int const flags)
{
	linux_word_t const ret = linux_syscall5_v((uint32_t)fd, (uintptr_t)name, (uintptr_t)value, size, (unsigned int)flags, linux_syscall_name_fsetxattr);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_getxattr_v(char const* const pathname, char const* const name, void* const value, linux_size_t const size, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall4_v((uintptr_t)pathname, (uintptr_t)name, (uintptr_t)value, size, linux_syscall_name_getxattr);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_ssize_t)ret;
	return err;
}

inline linux_error_t linux_lgetxattr_v(char const* const pathname, char const* const name, void* const value, linux_size_t const size, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall4_v((uintptr_t)pathname, (uintptr_t)name, (uintptr_t)value, size, linux_syscall_name_lgetxattr);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_ssize_t)ret;
	return err;
}

inline linux_error_t linux_fgetxattr_v(linux_fd_t const fd, char const* const name, void* const value, linux_size_t const size, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall4_v((uint32_t)fd, (uintptr_t)name, (uintptr_t)value, size, linux_syscall_name_fgetxattr);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_ssize_t)ret;
	return err;
}

inline linux_error_t linux_listxattr_v(char const* const pathname, char* const list, linux_size_t const size, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall3_v((uintptr_t)pathname, (uintptr_t)list, size, linux_syscall_name_listxattr);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_ssize_t)ret;
	return err;
}

inline linux_error_t linux_llistxattr_v(char const* const pathname, char* const list, linux_size_t const size, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall3_v((uintptr_t)pathname, (uintptr_t)list, size, linux_syscall_name_llistxattr);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_ssize_t)ret;
	return err;
}

inline linux_error_t linux_flistxattr_v(linux_fd_t const fd, char* const list, linux_size_t const size, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall3_v((uint32_t)fd, (uintptr_t)list, size, linux_syscall_name_flistxattr);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_ssize_t)ret;
	return err;
}

inline linux_error_t linux_removexattr_v(char const* const pathname, char const* const name)
{
	linux_word_t const ret = linux_syscall2_v((uintptr_t)pathname, (uintptr_t)name, linux_syscall_name_removexattr);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_lremovexattr_v(char const* const pathname, char const* const name)
{
	linux_word_t const ret = linux_syscall2_v((uintptr_t)pathname, (uintptr_t)name, linux_syscall_name_lremovexattr);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_fremovexattr_v(linux_fd_t const fd, char const* const name)
{
	linux_word_t const ret = linux_syscall2_v((uint32_t)fd, (uintptr_t)name, linux_syscall_name_fremovexattr);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
#endif

//-----------------------------------------------------------------------------
// polling

inline linux_error_t linux_epoll_create1(uint32_t const flags, linux_fd_t* const result)
{
	linux_word_t const ret = linux_syscall1(flags, linux_syscall_name_epoll_create1);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}

inline linux_error_t linux_epoll_ctl(linux_fd_t const epfd, uint32_t const op, linux_fd_t const fd, struct linux_epoll_event const* const event)
{
	linux_word_t const ret = linux_syscall4((uint32_t)epfd, op, (uint32_t)fd, (uintptr_t)event, linux_syscall_name_epoll_ctl);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_epoll_pwait(linux_fd_t const epfd, struct linux_epoll_event* const events, uint32_t const maxevents, int32_t const timeout, linux_sigset_t const* const sigmask, linux_size_t const sigsetsize, uint32_t* const result) // DEPRECATED: use linux_epoll_pwait2
{
	linux_word_t const ret = linux_syscall6((uint32_t)epfd, (uintptr_t)events, maxevents, (uint32_t)timeout, (uintptr_t)sigmask, sigsetsize, linux_syscall_name_epoll_pwait);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (uint32_t)ret;
	return err;
}

inline linux_error_t linux_epoll_pwait2(linux_fd_t const epfd, struct linux_epoll_event* const events, uint32_t const maxevents, struct linux_timespec const* const timeout, linux_sigset_t const* const sigmask, linux_size_t const sigsetsize, uint32_t* const result)
{
	linux_word_t const ret = linux_syscall6((uint32_t)epfd, (uintptr_t)events, maxevents, (uintptr_t)timeout, (uintptr_t)sigmask, sigsetsize, linux_syscall_name_epoll_pwait2);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (uint32_t)ret;
	return err;
}

inline linux_error_t linux_pselect6(uint32_t const n, linux_fd_set* const inp, linux_fd_set* const outp, linux_fd_set* const exp, struct linux_timespec* const tsp, void* const sig, uint32_t* const result)
{
	linux_word_t const ret = linux_syscall6(n, (uintptr_t)inp, (uintptr_t)outp, (uintptr_t)exp, (uintptr_t)tsp, (uintptr_t)sig, linux_syscall_name_pselect6);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (uint32_t)ret;
	return err;
}

inline linux_error_t linux_ppoll(struct linux_pollfd* const ufds, uint32_t const nfds, struct linux_timespec* const tsp, linux_sigset_t const* const sigmask, linux_size_t const sigsetsize, uint32_t* const result)
{
	linux_word_t const ret = linux_syscall5((uintptr_t)ufds, nfds, (uintptr_t)tsp, (uintptr_t)sigmask, sigsetsize, linux_syscall_name_ppoll);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (uint32_t)ret;
	return err;
}

#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_X86) || defined(LINUX_ARCH_X32) || defined(LINUX_ARCH_X86_64)
inline linux_error_t linux_epoll_create(int32_t const size, linux_fd_t* const result) // DEPRECATED: use linux_epoll_create1
{
	linux_word_t const ret = linux_syscall1((uint32_t)size, linux_syscall_name_epoll_create);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}

inline linux_error_t linux_epoll_wait(linux_fd_t const epfd, struct linux_epoll_event* const events, uint32_t const maxevents, int32_t const timeout, uint32_t* const result) // DEPRECATED: use linux_epoll_pwait
{
	linux_word_t const ret = linux_syscall4((uint32_t)epfd, (uintptr_t)events, maxevents, (uint32_t)timeout, linux_syscall_name_epoll_wait);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (uint32_t)ret;
	return err;
}
#endif

#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_X86) || defined(LINUX_ARCH_X32) || defined(LINUX_ARCH_X86_64)
inline linux_error_t linux_select(uint32_t const n, linux_fd_set* const inp, linux_fd_set* const outp, linux_fd_set* const exp, struct linux_old_timeval* const tvp, uint32_t* const result) // DEPRECATED: use linux_pselect6
{
	linux_word_t const ret = linux_syscall5(n, (uintptr_t)inp, (uintptr_t)outp, (uintptr_t)exp, (uintptr_t)tvp, linux_syscall_name_select);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (uint32_t)ret;
	return err;
}

inline linux_error_t linux_poll(struct linux_pollfd* const ufds, uint32_t const nfds, int32_t const timeout_msecs, uint32_t* const result) // DEPRECATED: use linux_ppoll
{
	linux_word_t const ret = linux_syscall3((uintptr_t)ufds, nfds, (uint32_t)timeout_msecs, linux_syscall_name_poll);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (uint32_t)ret;
	return err;
}
#endif

#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_X86)
inline linux_error_t linux_pselect6_time32(uint32_t const n, linux_fd_set* const inp, linux_fd_set* const outp, linux_fd_set* const exp, struct linux_timespec32* const tsp, void* const sig, uint32_t* const result) // DEPRECATED: use linux_pselect6
{
	linux_word_t const ret = linux_syscall6(n, (uintptr_t)inp, (uintptr_t)outp, (uintptr_t)exp, (uintptr_t)tsp, (uintptr_t)sig, linux_syscall_name_pselect6_time32);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (uint32_t)ret;
	return err;
}

inline linux_error_t linux_ppoll_time32(struct linux_pollfd* const ufds, uint32_t const nfds, struct linux_timespec32* const tsp, linux_sigset_t const* const sigmask, linux_size_t const sigsetsize, uint32_t* const result) // DEPRECATED: use linux_ppoll
{
	linux_word_t const ret = linux_syscall5((uintptr_t)ufds, nfds, (uintptr_t)tsp, (uintptr_t)sigmask, sigsetsize, linux_syscall_name_ppoll_time32);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (uint32_t)ret;
	return err;
}
#endif

#if defined(LINUX_ARCH_X86)
inline linux_error_t linux_old_select(struct linux_sel_arg_struct* const arg, uint32_t* const result) // DEPRECATED: use linux_pselect6
{
	linux_word_t const ret = linux_syscall1((uintptr_t)arg, linux_syscall_name_old_select);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (uint32_t)ret;
	return err;
}
#endif

#if defined(LINUX_ARCH_X86)
inline linux_error_t linux_epoll_create1_v(uint32_t const flags, linux_fd_t* const result)
{
	linux_word_t const ret = linux_syscall1_v(flags, linux_syscall_name_epoll_create1);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}

inline linux_error_t linux_epoll_ctl_v(linux_fd_t const epfd, uint32_t const op, linux_fd_t const fd, struct linux_epoll_event const* const event)
{
	linux_word_t const ret = linux_syscall4_v((uint32_t)epfd, op, (uint32_t)fd, (uintptr_t)event, linux_syscall_name_epoll_ctl);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_epoll_pwait_v(linux_fd_t const epfd, struct linux_epoll_event* const events, uint32_t const maxevents, int32_t const timeout, linux_sigset_t const* const sigmask, linux_size_t const sigsetsize, uint32_t* const result)
{
	linux_word_t const ret = linux_syscall6_v((uint32_t)epfd, (uintptr_t)events, maxevents, (uint32_t)timeout, (uintptr_t)sigmask, sigsetsize, linux_syscall_name_epoll_pwait);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (uint32_t)ret;
	return err;
}

inline linux_error_t linux_pselect6_v(uint32_t const n, linux_fd_set* const inp, linux_fd_set* const outp, linux_fd_set* const exp, struct linux_timespec* const tsp, void* const sig, uint32_t* const result)
{
	linux_word_t const ret = linux_syscall6_v(n, (uintptr_t)inp, (uintptr_t)outp, (uintptr_t)exp, (uintptr_t)tsp, (uintptr_t)sig, linux_syscall_name_pselect6);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (uint32_t)ret;
	return err;
}

inline linux_error_t linux_ppoll_v(struct linux_pollfd* const ufds, uint32_t const nfds, struct linux_timespec* const tsp, linux_sigset_t const* const sigmask, linux_size_t const sigsetsize, uint32_t* const result)
{
	linux_word_t const ret = linux_syscall5_v((uintptr_t)ufds, nfds, (uintptr_t)tsp, (uintptr_t)sigmask, sigsetsize, linux_syscall_name_ppoll);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (uint32_t)ret;
	return err;
}

inline linux_error_t linux_epoll_create_v(int32_t const size, linux_fd_t* const result) // DEPRECATED: use linux_epoll_create1_v
{
	linux_word_t const ret = linux_syscall1_v((uint32_t)size, linux_syscall_name_epoll_create);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}

inline linux_error_t linux_epoll_wait_v(linux_fd_t const epfd, struct linux_epoll_event* const events, uint32_t const maxevents, int32_t const timeout, uint32_t* const result) // DEPRECATED: use linux_epoll_pwait_v
{
	linux_word_t const ret = linux_syscall4_v((uint32_t)epfd, (uintptr_t)events, maxevents, (uint32_t)timeout, linux_syscall_name_epoll_wait);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (uint32_t)ret;
	return err;
}

inline linux_error_t linux_select_v(uint32_t const n, linux_fd_set* const inp, linux_fd_set* const outp, linux_fd_set* const exp, struct linux_old_timeval* const tvp, uint32_t* const result) // DEPRECATED: use linux_pselect6_v
{
	linux_word_t const ret = linux_syscall5_v(n, (uintptr_t)inp, (uintptr_t)outp, (uintptr_t)exp, (uintptr_t)tvp, linux_syscall_name_select);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (uint32_t)ret;
	return err;
}

inline linux_error_t linux_poll_v(struct linux_pollfd* const ufds, uint32_t const nfds, int32_t const timeout_msecs, uint32_t* const result) // DEPRECATED: use linux_ppoll_v
{
	linux_word_t const ret = linux_syscall3_v((uintptr_t)ufds, nfds, (uint32_t)timeout_msecs, linux_syscall_name_poll);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (uint32_t)ret;
	return err;
}

inline linux_error_t linux_pselect6_time32_v(uint32_t const n, linux_fd_set* const inp, linux_fd_set* const outp, linux_fd_set* const exp, struct linux_timespec32* const tsp, void* const sig, uint32_t* const result) // DEPRECATED: use linux_pselect6_v
{
	linux_word_t const ret = linux_syscall6_v(n, (uintptr_t)inp, (uintptr_t)outp, (uintptr_t)exp, (uintptr_t)tsp, (uintptr_t)sig, linux_syscall_name_pselect6_time32);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (uint32_t)ret;
	return err;
}

inline linux_error_t linux_ppoll_time32_v(struct linux_pollfd* const ufds, uint32_t const nfds, struct linux_timespec32* const tsp, linux_sigset_t const* const sigmask, linux_size_t const sigsetsize, uint32_t* const result) // DEPRECATED: use linux_ppoll_v
{
	linux_word_t const ret = linux_syscall5_v((uintptr_t)ufds, nfds, (uintptr_t)tsp, (uintptr_t)sigmask, sigsetsize, linux_syscall_name_ppoll_time32);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (uint32_t)ret;
	return err;
}

inline linux_error_t linux_old_select_v(struct linux_sel_arg_struct* const arg, uint32_t* const result) // DEPRECATED: use linux_pselect6_v
{
	linux_word_t const ret = linux_syscall1_v((uintptr_t)arg, linux_syscall_name_old_select);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (uint32_t)ret;
	return err;
}
#endif

//-----------------------------------------------------------------------------
// file decriptors

inline linux_error_t linux_dup(unsigned int const fildes, int* const result)
{
	linux_word_t const ret = linux_syscall1(fildes, linux_syscall_name_dup);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_dup3(linux_fd_t const oldfd, linux_fd_t const newfd, int const flags, linux_fd_t* const result)
{
	linux_word_t const ret = linux_syscall3((uint32_t)oldfd, (uint32_t)newfd, (unsigned int)flags, linux_syscall_name_dup3);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}
inline linux_error_t linux_ioctl(linux_fd_t const fd, unsigned int const cmd, linux_uword_t const arg, int* const result)
{
	linux_word_t const ret = linux_syscall3((uint32_t)fd, cmd, arg, linux_syscall_name_ioctl);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_flock(linux_fd_t const fd, unsigned int const cmd)
{
	linux_word_t const ret = linux_syscall2((uint32_t)fd, cmd, linux_syscall_name_flock);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_close(linux_fd_t const fd)
{
	linux_word_t const ret = linux_syscall1((uint32_t)fd, linux_syscall_name_close);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_close_range(linux_fd_t const fd, linux_fd_t const max_fd, unsigned int const flags)
{
	linux_word_t const ret = linux_syscall3((uint32_t)fd, (uint32_t)max_fd, flags, linux_syscall_name_close_range);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

//-----------------------------------------------------------------------------
// inotify

inline linux_error_t linux_inotify_init1(int const flags, linux_fd_t* const result)
{
	linux_word_t const ret = linux_syscall1((unsigned int)flags, linux_syscall_name_inotify_init1);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}
inline linux_error_t linux_inotify_add_watch(linux_fd_t const fd, char const* const pathname, uint32_t const mask, linux_wd_t* const result)
{
	linux_word_t const ret = linux_syscall3((uint32_t)fd, (uintptr_t)pathname, mask, linux_syscall_name_inotify_add_watch);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_wd_t)ret;
	return err;
}
inline linux_error_t linux_inotify_rm_watch(linux_fd_t const fd, linux_wd_t const wd)
{
	linux_word_t const ret = linux_syscall2((uint32_t)fd, (uint32_t)wd, linux_syscall_name_inotify_rm_watch);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

//-----------------------------------------------------------------------------
// filesystem

inline linux_error_t linux_mknodat(linux_fd_t const dfd, char const* const filename, linux_umode_t const mode, unsigned int const dev)
{
	linux_word_t const ret = linux_syscall4((uint32_t)dfd, (uintptr_t)filename, mode, dev, linux_syscall_name_mknodat);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_mkdirat(linux_fd_t const dfd, char const* const pathname, linux_umode_t const mode)
{
	linux_word_t const ret = linux_syscall3((uint32_t)dfd, (uintptr_t)pathname, mode, linux_syscall_name_mkdirat);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_unlinkat(linux_fd_t const dfd, char const* const pathname, int const flag)
{
	linux_word_t const ret = linux_syscall3((uint32_t)dfd, (uintptr_t)pathname, (unsigned int)flag, linux_syscall_name_unlinkat);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_symlinkat(char const* const oldname, linux_fd_t const newdfd, char const* const newname)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)oldname, (uint32_t)newdfd, (uintptr_t)newname, linux_syscall_name_symlinkat);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_linkat(linux_fd_t const olddfd, char const* const oldname, linux_fd_t const newdfd, char const* const newname, int const flags)
{
	linux_word_t const ret = linux_syscall5((uint32_t)olddfd, (uintptr_t)oldname, (uint32_t)newdfd, (uintptr_t)newname, (unsigned int)flags, linux_syscall_name_linkat);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_renameat2(linux_fd_t const olddfd, char const* const oldname, linux_fd_t const newdfd, char const* const newname, unsigned int const flags)
{
	linux_word_t const ret = linux_syscall5((uint32_t)olddfd, (uintptr_t)oldname, (uint32_t)newdfd, (uintptr_t)newname, flags, linux_syscall_name_renameat2);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_getdents64(linux_fd_t const fd, struct linux_dirent64* const dirent, unsigned int const count, int* const result)
{
	linux_word_t const ret = linux_syscall3((uint32_t)fd, (uintptr_t)dirent, count, linux_syscall_name_getdents64);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_readlinkat(linux_fd_t const dfd, char const* const pathname, char* const buf, int const bufsiz, int* const result)
{
	linux_word_t const ret = linux_syscall4((uint32_t)dfd, (uintptr_t)pathname, (uintptr_t)buf, (unsigned int)bufsiz, linux_syscall_name_readlinkat);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}

//-----------------------------------------------------------------------------
// regular files

inline linux_error_t linux_fallocate(linux_fd_t const fd, int const mode, linux_loff_t const offset, linux_loff_t const len)
{
#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_RISCV32) || defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall6((uint32_t)fd, (unsigned int)mode, LINUX_EXPAND(offset), LINUX_EXPAND(len), linux_syscall_name_fallocate);
#else
	linux_word_t const ret = linux_syscall4((uint32_t)fd, (unsigned int)mode, (uint64_t)offset, (uint64_t)len, linux_syscall_name_fallocate);
#endif
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_faccessat(linux_fd_t const dfd, char const* const filename, int const mode) // DEPRECATED: use linux_faccessat2
{
	linux_word_t const ret = linux_syscall3((uint32_t)dfd, (uintptr_t)filename, (unsigned int)mode, linux_syscall_name_faccessat);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_faccessat2(linux_fd_t const dfd, char const* const filename, int const mode, int const flags)
{
	linux_word_t const ret = linux_syscall4((uint32_t)dfd, (uintptr_t)filename, (unsigned int)mode, (unsigned int)flags, linux_syscall_name_faccessat2);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_fchmod(linux_fd_t const fd, linux_umode_t const mode) // DEPRECATED: use linux_fchmodat
{
	linux_word_t const ret = linux_syscall2((uint32_t)fd, mode, linux_syscall_name_fchmod);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_fchmodat(linux_fd_t const dfd, char const* const filename, linux_umode_t const mode)
{
	linux_word_t const ret = linux_syscall3((uint32_t)dfd, (uintptr_t)filename, mode, linux_syscall_name_fchmodat);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_fchownat(linux_fd_t const dfd, char const* const filename, linux_uid_t const user, linux_gid_t const group, int const flag)
{
	linux_word_t const ret = linux_syscall5((uint32_t)dfd, (uintptr_t)filename, user, group, (unsigned int)flag, linux_syscall_name_fchownat);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_fchown(linux_fd_t const fd, linux_uid_t const user, linux_gid_t const group) // DEPRECATED: use linux_fchownat
{
	linux_word_t const ret = linux_syscall3((uint32_t)fd, user, group, linux_syscall_name_fchown);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_openat(linux_fd_t const dfd, char const* const filename, int const flags, linux_umode_t const mode, linux_fd_t* const result) // DEPRECATED: use linux_openat2
{
	linux_word_t const ret = linux_syscall4((uint32_t)dfd, (uintptr_t)filename, (unsigned int)flags, mode, linux_syscall_name_openat);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}
inline linux_error_t linux_openat2(linux_fd_t const dfd, char const* const filename, struct linux_open_how* const how, linux_size_t const usize, linux_fd_t* const result)
{
	linux_word_t const ret = linux_syscall4((uint32_t)dfd, (uintptr_t)filename, (uintptr_t)how, usize, linux_syscall_name_openat2);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}
inline linux_error_t linux_name_to_handle_at(linux_fd_t const dfd, char const* const name, struct linux_file_handle* const handle, int* const mnt_id, int const flag)
{
	linux_word_t const ret = linux_syscall5((uint32_t)dfd, (uintptr_t)name, (uintptr_t)handle, (uintptr_t)mnt_id, (unsigned int)flag, linux_syscall_name_name_to_handle_at);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_open_by_handle_at(int const mountdirfd, struct linux_file_handle* const handle, int const flags, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)mountdirfd, (uintptr_t)handle, (unsigned int)flags, linux_syscall_name_open_by_handle_at);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_statx(linux_fd_t const dfd, char const* const filename, unsigned int const flags, unsigned int const mask, struct linux_statx* const buffer)
{
	linux_word_t const ret = linux_syscall5((uint32_t)dfd, (uintptr_t)filename, flags, mask, (uintptr_t)buffer, linux_syscall_name_statx);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

//-----------------------------------------------------------------------------
// read/write

inline linux_error_t linux_read(linux_fd_t const fd, void* const buf, linux_size_t const count, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall3((uint32_t)fd, (uintptr_t)buf, count, linux_syscall_name_read);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_ssize_t)ret;
	return err;
}
inline linux_error_t linux_write(linux_fd_t const fd, void const* const buf, linux_size_t const count, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall3((uint32_t)fd, (uintptr_t)buf, count, linux_syscall_name_write);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_ssize_t)ret;
	return err;
}
inline linux_error_t linux_readv(linux_uword_t const fd, struct linux_iovec const* const vec, linux_uword_t const vlen, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall3(fd, (uintptr_t)vec, vlen, linux_syscall_name_readv);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_ssize_t)ret;
	return err;
}
inline linux_error_t linux_writev(linux_uword_t const fd, struct linux_iovec const* const vec, linux_uword_t const vlen, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall3(fd, (uintptr_t)vec, vlen, linux_syscall_name_writev);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_ssize_t)ret;
	return err;
}
inline linux_error_t linux_pread64(linux_fd_t const fd, char* const buf, linux_size_t const count, linux_loff_t const pos, linux_ssize_t* const result)
{
#if defined(LINUX_ARCH_ARM_EABI)
	linux_word_t const ret = linux_syscall6((uint32_t)fd, (uintptr_t)buf, count, 0, LINUX_EXPAND(pos), linux_syscall_name_pread64);
#elif defined(LINUX_ARCH_RISCV32) || defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall5((uint32_t)fd, (uintptr_t)buf, count, LINUX_EXPAND(pos), linux_syscall_name_pread64);
#else
	linux_word_t const ret = linux_syscall4((uint32_t)fd, (uintptr_t)buf, count, (uint64_t)pos, linux_syscall_name_pread64);
#endif
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_ssize_t)ret;
	return err;
}
inline linux_error_t linux_pwrite64(linux_fd_t const fd, char const* const buf, linux_size_t const count, linux_loff_t const pos, linux_ssize_t* const result)
{
#if defined(LINUX_ARCH_ARM_EABI)
	linux_word_t const ret = linux_syscall6((uint32_t)fd, (uintptr_t)buf, count, 0, LINUX_EXPAND(pos), linux_syscall_name_pwrite64);
#elif defined(LINUX_ARCH_RISCV32) || defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall5((uint32_t)fd, (uintptr_t)buf, count, LINUX_EXPAND(pos), linux_syscall_name_pwrite64);
#else
	linux_word_t const ret = linux_syscall4((uint32_t)fd, (uintptr_t)buf, count, (uint64_t)pos, linux_syscall_name_pwrite64);
#endif
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_ssize_t)ret;
	return err;
}
inline linux_error_t linux_preadv(linux_uword_t const fd, struct linux_iovec const* const vec, linux_uword_t const vlen, linux_uword_t const pos_l, linux_uword_t const pos_h, linux_ssize_t* const result) // DEPRECATED: use linux_preadv2
{
	linux_word_t const ret = linux_syscall5(fd, (uintptr_t)vec, vlen, pos_l, pos_h, linux_syscall_name_preadv);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_ssize_t)ret;
	return err;
}
inline linux_error_t linux_pwritev(linux_uword_t const fd, struct linux_iovec const* const vec, linux_uword_t const vlen, linux_uword_t const pos_l, linux_uword_t const pos_h, linux_ssize_t* const result) // DEPRECATED: use linux_pwritev2
{
	linux_word_t const ret = linux_syscall5(fd, (uintptr_t)vec, vlen, pos_l, pos_h, linux_syscall_name_pwritev);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_ssize_t)ret;
	return err;
}
inline linux_error_t linux_sendfile64(linux_fd_t const out_fd, linux_fd_t const in_fd, linux_loff_t* const offset, linux_size_t const count, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall4((uint32_t)out_fd, (uint32_t)in_fd, (uintptr_t)offset, count, linux_syscall_name_sendfile64);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_ssize_t)ret;
	return err;
}
inline linux_error_t linux_vmsplice(linux_fd_t const fd, struct linux_iovec const* const uiov, linux_uword_t const nr_segs, unsigned int const flags, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall4((uint32_t)fd, (uintptr_t)uiov, nr_segs, flags, linux_syscall_name_vmsplice);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_splice(linux_fd_t const fd_in, linux_loff_t* const off_in, linux_fd_t const fd_out, linux_loff_t* const off_out, linux_size_t const len, unsigned int const flags, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall6((uint32_t)fd_in, (uintptr_t)off_in, (uint32_t)fd_out, (uintptr_t)off_out, len, flags, linux_syscall_name_splice);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_tee(linux_fd_t const fdin, linux_fd_t const fdout, linux_size_t const len, unsigned int const flags, int* const result)
{
	linux_word_t const ret = linux_syscall4((uint32_t)fdin, (uint32_t)fdout, len, flags, linux_syscall_name_tee);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_readahead(linux_fd_t const fd, linux_loff_t const offset, linux_size_t const count)
{
#if defined(LINUX_ARCH_ARM_EABI)
	linux_word_t const ret = linux_syscall5((uint32_t)fd, 0, LINUX_EXPAND(offset), count, linux_syscall_name_readahead);
#elif defined(LINUX_ARCH_RISCV32) || defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall4((uint32_t)fd, LINUX_EXPAND(offset), count, linux_syscall_name_readahead);
#else
	linux_word_t const ret = linux_syscall3((uint32_t)fd, (uint64_t)offset, count, linux_syscall_name_readahead);
#endif
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_process_vm_readv(linux_pid_t const pid, struct linux_iovec const* const lvec, linux_uword_t const liovcnt, struct linux_iovec const* const rvec, linux_uword_t const riovcnt, linux_uword_t const flags, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall6((uint32_t)pid, (uintptr_t)lvec, liovcnt, (uintptr_t)rvec, riovcnt, flags, linux_syscall_name_process_vm_readv);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_ssize_t)ret;
	return err;
}
inline linux_error_t linux_process_vm_writev(linux_pid_t const pid, struct linux_iovec const* const lvec, linux_uword_t const liovcnt, struct linux_iovec const* const rvec, linux_uword_t const riovcnt, linux_uword_t const flags, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall6((uint32_t)pid, (uintptr_t)lvec, liovcnt, (uintptr_t)rvec, riovcnt, flags, linux_syscall_name_process_vm_writev);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_ssize_t)ret;
	return err;
}
inline linux_error_t linux_copy_file_range(linux_fd_t const fd_in, linux_loff_t* const off_in, linux_fd_t const fd_out, linux_loff_t* const off_out, linux_size_t const len, unsigned int const flags, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall6((uint32_t)fd_in, (uintptr_t)off_in, (uint32_t)fd_out, (uintptr_t)off_out, len, flags, linux_syscall_name_copy_file_range);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_ssize_t)ret;
	return err;
}
inline linux_error_t linux_preadv2(linux_uword_t const fd, struct linux_iovec const* const vec, linux_uword_t const vlen, linux_uword_t const pos_l, linux_uword_t const pos_h, linux_rwf_t const flags, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall6(fd, (uintptr_t)vec, vlen, pos_l, pos_h, (uint32_t)flags, linux_syscall_name_preadv2);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_ssize_t)ret;
	return err;
}
inline linux_error_t linux_pwritev2(linux_uword_t const fd, struct linux_iovec const* const vec, linux_uword_t const vlen, linux_uword_t const pos_l, linux_uword_t const pos_h, linux_rwf_t const flags, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall6(fd, (uintptr_t)vec, vlen, pos_l, pos_h, (uint32_t)flags, linux_syscall_name_pwritev2);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_ssize_t)ret;
	return err;
}

//-----------------------------------------------------------------------------
// timerfd

inline linux_error_t linux_timerfd_create(int const clockid, int const flags, linux_fd_t* const result)
{
	linux_word_t const ret = linux_syscall2((unsigned int)clockid, (unsigned int)flags, linux_syscall_name_timerfd_create);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}
inline linux_error_t linux_timerfd_settime(linux_fd_t const ufd, int const flags, struct linux_itimerspec const* const utmr, struct linux_itimerspec* const otmr)
{
	linux_word_t const ret = linux_syscall4((uint32_t)ufd, (unsigned int)flags, (uintptr_t)utmr, (uintptr_t)otmr, linux_syscall_name_timerfd_settime);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_timerfd_gettime(linux_fd_t const ufd, struct linux_itimerspec* const otmr)
{
	linux_word_t const ret = linux_syscall2((uint32_t)ufd, (uintptr_t)otmr, linux_syscall_name_timerfd_gettime);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

//-----------------------------------------------------------------------------
// capabilities

inline linux_error_t linux_capget(linux_cap_user_header_t const header, struct linux_user_cap_data_struct* const dataptr)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)header, (uintptr_t)dataptr, linux_syscall_name_capget);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_capset(linux_cap_user_header_t const header, struct linux_user_cap_data_struct const* const data)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)header, (uintptr_t)data, linux_syscall_name_capset);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

//-----------------------------------------------------------------------------
// futexes

inline linux_error_t linux_futex(uint32_t* const uaddr, int const op, uint32_t const val, struct linux_timespec* const utime, uint32_t* const uaddr2, uint32_t const val3, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall6((uintptr_t)uaddr, (unsigned int)op, val, (uintptr_t)utime, (uintptr_t)uaddr2, val3, linux_syscall_name_futex);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_set_robust_list(struct linux_robust_list_head* const head, linux_size_t const len)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)head, len, linux_syscall_name_set_robust_list);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_get_robust_list(int const pid, struct linux_robust_list_head** const head_ptr, linux_size_t* const len_ptr)
{
	linux_word_t const ret = linux_syscall3((unsigned int)pid, (uintptr_t)head_ptr, (uintptr_t)len_ptr, linux_syscall_name_get_robust_list);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

//-----------------------------------------------------------------------------
// interval timer

inline linux_error_t linux_getitimer(int const which, struct linux_old_itimerval* const value)
{
	linux_word_t const ret = linux_syscall2((unsigned int)which, (uintptr_t)value, linux_syscall_name_getitimer);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_setitimer(int const which, struct linux_old_itimerval const* const value, struct linux_old_itimerval* const ovalue)
{
	linux_word_t const ret = linux_syscall3((unsigned int)which, (uintptr_t)value, (uintptr_t)ovalue, linux_syscall_name_setitimer);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

//-----------------------------------------------------------------------------
// kernel

inline linux_error_t linux_kexec_load(linux_uword_t const entry, linux_uword_t const nr_segments, struct linux_kexec_segment* const segments, linux_uword_t const flags)
{
	linux_word_t const ret = linux_syscall4(entry, nr_segments, (uintptr_t)segments, flags, linux_syscall_name_kexec_load);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_init_module(void* const umod, linux_uword_t const len, char const* const uargs)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)umod, len, (uintptr_t)uargs, linux_syscall_name_init_module);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_delete_module(char const* const name_user, unsigned int const flags)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)name_user, flags, linux_syscall_name_delete_module);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_reboot(int const magic1, int const magic2, unsigned int const cmd, void* const arg)
{
	linux_word_t const ret = linux_syscall4((unsigned int)magic1, (unsigned int)magic2, cmd, (uintptr_t)arg, linux_syscall_name_reboot);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_finit_module(linux_fd_t const fd, char const* const uargs, int const flags)
{
	linux_word_t const ret = linux_syscall3((uint32_t)fd, (uintptr_t)uargs, (unsigned int)flags, linux_syscall_name_finit_module);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

//-----------------------------------------------------------------------------
// timer

inline linux_error_t linux_timer_create(linux_clockid_t const which_clock, struct linux_sigevent* const timer_event_spec, linux_timer_t* const created_timer_id)
{
	linux_word_t const ret = linux_syscall3((unsigned int)which_clock, (uintptr_t)timer_event_spec, (uintptr_t)created_timer_id, linux_syscall_name_timer_create);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_timer_gettime(linux_timer_t const timer_id, struct linux_itimerspec* const setting)
{
	linux_word_t const ret = linux_syscall2((unsigned int)timer_id, (uintptr_t)setting, linux_syscall_name_timer_gettime);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_timer_getoverrun(linux_timer_t const timer_id, int* const result)
{
	linux_word_t const ret = linux_syscall1((unsigned int)timer_id, linux_syscall_name_timer_getoverrun);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_timer_settime(linux_timer_t const timer_id, int const flags, struct linux_itimerspec const* const new_setting, struct linux_itimerspec* const old_setting)
{
	linux_word_t const ret = linux_syscall4((unsigned int)timer_id, (unsigned int)flags, (uintptr_t)new_setting, (uintptr_t)old_setting, linux_syscall_name_timer_settime);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_timer_delete(linux_timer_t const timer_id)
{
	linux_word_t const ret = linux_syscall1((unsigned int)timer_id, linux_syscall_name_timer_delete);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

//-----------------------------------------------------------------------------
// clock

inline linux_error_t linux_clock_settime(linux_clockid_t const which_clock, struct linux_timespec const* const tp)
{
	linux_word_t const ret = linux_syscall2((unsigned int)which_clock, (uintptr_t)tp, linux_syscall_name_clock_settime);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_clock_gettime(linux_clockid_t const which_clock, struct linux_timespec* const tp)
{
	linux_word_t const ret = linux_syscall2((unsigned int)which_clock, (uintptr_t)tp, linux_syscall_name_clock_gettime);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_clock_getres(linux_clockid_t const which_clock, struct linux_timespec* const tp)
{
	linux_word_t const ret = linux_syscall2((unsigned int)which_clock, (uintptr_t)tp, linux_syscall_name_clock_getres);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_clock_nanosleep(linux_clockid_t const which_clock, int const flags, struct linux_timespec const* const rqtp, struct linux_timespec* const rmtp)
{
	linux_word_t const ret = linux_syscall4((unsigned int)which_clock, (unsigned int)flags, (uintptr_t)rqtp, (uintptr_t)rmtp, linux_syscall_name_clock_nanosleep);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_clock_adjtime(linux_clockid_t const which_clock, struct linux_timex* const ktx, int* const result)
{
	linux_word_t const ret = linux_syscall2((unsigned int)which_clock, (uintptr_t)ktx, linux_syscall_name_clock_adjtime);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}

//-----------------------------------------------------------------------------
// scheduler

inline linux_error_t linux_ioprio_set(int const which, int const who, int const ioprio)
{
	linux_word_t const ret = linux_syscall3((unsigned int)which, (unsigned int)who, (unsigned int)ioprio, linux_syscall_name_ioprio_set);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_ioprio_get(int const which, int const who, int* const result)
{
	linux_word_t const ret = linux_syscall2((unsigned int)which, (unsigned int)who, linux_syscall_name_ioprio_get);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_sched_setparam(linux_pid_t const pid, struct linux_sched_param* const param)
{
	linux_word_t const ret = linux_syscall2((uint32_t)pid, (uintptr_t)param, linux_syscall_name_sched_setparam);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_sched_setscheduler(linux_pid_t const pid, int const policy, struct linux_sched_param* const param)
{
	linux_word_t const ret = linux_syscall3((uint32_t)pid, (unsigned int)policy, (uintptr_t)param, linux_syscall_name_sched_setscheduler);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_sched_getscheduler(linux_pid_t const pid, int* const result)
{
	linux_word_t const ret = linux_syscall1((uint32_t)pid, linux_syscall_name_sched_getscheduler);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_sched_getparam(linux_pid_t const pid, struct linux_sched_param* const param)
{
	linux_word_t const ret = linux_syscall2((uint32_t)pid, (uintptr_t)param, linux_syscall_name_sched_getparam);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_sched_setaffinity(linux_pid_t const pid, unsigned int const len, linux_uword_t* const user_mask_ptr)
{
	linux_word_t const ret = linux_syscall3((uint32_t)pid, len, (uintptr_t)user_mask_ptr, linux_syscall_name_sched_setaffinity);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_sched_getaffinity(linux_pid_t const pid, unsigned int const len, linux_uword_t* const user_mask_ptr)
{
	linux_word_t const ret = linux_syscall3((uint32_t)pid, len, (uintptr_t)user_mask_ptr, linux_syscall_name_sched_getaffinity);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_sched_yield(void)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_sched_yield);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_sched_get_priority_max(int const policy, int* const result)
{
	linux_word_t const ret = linux_syscall1((unsigned int)policy, linux_syscall_name_sched_get_priority_max);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_sched_get_priority_min(int const policy, int* const result)
{
	linux_word_t const ret = linux_syscall1((unsigned int)policy, linux_syscall_name_sched_get_priority_min);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_sched_rr_get_interval(linux_pid_t const pid, struct linux_timespec* const interval)
{
	linux_word_t const ret = linux_syscall2((uint32_t)pid, (uintptr_t)interval, linux_syscall_name_sched_rr_get_interval);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_setpriority(int const which, int const who, int const niceval)
{
	linux_word_t const ret = linux_syscall3((unsigned int)which, (unsigned int)who, (unsigned int)niceval, linux_syscall_name_setpriority);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_getpriority(int const which, int const who, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall2((unsigned int)which, (unsigned int)who, linux_syscall_name_getpriority);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_sched_setattr(linux_pid_t const pid, struct linux_sched_attr* const uattr, unsigned int const flags)
{
	linux_word_t const ret = linux_syscall3((uint32_t)pid, (uintptr_t)uattr, flags, linux_syscall_name_sched_setattr);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_sched_getattr(linux_pid_t const pid, struct linux_sched_attr* const uattr, unsigned int const size, unsigned int const flags)
{
	linux_word_t const ret = linux_syscall4((uint32_t)pid, (uintptr_t)uattr, size, flags, linux_syscall_name_sched_getattr);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

//-----------------------------------------------------------------------------
// signals

inline linux_error_t linux_signalfd4(linux_fd_t const ufd, linux_sigset_t* const user_mask, linux_size_t const sizemask, uint32_t const flags, linux_fd_t* const result)
{
	linux_word_t const ret = linux_syscall4((uint32_t)ufd, (uintptr_t)user_mask, sizemask, flags, linux_syscall_name_signalfd4);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}

inline linux_error_t linux_kill(linux_pid_t const pid, uint32_t const sig)
{
	linux_word_t const ret = linux_syscall2((uint32_t)pid, sig, linux_syscall_name_kill);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_tkill(linux_pid_t const pid, uint32_t const sig) // DEPRECATED: use linux_tgkill
{
	linux_word_t const ret = linux_syscall2((uint32_t)pid, sig, linux_syscall_name_tkill);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_tgkill(linux_pid_t const tgid, linux_pid_t const pid, uint32_t const sig)
{
	linux_word_t const ret = linux_syscall3((uint32_t)tgid, (uint32_t)pid, sig, linux_syscall_name_tgkill);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_sigaltstack(linux_stack_t const* const uss, linux_stack_t* const uoss)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)uss, (uintptr_t)uoss, linux_syscall_name_sigaltstack);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_rt_sigsuspend(linux_sigset_t* const unewset, linux_size_t const sigsetsize)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)unewset, sigsetsize, linux_syscall_name_rt_sigsuspend);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_rt_sigaction(uint32_t const sig, struct linux_sigaction const* const act, struct linux_sigaction* const oact, linux_size_t const sigsetsize)
{
	linux_word_t const ret = linux_syscall4(sig, (uintptr_t)act, (uintptr_t)oact, sigsetsize, linux_syscall_name_rt_sigaction);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_rt_sigprocmask(uint32_t const how, linux_sigset_t* const nset, linux_sigset_t* const oset, linux_size_t const sigsetsize)
{
	linux_word_t const ret = linux_syscall4(how, (uintptr_t)nset, (uintptr_t)oset, sigsetsize, linux_syscall_name_rt_sigprocmask);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_rt_sigpending(linux_sigset_t* const uset, linux_size_t const sigsetsize)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)uset, sigsetsize, linux_syscall_name_rt_sigpending);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_rt_sigtimedwait(linux_sigset_t const* const uthese, linux_siginfo_t* const uinfo, struct linux_timespec const* const uts, linux_size_t const sigsetsize, uint32_t* const result)
{
	linux_word_t const ret = linux_syscall4((uintptr_t)uthese, (uintptr_t)uinfo, (uintptr_t)uts, sigsetsize, linux_syscall_name_rt_sigtimedwait);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (uint32_t)ret;
	return err;
}

inline linux_error_t linux_rt_sigqueueinfo(linux_pid_t const pid, uint32_t const sig, linux_siginfo_t* const uinfo) // DEPRECATED: use linux_rt_tgsigqueueinfo
{
	linux_word_t const ret = linux_syscall3((uint32_t)pid, sig, (uintptr_t)uinfo, linux_syscall_name_rt_sigqueueinfo);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_rt_tgsigqueueinfo(linux_pid_t const tgid, linux_pid_t const pid, uint32_t const sig, linux_siginfo_t* const uinfo)
{
	linux_word_t const ret = linux_syscall4((uint32_t)tgid, (uint32_t)pid, sig, (uintptr_t)uinfo, linux_syscall_name_rt_tgsigqueueinfo);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_X86) || defined(LINUX_ARCH_X32) || defined(LINUX_ARCH_X86_64)
inline linux_error_t linux_signalfd(linux_fd_t const ufd, linux_sigset_t* const user_mask, linux_size_t const sizemask, linux_fd_t* const result) // DEPRECATED: use linux_signalfd4
{
	linux_word_t const ret = linux_syscall3((uint32_t)ufd, (uintptr_t)user_mask, sizemask, linux_syscall_name_signalfd);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}
#endif

#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_X86)
inline linux_error_t linux_rt_sigtimedwait_time32(linux_sigset_t const* const uthese, linux_siginfo_t* const uinfo, struct linux_timespec32 const* const uts, linux_size_t const sigsetsize, uint32_t* const result)
{
	linux_word_t const ret = linux_syscall4((uintptr_t)uthese, (uintptr_t)uinfo, (uintptr_t)uts, sigsetsize, linux_syscall_name_rt_sigtimedwait_time32);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (uint32_t)ret;
	return err;
}

inline linux_error_t linux_sigaction(uint32_t const sig, struct linux_old_sigaction const* const act, struct linux_old_sigaction* const oact)
{
	linux_word_t const ret = linux_syscall3(sig, (uintptr_t)act, (uintptr_t)oact, linux_syscall_name_sigaction);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_sigsuspend(int32_t const unused1, int32_t const unused2, linux_old_sigset_t const mask)
{
	linux_word_t const ret = linux_syscall3((uint32_t)unused1, (uint32_t)unused2, mask, linux_syscall_name_sigsuspend);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_sigpending(linux_old_sigset_t* const uset)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)uset, linux_syscall_name_sigpending);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_sigprocmask(uint32_t const how, linux_old_sigset_t* const nset, linux_old_sigset_t* const oset)
{
	linux_word_t const ret = linux_syscall3(how, (uintptr_t)nset, (uintptr_t)oset, linux_syscall_name_sigprocmask);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
#endif

#if defined(LINUX_ARCH_X86)
inline linux_error_t linux_signal(uint32_t const sig, linux_sighandler_t const handler, linux_uword_t* const result)
{
	linux_word_t const ret = linux_syscall2(sig, (uintptr_t)handler, linux_syscall_name_signal);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_uword_t)ret;
	return err;
}
#endif

#if defined(LINUX_ARCH_X86)
inline linux_error_t linux_signalfd4_v(linux_fd_t const ufd, linux_sigset_t* const user_mask, linux_size_t const sizemask, uint32_t const flags, linux_fd_t* const result)
{
	linux_word_t const ret = linux_syscall4_v((uint32_t)ufd, (uintptr_t)user_mask, sizemask, flags, linux_syscall_name_signalfd4);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}

inline linux_error_t linux_kill_v(linux_pid_t const pid, uint32_t const sig)
{
	linux_word_t const ret = linux_syscall2_v((uint32_t)pid, sig, linux_syscall_name_kill);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_tkill_v(linux_pid_t const pid, uint32_t const sig) // DEPRECATED: use linux_tgkill_v
{
	linux_word_t const ret = linux_syscall2_v((uint32_t)pid, sig, linux_syscall_name_tkill);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_tgkill_v(linux_pid_t const tgid, linux_pid_t const pid, uint32_t const sig)
{
	linux_word_t const ret = linux_syscall3_v((uint32_t)tgid, (uint32_t)pid, sig, linux_syscall_name_tgkill);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_sigaltstack_v(linux_stack_t const* const uss, linux_stack_t* const uoss)
{
	linux_word_t const ret = linux_syscall2_v((uintptr_t)uss, (uintptr_t)uoss, linux_syscall_name_sigaltstack);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_rt_sigsuspend_v(linux_sigset_t* const unewset, linux_size_t const sigsetsize)
{
	linux_word_t const ret = linux_syscall2_v((uintptr_t)unewset, sigsetsize, linux_syscall_name_rt_sigsuspend);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_rt_sigaction_v(uint32_t const sig, struct linux_sigaction const* const act, struct linux_sigaction* const oact, linux_size_t const sigsetsize)
{
	linux_word_t const ret = linux_syscall4_v(sig, (uintptr_t)act, (uintptr_t)oact, sigsetsize, linux_syscall_name_rt_sigaction);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_rt_sigprocmask_v(uint32_t const how, linux_sigset_t* const nset, linux_sigset_t* const oset, linux_size_t const sigsetsize)
{
	linux_word_t const ret = linux_syscall4_v(how, (uintptr_t)nset, (uintptr_t)oset, sigsetsize, linux_syscall_name_rt_sigprocmask);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_rt_sigpending_v(linux_sigset_t* const uset, linux_size_t const sigsetsize)
{
	linux_word_t const ret = linux_syscall2_v((uintptr_t)uset, sigsetsize, linux_syscall_name_rt_sigpending);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_rt_sigtimedwait_v(linux_sigset_t const* const uthese, linux_siginfo_t* const uinfo, struct linux_timespec const* const uts, linux_size_t const sigsetsize, uint32_t* const result)
{
	linux_word_t const ret = linux_syscall4_v((uintptr_t)uthese, (uintptr_t)uinfo, (uintptr_t)uts, sigsetsize, linux_syscall_name_rt_sigtimedwait);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (uint32_t)ret;
	return err;
}

inline linux_error_t linux_rt_sigqueueinfo_v(linux_pid_t const pid, uint32_t const sig, linux_siginfo_t* const uinfo) // DEPRECATED: use linux_rt_tgsigqueueinfo_v
{
	linux_word_t const ret = linux_syscall3_v((uint32_t)pid, sig, (uintptr_t)uinfo, linux_syscall_name_rt_sigqueueinfo);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_rt_tgsigqueueinfo_v(linux_pid_t const tgid, linux_pid_t const pid, uint32_t const sig, linux_siginfo_t* const uinfo)
{
	linux_word_t const ret = linux_syscall4_v((uint32_t)tgid, (uint32_t)pid, sig, (uintptr_t)uinfo, linux_syscall_name_rt_tgsigqueueinfo);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_signalfd_v(linux_fd_t const ufd, linux_sigset_t* const user_mask, linux_size_t const sizemask, linux_fd_t* const result) // DEPRECATED: use linux_signalfd4_v
{
	linux_word_t const ret = linux_syscall3_v((uint32_t)ufd, (uintptr_t)user_mask, sizemask, linux_syscall_name_signalfd);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}

inline linux_error_t linux_rt_sigtimedwait_time32_v(linux_sigset_t const* const uthese, linux_siginfo_t* const uinfo, struct linux_timespec32 const* const uts, linux_size_t const sigsetsize, uint32_t* const result)
{
	linux_word_t const ret = linux_syscall4_v((uintptr_t)uthese, (uintptr_t)uinfo, (uintptr_t)uts, sigsetsize, linux_syscall_name_rt_sigtimedwait_time32);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (uint32_t)ret;
	return err;
}

inline linux_error_t linux_sigaction_v(uint32_t const sig, struct linux_old_sigaction const* const act, struct linux_old_sigaction* const oact)
{
	linux_word_t const ret = linux_syscall3_v(sig, (uintptr_t)act, (uintptr_t)oact, linux_syscall_name_sigaction);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_sigsuspend_v(int32_t const unused1, int32_t const unused2, linux_old_sigset_t const mask)
{
	linux_word_t const ret = linux_syscall3_v((uint32_t)unused1, (uint32_t)unused2, mask, linux_syscall_name_sigsuspend);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_sigpending_v(linux_old_sigset_t* const uset)
{
	linux_word_t const ret = linux_syscall1_v((uintptr_t)uset, linux_syscall_name_sigpending);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_sigprocmask_v(uint32_t const how, linux_old_sigset_t* const nset, linux_old_sigset_t* const oset)
{
	linux_word_t const ret = linux_syscall3_v(how, (uintptr_t)nset, (uintptr_t)oset, linux_syscall_name_sigprocmask);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

inline linux_error_t linux_signal_v(uint32_t const sig, linux_sighandler_t const handler, linux_uword_t* const result)
{
	linux_word_t const ret = linux_syscall2_v(sig, (uintptr_t)handler, linux_syscall_name_signal);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_uword_t)ret;
	return err;
}
#endif

//-----------------------------------------------------------------------------
// pidfd

inline linux_error_t linux_pidfd_open(linux_pid_t pid, unsigned int flags, linux_fd_t* result)
{
	linux_word_t const ret = linux_syscall2((uint32_t)pid, flags, linux_syscall_name_pidfd_open);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}
inline linux_error_t linux_pidfd_send_signal(linux_fd_t const pidfd, int const sig, linux_siginfo_t* const info, unsigned int const flags)
{
	linux_word_t const ret = linux_syscall4((uint32_t)pidfd, (unsigned int)sig, (uintptr_t)info, flags, linux_syscall_name_pidfd_send_signal);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_pidfd_getfd(linux_pid_t const pidfd, linux_fd_t const fd, unsigned int const flags, linux_fd_t* const result)
{
	linux_word_t const ret = linux_syscall3((uint32_t)pidfd, (uint32_t)fd, flags, linux_syscall_name_pidfd_getfd);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}

//-----------------------------------------------------------------------------
// process user/group id

inline linux_error_t linux_setuid(linux_uid_t const uid)
{
	linux_word_t const ret = linux_syscall1(uid, linux_syscall_name_setuid);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_setgid(linux_gid_t const gid)
{
	linux_word_t const ret = linux_syscall1(gid, linux_syscall_name_setgid);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_setreuid(linux_uid_t const ruid, linux_uid_t const euid)
{
	linux_word_t const ret = linux_syscall2(ruid, euid, linux_syscall_name_setreuid);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_setregid(linux_gid_t const rgid, linux_gid_t const egid)
{
	linux_word_t const ret = linux_syscall2(rgid, egid, linux_syscall_name_setregid);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_setresuid(linux_uid_t const ruid, linux_uid_t const euid, linux_uid_t const suid)
{
	linux_word_t const ret = linux_syscall3(ruid, euid, suid, linux_syscall_name_setresuid);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_setresgid(linux_gid_t const rgid, linux_gid_t const egid, linux_gid_t const sgid)
{
	linux_word_t const ret = linux_syscall3(rgid, egid, sgid, linux_syscall_name_setresgid);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_setfsuid(linux_uid_t const uid, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall1(uid, linux_syscall_name_setfsuid);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_setfsgid(linux_gid_t const gid, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall1(gid, linux_syscall_name_setfsgid);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_getuid(linux_uid_t* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_getuid);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_uid_t)ret;
	return err;
}
inline linux_error_t linux_getgid(linux_gid_t* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_getgid);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_gid_t)ret;
	return err;
}
inline linux_error_t linux_geteuid(linux_uid_t* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_geteuid);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_uid_t)ret;
	return err;
}
inline linux_error_t linux_getegid(linux_gid_t* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_getegid);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_gid_t)ret;
	return err;
}
inline linux_error_t linux_getresuid(linux_uid_t* const ruidp, linux_uid_t* const euidp, linux_uid_t* const suidp)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)ruidp, (uintptr_t)euidp, (uintptr_t)suidp, linux_syscall_name_getresuid);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_getresgid(linux_gid_t* const rgidp, linux_gid_t* const egidp, linux_gid_t* const sgidp)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)rgidp, (uintptr_t)egidp, (uintptr_t)sgidp, linux_syscall_name_getresgid);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

//-----------------------------------------------------------------------------
// process/process group/session id

inline linux_error_t linux_setpgid(linux_pid_t const pid, linux_pid_t const pgid)
{
	linux_word_t const ret = linux_syscall2((uint32_t)pid, (uint32_t)pgid, linux_syscall_name_setpgid);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_setsid(int* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_setsid);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_getpgid(linux_pid_t const pid, int* const result)
{
	linux_word_t const ret = linux_syscall1((uint32_t)pid, linux_syscall_name_getpgid);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_getsid(linux_pid_t const pid, int* const result)
{
	linux_word_t const ret = linux_syscall1((uint32_t)pid, linux_syscall_name_getsid);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_getpid(linux_pid_t* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_getpid);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_pid_t)ret;
	return err;
}
inline linux_error_t linux_getppid(int* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_getppid);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_gettid(linux_pid_t* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_gettid);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_pid_t)ret;
	return err;
}

//-----------------------------------------------------------------------------
// message queue

inline linux_error_t linux_mq_open(char const* const u_name, int const oflag, linux_umode_t const mode, struct linux_mq_attr* const u_attr, int* const result)
{
	linux_word_t const ret = linux_syscall4((uintptr_t)u_name, (unsigned int)oflag, mode, (uintptr_t)u_attr, linux_syscall_name_mq_open);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_mq_unlink(char const* const u_name)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)u_name, linux_syscall_name_mq_unlink);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_mq_timedsend(linux_mqd_t const mqdes, char const* const u_msg_ptr, linux_size_t const msg_len, unsigned int const msg_prio, struct linux_timespec const* const u_abs_timeout)
{
	linux_word_t const ret = linux_syscall5((unsigned int)mqdes, (uintptr_t)u_msg_ptr, msg_len, msg_prio, (uintptr_t)u_abs_timeout, linux_syscall_name_mq_timedsend);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_mq_timedreceive(linux_mqd_t const mqdes, char* const u_msg_ptr, linux_size_t const msg_len, unsigned int* const u_msg_prio, struct linux_timespec const* const u_abs_timeout, int* const result)
{
	linux_word_t const ret = linux_syscall5((unsigned int)mqdes, (uintptr_t)u_msg_ptr, msg_len, (uintptr_t)u_msg_prio, (uintptr_t)u_abs_timeout, linux_syscall_name_mq_timedreceive);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_mq_notify(linux_mqd_t const mqdes, struct linux_sigevent const* const u_notification)
{
	linux_word_t const ret = linux_syscall2((unsigned int)mqdes, (uintptr_t)u_notification, linux_syscall_name_mq_notify);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_mq_getsetattr(linux_mqd_t const mqdes, struct linux_mq_attr const* const u_mqstat, struct linux_mq_attr* const u_omqstat)
{
	linux_word_t const ret = linux_syscall3((unsigned int)mqdes, (uintptr_t)u_mqstat, (uintptr_t)u_omqstat, linux_syscall_name_mq_getsetattr);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

//-----------------------------------------------------------------------------
// System V IPC - message

inline linux_error_t linux_msgget(linux_key_t const key, int const msgflg, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall2((unsigned int)key, (unsigned int)msgflg, linux_syscall_name_msgget);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_msgrcv(int const msqid, struct linux_msgbuf* const msgp, linux_size_t const msgsz, linux_word_t const msgtyp, int const msgflg, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall5((unsigned int)msqid, (uintptr_t)msgp, msgsz, (linux_uword_t)msgtyp, (unsigned int)msgflg, linux_syscall_name_msgrcv);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_msgsnd(int const msqid, struct linux_msgbuf* const msgp, linux_size_t const msgsz, int const msgflg)
{
	linux_word_t const ret = linux_syscall4((unsigned int)msqid, (uintptr_t)msgp, msgsz, (unsigned int)msgflg, linux_syscall_name_msgsnd);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

//-----------------------------------------------------------------------------
// System V IPC - semaphore

inline linux_error_t linux_semget(linux_key_t const key, int const nsems, int const semflg, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)key, (unsigned int)nsems, (unsigned int)semflg, linux_syscall_name_semget);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_semtimedop(int const semid, struct linux_sembuf* const tsops, unsigned int const nsops, struct linux_timespec const* const timeout)
{
	linux_word_t const ret = linux_syscall4((unsigned int)semid, (uintptr_t)tsops, nsops, (uintptr_t)timeout, linux_syscall_name_semtimedop);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

//-----------------------------------------------------------------------------
// System V IPC - memory

inline linux_error_t linux_shmget(linux_key_t const key, linux_size_t const size, int const shmflg, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)key, size, (unsigned int)shmflg, linux_syscall_name_shmget);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_shmat(int const shmid, char* const shmaddr, int const shmflg, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)shmid, (uintptr_t)shmaddr, (unsigned int)shmflg, linux_syscall_name_shmat);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_shmdt(char* const shmaddr)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)shmaddr, linux_syscall_name_shmdt);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

//-----------------------------------------------------------------------------
// socket

inline linux_error_t linux_socket(int const family, int const type, int const protocol, linux_fd_t* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)family, (unsigned int)type, (unsigned int)protocol, linux_syscall_name_socket);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}
inline linux_error_t linux_socketpair(int const family, int const type, int const protocol, linux_fd_t* const usockvec)
{
	linux_word_t const ret = linux_syscall4((unsigned int)family, (unsigned int)type, (unsigned int)protocol, (uintptr_t)usockvec, linux_syscall_name_socketpair);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_bind(linux_fd_t const fd, struct linux_sockaddr const* const umyaddr, int const addrlen)
{
	linux_word_t const ret = linux_syscall3((uint32_t)fd, (uintptr_t)umyaddr, (unsigned int)addrlen, linux_syscall_name_bind);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_listen(linux_fd_t const fd, int const backlog)
{
	linux_word_t const ret = linux_syscall2((uint32_t)fd, (unsigned int)backlog, linux_syscall_name_listen);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_accept4(linux_fd_t const fd, struct linux_sockaddr* const upeer_sockaddr, int* const upeer_addrlen, int const flags, linux_fd_t* const result)
{
	linux_word_t const ret = linux_syscall4((uint32_t)fd, (uintptr_t)upeer_sockaddr, (uintptr_t)upeer_addrlen, (unsigned int)flags, linux_syscall_name_accept4);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}
inline linux_error_t linux_connect(linux_fd_t const fd, struct linux_sockaddr const* const uservaddr, int const addrlen)
{
	linux_word_t const ret = linux_syscall3((uint32_t)fd, (uintptr_t)uservaddr, (unsigned int)addrlen, linux_syscall_name_connect);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_getsockname(linux_fd_t const fd, struct linux_sockaddr* const usockaddr, int* const usockaddr_len)
{
	linux_word_t const ret = linux_syscall3((uint32_t)fd, (uintptr_t)usockaddr, (uintptr_t)usockaddr_len, linux_syscall_name_getsockname);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_getpeername(linux_fd_t const fd, struct linux_sockaddr* const usockaddr, int* const usockaddr_len)
{
	linux_word_t const ret = linux_syscall3((uint32_t)fd, (uintptr_t)usockaddr, (uintptr_t)usockaddr_len, linux_syscall_name_getpeername);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_sendto(linux_fd_t const fd, void const* const buff, linux_size_t const len, unsigned int const flags, struct linux_sockaddr const* const addr, int const addr_le, int* const result)
{
	linux_word_t const ret = linux_syscall6((uint32_t)fd, (uintptr_t)buff, len, flags, (uintptr_t)addr, (unsigned int)addr_le, linux_syscall_name_sendto);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_recvfrom(linux_fd_t const fd, void* const ubuf, linux_size_t const size, unsigned int const flags, struct linux_sockaddr* const addr, int* const addr_len, int* const result)
{
	linux_word_t const ret = linux_syscall6((uint32_t)fd, (uintptr_t)ubuf, size, flags, (uintptr_t)addr, (uintptr_t)addr_len, linux_syscall_name_recvfrom);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_setsockopt(linux_fd_t const fd, int const level, int const optname, char const* const optval, int const optlen)
{
	linux_word_t const ret = linux_syscall5((uint32_t)fd, (unsigned int)level, (unsigned int)optname, (uintptr_t)optval, (unsigned int)optlen, linux_syscall_name_setsockopt);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_getsockopt(linux_fd_t const fd, int const level, int const optname, char* const optval, int* const optlen)
{
	linux_word_t const ret = linux_syscall5((uint32_t)fd, (unsigned int)level, (unsigned int)optname, (uintptr_t)optval, (uintptr_t)optlen, linux_syscall_name_getsockopt);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_shutdown(linux_fd_t const fd, int const how)
{
	linux_word_t const ret = linux_syscall2((uint32_t)fd, (unsigned int)how, linux_syscall_name_shutdown);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_sendmsg(linux_fd_t const fd, struct linux_user_msghdr* const msg, unsigned int const flags, int* const result)
{
	linux_word_t const ret = linux_syscall3((uint32_t)fd, (uintptr_t)msg, flags, linux_syscall_name_sendmsg);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_recvmsg(linux_fd_t const fd, struct linux_user_msghdr* const msg, unsigned int const flags, int* const result)
{
	linux_word_t const ret = linux_syscall3((uint32_t)fd, (uintptr_t)msg, flags, linux_syscall_name_recvmsg);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_recvmmsg(linux_fd_t const fd, struct linux_mmsghdr* const mmsg, unsigned int const vlen, unsigned int const flags, struct linux_timespec* const timeout, int* const result)
{
	linux_word_t const ret = linux_syscall5((uint32_t)fd, (uintptr_t)mmsg, vlen, flags, (uintptr_t)timeout, linux_syscall_name_recvmmsg);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_sendmmsg(linux_fd_t const fd, struct linux_mmsghdr* const mmsg, unsigned int const vlen, unsigned int const flags, int* const result)
{
	linux_word_t const ret = linux_syscall4((uint32_t)fd, (uintptr_t)mmsg, vlen, flags, linux_syscall_name_sendmmsg);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}

//-----------------------------------------------------------------------------
// memory

inline linux_error_t linux_brk(linux_uword_t const brk, linux_uword_t* const result)
{
	linux_word_t const ret = linux_syscall1(brk, linux_syscall_name_brk);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_uword_t)ret;
	return err;
}
inline linux_error_t linux_munmap(linux_uword_t const addr, linux_size_t const len)
{
	linux_word_t const ret = linux_syscall2(addr, len, linux_syscall_name_munmap);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_mremap(linux_uword_t const addr, linux_uword_t const old_len, linux_uword_t const new_len, linux_uword_t const flags, linux_uword_t const new_addr, linux_uword_t* const result)
{
	linux_word_t const ret = linux_syscall5(addr, old_len, new_len, flags, new_addr, linux_syscall_name_mremap);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_uword_t)ret;
	return err;
}
inline linux_error_t linux_mprotect(linux_uword_t const start, linux_size_t const len, linux_uword_t const prot)
{
	linux_word_t const ret = linux_syscall3(start, len, prot, linux_syscall_name_mprotect);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_msync(linux_uword_t const start, linux_size_t const len, int const flags)
{
	linux_word_t const ret = linux_syscall3(start, len, (unsigned int)flags, linux_syscall_name_msync);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_mlock(linux_uword_t const start, linux_size_t const len) // DEPRECATED: use linux_mlock2
{
	linux_word_t const ret = linux_syscall2(start, len, linux_syscall_name_mlock);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_munlock(linux_uword_t const start, linux_size_t const len)
{
	linux_word_t const ret = linux_syscall2(start, len, linux_syscall_name_munlock);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_mlockall(int const flags)
{
	linux_word_t const ret = linux_syscall1((unsigned int)flags, linux_syscall_name_mlockall);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_munlockall(void)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_munlockall);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_mincore(linux_uword_t const start, linux_size_t const len, unsigned char* const vec)
{
	linux_word_t const ret = linux_syscall3(start, len, (uintptr_t)vec, linux_syscall_name_mincore);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_madvise(linux_uword_t const start, linux_size_t const len_in, int const behavior)
{
	linux_word_t const ret = linux_syscall3(start, len_in, (unsigned int)behavior, linux_syscall_name_madvise);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_process_madvise(int const pidfd, struct linux_iovec const* const vec, linux_size_t const vlen, int const behavior, unsigned int const flags, linux_size_t* const result)
{
	linux_word_t const ret = linux_syscall5((unsigned int)pidfd, (uintptr_t)vec, vlen, (unsigned int)behavior, flags, linux_syscall_name_process_madvise);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_size_t)ret;
	return err;
}
inline linux_error_t linux_process_mrelease(linux_fd_t const pidfd, unsigned int const flags)
{
	linux_word_t const ret = linux_syscall2((uint32_t)pidfd, flags, linux_syscall_name_process_mrelease);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_remap_file_pages(linux_uword_t const start, linux_uword_t const size, linux_uword_t const prot, linux_uword_t const pgoff, linux_uword_t const flags)
{
	linux_word_t const ret = linux_syscall5(start, size, prot, pgoff, flags, linux_syscall_name_remap_file_pages);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_mbind(linux_uword_t const start, linux_uword_t const len, linux_uword_t const mode, linux_uword_t const* const nmask, linux_uword_t const maxnode, unsigned int const flags)
{
	linux_word_t const ret = linux_syscall6(start, len, mode, (uintptr_t)nmask, maxnode, flags, linux_syscall_name_mbind);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_get_mempolicy(int* const policy, linux_uword_t* const nmask, linux_uword_t const maxnode, linux_uword_t const addr, linux_uword_t const flags)
{
	linux_word_t const ret = linux_syscall5((uintptr_t)policy, (uintptr_t)nmask, maxnode, addr, flags, linux_syscall_name_get_mempolicy);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_set_mempolicy(int const mode, linux_uword_t const* const nmask, linux_uword_t const maxnode)
{
	linux_word_t const ret = linux_syscall3((unsigned int)mode, (uintptr_t)nmask, maxnode, linux_syscall_name_set_mempolicy);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_migrate_pages(linux_pid_t const pid, linux_uword_t const maxnode, linux_uword_t const* const old_nodes, linux_uword_t const* const new_nodes, int* const result)
{
	linux_word_t const ret = linux_syscall4((uint32_t)pid, maxnode, (uintptr_t)old_nodes, (uintptr_t)new_nodes, linux_syscall_name_migrate_pages);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_move_pages(linux_pid_t const pid, linux_uword_t const nr_pages, void const** const pages, int const* const nodes, int* const status, int const flags)
{
	linux_word_t const ret = linux_syscall6((uint32_t)pid, nr_pages, (uintptr_t)pages, (uintptr_t)nodes, (uintptr_t)status, (unsigned int)flags, linux_syscall_name_move_pages);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_membarrier(int const cmd, int const flags, int* const result)
{
	linux_word_t const ret = linux_syscall2((unsigned int)cmd, (unsigned int)flags, linux_syscall_name_membarrier);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_mlock2(linux_uword_t const start, linux_size_t const len, int const flags)
{
	linux_word_t const ret = linux_syscall3(start, len, (unsigned int)flags, linux_syscall_name_mlock2);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_pkey_mprotect(linux_uword_t const start, linux_size_t const len, linux_uword_t const prot, int const pkey)
{
	linux_word_t const ret = linux_syscall4(start, len, prot, (unsigned int)pkey, linux_syscall_name_pkey_mprotect);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_pkey_alloc(linux_uword_t const flags, linux_uword_t const init_val, int* const result)
{
	linux_word_t const ret = linux_syscall2(flags, init_val, linux_syscall_name_pkey_alloc);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_pkey_free(int const pkey)
{
	linux_word_t const ret = linux_syscall1((unsigned int)pkey, linux_syscall_name_pkey_free);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

//-----------------------------------------------------------------------------
// key management

inline linux_error_t linux_add_key(char const* const type, char const* const description, void const* const payload, linux_size_t const plen, linux_key_serial_t const ringid, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall5((uintptr_t)type, (uintptr_t)description, (uintptr_t)payload, plen, (uint32_t)ringid, linux_syscall_name_add_key);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_request_key(char const* const type, char const* const description, char const* const callout_info, linux_key_serial_t const destringid, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall4((uintptr_t)type, (uintptr_t)description, (uintptr_t)callout_info, (uint32_t)destringid, linux_syscall_name_request_key);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_keyctl(int const option, linux_uword_t const arg2, linux_uword_t const arg3, linux_uword_t const arg4, linux_uword_t const arg5, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall5((unsigned int)option, arg2, arg3, arg4, arg5, linux_syscall_name_keyctl);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}

//-----------------------------------------------------------------------------
// process creation

inline linux_error_t linux_waitid(int const which, linux_pid_t const upid, struct linux_siginfo* const infop, int const options, struct linux_rusage* const ru)
{
	linux_word_t const ret = linux_syscall5((unsigned int)which, (uint32_t)upid, (uintptr_t)infop, (unsigned int)options, (uintptr_t)ru, linux_syscall_name_waitid);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_clone(linux_uword_t const clone_flags, linux_uword_t const newsp, int* const parent_tidptr, int* const child_tidptr, linux_uword_t const tls, linux_word_t* const result) // DEPRECATED: use linux_clone3
{
#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_ARM64) || defined(LINUX_ARCH_RISCV32) || defined(LINUX_ARCH_RISCV64) || defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall5(clone_flags, newsp, (uintptr_t)parent_tidptr, tls, (uintptr_t)child_tidptr, linux_syscall_name_clone);
#else
	linux_word_t const ret = linux_syscall5(clone_flags, newsp, (uintptr_t)parent_tidptr, (uintptr_t)child_tidptr, tls, linux_syscall_name_clone);
#endif
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_clone3(struct linux_clone_args* uargs, linux_size_t size, linux_pid_t* result)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)uargs, size, linux_syscall_name_clone3);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_pid_t)ret;
	return err;
}
inline linux_error_t linux_execve(char const* const filename, char const* const* const argv, char const* const* const envp) // DEPRECATED: use linux_execveat
{
	linux_word_t const ret = linux_syscall3((uintptr_t)filename, (uintptr_t)argv, (uintptr_t)envp, linux_syscall_name_execve);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_execveat(linux_fd_t const fd, char const* const filename, char const* const* const argv, char const* const* const envp, int const flags)
{
	linux_word_t const ret = linux_syscall5((uint32_t)fd, (uintptr_t)filename, (uintptr_t)argv, (uintptr_t)envp, (unsigned int)flags, linux_syscall_name_execveat);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

//-----------------------------------------------------------------------------
// fanotify

inline linux_error_t linux_fanotify_init(unsigned int const flags, unsigned int const event_f_flags, linux_fd_t* const result)
{
	linux_word_t const ret = linux_syscall2(flags, event_f_flags, linux_syscall_name_fanotify_init);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}
inline linux_error_t linux_fanotify_mark(linux_fd_t const fanotify_fd, unsigned int const flags, uint64_t const mask, linux_fd_t const dfd, char const* const pathname)
{
#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_RISCV32) || defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall6((uint32_t)fanotify_fd, flags, LINUX_EXPAND(mask), (uint32_t)dfd, (uintptr_t)pathname, linux_syscall_name_fanotify_mark);
#else
	linux_word_t const ret = linux_syscall5((uint32_t)fanotify_fd, flags, mask, (uint32_t)dfd, (uintptr_t)pathname, linux_syscall_name_fanotify_mark);
#endif
	linux_error_t const err = linux_get_error(ret);
	return err;
}

//-----------------------------------------------------------------------------
// misc file descriptors

inline linux_error_t linux_eventfd2(unsigned int const count, int const flags, linux_fd_t* const result)
{
	linux_word_t const ret = linux_syscall2(count, (unsigned int)flags, linux_syscall_name_eventfd2);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}
inline linux_error_t linux_memfd_create(char const* const uname, unsigned int const flags, linux_fd_t* const result)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)uname, flags, linux_syscall_name_memfd_create);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}
inline linux_error_t linux_userfaultfd(int const flags, linux_fd_t* const result)
{
	linux_word_t const ret = linux_syscall1((unsigned int)flags, linux_syscall_name_userfaultfd);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}

//-----------------------------------------------------------------------------
// io_uring

inline linux_error_t linux_io_uring_setup(uint32_t const entries, struct linux_io_uring_params* const params, linux_fd_t* const result)
{
	linux_word_t const ret = linux_syscall2(entries, (uintptr_t)params, linux_syscall_name_io_uring_setup);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}
inline linux_error_t linux_io_uring_enter(linux_fd_t const fd, uint32_t const to_submit, uint32_t const min_complete, uint32_t const flags, linux_sigset_t const* const sig, linux_size_t const sigsz, int* const result)
{
	linux_word_t const ret = linux_syscall6((uint32_t)fd, to_submit, min_complete, flags, (uintptr_t)sig, sigsz, linux_syscall_name_io_uring_enter);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_io_uring_register(linux_fd_t const fd, unsigned int const opcode, void* const arg, unsigned int const nr_args, int* const result)
{
	linux_word_t const ret = linux_syscall4((uint32_t)fd, opcode, (uintptr_t)arg, nr_args, linux_syscall_name_io_uring_register);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}

//-----------------------------------------------------------------------------
// mount

inline linux_error_t linux_umount(char* const name, int const flags)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)name, (unsigned int)flags, linux_syscall_name_umount);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_mount(char* const dev_name, char* const dir_name, char* const type, linux_uword_t const flags, void* const data)
{
	linux_word_t const ret = linux_syscall5((uintptr_t)dev_name, (uintptr_t)dir_name, (uintptr_t)type, flags, (uintptr_t)data, linux_syscall_name_mount);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_pivot_root(char const* const new_root, char const* const put_old)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)new_root, (uintptr_t)put_old, linux_syscall_name_pivot_root);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_open_tree(linux_fd_t dfd, char const* path, unsigned int flags, linux_fd_t* result)
{
	linux_word_t const ret = linux_syscall3((uint32_t)dfd, (uintptr_t)path, flags, linux_syscall_name_open_tree);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}
inline linux_error_t linux_move_mount(linux_fd_t from_dfd, char const* from_path, linux_fd_t to_dfd, char const* to_path, unsigned int ms_flags)
{
	linux_word_t const ret = linux_syscall5((uint32_t)from_dfd, (uintptr_t)from_path, (uint32_t)to_dfd, (uintptr_t)to_path, ms_flags, linux_syscall_name_move_mount);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_fsopen(char const* fs_name, unsigned int flags, linux_fd_t* result)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)fs_name, flags, linux_syscall_name_fsopen);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}
inline linux_error_t linux_fsconfig(linux_fd_t fs_fd, unsigned int cmd, char const* key, void const* value, int aux)
{
	linux_word_t const ret = linux_syscall5((uint32_t)fs_fd, cmd, (uintptr_t)key, (uintptr_t)value, (unsigned int)aux, linux_syscall_name_fsconfig);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_fsmount(linux_fd_t fs_fd, unsigned int flags, unsigned int ms_flags, linux_fd_t* result)
{
	linux_word_t const ret = linux_syscall3((uint32_t)fs_fd, flags, ms_flags, linux_syscall_name_fsmount);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}
inline linux_error_t linux_fspick(linux_fd_t dfd, char const* path, unsigned int flags, linux_fd_t* result)
{
	linux_word_t const ret = linux_syscall3((uint32_t)dfd, (uintptr_t)path, flags, linux_syscall_name_fspick);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}
inline linux_error_t linux_mount_setattr(linux_fd_t dfd, char const* path, unsigned int flags, struct linux_mount_attr* uattr, linux_size_t usize)
{
	linux_word_t const ret = linux_syscall5((uint32_t)dfd, (uintptr_t)path, flags, (uintptr_t)uattr, usize, linux_syscall_name_mount_setattr);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

//-----------------------------------------------------------------------------
// misc

inline linux_error_t linux_getcwd(char* const buf, linux_uword_t const size, int* const result)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)buf, size, linux_syscall_name_getcwd);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_lookup_dcookie(uint64_t const cookie64, char* const buf, linux_size_t const len, int* const result)
{
#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_RISCV32) || defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall4(LINUX_EXPAND(cookie64), (uintptr_t)buf, len, linux_syscall_name_fanotify_mark);
#else
	linux_word_t const ret = linux_syscall3(cookie64, (uintptr_t)buf, len, linux_syscall_name_fanotify_mark);
#endif
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_chdir(char const* const filename)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)filename, linux_syscall_name_chdir);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_fchdir(linux_fd_t const fd)
{
	linux_word_t const ret = linux_syscall1((uint32_t)fd, linux_syscall_name_fchdir);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_chroot(char const* const filename)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)filename, linux_syscall_name_chroot);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_vhangup(void)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_vhangup);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_pipe2(linux_fd_t* const fildes, int const flags)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)fildes, (unsigned int)flags, linux_syscall_name_pipe2);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_quotactl(unsigned int const cmd, char const* const special, linux_qid_t const id, void* const addr)
{
	linux_word_t const ret = linux_syscall4(cmd, (uintptr_t)special, id, (uintptr_t)addr, linux_syscall_name_quotactl);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_quotactl_fd(linux_fd_t const fd, unsigned int const cmd, linux_qid_t const id, void* const addr)
{
	linux_word_t const ret = linux_syscall4((uint32_t)fd, cmd, id, (uintptr_t)addr, linux_syscall_name_quotactl_fd);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_sync(void)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_sync);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_fsync(linux_fd_t const fd)
{
	linux_word_t const ret = linux_syscall1((uint32_t)fd, linux_syscall_name_fsync);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_fdatasync(linux_fd_t const fd)
{
	linux_word_t const ret = linux_syscall1((uint32_t)fd, linux_syscall_name_fdatasync);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_sync_file_range(linux_fd_t const fd, unsigned int const flags, linux_loff_t const offset, linux_loff_t const nbytes)
{
#if defined(LINUX_ARCH_ARM_EABI)
	linux_word_t const ret = linux_syscall6((uint32_t)fd, flags, LINUX_EXPAND(offset), LINUX_EXPAND(nbytes), linux_syscall_name_sync_file_range2);
#elif defined(LINUX_ARCH_RISCV32) || defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall6((uint32_t)fd, LINUX_EXPAND(offset), LINUX_EXPAND(nbytes), flags, linux_syscall_name_sync_file_range);
#else
	linux_word_t const ret = linux_syscall4((uint32_t)fd, (uint64_t)offset, (uint64_t)nbytes, flags, linux_syscall_name_sync_file_range);
#endif
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_utimensat(linux_fd_t const dfd, char const* const filename, struct linux_timespec* const utimes, int const flags)
{
	linux_word_t const ret = linux_syscall4((uint32_t)dfd, (uintptr_t)filename, (uintptr_t)utimes, (unsigned int)flags, linux_syscall_name_utimensat);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_acct(char const* const name)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)name, linux_syscall_name_acct);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_personality(unsigned int const personality, unsigned int* const result)
{
	linux_word_t const ret = linux_syscall1(personality, linux_syscall_name_personality);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (unsigned int)ret;
	return err;
}
inline linux_error_t linux_set_tid_address(int* const tidptr, linux_pid_t* const result)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)tidptr, linux_syscall_name_set_tid_address);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_pid_t)ret;
	return err;
}
inline linux_error_t linux_unshare(linux_uword_t const unshare_flags)
{
	linux_word_t const ret = linux_syscall1(unshare_flags, linux_syscall_name_unshare);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_syslog(int const type, char* const buf, int const len, int* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)type, (uintptr_t)buf, (unsigned int)len, linux_syscall_name_syslog);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_ptrace(linux_word_t const request, linux_word_t const pid, linux_uword_t const addr, linux_uword_t const data, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall4((linux_uword_t)request, (linux_uword_t)pid, addr, data, linux_syscall_name_ptrace);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_times(struct linux_tms* const tbuf, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)tbuf, linux_syscall_name_times);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_getgroups(int const gidsetsize, linux_gid_t* const grouplis, int* const result)
{
	linux_word_t const ret = linux_syscall2((unsigned int)gidsetsize, (uintptr_t)grouplis, linux_syscall_name_getgroups);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_setgroups(int const gidsetsize, linux_gid_t* const grouplist)
{
	linux_word_t const ret = linux_syscall2((unsigned int)gidsetsize, (uintptr_t)grouplist, linux_syscall_name_setgroups);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_newuname(struct linux_new_utsname* const name)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)name, linux_syscall_name_newuname);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_sethostname(char* const name, int const len)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)name, (unsigned int)len, linux_syscall_name_sethostname);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_setdomainname(char* const name, int const len)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)name, (unsigned int)len, linux_syscall_name_setdomainname);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_getrlimit(unsigned int const resource, struct linux_rlimit* const rlim)
{
	linux_word_t const ret = linux_syscall2(resource, (uintptr_t)rlim, linux_syscall_name_getrlimit);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_setrlimit(unsigned int const resource, struct linux_rlimit* const rlim)
{
	linux_word_t const ret = linux_syscall2(resource, (uintptr_t)rlim, linux_syscall_name_setrlimit);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_getrusage(int const who, struct linux_rusage* const ru)
{
	linux_word_t const ret = linux_syscall2((unsigned int)who, (uintptr_t)ru, linux_syscall_name_getrusage);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_umask(int const mask, int* const result)
{
	linux_word_t const ret = linux_syscall1((unsigned int)mask, linux_syscall_name_umask);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_prctl(int const option, linux_uword_t const arg2, linux_uword_t const arg3, linux_uword_t const arg4, linux_uword_t const arg5, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall5((unsigned int)option, arg2, arg3, arg4, arg5, linux_syscall_name_prctl);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_getcpu(unsigned int* const cpup, unsigned int* const nodep, struct linux_getcpu_cache* const unused)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)cpup, (uintptr_t)nodep, (uintptr_t)unused, linux_syscall_name_getcpu);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_sysinfo(struct linux_sysinfo* const info)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)info, linux_syscall_name_sysinfo);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_swapon(char const* const specialfile, int const swap_flags)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)specialfile, (unsigned int)swap_flags, linux_syscall_name_swapon);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_swapoff(char const* const specialfile)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)specialfile, linux_syscall_name_swapoff);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_perf_event_open(struct linux_perf_event_attr* const attr_uptr, linux_pid_t const pid, int const cpu, linux_fd_t const group_fd, linux_uword_t const flags, linux_fd_t* const result)
{
	linux_word_t const ret = linux_syscall5((uintptr_t)attr_uptr, (uint32_t)pid, (unsigned int)cpu, (uint32_t)group_fd, flags, linux_syscall_name_perf_event_open);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}
inline linux_error_t linux_prlimit64(linux_pid_t const pid, unsigned int const resource, struct linux_rlimit64 const* const new_rlim, struct linux_rlimit64* const old_rlim)
{
	linux_word_t const ret = linux_syscall4((uint32_t)pid, resource, (uintptr_t)new_rlim, (uintptr_t)old_rlim, linux_syscall_name_prlimit64);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_syncfs(linux_fd_t const fd)
{
	linux_word_t const ret = linux_syscall1((uint32_t)fd, linux_syscall_name_syncfs);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_setns(linux_fd_t const fd, int const nstype)
{
	linux_word_t const ret = linux_syscall2((uint32_t)fd, (unsigned int)nstype, linux_syscall_name_setns);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_kcmp(linux_pid_t const pid1, linux_pid_t const pid2, int const type, linux_uword_t const idx1, linux_uword_t const idx2, int* const result)
{
	linux_word_t const ret = linux_syscall5((uint32_t)pid1, (uint32_t)pid2, (unsigned int)type, idx1, idx2, linux_syscall_name_kcmp);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_seccomp(unsigned int const op, unsigned int const flags, void* const uargs, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall3(op, flags, (uintptr_t)uargs, linux_syscall_name_seccomp);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_getrandom(char* const buf, linux_size_t const count, unsigned int const flags, linux_ssize_t* const result)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)buf, count, flags, linux_syscall_name_getrandom);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_ssize_t)ret;
	return err;
}
inline linux_error_t linux_bpf(int const cmd, union linux_bpf_attr* const uattr, unsigned int const size, int* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)cmd, (uintptr_t)uattr, size, linux_syscall_name_bpf);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_rseq(struct linux_rseq* const rseq, uint32_t const rseq_len, int const flags, uint32_t const sig)
{
	linux_word_t const ret = linux_syscall4((uintptr_t)rseq, rseq_len, (unsigned int)flags, sig, linux_syscall_name_rseq);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_landlock_create_ruleset(struct linux_landlock_ruleset_attr const* const attr, linux_size_t const size, uint32_t const flags, int* result)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)attr, size, flags, linux_syscall_name_landlock_create_ruleset);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_landlock_add_rule(linux_fd_t const ruleset_fd, enum linux_landlock_rule_type const rule_type, void const* const rule_attr, uint32_t const flags)
{
	linux_word_t const ret = linux_syscall4((uint32_t)ruleset_fd, (unsigned int)rule_type, (uintptr_t)rule_attr, flags, linux_syscall_name_landlock_add_rule);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_landlock_restrict_self(linux_fd_t const ruleset_fd, uint32_t const flags)
{
	linux_word_t const ret = linux_syscall2((uint32_t)ruleset_fd, flags, linux_syscall_name_landlock_restrict_self);
	linux_error_t const err = linux_get_error(ret);
	return err;
}

//=============================================================================
// Architecture specific syscalls

#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_ARM64) || defined(LINUX_ARCH_RISCV32) || defined(LINUX_ARCH_RISCV64) || defined(LINUX_ARCH_X86)
inline linux_error_t linux_fadvise64_64(linux_fd_t const fd, linux_loff_t const offset, linux_loff_t const len, int const advice)
{
#if defined(LINUX_ARCH_ARM_EABI)
	linux_word_t const ret = linux_syscall6((uint32_t)fd, (unsigned int)advice, LINUX_EXPAND(offset), LINUX_EXPAND(len), linux_syscall_name_fadvise64_64);
#elif defined(LINUX_ARCH_RISCV32) || defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall6((uint32_t)fd, LINUX_EXPAND(offset), LINUX_EXPAND(len), (unsigned int)advice, linux_syscall_name_fadvise64_64);
#else
	linux_word_t const ret = linux_syscall4((uint32_t)fd, (uint64_t)offset, (uint64_t)len, (unsigned int)advice, linux_syscall_name_fadvise64_64);
#endif
	linux_error_t const err = linux_get_error(ret);
	return err;
}
#endif

#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_ARM64) || defined(LINUX_ARCH_RISCV32) || defined(LINUX_ARCH_RISCV64) || defined(LINUX_ARCH_X32) || defined(LINUX_ARCH_X86_64)
inline linux_error_t linux_semop(int const semid, struct linux_sembuf* const tsops, unsigned int const nsops) // DEPRECATED: use linux_semtimedop
{
	linux_word_t const ret = linux_syscall3((unsigned int)semid, (uintptr_t)tsops, nsops, linux_syscall_name_semop);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_accept(linux_fd_t const fd, struct linux_sockaddr* const upeer_sockaddr, int* const upeer_addrlen, linux_fd_t* const result) // DEPRECATED: use linux_accept4
{
	linux_word_t const ret = linux_syscall3((uint32_t)fd, (uintptr_t)upeer_sockaddr, (uintptr_t)upeer_addrlen, linux_syscall_name_accept);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}
inline linux_error_t linux_kexec_file_load(linux_fd_t const kernel_fd, linux_fd_t const initrd_fd, linux_uword_t const cmdline_len, char const* const cmdline_ptr, linux_uword_t const flags)
{
	linux_word_t const ret = linux_syscall5((uint32_t)kernel_fd, (uint32_t)initrd_fd, cmdline_len, (uintptr_t)cmdline_ptr, flags, linux_syscall_name_kexec_file_load);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
#endif

#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_ARM64) || defined(LINUX_ARCH_RISCV64) || defined(LINUX_ARCH_X86) || defined(LINUX_ARCH_X32) || defined(LINUX_ARCH_X86_64)
inline linux_error_t linux_newfstat(linux_fd_t const fd, struct linux_stat* const statbuf) // DEPRECATED: use linux_statx
{
	linux_word_t const ret = linux_syscall2((uint32_t)fd, (uintptr_t)statbuf, linux_syscall_name_newfstat);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_truncate(char const* const path, linux_word_t const length)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)path, (linux_uword_t)length, linux_syscall_name_truncate);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_ftruncate(linux_fd_t const fd, linux_uword_t const length)
{
	linux_word_t const ret = linux_syscall2((uint32_t)fd, length, linux_syscall_name_ftruncate);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_lseek(linux_fd_t const fd, linux_off_t const offset, unsigned int const whence, linux_off_t* const result)
{
	linux_word_t const ret = linux_syscall3((uint32_t)fd, (linux_uword_t)offset, whence, linux_syscall_name_lseek);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_off_t)ret;
	return err;
}
inline linux_error_t linux_statfs(char const* const pathname, struct linux_statfs* const buf)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)pathname, (uintptr_t)buf, linux_syscall_name_statfs);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_fstatfs(linux_fd_t const fd, struct linux_statfs* const buf)
{
	linux_word_t const ret = linux_syscall2((uint32_t)fd, (uintptr_t)buf, linux_syscall_name_fstatfs);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_fcntl(linux_fd_t const fd, unsigned int const cmd, linux_uword_t const arg, linux_word_t* const result) // DEPRECATED ON 32 BIT: use linux_fcntl64
{
	linux_word_t const ret = linux_syscall3((uint32_t)fd, cmd, arg, linux_syscall_name_fcntl);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_wait4(linux_pid_t const upid, int* const stat_addr, int const options, struct linux_rusage* const ru, linux_word_t* const result) // DEPRECATED: use linux_waitid
{
	linux_word_t const ret = linux_syscall4((uint32_t)upid, (uintptr_t)stat_addr, (unsigned int)options, (uintptr_t)ru, linux_syscall_name_wait4);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_gettimeofday(struct linux_old_timeval* const tv, struct linux_timezone* const tz) // DEPRECATED: use linux_clock_gettime
{
	linux_word_t const ret = linux_syscall2((uintptr_t)tv, (uintptr_t)tz, linux_syscall_name_gettimeofday);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_settimeofday(struct linux_old_timeval* const tv, struct linux_timezone* const tz) // DEPRECATED: use linux_clock_settime
{
	linux_word_t const ret = linux_syscall2((uintptr_t)tv, (uintptr_t)tz, linux_syscall_name_settimeofday);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
#endif

#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_ARM64) || defined(LINUX_ARCH_X86) || defined(LINUX_ARCH_X32) || defined(LINUX_ARCH_X86_64)
inline linux_error_t linux_renameat(linux_fd_t const olddfd, char const* const oldname, linux_fd_t const newdfd, char const* const newname) // DEPRECATED: use linux_renameat2
{
	linux_word_t const ret = linux_syscall4((uint32_t)olddfd, (uintptr_t)oldname, (uint32_t)newdfd, (uintptr_t)newname, linux_syscall_name_renameat);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
#endif

#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_X86) || defined(LINUX_ARCH_X32) || defined(LINUX_ARCH_X86_64)
inline linux_error_t linux_fork(linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_fork);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_open(char const* const filename, int const flags, linux_umode_t const mode, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)filename, (unsigned int)flags, mode, linux_syscall_name_open);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_creat(char const* const pathname, linux_umode_t const mode, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)pathname, mode, linux_syscall_name_creat);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_link(char const* const oldname, char const* const newname)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)oldname, (uintptr_t)newname, linux_syscall_name_link);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_unlink(char const* const pathname) // DEPRECATED: use linux_unlinkat
{
	linux_word_t const ret = linux_syscall1((uintptr_t)pathname, linux_syscall_name_unlink);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_mknod(char const* const filename, linux_umode_t const mode, unsigned int const dev) // DEPRECATED: use linux_mknodat
{
	linux_word_t const ret = linux_syscall3((uintptr_t)filename, mode, dev, linux_syscall_name_mknod);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_chmod(char const* const filename, linux_umode_t const mode)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)filename, mode, linux_syscall_name_chmod);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_pause(void)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_pause);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_access(char const* const filename, int const mode)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)filename, (unsigned int)mode, linux_syscall_name_access);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_rename(char const* const oldname, char const* const newname)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)oldname, (uintptr_t)newname, linux_syscall_name_rename);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_mkdir(char const* const pathname, linux_umode_t const mode)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)pathname, mode, linux_syscall_name_mkdir);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_rmdir(char const* const pathname)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)pathname, linux_syscall_name_rmdir);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_pipe(int* const fildes)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)fildes, linux_syscall_name_pipe);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_ustat(unsigned int const dev, struct linux_ustat* const ubuf)
{
	linux_word_t const ret = linux_syscall2(dev, (uintptr_t)ubuf, linux_syscall_name_ustat);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_dup2(linux_fd_t const oldfd, linux_fd_t const newfd, int* const result)
{
	linux_word_t const ret = linux_syscall2((uint32_t)oldfd, (uint32_t)newfd, linux_syscall_name_dup2);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_getpgrp(int* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_getpgrp);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_symlink(char const* const oldname, char const* const newname)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)oldname, (uintptr_t)newname, linux_syscall_name_symlink);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_readlink(char const* const path, char* const buf, int const bufsiz, int* const result)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)path, (uintptr_t)buf, (unsigned int)bufsiz, linux_syscall_name_readlink);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_newstat(char const* const filename, struct linux_stat* const statbuf)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)filename, (uintptr_t)statbuf, linux_syscall_name_newstat);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_newlstat(char const* const filename, struct linux_stat* const statbuf)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)filename, (uintptr_t)statbuf, linux_syscall_name_newlstat);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_sysfs(int const option, linux_uword_t const arg1, linux_uword_t const arg2, int* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)option, arg1, arg2, linux_syscall_name_sysfs);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_getdents(linux_fd_t const fd, struct linux_dirent* const dirent, unsigned int const count, int* const result) // DEPRECATED: use linux_getdents64
{
	linux_word_t const ret = linux_syscall3((uint32_t)fd, (uintptr_t)dirent, count, linux_syscall_name_getdents);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_lchown(char const* const filename, linux_uid_t const user, linux_gid_t const group)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)filename, user, group, linux_syscall_name_lchown);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_chown(char const* const filename, linux_uid_t const user, linux_gid_t const group)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)filename, user, group, linux_syscall_name_chown);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_inotify_init(linux_fd_t* const result) // DEPRECATED: use linux_inotify_init1
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_inotify_init);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}
inline linux_error_t linux_eventfd(unsigned int const count, linux_fd_t* const result) // DEPRECATED: use linux_eventfd2
{
	linux_word_t const ret = linux_syscall1(count, linux_syscall_name_eventfd);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}
#endif

#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_RISCV32) || defined(LINUX_ARCH_X86)
inline linux_error_t linux_fcntl64(linux_fd_t const fd, unsigned int const cmd, linux_uword_t const arg, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall3((uint32_t)fd, cmd, arg, linux_syscall_name_fcntl64);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_statfs64(char const* const pathname, linux_size_t const sz, struct linux_statfs64* const buf)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)pathname, sz, (uintptr_t)buf, linux_syscall_name_statfs64);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_fstatfs64(linux_fd_t const fd, linux_size_t const sz, struct linux_statfs64* const buf)
{
	linux_word_t const ret = linux_syscall3((uint32_t)fd, sz, (uintptr_t)buf, linux_syscall_name_fstatfs64);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_truncate64(char const* const path, linux_loff_t const length)
{
#if defined(LINUX_ARCH_ARM_EABI)
	linux_word_t const ret = linux_syscall4((uintptr_t)path, 0, LINUX_EXPAND(length), linux_syscall_name_truncate64);
#elif defined(LINUX_ARCH_RISCV32) || defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall3((uintptr_t)path, LINUX_EXPAND(length), linux_syscall_name_truncate64);
#else
	linux_word_t const ret = linux_syscall2((uintptr_t)path, (uint64_t)length, linux_syscall_name_truncate64);
#endif
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_ftruncate64(linux_fd_t const fd, linux_loff_t const length)
{
#if defined(LINUX_ARCH_ARM_EABI)
	linux_word_t const ret = linux_syscall4((uint32_t)fd, 0, LINUX_EXPAND(length), linux_syscall_name_ftruncate64);
#elif defined(LINUX_ARCH_RISCV32) || defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall3((uint32_t)fd, LINUX_EXPAND(length), linux_syscall_name_ftruncate64);
#else
	linux_word_t const ret = linux_syscall2((uint32_t)fd, (uint64_t)length, linux_syscall_name_ftruncate64);
#endif
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_llseek(linux_fd_t const fd, linux_uword_t const offset_high, linux_uword_t const offset_low, linux_loff_t* const result, unsigned int const whence)
{
	linux_word_t const ret = linux_syscall5((uint32_t)fd, offset_high, offset_low, (uintptr_t)result, whence, linux_syscall_name_llseek);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_fstatat64(linux_fd_t const dfd, char const* const filename, struct linux_stat64* const statbuf, int const flag)
{
	linux_word_t const ret = linux_syscall4((uint32_t)dfd, (uintptr_t)filename, (uintptr_t)statbuf, (unsigned int)flag, linux_syscall_name_fstatat64);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_fstat64(linux_uword_t const fd, struct linux_stat64* const statbuf)
{
	linux_word_t const ret = linux_syscall2(fd, (uintptr_t)statbuf, linux_syscall_name_fstat64);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
#endif

#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_X86)
inline linux_error_t linux_adjtimex_time32(struct linux_timex32* const utp, int* const result)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)utp, linux_syscall_name_adjtimex_time32);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_sched_rr_get_interval_time32(linux_pid_t const pid, struct linux_timespec32* const interval)
{
	linux_word_t const ret = linux_syscall2((uint32_t)pid, (uintptr_t)interval, linux_syscall_name_sched_rr_get_interval_time32);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_futex_time32(uint32_t* const uaddr, int const op, uint32_t const val, struct linux_timespec32* const utime, uint32_t* const uaddr2, uint32_t const val3, linux_word_t* const result) // DEPRECATED: use linux_futex
{
	linux_word_t const ret = linux_syscall6((uintptr_t)uaddr, (unsigned int)op, val, (uintptr_t)utime, (uintptr_t)uaddr2, val3, linux_syscall_name_futex_time32);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_nanosleep_time32(struct linux_timespec32 const* const rqtp, struct linux_timespec32* const rmtp)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)rqtp, (uintptr_t)rmtp, linux_syscall_name_nanosleep_time32);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_timer_settime32(linux_timer_t const timer_id, int const flags, struct linux_itimerspec32* const new, struct linux_itimerspec32* const old)
{
	linux_word_t const ret = linux_syscall4((unsigned int)timer_id, (unsigned int)flags, (uintptr_t)new, (uintptr_t)old, linux_syscall_name_timer_settime32);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_timer_gettime32(linux_timer_t const timer_id, struct linux_itimerspec32* const setting)
{
	linux_word_t const ret = linux_syscall2((unsigned int)timer_id, (uintptr_t)setting, linux_syscall_name_timer_gettime32);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_clock_settime32(linux_clockid_t const which_clock, struct linux_timespec32* const tp)
{
	linux_word_t const ret = linux_syscall2((unsigned int)which_clock, (uintptr_t)tp, linux_syscall_name_clock_settime32);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_clock_gettime32(linux_clockid_t const which_clock, struct linux_timespec32* const tp)
{
	linux_word_t const ret = linux_syscall2((unsigned int)which_clock, (uintptr_t)tp, linux_syscall_name_clock_gettime32);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_clock_getres_time32(linux_clockid_t const which_clock, struct linux_timespec32* const tp)
{
	linux_word_t const ret = linux_syscall2((unsigned int)which_clock, (uintptr_t)tp, linux_syscall_name_clock_getres_time32);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_clock_nanosleep_time32(linux_clockid_t const which_clock, int const flags, struct linux_timespec32 const* const rqtp, struct linux_timespec32* const rmtp)
{
	linux_word_t const ret = linux_syscall4((unsigned int)which_clock, (unsigned int)flags, (uintptr_t)rqtp, (uintptr_t)rmtp, linux_syscall_name_clock_nanosleep_time32);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_utimes_time32(char const* const filename, struct linux_timeval32* const t)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)filename, (uintptr_t)t, linux_syscall_name_utimes_time32);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_mq_timedsend_time32(linux_mqd_t const mqdes, char const* const u_msg_ptr, unsigned int const msg_len, unsigned int const msg_prio, struct linux_timespec32 const* const u_abs_timeout)
{
	linux_word_t const ret = linux_syscall5((unsigned int)mqdes, (uintptr_t)u_msg_ptr, msg_len, msg_prio, (uintptr_t)u_abs_timeout, linux_syscall_name_mq_timedsend_time32);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_mq_timedreceive_time32(linux_mqd_t const mqdes, char* const u_msg_ptr, unsigned int const msg_len, unsigned int* const u_msg_prio, struct linux_timespec32 const* const u_abs_timeout, int* const result)
{
	linux_word_t const ret = linux_syscall5((unsigned int)mqdes, (uintptr_t)u_msg_ptr, msg_len, (uintptr_t)u_msg_prio, (uintptr_t)u_abs_timeout, linux_syscall_name_mq_timedreceive_time32);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_futimesat_time32(linux_fd_t const dfd, char const* const filename, struct linux_timeval32* const t)
{
	linux_word_t const ret = linux_syscall3((uint32_t)dfd, (uintptr_t)filename, (uintptr_t)t, linux_syscall_name_futimesat_time32);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_utimensat_time32(linux_fd_t const dfd, char const* const filename, struct linux_timespec32* const t, int const flags)
{
	linux_word_t const ret = linux_syscall4((uint32_t)dfd, (uintptr_t)filename, (uintptr_t)t, (unsigned int)flags, linux_syscall_name_utimensat_time32);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_timerfd_settime32(linux_fd_t const ufd, int const flags, struct linux_itimerspec32 const* const utmr, struct linux_itimerspec32* const otmr)
{
	linux_word_t const ret = linux_syscall4((uint32_t)ufd, (unsigned int)flags, (uintptr_t)utmr, (uintptr_t)otmr, linux_syscall_name_timerfd_settime32);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_timerfd_gettime32(linux_fd_t const ufd, struct linux_itimerspec32* const otmr)
{
	linux_word_t const ret = linux_syscall2((uint32_t)ufd, (uintptr_t)otmr, linux_syscall_name_timerfd_gettime32);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_recvmmsg_time32(linux_fd_t const fd, struct linux_mmsghdr* const mmsg, unsigned int const vlen, unsigned int const flags, struct linux_timespec32* const timeout, int* const result)
{
	linux_word_t const ret = linux_syscall5((uint32_t)fd, (uintptr_t)mmsg, vlen, flags, (uintptr_t)timeout, linux_syscall_name_recvmmsg_time32);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_clock_adjtime32(linux_clockid_t const which_clock, struct linux_timex32* const utp, int* const result)
{
	linux_word_t const ret = linux_syscall2((unsigned int)which_clock, (uintptr_t)utp, linux_syscall_name_clock_adjtime32);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_sendfile(linux_fd_t const out_fd, linux_fd_t const in_fd, linux_off_t* const offset, linux_size_t const count, linux_ssize_t* const result) // DEPRECATED: use linux_sendfile64
{
	linux_word_t const ret = linux_syscall4((uint32_t)out_fd, (uint32_t)in_fd, (uintptr_t)offset, count, linux_syscall_name_sendfile);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_ssize_t)ret;
	return err;
}
inline linux_error_t linux_lchown16(char const* const filename, linux_old_uid_t const user, linux_old_gid_t const group)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)filename, user, group, linux_syscall_name_lchown16);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_setuid16(linux_old_uid_t const uid)
{
	linux_word_t const ret = linux_syscall1(uid, linux_syscall_name_setuid16);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_getuid16(linux_old_uid_t* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_getuid16);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_old_uid_t)ret;
	return err;
}
inline linux_error_t linux_nice(int const increment, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall1((unsigned int)increment, linux_syscall_name_nice);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_setgid16(linux_old_gid_t const gid)
{
	linux_word_t const ret = linux_syscall1(gid, linux_syscall_name_setgid16);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_getgid16(linux_old_gid_t* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_getgid16);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_old_gid_t)ret;
	return err;
}
inline linux_error_t linux_geteuid16(linux_old_uid_t* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_geteuid16);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_old_uid_t)ret;
	return err;
}
inline linux_error_t linux_getegid16(linux_old_gid_t* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_getegid16);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_old_gid_t)ret;
	return err;
}
inline linux_error_t linux_setreuid16(linux_old_uid_t const ruid, linux_old_uid_t const euid)
{
	linux_word_t const ret = linux_syscall2(ruid, euid, linux_syscall_name_setreuid16);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_setregid16(linux_old_gid_t const rgid, linux_old_gid_t const egid)
{
	linux_word_t const ret = linux_syscall2(rgid, egid, linux_syscall_name_setregid16);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_getgroups16(int const gidsetsize, linux_old_gid_t* const grouplist, int* const result)
{
	linux_word_t const ret = linux_syscall2((unsigned int)gidsetsize, (uintptr_t)grouplist, linux_syscall_name_getgroups16);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_setgroups16(int const gidsetsize, linux_old_gid_t* const grouplist)
{
	linux_word_t const ret = linux_syscall2((unsigned int)gidsetsize, (uintptr_t)grouplist, linux_syscall_name_setgroups16);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_uselib(char const* const library)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)library, linux_syscall_name_uselib);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_fchown16(linux_fd_t const fd, linux_old_uid_t const user, linux_old_gid_t const group)
{
	linux_word_t const ret = linux_syscall3((uint32_t)fd, user, group, linux_syscall_name_fchown16);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_bdflush(int const func, linux_word_t const data)
{
	linux_word_t const ret = linux_syscall2((unsigned int)func, (linux_uword_t)data, linux_syscall_name_bdflush);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_setfsuid16(linux_old_uid_t const uid, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall1(uid, linux_syscall_name_setfsuid16);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_setfsgid16(linux_old_gid_t const gid, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall1(gid, linux_syscall_name_setfsgid16);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_setresuid16(linux_old_uid_t const ruid, linux_old_uid_t const euid, linux_old_uid_t const suid)
{
	linux_word_t const ret = linux_syscall3(ruid, euid, suid, linux_syscall_name_setresuid16);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_getresuid16(linux_old_uid_t* const ruidp, linux_old_uid_t* const euidp, linux_old_uid_t* const suidp)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)ruidp, (uintptr_t)euidp, (uintptr_t)suidp, linux_syscall_name_getresuid16);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_setresgid16(linux_old_gid_t const rgid, linux_old_gid_t const egid, linux_old_gid_t const sgid)
{
	linux_word_t const ret = linux_syscall3(rgid, egid, sgid, linux_syscall_name_setresgid16);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_getresgid16(linux_old_gid_t* const rgidp, linux_old_gid_t* const egidp, linux_old_gid_t* const sgidp)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)rgidp, (uintptr_t)egidp, (uintptr_t)sgidp, linux_syscall_name_getresgid16);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_chown16(char const* const filename, linux_old_uid_t const user, linux_old_gid_t const group)
{
	linux_word_t const ret = linux_syscall3((uintptr_t)filename, user, group, linux_syscall_name_chown16);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_mmap_pgoff(linux_uword_t const addr, linux_uword_t const len, linux_uword_t const prot, linux_uword_t const flags, linux_uword_t const fd, linux_uword_t const pgoff, linux_uword_t* const result)
{
	linux_word_t const ret = linux_syscall6(addr, len, prot, flags, fd, pgoff, linux_syscall_name_mmap_pgoff);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_uword_t)ret;
	return err;
}
inline linux_error_t linux_stat64(char const* const filename, struct linux_stat64* const statbuf)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)filename, (uintptr_t)statbuf, linux_syscall_name_stat64);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_lstat64(char const* const filename, struct linux_stat64* const statbuf)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)filename, (uintptr_t)statbuf, linux_syscall_name_lstat64);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
#endif

#if defined(LINUX_ARCH_ARM_EABI)
inline linux_error_t linux_vfork(linux_word_t* const result) // DEPRECATED: use linux_clone3
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_vfork);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_old_msgctl(int const msqid, int const cmd, struct linux_msqid64_ds* const buf, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)msqid, (unsigned int)cmd, (uintptr_t)buf, linux_syscall_name_old_msgctl);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_old_semctl(int const semid, int const semnum, int const cmd, linux_uword_t const arg, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall4((unsigned int)semid, (unsigned int)semnum, (unsigned int)cmd, arg, linux_syscall_name_old_semctl);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_old_shmctl(int const shmid, int const cmd, struct linux_shmid64_ds* const buf, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)shmid, (unsigned int)cmd, (uintptr_t)buf, linux_syscall_name_old_shmctl);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_semtimedop_time32(int const semid, struct linux_sembuf* const tsems, unsigned int const nsops, struct linux_timespec32 const* const timeout)
{
	linux_word_t const ret = linux_syscall4((unsigned int)semid, (uintptr_t)tsems, nsops, (uintptr_t)timeout, linux_syscall_name_semtimedop_time32);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_pciconfig_iobase(linux_word_t const which, linux_uword_t const bus, linux_uword_t const devfn, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall3((linux_uword_t)which, bus, devfn, linux_syscall_name_pciconfig_iobase);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_pciconfig_read(linux_uword_t const bus, linux_uword_t const dfn, linux_uword_t const off, linux_uword_t const len, void* const buf)
{
	linux_word_t const ret = linux_syscall5(bus, dfn, off, len, (uintptr_t)buf, linux_syscall_name_pciconfig_read);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_pciconfig_write(linux_uword_t const bus, linux_uword_t const dfn, linux_uword_t const off, linux_uword_t const len, void* const buf)
{
	linux_word_t const ret = linux_syscall5(bus, dfn, off, len, (uintptr_t)buf, linux_syscall_name_pciconfig_write);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_send(linux_fd_t const fd, void* const buff, linux_size_t const len, unsigned int const flags, int* const result)
{
	linux_word_t const ret = linux_syscall4((uint32_t)fd, (uintptr_t)buff, len, flags, linux_syscall_name_send);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_recv(linux_fd_t const fd, void* const ubuf, linux_size_t const size, unsigned int const flags, int* const result)
{
	linux_word_t const ret = linux_syscall4((uint32_t)fd, (uintptr_t)ubuf, size, flags, linux_syscall_name_recv);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_breakpoint(void)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_breakpoint);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_cacheflush(linux_uword_t const start, linux_uword_t const end, int const flags)
{
	linux_word_t const ret = linux_syscall3(start, end, (unsigned int)flags, linux_syscall_name_cacheflush);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_usr26(void)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_usr26);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_usr32(void)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_usr32);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_set_tls(linux_uword_t const val)
{
	linux_word_t const ret = linux_syscall1(val, linux_syscall_name_set_tls);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_get_tls(linux_uword_t* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_get_tls);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_uword_t)ret;
	return err;
}
#endif

#if defined(LINUX_ARCH_ARM64) || defined(LINUX_ARCH_RISCV32) || defined(LINUX_ARCH_RISCV64) || defined(LINUX_ARCH_X86) || defined(LINUX_ARCH_X32) || defined(LINUX_ARCH_X86_64)
inline linux_error_t linux_memfd_secret(unsigned int const flags, linux_fd_t* const result)
{
	linux_word_t const ret = linux_syscall1(flags, linux_syscall_name_memfd_secret);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_fd_t)ret;
	return err;
}
inline linux_error_t linux_msgctl(int const msqid, int const cmd, struct linux_msqid64_ds* const buf, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)msqid, (unsigned int)cmd, (uintptr_t)buf, linux_syscall_name_msgctl);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_semctl(int const semid, int const semnum, int const cmd, linux_uword_t const arg, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall4((unsigned int)semid, (unsigned int)semnum, (unsigned int)cmd, arg, linux_syscall_name_semctl);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_shmctl(int const shmid, int const cmd, struct linux_shmid64_ds* const buf, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall3((unsigned int)shmid, (unsigned int)cmd, (uintptr_t)buf, linux_syscall_name_shmctl);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
#endif

#if defined(LINUX_ARCH_ARM64) || defined(LINUX_ARCH_RISCV32) || defined(LINUX_ARCH_RISCV64) || defined(LINUX_ARCH_X32) || defined(LINUX_ARCH_X86_64)
inline linux_error_t linux_mmap(linux_uword_t const addr, linux_uword_t const len, linux_uword_t const prot, linux_uword_t const flags, linux_uword_t const fd, linux_uword_t const off, linux_uword_t* const result)
{
	linux_word_t const ret = linux_syscall6(addr, len, prot, flags, fd, off, linux_syscall_name_mmap);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_uword_t)ret;
	return err;
}
#endif

#if defined(LINUX_ARCH_ARM64) || defined(LINUX_ARCH_RISCV64) || defined(LINUX_ARCH_X32) || defined(LINUX_ARCH_X86_64)
inline linux_error_t linux_adjtimex(struct linux_timex* const txc_p, int* const result) // DEPRECATED: use linux_clock_adjtime
{
	linux_word_t const ret = linux_syscall1((uintptr_t)txc_p, linux_syscall_name_adjtimex);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_nanosleep(struct linux_timespec const* const rqtp, struct linux_timespec* const rmtp) // DEPRECATED: use linux_clock_nanosleep
{
	linux_word_t const ret = linux_syscall2((uintptr_t)rqtp, (uintptr_t)rmtp, linux_syscall_name_nanosleep);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_newfstatat(linux_fd_t const dfd, char const* const filename, struct linux_stat* const statbuf, int const flag)
{
	linux_word_t const ret = linux_syscall4((uint32_t)dfd, (uintptr_t)filename, (uintptr_t)statbuf, (unsigned int)flag, linux_syscall_name_newfstatat);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
#endif

#if defined(LINUX_ARCH_RISCV32) || defined(LINUX_ARCH_RISCV64)
inline linux_error_t linux_riscv_flush_icache(uintptr_t const start, uintptr_t const end, uintptr_t const flags)
{
	linux_word_t const ret = linux_syscall3(start, end, flags, linux_syscall_name_riscv_flush_icache);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
#endif

#if defined(LINUX_ARCH_X86) || defined(LINUX_ARCH_X32) || defined(LINUX_ARCH_X86_64)
inline linux_error_t linux_alarm(unsigned int const seconds, unsigned int* const result)
{
	linux_word_t const ret = linux_syscall1(seconds, linux_syscall_name_alarm);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (unsigned int)ret;
	return err;
}
inline linux_error_t linux_modify_ldt(int const func, void* const ptr, linux_uword_t const bytecount, int* const result)
{
	int const ret = (int)linux_syscall3((unsigned int)func, (uintptr_t)ptr, bytecount, linux_syscall_name_modify_ldt);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_arch_prctl(int const option, linux_uword_t const arg2)
{
	linux_word_t const ret = linux_syscall2((unsigned int)option, arg2, linux_syscall_name_arch_prctl);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_iopl(unsigned int const level)
{
	linux_word_t const ret = linux_syscall1(level, linux_syscall_name_iopl);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_ioperm(linux_uword_t const from, linux_uword_t const num, int const turn_on)
{
	linux_word_t const ret = linux_syscall3(from, num, (unsigned int)turn_on, linux_syscall_name_ioperm);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_fadvise64(linux_fd_t const fd, linux_loff_t const offset, linux_size_t const len, int const advice)
{
#if defined(LINUX_ARCH_X86)
	linux_word_t const ret = linux_syscall5((uint32_t)fd, LINUX_EXPAND(offset), len, (unsigned int)advice, linux_syscall_name_fadvise64);
#else
	linux_word_t const ret = linux_syscall4((uint32_t)fd, (uint64_t)offset, len, (unsigned int)advice, linux_syscall_name_fadvise64);
#endif
	linux_error_t const err = linux_get_error(ret);
	return err;
}
#endif

#if defined(LINUX_ARCH_X86)
inline linux_error_t linux_waitpid(linux_pid_t const pid, int* const stat_addr, int const options, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall3((uint32_t)pid, (uintptr_t)stat_addr, (unsigned int)options, linux_syscall_name_waitpid);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_stat(char const* const filename, struct linux_old_kernel_stat* const statbuf)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)filename, (uintptr_t)statbuf, linux_syscall_name_stat);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_oldumount(char* const name)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)name, linux_syscall_name_oldumount);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_time32(linux_time32_t* const tloc, linux_time32_t* const result)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)tloc, linux_syscall_name_time32);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_time32_t)ret;
	return err;
}
inline linux_error_t linux_stime32(linux_time32_t* const tptr)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)tptr, linux_syscall_name_stime32);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_utime32(char const* const filename, struct linux_utimbuf32* const t)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)filename, (uintptr_t)t, linux_syscall_name_utime32);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_fstat(linux_fd_t const fd, struct linux_old_kernel_stat* const statbuf)
{
	linux_word_t const ret = linux_syscall2((uint32_t)fd, (uintptr_t)statbuf, linux_syscall_name_fstat);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_olduname(struct linux_oldold_utsname* const name)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)name, linux_syscall_name_olduname);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_sgetmask(int* const result)
{
	linux_word_t const ret = linux_syscall0(linux_syscall_name_sgetmask);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_ssetmask(int const newmask, int* const result)
{
	linux_word_t const ret = linux_syscall1((unsigned int)newmask, linux_syscall_name_ssetmask);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_old_getrlimit(unsigned int const resource, struct linux_rlimit* const rlim)
{
	linux_word_t const ret = linux_syscall2(resource, (uintptr_t)rlim, linux_syscall_name_old_getrlimit);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_lstat(char const* const filename, struct linux_old_kernel_stat* const statbuf)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)filename, (uintptr_t)statbuf, linux_syscall_name_lstat);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_old_readdir(linux_fd_t const fd, struct linux_old_linux_dirent* const dirent, unsigned int const count)
{
	linux_word_t const ret = linux_syscall3((uint32_t)fd, (uintptr_t)dirent, count, linux_syscall_name_old_readdir);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_old_mmap(struct linux_mmap_arg_struct* const arg, linux_uword_t* const result)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)arg, linux_syscall_name_old_mmap);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_uword_t)ret;
	return err;
}
inline linux_error_t linux_socketcall(int const call, linux_uword_t* const args, int* const result)
{
	linux_word_t const ret = linux_syscall2((unsigned int)call, (uintptr_t)args, linux_syscall_name_socketcall);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (int)ret;
	return err;
}
inline linux_error_t linux_uname(struct linux_old_utsname* const name)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)name, linux_syscall_name_uname);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_vm86old(struct linux_vm86_struct* const user_vm86)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)user_vm86, linux_syscall_name_vm86old);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_ipc(unsigned int const call, int const first, linux_uword_t const second, linux_uword_t const third, void* const ptr, linux_word_t const fifth, linux_word_t* const result)
{
	linux_word_t const ret = linux_syscall6(call, (unsigned int)first, second, third, (uintptr_t)ptr, (linux_uword_t)fifth, linux_syscall_name_ipc);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_word_t)ret;
	return err;
}
inline linux_error_t linux_vm86(linux_uword_t const cmd, linux_uword_t const arg)
{
	linux_word_t const ret = linux_syscall2(cmd, arg, linux_syscall_name_vm86);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_set_thread_area(struct linux_user_desc* const u_info)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)u_info, linux_syscall_name_set_thread_area);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_get_thread_area(struct linux_user_desc* const u_info)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)u_info, linux_syscall_name_get_thread_area);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
#endif

#if defined(LINUX_ARCH_X32) || defined(LINUX_ARCH_X86_64)
inline linux_error_t linux_time(linux_old_time_t* const tloc, linux_old_time_t* const result)
{
	linux_word_t const ret = linux_syscall1((uintptr_t)tloc, linux_syscall_name_time);
	linux_error_t const err = linux_get_error(ret);
	if (!err && result)
		*result = (linux_old_time_t)ret;
	return err;
}
inline linux_error_t linux_utime(char* const filename, struct linux_utimbuf* const times)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)filename, (uintptr_t)times, linux_syscall_name_utime);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_utimes(char* const filename, struct linux_old_timeval* const utimes)
{
	linux_word_t const ret = linux_syscall2((uintptr_t)filename, (uintptr_t)utimes, linux_syscall_name_utimes);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
inline linux_error_t linux_futimesat(linux_fd_t const dfd, char const* const filename, struct linux_old_timeval* const utimes)
{
	linux_word_t const ret = linux_syscall3((uint32_t)dfd, (uintptr_t)filename, (uintptr_t)utimes, linux_syscall_name_futimesat);
	linux_error_t const err = linux_get_error(ret);
	return err;
}
#endif

//=============================================================================
// x86 vsyscalls

#if defined(LINUX_ARCH_X86)
// TODO: Add vsyscalls for x86, except for clone (see the manpage).
#endif

//=============================================================================
// TODO Helper functions

// Process status bits
// -------------------
// Bits  1- 7: signal number
// Bit      8: core dump
// Bits  9-16: exit code
// Bits 17-32: unknown

static inline uint8_t linux_WEXITSTATUS(int const status)
{
	return (status & 0xFF00) >> 8;
}
static inline uint8_t linux_WTERMSIG(int const status)
{
	return status & 0x7F;
}
static inline uint8_t linux_WSTOPSIG(int const status)
{
	return linux_WEXITSTATUS(status);
}
static inline bool linux_WIFEXITED(int const status)
{
	return !linux_WTERMSIG(status);
}
static inline bool linux_WIFSTOPPED(int const status)
{
	return (status & 0xFF) == 0x7F;
}
static inline bool linux_WIFSIGNALED(int const status)
{
	return (status & 0xFFFF) - 1u < 0xFFu;
}
static inline bool linux_WCOREDUMP(int const status)
{
	return status & 0x80;
}
static inline bool linux_WIFCONTINUED(int const status)
{
	return status == 0xFFFF;
}

static inline bool linux_S_ISLNK(linux_umode_t const m)
{
	return (m & linux_S_IFMT) == linux_S_IFLNK;
}

static inline bool linux_S_ISREG(linux_umode_t const m)
{
	return (m & linux_S_IFMT) == linux_S_IFREG;
}

static inline bool linux_S_ISDIR(linux_umode_t const m)
{
	return (m & linux_S_IFMT) == linux_S_IFDIR;
}

static inline bool linux_S_ISCHR(linux_umode_t const m)
{
	return (m & linux_S_IFMT) == linux_S_IFCHR;
}

static inline bool linux_S_ISBLK(linux_umode_t const m)
{
	return (m & linux_S_IFMT) == linux_S_IFBLK;
}

static inline bool linux_S_ISFIFO(linux_umode_t const m)
{
	return (m & linux_S_IFMT) == linux_S_IFIFO;
}

static inline bool linux_S_ISSOCK(linux_umode_t const m)
{
	return (m & linux_S_IFMT) == linux_S_IFSOCK;
}

#define LINUX_ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
static inline void linux_sigemptyset(linux_sigset_t* const set)
{
	for (size_t i = 0; i < LINUX_ARRAY_SIZE(set->sig); ++i)
		set->sig[i] = 0UL;
}

static inline void linux_sigfillset(linux_sigset_t* const set)
{
	for (size_t i = 0; i < LINUX_ARRAY_SIZE(set->sig); ++i)
		set->sig[i] = (unsigned long)-1; // -1 == ULONG_MAX
}

static inline linux_error_t linux_sigaddset(linux_sigset_t* const set, uint32_t const signum)
{
	if (signum <= 0 || signum > linux_NSIG)
		return linux_EINVAL;
	size_t const word = (size_t)(signum - 1) / (8 * sizeof set->sig[0]); // 8 == CHAR_BIT
	size_t const bit = (size_t)(signum - 1) % (8 * sizeof set->sig[0]); // 8 == CHAR_BIT
	set->sig[word] |= 1UL << bit;
	return 0;
}

static inline linux_error_t linux_sigdelset(linux_sigset_t* const set, uint32_t const signum)
{
	if (signum <= 0 || signum > linux_NSIG)
		return linux_EINVAL;
	size_t const word = (size_t)(signum - 1) / (8 * sizeof set->sig[0]); // 8 == CHAR_BIT
	size_t const bit = (size_t)(signum - 1) % (8 * sizeof set->sig[0]); // 8 == CHAR_BIT
	set->sig[word] &= ~(1UL << bit);
	return 0;
}

static inline linux_error_t linux_sigismember(linux_sigset_t const* const set, uint32_t const signum, bool* const ret)
{
	if (signum <= 0 || signum > linux_NSIG)
		return linux_EINVAL;
	size_t const word = (size_t)(signum - 1) / (8 * sizeof set->sig[0]); // 8 == CHAR_BIT
	size_t const bit = (size_t)(signum - 1) % (8 * sizeof set->sig[0]); // 8 == CHAR_BIT
	*ret = set->sig[word] & (1UL << bit);
	return 0;
}

#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_X86)
static inline void linux_old_sigemptyset(linux_old_sigset_t* const set)
{
	*set = 0;
}

static inline void linux_old_sigfillset(linux_old_sigset_t* const set)
{
	*set = (linux_old_sigset_t)-1;
}

static inline linux_error_t linux_old_sigaddset(linux_old_sigset_t* const set, uint32_t const signum)
{
	if (signum <= 0 || signum > linux_OLD_NSIG)
		return linux_EINVAL;
	_Static_assert(linux_OLD_NSIG <= (8 * sizeof *set), "linux_old_sigset_t is too small"); // 8 == CHAR_BIT
	*set |= 1UL << (signum - 1);
	return 0;
}

static inline linux_error_t linux_old_sigdelset(linux_old_sigset_t* const set, uint32_t const signum)
{
	if (signum <= 0 || signum > linux_OLD_NSIG)
		return linux_EINVAL;
	_Static_assert(linux_OLD_NSIG <= (8 * sizeof *set), "linux_old_sigset_t is too small"); // 8 == CHAR_BIT
	*set &= ~(1UL << (signum - 1));
	return 0;
}

static inline linux_error_t linux_old_sigismember(linux_old_sigset_t const* const set, uint32_t const signum, bool* const ret)
{
	if (signum <= 0 || signum > linux_OLD_NSIG)
		return linux_EINVAL;
	_Static_assert(linux_OLD_NSIG <= (8 * sizeof *set), "linux_old_sigset_t is too small"); // 8 == CHAR_BIT
	*ret = *set & (1UL << (signum - 1));
	return 0;
}
#endif

static inline void linux_FD_ZERO(linux_fd_set* const set)
{
	for (size_t i = 0; i < LINUX_ARRAY_SIZE(set->fds_bits); ++i)
		set->fds_bits[i] = 0UL;
}
#undef LINUX_ARRAY_SIZE

static inline void linux_FD_SET(linux_fd_t const fd, linux_fd_set* const set)
{
	if ((uint32_t)fd >= linux_FD_SETSIZE)
		return;
	set->fds_bits[(uint32_t)fd / (8 * sizeof(long))] |= (1UL << ((uint32_t)fd % (8 * sizeof(long)))); // 8 == CHAR_BIT
}

static inline void linux_FD_CLR(linux_fd_t const fd, linux_fd_set* const set)
{
	if ((uint32_t)fd >= linux_FD_SETSIZE)
		return;
	set->fds_bits[(uint32_t)fd / (8 * sizeof(long))] &= ~(1UL << ((uint32_t)fd % (8 * sizeof(long)))); // 8 == CHAR_BIT
}

static inline bool linux_FD_ISSET(linux_fd_t const fd, linux_fd_set* const set)
{
	if ((uint32_t)fd >= linux_FD_SETSIZE)
		return false;
	return set->fds_bits[(uint32_t)fd / (8 * sizeof(long))] & (1UL << ((uint32_t)fd % (8 * sizeof(long)))); // 8 == CHAR_BIT
}

static inline size_t linux_IP_MSFILTER_SIZE(size_t numsrc)
{
	return sizeof(struct linux_ip_msfilter) - sizeof(uint32_t) + numsrc * sizeof(uint32_t);
}

static inline size_t linux_GROUP_FILTER_SIZE(size_t numsrc)
{
	return sizeof(struct linux_group_filter) - sizeof(struct linux_sockaddr_storage) + numsrc * sizeof(struct linux_sockaddr_storage);
}

static inline bool linux_IN_CLASSA(uint32_t const addr)
{
	return (addr & 0x80000000) == 0;
}

static inline bool linux_IN_CLASSB(uint32_t const addr)
{
	return (addr & 0xc0000000) == 0x80000000;
}

static inline bool linux_IN_CLASSC(uint32_t const addr)
{
	return (addr & 0xe0000000) == 0xc0000000;
}

static inline bool linux_IN_CLASSD(uint32_t const addr)
{
	return (addr & 0xf0000000) == 0xe0000000;
}

static inline bool linux_IN_CLASSE(uint32_t const addr)
{
	return (addr & 0xf0000000) == 0xf0000000;
}

static inline bool linux_IN_MULTICAST(uint32_t const addr)
{
	return linux_IN_CLASSD(addr);
}

static inline bool linux_IN_BADCLASS(uint32_t const addr)
{
	return addr == 0xffffffff;
}

static inline bool linux_IN_EXPERIMENTAL(uint32_t const addr)
{
	return linux_IN_BADCLASS(addr);
}

static inline bool linux_IN_LOOPBACK(uint32_t const addr)
{
	return (addr & 0xff000000) == 0x7f000000;
}

#endif // !HEADER_LIBLINUX_LINUX_H_INCLUDED
