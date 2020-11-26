/*
 * Copyright 2018-2020 Mahdi Khanalizadeh
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

#ifndef HEADER_LIBLINUX_RISCV32_STRUCTS_H_INCLUDED
#define HEADER_LIBLINUX_RISCV32_STRUCTS_H_INCLUDED

#include <stdint.h>
#include <stdalign.h>

struct linux_stat
{
	unsigned long st_dev;
	unsigned long st_ino;
	unsigned int st_mode;
	unsigned int st_nlink;
	unsigned int st_uid;
	unsigned int st_gid;
	unsigned long st_rdev;
	unsigned long _pad1;
	long st_size;
	int st_blksize;
	int _pad2;
	long st_blocks;
	long st_atime;
	unsigned long st_atime_nsec;
	long st_mtime;
	unsigned long st_mtime_nsec;
	long st_ctime;
	unsigned long st_ctime_nsec;
	unsigned int _unused4;
	unsigned int _unused5;
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
union linux_sifields
{
	struct
	{
		linux_pid_t pid;
		linux_uid_t uid;
	} kill;
	struct
	{
		linux_timer_t tid;
		int overrun;
		linux_sigval_t sigval;
		int _sys_private;
	} timer;
	struct
	{
		linux_pid_t pid;
		linux_uid_t uid;
		linux_sigval_t sigval;
	} rt;
	struct
	{
		linux_pid_t pid;
		linux_uid_t uid;
		int status;
		linux_kernel_clock_t utime;
		linux_kernel_clock_t stime;
	} sigchld;
	struct
	{
		void* addr;
		union
		{
			short addr_lsb;
			struct
			{
				char _dummy_bnd[alignof(void*) < sizeof(short) ? sizeof(short) : alignof(void*)];
				void* lower;
				void* upper;
			} addr_bnd;
			struct
			{
				char _dummy_pkey[alignof(void*) < sizeof(short) ? sizeof(short) : alignof(void*)];
				uint32_t pkey;
			} addr_pkey;
		};
	} sigfault;
	struct
	{
		long band;
		int fd;
	} sigpoll;
	struct
	{
		void* call_addr;
		int syscall;
		unsigned int arch;
	} sigsys;
};
typedef struct linux_siginfo
{
	union
	{
		struct
		{
			int si_signo;
			int si_errno;
			int si_code;
			union linux_sifields sifields;
		};
		int _si_pad[128 / sizeof(int)];
	};
} linux_siginfo_t;
struct linux_sigaction
{
	linux_sighandler_t sa_handler;
	unsigned long sa_flags;
	linux_sigset_t sa_mask;
};
struct linux_ipc64_perm
{
	linux_key_t key;
	linux_uid_t uid;
	linux_gid_t gid;
	linux_uid_t cuid;
	linux_gid_t cgid;
	linux_kernel_mode_t mode;
	//unsigned char _pad1[4 - sizeof(linux_kernel_mode_t)];
	unsigned short seq;
	unsigned short _pad2;
	linux_kernel_ulong_t _unused1;
	linux_kernel_ulong_t _unused2;
};
struct linux_shmid64_ds
{
	struct linux_ipc64_perm shm_perm;
	linux_size_t shm_segsz;
	long shm_atime;
	long shm_dtime;
	long shm_ctime;
	linux_pid_t shm_cpid;
	linux_pid_t shm_lpid;
	unsigned long shm_nattch;
	unsigned long _unused4;
	unsigned long _unused5;
};
struct linux_msqid64_ds
{
	struct linux_ipc64_perm msg_perm;
	long msg_stime;
	long msg_rtime;
	long msg_ctime;
	unsigned long msg_cbytes;
	unsigned long msg_qnum;
	unsigned long msg_qbytes;
	linux_pid_t msg_lspid;
	linux_pid_t msg_lrpid;
	unsigned long _unused4;
	unsigned long _unused5;
};
struct linux_sysinfo
{
	linux_kernel_long_t uptime;
	linux_kernel_ulong_t loads[3];
	linux_kernel_ulong_t totalram;
	linux_kernel_ulong_t freeram;
	linux_kernel_ulong_t sharedram;
	linux_kernel_ulong_t bufferram;
	linux_kernel_ulong_t totalswap;
	linux_kernel_ulong_t freeswap;
	uint16_t procs;
	uint16_t pad;
	linux_kernel_ulong_t totalhigh;
	linux_kernel_ulong_t freehigh;
	uint32_t mem_unit;
	//char _f[20 - 2 * sizeof(linux_kernel_ulong_t) - sizeof(uint32_t)];
};
typedef struct linux_sigaltstack
{
	void* ss_sp;
	int ss_flags;
	linux_size_t ss_size;
} linux_stack_t;
struct linux_stat64
{
	unsigned long long st_dev;
	unsigned long long st_ino;
	unsigned int st_mode;
	unsigned int st_nlink;
	unsigned int st_uid;
	unsigned int st_gid;
	unsigned long long st_rdev;
	unsigned long long _pad1;
	long long st_size;
	int st_blksize;
	int _pad2;
	long long st_blocks;
	int st_atime;
	unsigned int st_atime_nsec;
	int st_mtime;
	unsigned int st_mtime_nsec;
	int st_ctime;
	unsigned int st_ctime_nsec;
	unsigned int _unused4;
	unsigned int _unused5;
};
struct linux_statfs64
{
	uint32_t f_type;
	uint32_t f_bsize;
	uint64_t f_blocks;
	uint64_t f_bfree;
	uint64_t f_bavail;
	uint64_t f_files;
	uint64_t f_ffree;
	linux_fsid_t f_fsid;
	uint32_t f_namelen;
	uint32_t f_frsize;
	uint32_t f_flags;
	uint32_t f_spare[4];
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
	linux_kernel_off_t l_start;
	linux_kernel_off_t l_len;
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
// epoll

struct linux_epoll_event
{
	linux_poll_t events;
	uint64_t data;
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
	linux_kernel_ulong_t sec;
	linux_kernel_ulong_t usec;
	uint16_t type;
	uint16_t code;
	int32_t value;
};

#endif // !HEADER_LIBLINUX_RISCV32_STRUCTS_H_INCLUDED