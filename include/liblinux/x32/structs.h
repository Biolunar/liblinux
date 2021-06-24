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

#ifndef HEADER_LIBLINUX_X32_STRUCTS_H_INCLUDED
#define HEADER_LIBLINUX_X32_STRUCTS_H_INCLUDED

#include <stddef.h>
#include <stdint.h>
#include <stdalign.h>

//=============================================================================
// epoll

// NOTICE: Technically this struct wants an alignment of 1 but that is not
// possible with standard C, and it doesn't matter in practice since the kernel
// doesn't produce these structs.
struct linux_epoll_event
{
	linux_poll_t  events;
	unsigned char data[sizeof(uint64_t)];
};
_Static_assert(sizeof(struct linux_epoll_event) == sizeof(linux_poll_t) + sizeof(uint64_t), "struct linux_epoll_event has incorrect size");
_Static_assert(offsetof(struct linux_epoll_event, data) == sizeof(linux_poll_t), "struct linux_epoll_event member 'data' is misaligned");

//=============================================================================
// signal

typedef struct
{
	alignas(4) unsigned char data[sizeof(linux_clock_t)];
} linux_si_clock_t; // NOTICE: can be memcpy'd into a linux_clock_t
_Static_assert(sizeof(linux_si_clock_t) == sizeof(linux_clock_t), "size of linux_si_clock_t is not equal to size of linux_clock_t");
_Static_assert(alignof(linux_si_clock_t) == 4, "alignment of linux_si_clock_t is not equal to 4");

union linux_sifields
{
	struct
	{
		linux_pid_t pid;
		linux_uid_t uid;
	} kill;
	struct
	{
		linux_timer_t  tid;
		uint32_t       overrun; // Won't have more than INT_MAX.
		linux_sigval_t sigval;
		int            _sys_private;
	} timer;
	struct
	{
		linux_pid_t    pid;
		linux_uid_t    uid;
		linux_sigval_t sigval;
	} rt;
	struct
	{
		linux_pid_t      pid;
		linux_uid_t      uid;
		uint32_t         status;
		linux_si_clock_t utime;
		linux_si_clock_t stime;
	} sigchld;
	struct
	{
		void* addr;
#define linux_ADDR_BND_PKEY_PAD (alignof(void*) < sizeof(short) ? sizeof(short) : alignof(void*))
		union
		{
			short addr_lsb;
			struct
			{
				char  _dummy_bnd[linux_ADDR_BND_PKEY_PAD];
				void* lower;
				void* upper;
			} addr_bnd;
			struct
			{
				char     _dummy_pkey[linux_ADDR_BND_PKEY_PAD];
				uint32_t pkey;
			} addr_pkey;
		};
#undef linux_ADDR_BND_PKEY_PAD
	} sigfault;
	struct
	{
		linux_si_band_t band;
		linux_fd_t      fd;
	} sigpoll;
	struct
	{
		void*    call_addr;
		uint32_t syscall;
		uint32_t arch;
	} sigsys;
};

typedef struct linux_siginfo
{
	union
	{
		struct
		{
			alignas(8) uint32_t  si_signo;
			uint32_t             si_errno;
			int32_t              si_code;
			union linux_sifields sifields;
		};
		int _si_pad[linux_SI_MAX_SIZE / sizeof(int)];
	};
} linux_siginfo_t;
_Static_assert(alignof(linux_siginfo_t) == 8, "linux_siginfo_t is misaligned");

struct linux_sigaction
{
	union
	{
		linux_sighandler_t   sa_handler;
		void               (*sa_sigaction)(int, struct linux_siginfo*, void*);
	};
	uintptr_t          sa_flags;
	linux_sigrestore_t sa_restorer;
	linux_sigset_t     sa_mask;
};

typedef struct linux_sigaltstack
{
	void*        ss_sp;
	uint32_t     ss_flags;
	linux_size_t ss_size;
} linux_stack_t;

//=============================================================================
// TODO

struct linux_stat
{
	linux_uword_t st_dev;
	linux_uword_t st_ino;
	linux_uword_t st_nlink;
	unsigned int st_mode;
	unsigned int st_uid;
	unsigned int st_gid;
	unsigned int _pad0;
	linux_uword_t st_rdev;
	linux_word_t st_size;
	linux_word_t st_blksize;
	linux_word_t st_blocks;
	linux_uword_t st_atime;
	linux_uword_t st_atime_nsec;
	linux_uword_t st_mtime;
	linux_uword_t st_mtime_nsec;
	linux_uword_t st_ctime;
	linux_uword_t st_ctime_nsec;
	linux_word_t _unused[3];
};
struct linux_statfs
{
	linux_statfs_word f_type;
	linux_statfs_word f_bsize;
	linux_statfs_word f_blocks;
	linux_statfs_word f_bfree;
	linux_statfs_word f_bavail;
	linux_statfs_word f_files;
	linux_statfs_word f_ffree;
	linux_fsid_t f_fsid;
	linux_statfs_word f_namelen;
	linux_statfs_word f_frsize;
	linux_statfs_word f_flags;
	linux_statfs_word f_spare[4];
};
struct linux_ipc64_perm
{
	linux_key_t key;
	linux_uid_t uid;
	linux_gid_t gid;
	linux_uid_t cuid;
	linux_gid_t cgid;
	linux_mode_t mode;
	//unsigned char _pad1[4 - sizeof(linux_mode_t)];
	unsigned short seq;
	unsigned short _pad2;
	linux_uword_t _unused1;
	linux_uword_t _unused2;
};
struct linux_shmid64_ds
{
	struct linux_ipc64_perm shm_perm;
	linux_size_t shm_segsz;
	linux_word_t shm_atime;
	linux_word_t shm_dtime;
	linux_word_t shm_ctime;
	linux_pid_t shm_cpid;
	linux_pid_t shm_lpid;
	linux_uword_t shm_nattch;
	linux_uword_t _unused4;
	linux_uword_t _unused5;
};
struct linux_msqid64_ds
{
	struct linux_ipc64_perm msg_perm;
	linux_word_t msg_stime;
	linux_word_t msg_rtime;
	linux_word_t msg_ctime;
	linux_uword_t msg_cbytes;
	linux_uword_t msg_qnum;
	linux_uword_t msg_qbytes;
	linux_pid_t msg_lspid;
	linux_pid_t msg_lrpid;
	linux_uword_t _unused4;
	linux_uword_t _unused5;
};
struct linux_sysinfo
{
	linux_word_t uptime;
	linux_uword_t loads[3];
	linux_uword_t totalram;
	linux_uword_t freeram;
	linux_uword_t sharedram;
	linux_uword_t bufferram;
	linux_uword_t totalswap;
	linux_uword_t freeswap;
	uint16_t procs;
	uint16_t pad;
	linux_uword_t totalhigh;
	linux_uword_t freehigh;
	uint32_t mem_unit;
	//char _f[20 - 2 * sizeof(linux_uword_t) - sizeof(uint32_t)];
};

//=============================================================================
// termbits

typedef unsigned int linux_tcflag_t;

struct linux_termios
{
	linux_tcflag_t c_iflag;
	linux_tcflag_t c_oflag;
	linux_tcflag_t c_cflag;
	linux_tcflag_t c_lflag;
	linux_cc_t c_line;
	linux_cc_t c_cc[linux_NCCS];
};
struct linux_termios2
{
	linux_tcflag_t c_iflag;
	linux_tcflag_t c_oflag;
	linux_tcflag_t c_cflag;
	linux_tcflag_t c_lflag;
	linux_cc_t c_line;
	linux_cc_t c_cc[linux_NCCS];
	linux_speed_t c_ispeed;
	linux_speed_t c_ospeed;
};

//=============================================================================
// fcntl

struct linux_flock
{
	short l_type;
	short l_whence;
	linux_off_t l_start;
	linux_off_t l_len;
	linux_pid_t l_pid;
};
struct linux_flock64
{
	short l_type;
	short l_whence;
	linux_loff_t l_start;
	linux_loff_t l_len;
	linux_pid_t l_pid;
};

//=============================================================================
// termios

struct linux_termio
{
	unsigned short c_iflag;
	unsigned short c_oflag;
	unsigned short c_cflag;
	unsigned short c_lflag;
	unsigned char c_line;
	unsigned char c_cc[linux_NCC];
};

//=============================================================================
// termiox

struct linux_termiox
{
	uint16_t x_hflag;
	uint16_t x_cflag;
	uint16_t x_rflag[linux_NFF];
	uint16_t x_sflag;
};

//=============================================================================
// evdev

struct linux_input_event
{
	linux_uword_t sec;
	linux_uword_t usec;
	uint16_t type;
	uint16_t code;
	int32_t value;
};

#endif // !HEADER_LIBLINUX_X32_STRUCTS_H_INCLUDED
