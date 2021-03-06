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

#ifndef HEADER_LIBLINUX_X86_64_NAMES_H_INCLUDED
#define HEADER_LIBLINUX_X86_64_NAMES_H_INCLUDED

// Differences (name/function/number):
// -----------------------------------
// stat newstat 4
// fstat newfstat 5
// lstat newlstat 6
// sendfile sendfile64 40
// uname newuname 63
// umount2 umount 166

enum
{
	linux_syscall_name_read                   =   0,
	linux_syscall_name_write                  =   1,
	linux_syscall_name_open                   =   2,
	linux_syscall_name_close                  =   3,
	linux_syscall_name_newstat                =   4,
	linux_syscall_name_newfstat               =   5,
	linux_syscall_name_newlstat               =   6,
	linux_syscall_name_poll                   =   7,
	linux_syscall_name_lseek                  =   8,
	linux_syscall_name_mmap                   =   9,
	linux_syscall_name_mprotect               =  10,
	linux_syscall_name_munmap                 =  11,
	linux_syscall_name_brk                    =  12,
	linux_syscall_name_rt_sigaction           =  13,
	linux_syscall_name_rt_sigprocmask         =  14,
	// linux_syscall_name_rt_sigreturn           =  15, // Use linux_rt_sigreturn()
	linux_syscall_name_ioctl                  =  16,
	linux_syscall_name_pread64                =  17,
	linux_syscall_name_pwrite64               =  18,
	linux_syscall_name_readv                  =  19,
	linux_syscall_name_writev                 =  20,
	linux_syscall_name_access                 =  21,
	linux_syscall_name_pipe                   =  22,
	linux_syscall_name_select                 =  23,
	linux_syscall_name_sched_yield            =  24,
	linux_syscall_name_mremap                 =  25,
	linux_syscall_name_msync                  =  26,
	linux_syscall_name_mincore                =  27,
	linux_syscall_name_madvise                =  28,
	linux_syscall_name_shmget                 =  29,
	linux_syscall_name_shmat                  =  30,
	linux_syscall_name_shmctl                 =  31,
	linux_syscall_name_dup                    =  32,
	linux_syscall_name_dup2                   =  33,
	linux_syscall_name_pause                  =  34,
	linux_syscall_name_nanosleep              =  35,
	linux_syscall_name_getitimer              =  36,
	linux_syscall_name_alarm                  =  37,
	linux_syscall_name_setitimer              =  38,
	linux_syscall_name_getpid                 =  39,
	linux_syscall_name_sendfile64             =  40,
	linux_syscall_name_socket                 =  41,
	linux_syscall_name_connect                =  42,
	linux_syscall_name_accept                 =  43,
	linux_syscall_name_sendto                 =  44,
	linux_syscall_name_recvfrom               =  45,
	linux_syscall_name_sendmsg                =  46,
	linux_syscall_name_recvmsg                =  47,
	linux_syscall_name_shutdown               =  48,
	linux_syscall_name_bind                   =  49,
	linux_syscall_name_listen                 =  50,
	linux_syscall_name_getsockname            =  51,
	linux_syscall_name_getpeername            =  52,
	linux_syscall_name_socketpair             =  53,
	linux_syscall_name_setsockopt             =  54,
	linux_syscall_name_getsockopt             =  55,
	linux_syscall_name_clone                  =  56,
	linux_syscall_name_fork                   =  57,
	// linux_syscall_name_vfork                  =  58, // Use linux_vfork_raw()
	linux_syscall_name_execve                 =  59,
	linux_syscall_name_exit                   =  60,
	linux_syscall_name_wait4                  =  61,
	linux_syscall_name_kill                   =  62,
	linux_syscall_name_newuname               =  63,
	linux_syscall_name_semget                 =  64,
	linux_syscall_name_semop                  =  65,
	linux_syscall_name_semctl                 =  66,
	linux_syscall_name_shmdt                  =  67,
	linux_syscall_name_msgget                 =  68,
	linux_syscall_name_msgsnd                 =  69,
	linux_syscall_name_msgrcv                 =  70,
	linux_syscall_name_msgctl                 =  71,
	linux_syscall_name_fcntl                  =  72,
	linux_syscall_name_flock                  =  73,
	linux_syscall_name_fsync                  =  74,
	linux_syscall_name_fdatasync              =  75,
	linux_syscall_name_truncate               =  76,
	linux_syscall_name_ftruncate              =  77,
	linux_syscall_name_getdents               =  78,
	linux_syscall_name_getcwd                 =  79,
	linux_syscall_name_chdir                  =  80,
	linux_syscall_name_fchdir                 =  81,
	linux_syscall_name_rename                 =  82,
	linux_syscall_name_mkdir                  =  83,
	linux_syscall_name_rmdir                  =  84,
	linux_syscall_name_creat                  =  85,
	linux_syscall_name_link                   =  86,
	linux_syscall_name_unlink                 =  87,
	linux_syscall_name_symlink                =  88,
	linux_syscall_name_readlink               =  89,
	linux_syscall_name_chmod                  =  90,
	linux_syscall_name_fchmod                 =  91,
	linux_syscall_name_chown                  =  92,
	linux_syscall_name_fchown                 =  93,
	linux_syscall_name_lchown                 =  94,
	linux_syscall_name_umask                  =  95,
	linux_syscall_name_gettimeofday           =  96,
	linux_syscall_name_getrlimit              =  97,
	linux_syscall_name_getrusage              =  98,
	linux_syscall_name_sysinfo                =  99,
	linux_syscall_name_times                  = 100,
	linux_syscall_name_ptrace                 = 101,
	linux_syscall_name_getuid                 = 102,
	linux_syscall_name_syslog                 = 103,
	linux_syscall_name_getgid                 = 104,
	linux_syscall_name_setuid                 = 105,
	linux_syscall_name_setgid                 = 106,
	linux_syscall_name_geteuid                = 107,
	linux_syscall_name_getegid                = 108,
	linux_syscall_name_setpgid                = 109,
	linux_syscall_name_getppid                = 110,
	linux_syscall_name_getpgrp                = 111,
	linux_syscall_name_setsid                 = 112,
	linux_syscall_name_setreuid               = 113,
	linux_syscall_name_setregid               = 114,
	linux_syscall_name_getgroups              = 115,
	linux_syscall_name_setgroups              = 116,
	linux_syscall_name_setresuid              = 117,
	linux_syscall_name_getresuid              = 118,
	linux_syscall_name_setresgid              = 119,
	linux_syscall_name_getresgid              = 120,
	linux_syscall_name_getpgid                = 121,
	linux_syscall_name_setfsuid               = 122,
	linux_syscall_name_setfsgid               = 123,
	linux_syscall_name_getsid                 = 124,
	linux_syscall_name_capget                 = 125,
	linux_syscall_name_capset                 = 126,
	linux_syscall_name_rt_sigpending          = 127,
	linux_syscall_name_rt_sigtimedwait        = 128,
	linux_syscall_name_rt_sigqueueinfo        = 129,
	linux_syscall_name_rt_sigsuspend          = 130,
	linux_syscall_name_sigaltstack            = 131,
	linux_syscall_name_utime                  = 132,
	linux_syscall_name_mknod                  = 133,
	// (unused) linux_syscall_name_uselib                 = 134,
	linux_syscall_name_personality            = 135,
	linux_syscall_name_ustat                  = 136,
	linux_syscall_name_statfs                 = 137,
	linux_syscall_name_fstatfs                = 138,
	linux_syscall_name_sysfs                  = 139,
	linux_syscall_name_getpriority            = 140,
	linux_syscall_name_setpriority            = 141,
	linux_syscall_name_sched_setparam         = 142,
	linux_syscall_name_sched_getparam         = 143,
	linux_syscall_name_sched_setscheduler     = 144,
	linux_syscall_name_sched_getscheduler     = 145,
	linux_syscall_name_sched_get_priority_max = 146,
	linux_syscall_name_sched_get_priority_min = 147,
	linux_syscall_name_sched_rr_get_interval  = 148,
	linux_syscall_name_mlock                  = 149,
	linux_syscall_name_munlock                = 150,
	linux_syscall_name_mlockall               = 151,
	linux_syscall_name_munlockall             = 152,
	linux_syscall_name_vhangup                = 153,
	linux_syscall_name_modify_ldt             = 154,
	linux_syscall_name_pivot_root             = 155,
	linux_syscall_name_sysctl                 = 156,
	linux_syscall_name_prctl                  = 157,
	linux_syscall_name_arch_prctl             = 158,
	linux_syscall_name_adjtimex               = 159,
	linux_syscall_name_setrlimit              = 160,
	linux_syscall_name_chroot                 = 161,
	linux_syscall_name_sync                   = 162,
	linux_syscall_name_acct                   = 163,
	linux_syscall_name_settimeofday           = 164,
	linux_syscall_name_mount                  = 165,
	linux_syscall_name_umount                 = 166,
	linux_syscall_name_swapon                 = 167,
	linux_syscall_name_swapoff                = 168,
	linux_syscall_name_reboot                 = 169,
	linux_syscall_name_sethostname            = 170,
	linux_syscall_name_setdomainname          = 171,
	linux_syscall_name_iopl                   = 172,
	linux_syscall_name_ioperm                 = 173,
	// (unused) linux_syscall_name_create_module          = 174,
	linux_syscall_name_init_module            = 175,
	linux_syscall_name_delete_module          = 176,
	// (unused) linux_syscall_name_get_kernel_syms        = 177,
	// (unused) linux_syscall_name_query_module           = 178,
	linux_syscall_name_quotactl               = 179,
	// (unused) linux_syscall_name_nfsservctl             = 180,
	// (unused) linux_syscall_name_getpmsg                = 181,
	// (unused) linux_syscall_name_putpmsg                = 182,
	// (unused) linux_syscall_name_afs_syscall            = 183,
	// (unused) linux_syscall_name_tuxcall                = 184,
	// (unused) linux_syscall_name_security               = 185,
	linux_syscall_name_gettid                 = 186,
	linux_syscall_name_readahead              = 187,
	linux_syscall_name_setxattr               = 188,
	linux_syscall_name_lsetxattr              = 189,
	linux_syscall_name_fsetxattr              = 190,
	linux_syscall_name_getxattr               = 191,
	linux_syscall_name_lgetxattr              = 192,
	linux_syscall_name_fgetxattr              = 193,
	linux_syscall_name_listxattr              = 194,
	linux_syscall_name_llistxattr             = 195,
	linux_syscall_name_flistxattr             = 196,
	linux_syscall_name_removexattr            = 197,
	linux_syscall_name_lremovexattr           = 198,
	linux_syscall_name_fremovexattr           = 199,
	linux_syscall_name_tkill                  = 200,
	linux_syscall_name_time                   = 201,
	linux_syscall_name_futex                  = 202,
	linux_syscall_name_sched_setaffinity      = 203,
	linux_syscall_name_sched_getaffinity      = 204,
	// (unused) linux_syscall_name_set_thread_area        = 205,
	linux_syscall_name_io_setup               = 206,
	linux_syscall_name_io_destroy             = 207,
	linux_syscall_name_io_getevents           = 208,
	linux_syscall_name_io_submit              = 209,
	linux_syscall_name_io_cancel              = 210,
	// (unused) linux_syscall_name_get_thread_area        = 211,
	linux_syscall_name_lookup_dcookie         = 212,
	linux_syscall_name_epoll_create           = 213,
	// (unused) linux_syscall_name_epoll_ctl_old          = 214,
	// (unused) linux_syscall_name_epoll_wait_old         = 215,
	linux_syscall_name_remap_file_pages       = 216,
	linux_syscall_name_getdents64             = 217,
	linux_syscall_name_set_tid_address        = 218,
	// (don't use) linux_syscall_name_restart_syscall        = 219,
	linux_syscall_name_semtimedop             = 220,
	linux_syscall_name_fadvise64              = 221,
	linux_syscall_name_timer_create           = 222,
	linux_syscall_name_timer_settime          = 223,
	linux_syscall_name_timer_gettime          = 224,
	linux_syscall_name_timer_getoverrun       = 225,
	linux_syscall_name_timer_delete           = 226,
	linux_syscall_name_clock_settime          = 227,
	linux_syscall_name_clock_gettime          = 228,
	linux_syscall_name_clock_getres           = 229,
	linux_syscall_name_clock_nanosleep        = 230,
	linux_syscall_name_exit_group             = 231,
	linux_syscall_name_epoll_wait             = 232,
	linux_syscall_name_epoll_ctl              = 233,
	linux_syscall_name_tgkill                 = 234,
	linux_syscall_name_utimes                 = 235,
	// (unused) linux_syscall_name_vserver                = 236,
	linux_syscall_name_mbind                  = 237,
	linux_syscall_name_set_mempolicy          = 238,
	linux_syscall_name_get_mempolicy          = 239,
	linux_syscall_name_mq_open                = 240,
	linux_syscall_name_mq_unlink              = 241,
	linux_syscall_name_mq_timedsend           = 242,
	linux_syscall_name_mq_timedreceive        = 243,
	linux_syscall_name_mq_notify              = 244,
	linux_syscall_name_mq_getsetattr          = 245,
	linux_syscall_name_kexec_load             = 246,
	linux_syscall_name_waitid                 = 247,
	linux_syscall_name_add_key                = 248,
	linux_syscall_name_request_key            = 249,
	linux_syscall_name_keyctl                 = 250,
	linux_syscall_name_ioprio_set             = 251,
	linux_syscall_name_ioprio_get             = 252,
	linux_syscall_name_inotify_init           = 253,
	linux_syscall_name_inotify_add_watch      = 254,
	linux_syscall_name_inotify_rm_watch       = 255,
	linux_syscall_name_migrate_pages          = 256,
	linux_syscall_name_openat                 = 257,
	linux_syscall_name_mkdirat                = 258,
	linux_syscall_name_mknodat                = 259,
	linux_syscall_name_fchownat               = 260,
	linux_syscall_name_futimesat              = 261,
	linux_syscall_name_newfstatat             = 262,
	linux_syscall_name_unlinkat               = 263,
	linux_syscall_name_renameat               = 264,
	linux_syscall_name_linkat                 = 265,
	linux_syscall_name_symlinkat              = 266,
	linux_syscall_name_readlinkat             = 267,
	linux_syscall_name_fchmodat               = 268,
	linux_syscall_name_faccessat              = 269,
	linux_syscall_name_pselect6               = 270,
	linux_syscall_name_ppoll                  = 271,
	linux_syscall_name_unshare                = 272,
	linux_syscall_name_set_robust_list        = 273,
	linux_syscall_name_get_robust_list        = 274,
	linux_syscall_name_splice                 = 275,
	linux_syscall_name_tee                    = 276,
	linux_syscall_name_sync_file_range        = 277,
	linux_syscall_name_vmsplice               = 278,
	linux_syscall_name_move_pages             = 279,
	linux_syscall_name_utimensat              = 280,
	linux_syscall_name_epoll_pwait            = 281,
	linux_syscall_name_signalfd               = 282,
	linux_syscall_name_timerfd_create         = 283,
	linux_syscall_name_eventfd                = 284,
	linux_syscall_name_fallocate              = 285,
	linux_syscall_name_timerfd_settime        = 286,
	linux_syscall_name_timerfd_gettime        = 287,
	linux_syscall_name_accept4                = 288,
	linux_syscall_name_signalfd4              = 289,
	linux_syscall_name_eventfd2               = 290,
	linux_syscall_name_epoll_create1          = 291,
	linux_syscall_name_dup3                   = 292,
	linux_syscall_name_pipe2                  = 293,
	linux_syscall_name_inotify_init1          = 294,
	linux_syscall_name_preadv                 = 295,
	linux_syscall_name_pwritev                = 296,
	linux_syscall_name_rt_tgsigqueueinfo      = 297,
	linux_syscall_name_perf_event_open        = 298,
	linux_syscall_name_recvmmsg               = 299,
	linux_syscall_name_fanotify_init          = 300,
	linux_syscall_name_fanotify_mark          = 301,
	linux_syscall_name_prlimit64              = 302,
	linux_syscall_name_name_to_handle_at      = 303,
	linux_syscall_name_open_by_handle_at      = 304,
	linux_syscall_name_clock_adjtime          = 305,
	linux_syscall_name_syncfs                 = 306,
	linux_syscall_name_sendmmsg               = 307,
	linux_syscall_name_setns                  = 308,
	linux_syscall_name_getcpu                 = 309,
	linux_syscall_name_process_vm_readv       = 310,
	linux_syscall_name_process_vm_writev      = 311,
	linux_syscall_name_kcmp                   = 312,
	linux_syscall_name_finit_module           = 313,
	linux_syscall_name_sched_setattr          = 314,
	linux_syscall_name_sched_getattr          = 315,
	linux_syscall_name_renameat2              = 316,
	linux_syscall_name_seccomp                = 317,
	linux_syscall_name_getrandom              = 318,
	linux_syscall_name_memfd_create           = 319,
	linux_syscall_name_kexec_file_load        = 320,
	linux_syscall_name_bpf                    = 321,
	linux_syscall_name_execveat               = 322,
	linux_syscall_name_userfaultfd            = 323,
	linux_syscall_name_membarrier             = 324,
	linux_syscall_name_mlock2                 = 325,
	linux_syscall_name_copy_file_range        = 326,
	linux_syscall_name_preadv2                = 327,
	linux_syscall_name_pwritev2               = 328,
	linux_syscall_name_pkey_mprotect          = 329,
	linux_syscall_name_pkey_alloc             = 330,
	linux_syscall_name_pkey_free              = 331,
	linux_syscall_name_statx                  = 332,
	linux_syscall_name_io_pgetevents          = 333,
	linux_syscall_name_rseq                   = 334,
	// ...
	// (335 to 423 are unused, so that the numbers are the same as on 32-bit systems)
	// ...
	linux_syscall_name_pidfd_send_signal      = 424,
	linux_syscall_name_io_uring_setup         = 425,
	linux_syscall_name_io_uring_enter         = 426,
	linux_syscall_name_io_uring_register      = 427,
	linux_syscall_name_open_tree              = 428,
	linux_syscall_name_move_mount             = 429,
	linux_syscall_name_fsopen                 = 430,
	linux_syscall_name_fsconfig               = 431,
	linux_syscall_name_fsmount                = 432,
	linux_syscall_name_fspick                 = 433,
	linux_syscall_name_pidfd_open             = 434,
	linux_syscall_name_clone3                 = 435,
};

#endif // !HEADER_LIBLINUX_X86_64_NAMES_H_INCLUDED
