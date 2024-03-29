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

#ifndef HEADER_LIBLINUX_ARM_EABI_STRUCTS_H_INCLUDED
#define HEADER_LIBLINUX_ARM_EABI_STRUCTS_H_INCLUDED

#include <stdint.h>
#include <stdalign.h>

//=============================================================================
// epoll

struct linux_epoll_event
{
	linux_poll_t events;
	uint64_t     data[1];
};

//=============================================================================
// signal

typedef struct
{
	alignas(alignof(linux_clock_t)) unsigned char data[sizeof(linux_clock_t)];
} linux_si_clock_t; // NOTICE: can be memcpy'd into a linux_clock_t
_Static_assert(sizeof(linux_si_clock_t) == sizeof(linux_clock_t), "size of linux_si_clock_t is not equal to size of linux_clock_t");
_Static_assert(alignof(linux_si_clock_t) == alignof(linux_clock_t), "alignment of linux_si_clock_t is not equal to alignment of linux_clock_t");

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
			uint32_t             si_signo;
			uint32_t             si_errno;
			int32_t              si_code;
			union linux_sifields sifields;
		};
		int _si_pad[linux_SI_MAX_SIZE / sizeof(int)];
	};
} linux_siginfo_t;

struct linux_sigaction
{
	union
	{
		linux_sighandler_t   sa_handler;
		void               (*sa_sigaction)(int, struct linux_siginfo*, void*);
	};
	linux_sigset_t     sa_mask;
	uintptr_t          sa_flags;
	linux_sigrestore_t sa_restorer;
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
#if defined(LINUX_ENDIAN_BIG)
	unsigned short st_dev;
	unsigned short _pad1;
#else
	unsigned long st_dev;
#endif
	unsigned long st_ino;
	unsigned short st_mode;
	unsigned short st_nlink;
	unsigned short st_uid;
	unsigned short st_gid;
#if defined(LINUX_ENDIAN_BIG)
	unsigned short st_rdev;
	unsigned short _pad2;
#else
	unsigned long st_rdev;
#endif
	unsigned long st_size;
	unsigned long st_blksize;
	unsigned long st_blocks;
	unsigned long st_atime;
	unsigned long st_atime_nsec;
	unsigned long st_mtime;
	unsigned long st_mtime_nsec;
	unsigned long st_ctime;
	unsigned long st_ctime_nsec;
	unsigned long _unused4;
	unsigned long _unused5;
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
	unsigned char _pad1[4 - sizeof(linux_mode_t)];
	unsigned short seq;
	unsigned short _pad2;
	linux_uword_t _unused1;
	linux_uword_t _unused2;
};
struct linux_shmid64_ds
{
	struct linux_ipc64_perm shm_perm;
	linux_size_t shm_segsz;
	unsigned long shm_atime;
	unsigned long shm_atime_high;
	unsigned long shm_dtime;
	unsigned long shm_dtime_high;
	unsigned long shm_ctime;
	unsigned long shm_ctime_high;
	linux_pid_t shm_cpid;
	linux_pid_t shm_lpid;
	unsigned long shm_nattch;
	unsigned long _unused4;
	unsigned long _unused5;
};
struct linux_msqid64_ds
{
	struct linux_ipc64_perm msg_perm;
	unsigned long msg_stime;
	unsigned long msg_stime_high;
	unsigned long msg_rtime;
	unsigned long msg_rtime_high;
	unsigned long msg_ctime;
	unsigned long msg_ctime_high;
	unsigned long msg_cbytes;
	unsigned long msg_qnum;
	unsigned long  msg_qbytes;
	linux_pid_t msg_lspid;
	linux_pid_t msg_lrpid;
	unsigned long _unused4;
	unsigned long _unused5;
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
	char _f[20 - 2 * sizeof(linux_uword_t) - sizeof(uint32_t)];
};
struct linux_stat64
{
	unsigned long long st_dev;
	unsigned char _pad0[4];
	unsigned long _st_ino;
	unsigned int st_mode;
	unsigned int st_nlink;
	unsigned long st_uid;
	unsigned long st_gid;
	unsigned long long st_rdev;
	unsigned char _pad3[4];
	long long st_size;
	unsigned long st_blksize;
	unsigned long long st_blocks;
	unsigned long st_atime;
	unsigned long st_atime_nsec;
	unsigned long st_mtime;
	unsigned long st_mtime_nsec;
	unsigned long st_ctime;
	unsigned long st_ctime_nsec;
	unsigned long long st_ino;
};
struct linux_statfs64
{
	linux_statfs_word f_type;
	linux_statfs_word f_bsize;
	uint64_t f_blocks;
	uint64_t f_bfree;
	uint64_t f_bavail;
	uint64_t f_files;
	uint64_t f_ffree;
	linux_fsid_t f_fsid;
	linux_statfs_word f_namelen;
	linux_statfs_word f_frsize;
	linux_statfs_word f_flags;
	linux_statfs_word f_spare[4];
};
_Static_assert(sizeof(struct linux_statfs64) == 84 || sizeof(struct linux_statfs64) == 88, "struct linux_statfs64 has wrong size");

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

#endif // !HEADER_LIBLINUX_ARM_EABI_STRUCTS_H_INCLUDED
