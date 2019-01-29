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

#ifndef HEADER_LIBLINUX_ARM64_STRUCTS_H_INCLUDED
#define HEADER_LIBLINUX_ARM64_STRUCTS_H_INCLUDED

#include <stdint.h>
#include <stdalign.h>

typedef struct
{
	int val[2];
} linux_kernel_fsid_t;
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
	linux_kernel_fsid_t f_fsid;
	linux_statfs_word f_namelen;
	linux_statfs_word f_frsize;
	linux_statfs_word f_flags;
	linux_statfs_word f_spare[4];
};
union linux_sifields
{
	struct
	{
		linux_kernel_pid_t pid;
		linux_kernel_uid32_t uid;
	} kill;
	struct
	{
		linux_kernel_timer_t tid;
		int overrun;
		linux_sigval_t sigval;
		int _sys_private;
	} timer;
	struct
	{
		linux_kernel_pid_t pid;
		linux_kernel_uid32_t uid;
		linux_sigval_t sigval;
	} rt;
	struct
	{
		linux_kernel_pid_t pid;
		linux_kernel_uid32_t uid;
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
	linux_sigrestore_t sa_restorer;
	linux_sigset_t sa_mask;
};
struct linux_ipc64_perm
{
	linux_kernel_key_t key;
	linux_kernel_uid32_t uid;
	linux_kernel_gid32_t gid;
	linux_kernel_uid32_t cuid;
	linux_kernel_gid32_t cgid;
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
	linux_kernel_time_t shm_atime;
	linux_kernel_time_t shm_dtime;
	linux_kernel_time_t shm_ctime;
	linux_kernel_pid_t shm_cpid;
	linux_kernel_pid_t shm_lpid;
	unsigned long shm_nattch;
	unsigned long _unused4;
	unsigned long _unused5;
};
struct linux_msqid64_ds
{
	struct linux_ipc64_perm msg_perm;
	linux_kernel_time_t msg_stime;
	linux_kernel_time_t msg_rtime;
	linux_kernel_time_t msg_ctime;
	unsigned long msg_cbytes;
	unsigned long msg_qnum;
	unsigned long msg_qbytes;
	linux_kernel_pid_t msg_lspid;
	linux_kernel_pid_t msg_lrpid;
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
struct linux_epoll_event
{
	linux_poll_t events;
	uint64_t data;
};
struct linux_rseq
{
	alignas(4 * sizeof(uint64_t)) uint32_t cpu_id_start;
	uint32_t cpu_id;
	union
	{
		uint64_t ptr64;
		uint64_t ptr;
	} rseq_cs;
	uint32_t flags;
};
_Static_assert(alignof(struct linux_rseq) == (4 * sizeof(uint64_t)), "struct linux_rseq is misaligned");

#endif // !HEADER_LIBLINUX_ARM64_STRUCTS_H_INCLUDED
