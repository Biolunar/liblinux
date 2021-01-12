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

#ifndef HEADER_LIBLINUX_X86_NAMES_H_INCLUDED
#define HEADER_LIBLINUX_X86_NAMES_H_INCLUDED

// Differences (name/function/number):
// -----------------------------------
//time time32 13
//lchown lchown16 16
//oldstat stat 18
//umount oldumount 22
//setuid setuid16 23
//getuid getuid16 24
//stime stime32 25
//oldfstat fstat 28
//utime utime32 30
//setgid setgid16 46
//getgid getgid16 47
//geteuid geteuid16 49
//getegid getegid16 50
//umount2 umount 52
//oldolduname olduname 59
//setreuid setreuid16 70
//setregid setregid16 71
//getrlimit old_getrlimit 76
//getgroups getgroups16 80
//setgroups setgroups16 81
//select old_select 82
//oldlstat lstat 84
//readdir old_readdir 89
//mmap old_mmap 90
//fchown fchown16 95
//stat newstat 106
//lstat newlstat 107
//fstat newfstat 108
//olduname uname 109
//uname newuname 122
//adjtimex adjtimex_time32 124
//setfsuid setfsuid16 138
//setfsgid setfsgid16 139
//newselect select 142
//sched_rr_get_interval sched_rr_get_interval_time32 161
//nanosleep nanosleep_time32 162
//setresuid setresuid16 164
//getresuid getresuid16 165
//setresgid setresgid16 170
//getresgid getresgid16 171
//rt_sigtimedwait rt_sigtimedwait_time32 177
//chown chown16 182
//ugetrlimit getrlimit 191
//mmap2 mmap_pgoff 192
//lchown32 lchown 198
//getuid32 getuid 199
//getgid32 getgid 200
//geteuid32 geteuid 201
//getegid32 getegid 202
//setreuid32 setreuid 203
//setregid32 setregid 204
//getgroups32 getgroups 205
//setgroups32 setgroups 206
//fchown32 fchown 207
//setresuid32 setresuid 208
//getresuid32 getresuid 209
//setresgid32 setresgid 210
//getresgid32 getresgid 211
//chown32 chown 212
//setuid32 setuid 213
//setgid32 setgid 214
//setfsuid32 setfsuid 215
//setfsgid32 setfsgid 216
//futex futex_time32 240
//io_getevents io_getevents_time32 247
//timer_settime timer_settime32 260
//timer_gettime timer_gettime32 261
//clock_settime clock_settime32 264
//clock_gettime clock_gettime32 265
//clock_getres clock_getres_time32 266
//clock_nanosleep clock_nanosleep_time32 267
//utimes utimes_time32 271
//mq_timedsend mq_timedsend_time32 279
//mq_timedreceive mq_timedreceive_time32 280
//futimesat futimesat_time32 299
//pselect6 pselect6_time32 308
//ppoll ppoll_time32 309
//utimensat utimensat_time32 320
//timerfd_settime timerfd_settime32 325
//timerfd_gettime timerfd_gettime32 326
//recvmmsg recvmmsg_time32 337
//clock_adjtime clock_adjtime32 343
//io_pgetevents io_pgetevents_time32 385
//clock_gettime64 clock_gettime 403
//clock_settime64 clock_settime 404
//clock_adjtime64 clock_adjtime 405
//clock_getres_time64 clock_getres 406
//clock_nanosleep_time64 clock_nanosleep 407
//timer_gettime64 timer_gettime 408
//timer_settime64 timer_settime 409
//timerfd_gettime64 timerfd_gettime 410
//timerfd_settime64 timerfd_settime 411
//utimensat_time64 utimensat 412
//pselect6_time64 pselect6 413
//ppoll_time64 ppoll 414
//io_pgetevents_time64 io_pgetevents 416
//recvmmsg_time64 recvmmsg 417
//mq_timedsend_time64 mq_timedsend 418
//mq_timedreceive_time64 mq_timedreceive 419
//semtimedop_time64 semtimedop 420
//rt_sigtimedwait_time64 rt_sigtimedwait 421
//futex_time64 futex 422
//sched_rr_get_interval_time64 sched_rr_get_interval 423

enum
{
	// (don't use) linux_syscall_name_restart_syscall              =   0,
	linux_syscall_name_exit                         =   1,
	linux_syscall_name_fork                         =   2,
	linux_syscall_name_read                         =   3,
	linux_syscall_name_write                        =   4,
	linux_syscall_name_open                         =   5,
	linux_syscall_name_close                        =   6,
	linux_syscall_name_waitpid                      =   7,
	linux_syscall_name_creat                        =   8,
	linux_syscall_name_link                         =   9,
	linux_syscall_name_unlink                       =  10,
	linux_syscall_name_execve                       =  11,
	linux_syscall_name_chdir                        =  12,
	linux_syscall_name_time32                       =  13,
	linux_syscall_name_mknod                        =  14,
	linux_syscall_name_chmod                        =  15,
	linux_syscall_name_lchown16                     =  16,
	// (unused) linux_syscall_name_break                        =  17,
	linux_syscall_name_stat                         =  18,
	linux_syscall_name_lseek                        =  19,
	linux_syscall_name_getpid                       =  20,
	linux_syscall_name_mount                        =  21,
	linux_syscall_name_oldumount                    =  22,
	linux_syscall_name_setuid16                     =  23,
	linux_syscall_name_getuid16                     =  24,
	linux_syscall_name_stime32                      =  25,
	linux_syscall_name_ptrace                       =  26,
	linux_syscall_name_alarm                        =  27,
	linux_syscall_name_fstat                        =  28,
	linux_syscall_name_pause                        =  29,
	linux_syscall_name_utime32                      =  30,
	// (unused) linux_syscall_name_stty                         =  31,
	// (unused) linux_syscall_name_gtty                         =  32,
	linux_syscall_name_access                       =  33,
	linux_syscall_name_nice                         =  34,
	// (unused) linux_syscall_name_ftime                        =  35,
	linux_syscall_name_sync                         =  36,
	linux_syscall_name_kill                         =  37,
	linux_syscall_name_rename                       =  38,
	linux_syscall_name_mkdir                        =  39,
	linux_syscall_name_rmdir                        =  40,
	linux_syscall_name_dup                          =  41,
	linux_syscall_name_pipe                         =  42,
	linux_syscall_name_times                        =  43,
	// (unused) linux_syscall_name_prof                         =  44,
	linux_syscall_name_brk                          =  45,
	linux_syscall_name_setgid16                     =  46,
	linux_syscall_name_getgid16                     =  47,
	linux_syscall_name_signal                       =  48,
	linux_syscall_name_geteuid16                    =  49,
	linux_syscall_name_getegid16                    =  50,
	linux_syscall_name_acct                         =  51,
	linux_syscall_name_umount                       =  52,
	// (unused) linux_syscall_name_lock                         =  53,
	linux_syscall_name_ioctl                        =  54,
	linux_syscall_name_fcntl                        =  55,
	// (unused) linux_syscall_name_mpx                          =  56,
	linux_syscall_name_setpgid                      =  57,
	// (unused) linux_syscall_name_ulimit                       =  58,
	linux_syscall_name_olduname                     =  59,
	linux_syscall_name_umask                        =  60,
	linux_syscall_name_chroot                       =  61,
	linux_syscall_name_ustat                        =  62,
	linux_syscall_name_dup2                         =  63,
	linux_syscall_name_getppid                      =  64,
	linux_syscall_name_getpgrp                      =  65,
	linux_syscall_name_setsid                       =  66,
	linux_syscall_name_sigaction                    =  67,
	linux_syscall_name_sgetmask                     =  68,
	linux_syscall_name_ssetmask                     =  69,
	linux_syscall_name_setreuid16                   =  70,
	linux_syscall_name_setregid16                   =  71,
	linux_syscall_name_sigsuspend                   =  72,
	linux_syscall_name_sigpending                   =  73,
	linux_syscall_name_sethostname                  =  74,
	linux_syscall_name_setrlimit                    =  75,
	linux_syscall_name_old_getrlimit                =  76,
	linux_syscall_name_getrusage                    =  77,
	linux_syscall_name_gettimeofday                 =  78,
	linux_syscall_name_settimeofday                 =  79,
	linux_syscall_name_getgroups16                  =  80,
	linux_syscall_name_setgroups16                  =  81,
	linux_syscall_name_old_select                   =  82,
	linux_syscall_name_symlink                      =  83,
	linux_syscall_name_lstat                        =  84,
	linux_syscall_name_readlink                     =  85,
	linux_syscall_name_uselib                       =  86,
	linux_syscall_name_swapon                       =  87,
	linux_syscall_name_reboot                       =  88,
	linux_syscall_name_old_readdir                  =  89,
	linux_syscall_name_old_mmap                     =  90,
	linux_syscall_name_munmap                       =  91,
	linux_syscall_name_truncate                     =  92,
	linux_syscall_name_ftruncate                    =  93,
	linux_syscall_name_fchmod                       =  94,
	linux_syscall_name_fchown16                     =  95,
	linux_syscall_name_getpriority                  =  96,
	linux_syscall_name_setpriority                  =  97,
	// (unused) linux_syscall_name_profil                       =  98,
	linux_syscall_name_statfs                       =  99,
	linux_syscall_name_fstatfs                      = 100,
	linux_syscall_name_ioperm                       = 101,
	linux_syscall_name_socketcall                   = 102,
	linux_syscall_name_syslog                       = 103,
	linux_syscall_name_setitimer                    = 104,
	linux_syscall_name_getitimer                    = 105,
	linux_syscall_name_newstat                      = 106,
	linux_syscall_name_newlstat                     = 107,
	linux_syscall_name_newfstat                     = 108,
	linux_syscall_name_uname                        = 109,
	linux_syscall_name_iopl                         = 110,
	linux_syscall_name_vhangup                      = 111,
	// (unused) linux_syscall_name_idle                         = 112,
	linux_syscall_name_vm86old                      = 113,
	linux_syscall_name_wait4                        = 114,
	linux_syscall_name_swapoff                      = 115,
	linux_syscall_name_sysinfo                      = 116,
	linux_syscall_name_ipc                          = 117,
	linux_syscall_name_fsync                        = 118,
	// linux_syscall_name_sigreturn                    = 119, // Use linux_sigreturn()
	linux_syscall_name_clone                        = 120,
	linux_syscall_name_setdomainname                = 121,
	linux_syscall_name_newuname                     = 122,
	linux_syscall_name_modify_ldt                   = 123,
	linux_syscall_name_adjtimex_time32              = 124,
	linux_syscall_name_mprotect                     = 125,
	linux_syscall_name_sigprocmask                  = 126,
	// (unused) linux_syscall_name_create_module                = 127,
	linux_syscall_name_init_module                  = 128,
	linux_syscall_name_delete_module                = 129,
	// (unused) linux_syscall_name_get_kernel_syms              = 130,
	linux_syscall_name_quotactl                     = 131,
	linux_syscall_name_getpgid                      = 132,
	linux_syscall_name_fchdir                       = 133,
	linux_syscall_name_bdflush                      = 134,
	linux_syscall_name_sysfs                        = 135,
	linux_syscall_name_personality                  = 136,
	// (unused) linux_syscall_name_afs_syscall                  = 137,
	linux_syscall_name_setfsuid16                   = 138,
	linux_syscall_name_setfsgid16                   = 139,
	linux_syscall_name_llseek                       = 140,
	linux_syscall_name_getdents                     = 141,
	linux_syscall_name_select                       = 142,
	linux_syscall_name_flock                        = 143,
	linux_syscall_name_msync                        = 144,
	linux_syscall_name_readv                        = 145,
	linux_syscall_name_writev                       = 146,
	linux_syscall_name_getsid                       = 147,
	linux_syscall_name_fdatasync                    = 148,
	// linux_syscall_name_sysctl                    = 149, // unimplemented
	linux_syscall_name_mlock                        = 150,
	linux_syscall_name_munlock                      = 151,
	linux_syscall_name_mlockall                     = 152,
	linux_syscall_name_munlockall                   = 153,
	linux_syscall_name_sched_setparam               = 154,
	linux_syscall_name_sched_getparam               = 155,
	linux_syscall_name_sched_setscheduler           = 156,
	linux_syscall_name_sched_getscheduler           = 157,
	linux_syscall_name_sched_yield                  = 158,
	linux_syscall_name_sched_get_priority_max       = 159,
	linux_syscall_name_sched_get_priority_min       = 160,
	linux_syscall_name_sched_rr_get_interval_time32 = 161,
	linux_syscall_name_nanosleep_time32             = 162,
	linux_syscall_name_mremap                       = 163,
	linux_syscall_name_setresuid16                  = 164,
	linux_syscall_name_getresuid16                  = 165,
	linux_syscall_name_vm86                         = 166,
	// (unused) linux_syscall_name_query_module                 = 167,
	linux_syscall_name_poll                         = 168,
	// (unused) linux_syscall_name_nfsservctl                   = 169,
	linux_syscall_name_setresgid16                  = 170,
	linux_syscall_name_getresgid16                  = 171,
	linux_syscall_name_prctl                        = 172,
	// linux_syscall_name_rt_sigreturn                 = 173, // Use linux_rt_sigreturn()
	linux_syscall_name_rt_sigaction                 = 174,
	linux_syscall_name_rt_sigprocmask               = 175,
	linux_syscall_name_rt_sigpending                = 176,
	linux_syscall_name_rt_sigtimedwait_time32       = 177,
	linux_syscall_name_rt_sigqueueinfo              = 178,
	linux_syscall_name_rt_sigsuspend                = 179,
	linux_syscall_name_pread64                      = 180,
	linux_syscall_name_pwrite64                     = 181,
	linux_syscall_name_chown16                      = 182,
	linux_syscall_name_getcwd                       = 183,
	linux_syscall_name_capget                       = 184,
	linux_syscall_name_capset                       = 185,
	linux_syscall_name_sigaltstack                  = 186,
	linux_syscall_name_sendfile                     = 187,
	// (unused) linux_syscall_name_getpmsg                      = 188,
	// (unused) linux_syscall_name_putpmsg                      = 189,
	// linux_syscall_name_vfork                        = 190, // Use linux_vfork_raw()
	linux_syscall_name_getrlimit                    = 191,
	linux_syscall_name_mmap_pgoff                   = 192,
	linux_syscall_name_truncate64                   = 193,
	linux_syscall_name_ftruncate64                  = 194,
	linux_syscall_name_stat64                       = 195,
	linux_syscall_name_lstat64                      = 196,
	linux_syscall_name_fstat64                      = 197,
	linux_syscall_name_lchown                       = 198,
	linux_syscall_name_getuid                       = 199,
	linux_syscall_name_getgid                       = 200,
	linux_syscall_name_geteuid                      = 201,
	linux_syscall_name_getegid                      = 202,
	linux_syscall_name_setreuid                     = 203,
	linux_syscall_name_setregid                     = 204,
	linux_syscall_name_getgroups                    = 205,
	linux_syscall_name_setgroups                    = 206,
	linux_syscall_name_fchown                       = 207,
	linux_syscall_name_setresuid                    = 208,
	linux_syscall_name_getresuid                    = 209,
	linux_syscall_name_setresgid                    = 210,
	linux_syscall_name_getresgid                    = 211,
	linux_syscall_name_chown                        = 212,
	linux_syscall_name_setuid                       = 213,
	linux_syscall_name_setgid                       = 214,
	linux_syscall_name_setfsuid                     = 215,
	linux_syscall_name_setfsgid                     = 216,
	linux_syscall_name_pivot_root                   = 217,
	linux_syscall_name_mincore                      = 218,
	linux_syscall_name_madvise                      = 219,
	linux_syscall_name_getdents64                   = 220,
	linux_syscall_name_fcntl64                      = 221,
	// (unused)
	// (unused)
	linux_syscall_name_gettid                       = 224,
	linux_syscall_name_readahead                    = 225,
	linux_syscall_name_setxattr                     = 226,
	linux_syscall_name_lsetxattr                    = 227,
	linux_syscall_name_fsetxattr                    = 228,
	linux_syscall_name_getxattr                     = 229,
	linux_syscall_name_lgetxattr                    = 230,
	linux_syscall_name_fgetxattr                    = 231,
	linux_syscall_name_listxattr                    = 232,
	linux_syscall_name_llistxattr                   = 233,
	linux_syscall_name_flistxattr                   = 234,
	linux_syscall_name_removexattr                  = 235,
	linux_syscall_name_lremovexattr                 = 236,
	linux_syscall_name_fremovexattr                 = 237,
	linux_syscall_name_tkill                        = 238,
	linux_syscall_name_sendfile64                   = 239,
	linux_syscall_name_futex_time32                 = 240,
	linux_syscall_name_sched_setaffinity            = 241,
	linux_syscall_name_sched_getaffinity            = 242,
	linux_syscall_name_set_thread_area              = 243,
	linux_syscall_name_get_thread_area              = 244,
	linux_syscall_name_io_setup                     = 245,
	linux_syscall_name_io_destroy                   = 246,
	linux_syscall_name_io_getevents_time32          = 247,
	linux_syscall_name_io_submit                    = 248,
	linux_syscall_name_io_cancel                    = 249,
	linux_syscall_name_fadvise64                    = 250,
	// (unused)
	linux_syscall_name_exit_group                   = 252,
	linux_syscall_name_lookup_dcookie               = 253,
	linux_syscall_name_epoll_create                 = 254,
	linux_syscall_name_epoll_ctl                    = 255,
	linux_syscall_name_epoll_wait                   = 256,
	linux_syscall_name_remap_file_pages             = 257,
	linux_syscall_name_set_tid_address              = 258,
	linux_syscall_name_timer_create                 = 259,
	linux_syscall_name_timer_settime32              = 260,
	linux_syscall_name_timer_gettime32              = 261,
	linux_syscall_name_timer_getoverrun             = 262,
	linux_syscall_name_timer_delete                 = 263,
	linux_syscall_name_clock_settime32              = 264,
	linux_syscall_name_clock_gettime32              = 265,
	linux_syscall_name_clock_getres_time32          = 266,
	linux_syscall_name_clock_nanosleep_time32       = 267,
	linux_syscall_name_statfs64                     = 268,
	linux_syscall_name_fstatfs64                    = 269,
	linux_syscall_name_tgkill                       = 270,
	linux_syscall_name_utimes_time32                = 271,
	linux_syscall_name_fadvise64_64                 = 272,
	// (unused) linux_syscall_name_vserver                      = 273,
	linux_syscall_name_mbind                        = 274,
	linux_syscall_name_get_mempolicy                = 275,
	linux_syscall_name_set_mempolicy                = 276,
	linux_syscall_name_mq_open                      = 277,
	linux_syscall_name_mq_unlink                    = 278,
	linux_syscall_name_mq_timedsend_time32          = 279,
	linux_syscall_name_mq_timedreceive_time32       = 280,
	linux_syscall_name_mq_notify                    = 281,
	linux_syscall_name_mq_getsetattr                = 282,
	linux_syscall_name_kexec_load                   = 283,
	linux_syscall_name_waitid                       = 284,
	// (unused) linux_syscall_name_setaltroot                   = 285,
	linux_syscall_name_add_key                      = 286,
	linux_syscall_name_request_key                  = 287,
	linux_syscall_name_keyctl                       = 288,
	linux_syscall_name_ioprio_set                   = 289,
	linux_syscall_name_ioprio_get                   = 290,
	linux_syscall_name_inotify_init                 = 291,
	linux_syscall_name_inotify_add_watch            = 292,
	linux_syscall_name_inotify_rm_watch             = 293,
	linux_syscall_name_migrate_pages                = 294,
	linux_syscall_name_openat                       = 295,
	linux_syscall_name_mkdirat                      = 296,
	linux_syscall_name_mknodat                      = 297,
	linux_syscall_name_fchownat                     = 298,
	linux_syscall_name_futimesat_time32             = 299,
	linux_syscall_name_fstatat64                    = 300,
	linux_syscall_name_unlinkat                     = 301,
	linux_syscall_name_renameat                     = 302,
	linux_syscall_name_linkat                       = 303,
	linux_syscall_name_symlinkat                    = 304,
	linux_syscall_name_readlinkat                   = 305,
	linux_syscall_name_fchmodat                     = 306,
	linux_syscall_name_faccessat                    = 307,
	linux_syscall_name_pselect6_time32              = 308,
	linux_syscall_name_ppoll_time32                 = 309,
	linux_syscall_name_unshare                      = 310,
	linux_syscall_name_set_robust_list              = 311,
	linux_syscall_name_get_robust_list              = 312,
	linux_syscall_name_splice                       = 313,
	linux_syscall_name_sync_file_range              = 314,
	linux_syscall_name_tee                          = 315,
	linux_syscall_name_vmsplice                     = 316,
	linux_syscall_name_move_pages                   = 317,
	linux_syscall_name_getcpu                       = 318,
	linux_syscall_name_epoll_pwait                  = 319,
	linux_syscall_name_utimensat_time32             = 320,
	linux_syscall_name_signalfd                     = 321,
	linux_syscall_name_timerfd_create               = 322,
	linux_syscall_name_eventfd                      = 323,
	linux_syscall_name_fallocate                    = 324,
	linux_syscall_name_timerfd_settime32            = 325,
	linux_syscall_name_timerfd_gettime32            = 326,
	linux_syscall_name_signalfd4                    = 327,
	linux_syscall_name_eventfd2                     = 328,
	linux_syscall_name_epoll_create1                = 329,
	linux_syscall_name_dup3                         = 330,
	linux_syscall_name_pipe2                        = 331,
	linux_syscall_name_inotify_init1                = 332,
	linux_syscall_name_preadv                       = 333,
	linux_syscall_name_pwritev                      = 334,
	linux_syscall_name_rt_tgsigqueueinfo            = 335,
	linux_syscall_name_perf_event_open              = 336,
	linux_syscall_name_recvmmsg_time32              = 337,
	linux_syscall_name_fanotify_init                = 338,
	linux_syscall_name_fanotify_mark                = 339,
	linux_syscall_name_prlimit64                    = 340,
	linux_syscall_name_name_to_handle_at            = 341,
	linux_syscall_name_open_by_handle_at            = 342,
	linux_syscall_name_clock_adjtime32              = 343,
	linux_syscall_name_syncfs                       = 344,
	linux_syscall_name_sendmmsg                     = 345,
	linux_syscall_name_setns                        = 346,
	linux_syscall_name_process_vm_readv             = 347,
	linux_syscall_name_process_vm_writev            = 348,
	linux_syscall_name_kcmp                         = 349,
	linux_syscall_name_finit_module                 = 350,
	linux_syscall_name_sched_setattr                = 351,
	linux_syscall_name_sched_getattr                = 352,
	linux_syscall_name_renameat2                    = 353,
	linux_syscall_name_seccomp                      = 354,
	linux_syscall_name_getrandom                    = 355,
	linux_syscall_name_memfd_create                 = 356,
	linux_syscall_name_bpf                          = 357,
	linux_syscall_name_execveat                     = 358,
	linux_syscall_name_socket                       = 359,
	linux_syscall_name_socketpair                   = 360,
	linux_syscall_name_bind                         = 361,
	linux_syscall_name_connect                      = 362,
	linux_syscall_name_listen                       = 363,
	linux_syscall_name_accept4                      = 364,
	linux_syscall_name_getsockopt                   = 365,
	linux_syscall_name_setsockopt                   = 366,
	linux_syscall_name_getsockname                  = 367,
	linux_syscall_name_getpeername                  = 368,
	linux_syscall_name_sendto                       = 369,
	linux_syscall_name_sendmsg                      = 370,
	linux_syscall_name_recvfrom                     = 371,
	linux_syscall_name_recvmsg                      = 372,
	linux_syscall_name_shutdown                     = 373,
	linux_syscall_name_userfaultfd                  = 374,
	linux_syscall_name_membarrier                   = 375,
	linux_syscall_name_mlock2                       = 376,
	linux_syscall_name_copy_file_range              = 377,
	linux_syscall_name_preadv2                      = 378,
	linux_syscall_name_pwritev2                     = 379,
	linux_syscall_name_pkey_mprotect                = 380,
	linux_syscall_name_pkey_alloc                   = 381,
	linux_syscall_name_pkey_free                    = 382,
	linux_syscall_name_statx                        = 383,
	linux_syscall_name_arch_prctl                   = 384,
	linux_syscall_name_io_pgetevents_time32         = 385,
	linux_syscall_name_rseq                         = 386,
	// (unused)
	// (unused)
	// (unused)
	// (unused)
	// (unused)
	// (unused)
	linux_syscall_name_semget                       = 393,
	linux_syscall_name_semctl                       = 394,
	linux_syscall_name_shmget                       = 395,
	linux_syscall_name_shmctl                       = 396,
	linux_syscall_name_shmat                        = 397,
	linux_syscall_name_shmdt                        = 398,
	linux_syscall_name_msgget                       = 399,
	linux_syscall_name_msgsnd                       = 400,
	linux_syscall_name_msgrcv                       = 401,
	linux_syscall_name_msgctl                       = 402,
	linux_syscall_name_clock_gettime                = 403,
	linux_syscall_name_clock_settime                = 404,
	linux_syscall_name_clock_adjtime                = 405,
	linux_syscall_name_clock_getres                 = 406,
	linux_syscall_name_clock_nanosleep              = 407,
	linux_syscall_name_timer_gettime                = 408,
	linux_syscall_name_timer_settime                = 409,
	linux_syscall_name_timerfd_gettime              = 410,
	linux_syscall_name_timerfd_settime              = 411,
	linux_syscall_name_utimensat                    = 412,
	linux_syscall_name_pselect6                     = 413,
	linux_syscall_name_ppoll                        = 414,
	// (unused)
	linux_syscall_name_io_pgetevents                = 416,
	linux_syscall_name_recvmmsg                     = 417,
	linux_syscall_name_mq_timedsend                 = 418,
	linux_syscall_name_mq_timedreceive              = 419,
	linux_syscall_name_semtimedop                   = 420,
	linux_syscall_name_rt_sigtimedwait              = 421,
	linux_syscall_name_futex                        = 422,
	linux_syscall_name_sched_rr_get_interval        = 423,
	linux_syscall_name_pidfd_send_signal            = 424,
	linux_syscall_name_io_uring_setup               = 425,
	linux_syscall_name_io_uring_enter               = 426,
	linux_syscall_name_io_uring_register            = 427,
	linux_syscall_name_open_tree                    = 428,
	linux_syscall_name_move_mount                   = 429,
	linux_syscall_name_fsopen                       = 430,
	linux_syscall_name_fsconfig                     = 431,
	linux_syscall_name_fsmount                      = 432,
	linux_syscall_name_fspick                       = 433,
	linux_syscall_name_pidfd_open                   = 434,
	linux_syscall_name_clone3                       = 435,
	linux_syscall_name_close_range                  = 436,
	linux_syscall_name_openat2                      = 437,
	linux_syscall_name_pidfd_getfd                  = 438,
	linux_syscall_name_faccessat2                   = 439,
	linux_syscall_name_process_madvise              = 440,
};

#endif // !HEADER_LIBLINUX_X86_NAMES_H_INCLUDED
