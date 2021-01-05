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

#ifndef HEADER_LIBLINUX_RISCV32_NAMES_H_INCLUDED
#define HEADER_LIBLINUX_RISCV32_NAMES_H_INCLUDED

// Differences (name/function/number):
// -----------------------------------
// fcntl fcntl64 25
// umount2 umount 39
// statfs statfs64 43
// fstatfs fstatfs64 44
// truncate truncate64 45
// ftruncate ftruncate64 46
// lseek llseek 62
// sendfile sendfile64 71
// fstatat fstatat64 79
// fstat fstat64 80
// uname newuname 160
// fadvise64 fadvise64_64 223

enum
{
	linux_syscall_name_io_setup                        =   0,
	linux_syscall_name_io_destroy                      =   1,
	linux_syscall_name_io_submit                       =   2,
	linux_syscall_name_io_cancel                       =   3,
	// linux_syscall_name_io_getevents_time32          =   4, // unimplemented
	linux_syscall_name_setxattr                        =   5,
	linux_syscall_name_lsetxattr                       =   6,
	linux_syscall_name_fsetxattr                       =   7,
	linux_syscall_name_getxattr                        =   8,
	linux_syscall_name_lgetxattr                       =   9,
	linux_syscall_name_fgetxattr                       =  10,
	linux_syscall_name_listxattr                       =  11,
	linux_syscall_name_llistxattr                      =  12,
	linux_syscall_name_flistxattr                      =  13,
	linux_syscall_name_removexattr                     =  14,
	linux_syscall_name_lremovexattr                    =  15,
	linux_syscall_name_fremovexattr                    =  16,
	linux_syscall_name_getcwd                          =  17,
	linux_syscall_name_lookup_dcookie                  =  18,
	linux_syscall_name_eventfd2                        =  19,
	linux_syscall_name_epoll_create1                   =  20,
	linux_syscall_name_epoll_ctl                       =  21,
	linux_syscall_name_epoll_pwait                     =  22,
	linux_syscall_name_dup                             =  23,
	linux_syscall_name_dup3                            =  24,
	linux_syscall_name_fcntl64                         =  25,
	linux_syscall_name_inotify_init1                   =  26,
	linux_syscall_name_inotify_add_watch               =  27,
	linux_syscall_name_inotify_rm_watch                =  28,
	linux_syscall_name_ioctl                           =  29,
	linux_syscall_name_ioprio_set                      =  30,
	linux_syscall_name_ioprio_get                      =  31,
	linux_syscall_name_flock                           =  32,
	linux_syscall_name_mknodat                         =  33,
	linux_syscall_name_mkdirat                         =  34,
	linux_syscall_name_unlinkat                        =  35,
	linux_syscall_name_symlinkat                       =  36,
	linux_syscall_name_linkat                          =  37,
	// linux_syscall_name_renameat                     =  38, // unimplemented
	linux_syscall_name_umount                          =  39,
	linux_syscall_name_mount                           =  40,
	linux_syscall_name_pivot_root                      =  41,
	// linux_syscall_name_nfsservctl                   =  42, // unimplemented
	linux_syscall_name_statfs64                        =  43,
	linux_syscall_name_fstatfs64                       =  44,
	linux_syscall_name_truncate64                      =  45,
	linux_syscall_name_ftruncate64                     =  46,
	linux_syscall_name_fallocate                       =  47,
	linux_syscall_name_faccessat                       =  48,
	linux_syscall_name_chdir                           =  49,
	linux_syscall_name_fchdir                          =  50,
	linux_syscall_name_chroot                          =  51,
	linux_syscall_name_fchmod                          =  52,
	linux_syscall_name_fchmodat                        =  53,
	linux_syscall_name_fchownat                        =  54,
	linux_syscall_name_fchown                          =  55,
	linux_syscall_name_openat                          =  56,
	linux_syscall_name_close                           =  57,
	linux_syscall_name_vhangup                         =  58,
	linux_syscall_name_pipe2                           =  59,
	linux_syscall_name_quotactl                        =  60,
	linux_syscall_name_getdents64                      =  61,
	linux_syscall_name_llseek                          =  62,
	linux_syscall_name_read                            =  63,
	linux_syscall_name_write                           =  64,
	linux_syscall_name_readv                           =  65,
	linux_syscall_name_writev                          =  66,
	linux_syscall_name_pread64                         =  67,
	linux_syscall_name_pwrite64                        =  68,
	linux_syscall_name_preadv                          =  69,
	linux_syscall_name_pwritev                         =  70,
	linux_syscall_name_sendfile64                      =  71,
	// linux_syscall_name_pselect6_time32              =  72, // unimplemented
	// linux_syscall_name_ppoll_time32                 =  73, // unimplemented
	linux_syscall_name_signalfd4                       =  74,
	linux_syscall_name_vmsplice                        =  75,
	linux_syscall_name_splice                          =  76,
	linux_syscall_name_tee                             =  77,
	linux_syscall_name_readlinkat                      =  78,
	linux_syscall_name_fstatat64                       =  79,
	linux_syscall_name_fstat64                         =  80,
	linux_syscall_name_sync                            =  81,
	linux_syscall_name_fsync                           =  82,
	linux_syscall_name_fdatasync                       =  83,
	linux_syscall_name_sync_file_range                 =  84,
	linux_syscall_name_timerfd_create                  =  85,
	// linux_syscall_name_timerfd_settime32            =  86, // unimplemented
	// linux_syscall_name_timerfd_gettime32            =  87, // unimplemented
	// linux_syscall_name_utimensat_time32             =  88, // unimplemented
	linux_syscall_name_acct                            =  89,
	linux_syscall_name_capget                          =  90,
	linux_syscall_name_capset                          =  91,
	linux_syscall_name_personality                     =  92,
	linux_syscall_name_exit                            =  93,
	linux_syscall_name_exit_group                      =  94,
	linux_syscall_name_waitid                          =  95,
	linux_syscall_name_set_tid_address                 =  96,
	linux_syscall_name_unshare                         =  97,
	// linux_syscall_name_futex_time32                 =  98, // unimplemented
	linux_syscall_name_set_robust_list                 =  99,
	linux_syscall_name_get_robust_list                 = 100,
	// linux_syscall_name_nanosleep_time32             = 101, // unimplemented
	linux_syscall_name_getitimer                       = 102,
	linux_syscall_name_setitimer                       = 103,
	linux_syscall_name_kexec_load                      = 104,
	linux_syscall_name_init_module                     = 105,
	linux_syscall_name_delete_module                   = 106,
	linux_syscall_name_timer_create                    = 107,
	// linux_syscall_name_timer_gettime32              = 108, // unimplemented
	linux_syscall_name_timer_getoverrun                = 109,
	// linux_syscall_name_timer_settime32              = 110, // unimplemented
	linux_syscall_name_timer_delete                    = 111,
	// linux_syscall_name_clock_settime32              = 112, // unimplemented
	// linux_syscall_name_clock_gettime32              = 113, // unimplemented
	// linux_syscall_name_clock_getres_time32          = 114, // unimplemented
	// linux_syscall_name_clock_nanosleep_time32       = 115, // unimplemented
	linux_syscall_name_syslog                          = 116,
	linux_syscall_name_ptrace                          = 117,
	linux_syscall_name_sched_setparam                  = 118,
	linux_syscall_name_sched_setscheduler              = 119,
	linux_syscall_name_sched_getscheduler              = 120,
	linux_syscall_name_sched_getparam                  = 121,
	linux_syscall_name_sched_setaffinity               = 122,
	linux_syscall_name_sched_getaffinity               = 123,
	linux_syscall_name_sched_yield                     = 124,
	linux_syscall_name_sched_get_priority_max          = 125,
	linux_syscall_name_sched_get_priority_min          = 126,
	// linux_syscall_name_sched_rr_get_interval_time32 = 127, // unimplemented
	// linux_syscall_name_restart_syscall              = 128, // Do not use.
	linux_syscall_name_kill                            = 129,
	linux_syscall_name_tkill                           = 130,
	linux_syscall_name_tgkill                          = 131,
	linux_syscall_name_sigaltstack                     = 132,
	linux_syscall_name_rt_sigsuspend                   = 133,
	linux_syscall_name_rt_sigaction                    = 134,
	linux_syscall_name_rt_sigprocmask                  = 135,
	linux_syscall_name_rt_sigpending                   = 136,
	// linux_syscall_name_rt_sigtimedwait_time32       = 137, // unimplemented
	linux_syscall_name_rt_sigqueueinfo                 = 138,
	linux_syscall_name_rt_sigreturn                    = 139, // Use linux_rt_sigreturn()
	linux_syscall_name_setpriority                     = 140,
	linux_syscall_name_getpriority                     = 141,
	linux_syscall_name_reboot                          = 142,
	linux_syscall_name_setregid                        = 143,
	linux_syscall_name_setgid                          = 144,
	linux_syscall_name_setreuid                        = 145,
	linux_syscall_name_setuid                          = 146,
	linux_syscall_name_setresuid                       = 147,
	linux_syscall_name_getresuid                       = 148,
	linux_syscall_name_setresgid                       = 149,
	linux_syscall_name_getresgid                       = 150,
	linux_syscall_name_setfsuid                        = 151,
	linux_syscall_name_setfsgid                        = 152,
	linux_syscall_name_times                           = 153,
	linux_syscall_name_setpgid                         = 154,
	linux_syscall_name_getpgid                         = 155,
	linux_syscall_name_getsid                          = 156,
	linux_syscall_name_setsid                          = 157,
	linux_syscall_name_getgroups                       = 158,
	linux_syscall_name_setgroups                       = 159,
	linux_syscall_name_newuname                        = 160,
	linux_syscall_name_sethostname                     = 161,
	linux_syscall_name_setdomainname                   = 162,
	linux_syscall_name_getrlimit                       = 163,
	linux_syscall_name_setrlimit                       = 164,
	linux_syscall_name_getrusage                       = 165,
	linux_syscall_name_umask                           = 166,
	linux_syscall_name_prctl                           = 167,
	linux_syscall_name_getcpu                          = 168,
	// linux_syscall_name_gettimeofday                 = 169, // unimplemented
	// linux_syscall_name_settimeofday                 = 170, // unimplemented
	// linux_syscall_name_adjtimex_time32              = 171, // unimplemented
	linux_syscall_name_getpid                          = 172,
	linux_syscall_name_getppid                         = 173,
	linux_syscall_name_getuid                          = 174,
	linux_syscall_name_geteuid                         = 175,
	linux_syscall_name_getgid                          = 176,
	linux_syscall_name_getegid                         = 177,
	linux_syscall_name_gettid                          = 178,
	linux_syscall_name_sysinfo                         = 179,
	linux_syscall_name_mq_open                         = 180,
	linux_syscall_name_mq_unlink                       = 181,
	// linux_syscall_name_mq_timedsend_time32          = 182, // unimplemented
	// linux_syscall_name_mq_timedreceive_time32       = 183, // unimplemented
	linux_syscall_name_mq_notify                       = 184,
	linux_syscall_name_mq_getsetattr                   = 185,
	linux_syscall_name_msgget                          = 186,
	linux_syscall_name_msgctl                          = 187,
	linux_syscall_name_msgrcv                          = 188,
	linux_syscall_name_msgsnd                          = 189,
	linux_syscall_name_semget                          = 190,
	linux_syscall_name_semctl                          = 191,
	// linux_syscall_name_semtimedop_time32            = 192, // unimplemented
	linux_syscall_name_semop                           = 193,
	linux_syscall_name_shmget                          = 194,
	linux_syscall_name_shmctl                          = 195,
	linux_syscall_name_shmat                           = 196,
	linux_syscall_name_shmdt                           = 197,
	linux_syscall_name_socket                          = 198,
	linux_syscall_name_socketpair                      = 199,
	linux_syscall_name_bind                            = 200,
	linux_syscall_name_listen                          = 201,
	linux_syscall_name_accept                          = 202,
	linux_syscall_name_connect                         = 203,
	linux_syscall_name_getsockname                     = 204,
	linux_syscall_name_getpeername                     = 205,
	linux_syscall_name_sendto                          = 206,
	linux_syscall_name_recvfrom                        = 207,
	linux_syscall_name_setsockopt                      = 208,
	linux_syscall_name_getsockopt                      = 209,
	linux_syscall_name_shutdown                        = 210,
	linux_syscall_name_sendmsg                         = 211,
	linux_syscall_name_recvmsg                         = 212,
	linux_syscall_name_readahead                       = 213,
	linux_syscall_name_brk                             = 214,
	linux_syscall_name_munmap                          = 215,
	linux_syscall_name_mremap                          = 216,
	linux_syscall_name_add_key                         = 217,
	linux_syscall_name_request_key                     = 218,
	linux_syscall_name_keyctl                          = 219,
	linux_syscall_name_clone                           = 220,
	linux_syscall_name_execve                          = 221,
	linux_syscall_name_mmap                            = 222,
	linux_syscall_name_fadvise64_64                    = 223,
	linux_syscall_name_swapon                          = 224,
	linux_syscall_name_swapoff                         = 225,
	linux_syscall_name_mprotect                        = 226,
	linux_syscall_name_msync                           = 227,
	linux_syscall_name_mlock                           = 228,
	linux_syscall_name_munlock                         = 229,
	linux_syscall_name_mlockall                        = 230,
	linux_syscall_name_munlockall                      = 231,
	linux_syscall_name_mincore                         = 232,
	linux_syscall_name_madvise                         = 233,
	linux_syscall_name_remap_file_pages                = 234,
	linux_syscall_name_mbind                           = 235,
	linux_syscall_name_get_mempolicy                   = 236,
	linux_syscall_name_set_mempolicy                   = 237,
	linux_syscall_name_migrate_pages                   = 238,
	linux_syscall_name_move_pages                      = 239,
	linux_syscall_name_rt_tgsigqueueinfo               = 240,
	linux_syscall_name_perf_event_open                 = 241,
	linux_syscall_name_accept4                         = 242,
	// linux_syscall_name_recvmmsg_time32              = 243, // unimplemented
	// ...
	// (244 to 259 are reserved for architecture specific syscalls)
	// ...
	// linux_syscall_name_wait4                        = 260, // unimplemented
	linux_syscall_name_prlimit64                       = 261,
	linux_syscall_name_fanotify_init                   = 262,
	linux_syscall_name_fanotify_mark                   = 263,
	linux_syscall_name_name_to_handle_at               = 264,
	linux_syscall_name_open_by_handle_at               = 265,
	// linux_syscall_name_clock_adjtime32              = 266, // unimplemented
	linux_syscall_name_syncfs                          = 267,
	linux_syscall_name_setns                           = 268,
	linux_syscall_name_sendmmsg                        = 269,
	linux_syscall_name_process_vm_readv                = 270,
	linux_syscall_name_process_vm_writev               = 271,
	linux_syscall_name_kcmp                            = 272,
	linux_syscall_name_finit_module                    = 273,
	linux_syscall_name_sched_setattr                   = 274,
	linux_syscall_name_sched_getattr                   = 275,
	linux_syscall_name_renameat2                       = 276,
	linux_syscall_name_seccomp                         = 277,
	linux_syscall_name_getrandom                       = 278,
	linux_syscall_name_memfd_create                    = 279,
	linux_syscall_name_bpf                             = 280,
	linux_syscall_name_execveat                        = 281,
	linux_syscall_name_userfaultfd                     = 282,
	linux_syscall_name_membarrier                      = 283,
	linux_syscall_name_mlock2                          = 284,
	linux_syscall_name_copy_file_range                 = 285,
	linux_syscall_name_preadv2                         = 286,
	linux_syscall_name_pwritev2                        = 287,
	linux_syscall_name_pkey_mprotect                   = 288,
	linux_syscall_name_pkey_alloc                      = 289,
	linux_syscall_name_pkey_free                       = 290,
	linux_syscall_name_statx                           = 291,
	// linux_syscall_name_io_pgetevents_time32         = 292, // unimplemented
	linux_syscall_name_rseq                            = 293,
	linux_syscall_name_kexec_file_load                 = 294,
	// ...
	// (295 to 402 are unused, so that the following numbers are in sync on 32 and 64 bit systems)
	// ...
	linux_syscall_name_clock_gettime                   = 403,
	linux_syscall_name_clock_settime                   = 404,
	linux_syscall_name_clock_adjtime                   = 405,
	linux_syscall_name_clock_getres                    = 406,
	linux_syscall_name_clock_nanosleep                 = 407,
	linux_syscall_name_timer_gettime                   = 408,
	linux_syscall_name_timer_settime                   = 409,
	linux_syscall_name_timerfd_gettime                 = 410,
	linux_syscall_name_timerfd_settime                 = 411,
	linux_syscall_name_utimensat                       = 412,
	linux_syscall_name_pselect6                        = 413,
	linux_syscall_name_ppoll                           = 414,
	// (unused)
	linux_syscall_name_io_pgetevents                   = 416,
	linux_syscall_name_recvmmsg                        = 417,
	linux_syscall_name_mq_timedsend                    = 418,
	linux_syscall_name_mq_timedreceive                 = 419,
	linux_syscall_name_semtimedop                      = 420,
	linux_syscall_name_rt_sigtimedwait                 = 421,
	linux_syscall_name_futex                           = 422,
	linux_syscall_name_sched_rr_get_interval           = 423,
	linux_syscall_name_pidfd_send_signal               = 424,
	linux_syscall_name_io_uring_setup                  = 425,
	linux_syscall_name_io_uring_enter                  = 426,
	linux_syscall_name_io_uring_register               = 427,
	linux_syscall_name_open_tree                       = 428,
	linux_syscall_name_move_mount                      = 429,
	linux_syscall_name_fsopen                          = 430,
	linux_syscall_name_fsconfig                        = 431,
	linux_syscall_name_fsmount                         = 432,
	linux_syscall_name_fspick                          = 433,
	linux_syscall_name_pidfd_open                      = 434,
	linux_syscall_name_clone3                          = 435,
	linux_syscall_name_close_range                     = 436,
	linux_syscall_name_openat2                         = 437,
	linux_syscall_name_pidfd_getfd                     = 438,
	linux_syscall_name_faccessat2                      = 439,
	linux_syscall_name_process_madvise                 = 440,

	linux_syscall_name_riscv_flush_icache              = 244 + 15,
};

#endif // !HEADER_LIBLINUX_RISCV32_NAMES_H_INCLUDED
