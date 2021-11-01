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

#ifndef HEADER_LIBLINUX_RISCV32_UNISTD_H_INCLUDED
#define HEADER_LIBLINUX_RISCV32_UNISTD_H_INCLUDED

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

#define linux_syscall_name_io_setup                         0 ///< io_setup
#define linux_syscall_name_io_destroy                       1 ///< io_destroy
#define linux_syscall_name_io_submit                        2 ///< io_submit
#define linux_syscall_name_io_cancel                        3 ///< io_cancel
//#define linux_syscall_name_io_getevents_time32            4 // unimplemented
#define linux_syscall_name_setxattr                         5 ///< setxattr
#define linux_syscall_name_lsetxattr                        6 ///< lsetxattr
#define linux_syscall_name_fsetxattr                        7 ///< fsetxattr
#define linux_syscall_name_getxattr                         8 ///< getxattr
#define linux_syscall_name_lgetxattr                        9 ///< lgetxattr
#define linux_syscall_name_fgetxattr                       10 ///< fgetxattr
#define linux_syscall_name_listxattr                       11 ///< listxattr
#define linux_syscall_name_llistxattr                      12 ///< llistxattr
#define linux_syscall_name_flistxattr                      13 ///< flistxattr
#define linux_syscall_name_removexattr                     14 ///< removexattr
#define linux_syscall_name_lremovexattr                    15 ///< lremovexattr
#define linux_syscall_name_fremovexattr                    16 ///< fremovexattr
#define linux_syscall_name_getcwd                          17 ///< getcwd
#define linux_syscall_name_lookup_dcookie                  18 ///< lookup_dcookie
#define linux_syscall_name_eventfd2                        19 ///< eventfd2
#define linux_syscall_name_epoll_create1                   20 ///< epoll_create1
#define linux_syscall_name_epoll_ctl                       21 ///< epoll_ctl
#define linux_syscall_name_epoll_pwait                     22 ///< epoll_pwait
#define linux_syscall_name_dup                             23 ///< dup
#define linux_syscall_name_dup3                            24 ///< dup3
#define linux_syscall_name_fcntl64                         25 ///< fcntl64
#define linux_syscall_name_inotify_init1                   26 ///< inotify_init1
#define linux_syscall_name_inotify_add_watch               27 ///< inotify_add_watch
#define linux_syscall_name_inotify_rm_watch                28 ///< inotify_rm_watch
#define linux_syscall_name_ioctl                           29 ///< ioctl
#define linux_syscall_name_ioprio_set                      30 ///< ioprio_set
#define linux_syscall_name_ioprio_get                      31 ///< ioprio_get
#define linux_syscall_name_flock                           32 ///< flock
#define linux_syscall_name_mknodat                         33 ///< mknodat
#define linux_syscall_name_mkdirat                         34 ///< mkdirat
#define linux_syscall_name_unlinkat                        35 ///< unlinkat
#define linux_syscall_name_symlinkat                       36 ///< symlinkat
#define linux_syscall_name_linkat                          37 ///< linkat
//#define linux_syscall_name_renameat                      38 // unimplemented
#define linux_syscall_name_umount                          39 ///< umount
#define linux_syscall_name_mount                           40 ///< mount
#define linux_syscall_name_pivot_root                      41 ///< pivot_root
//#define linux_syscall_name_nfsservctl                    42 // unimplemented
#define linux_syscall_name_statfs64                        43 ///< statfs64
#define linux_syscall_name_fstatfs64                       44 ///< fstatfs64
#define linux_syscall_name_truncate64                      45 ///< truncate64
#define linux_syscall_name_ftruncate64                     46 ///< ftruncate64
#define linux_syscall_name_fallocate                       47 ///< fallocate
#define linux_syscall_name_faccessat                       48 ///< faccessat
#define linux_syscall_name_chdir                           49 ///< chdir
#define linux_syscall_name_fchdir                          50 ///< fchdir
#define linux_syscall_name_chroot                          51 ///< chroot
#define linux_syscall_name_fchmod                          52 ///< fchmod
#define linux_syscall_name_fchmodat                        53 ///< fchmodat
#define linux_syscall_name_fchownat                        54 ///< fchownat
#define linux_syscall_name_fchown                          55 ///< fchown
#define linux_syscall_name_openat                          56 ///< openat
#define linux_syscall_name_close                           57 ///< close
#define linux_syscall_name_vhangup                         58 ///< vhangup
#define linux_syscall_name_pipe2                           59 ///< pipe2
#define linux_syscall_name_quotactl                        60 ///< quotactl
#define linux_syscall_name_getdents64                      61 ///< getdents64
#define linux_syscall_name_llseek                          62 ///< llseek
#define linux_syscall_name_read                            63 ///< read
#define linux_syscall_name_write                           64 ///< write
#define linux_syscall_name_readv                           65 ///< readv
#define linux_syscall_name_writev                          66 ///< writev
#define linux_syscall_name_pread64                         67 ///< pread64
#define linux_syscall_name_pwrite64                        68 ///< pwrite64
#define linux_syscall_name_preadv                          69 ///< preadv
#define linux_syscall_name_pwritev                         70 ///< pwritev
#define linux_syscall_name_sendfile64                      71 ///< sendfile64
//#define linux_syscall_name_pselect6_time32               72 // unimplemented
//#define linux_syscall_name_ppoll_time32                  73 // unimplemented
#define linux_syscall_name_signalfd4                       74 ///< signalfd4
#define linux_syscall_name_vmsplice                        75 ///< vmsplice
#define linux_syscall_name_splice                          76 ///< splice
#define linux_syscall_name_tee                             77 ///< tee
#define linux_syscall_name_readlinkat                      78 ///< readlinkat
#define linux_syscall_name_fstatat64                       79 ///< fstatat64
#define linux_syscall_name_fstat64                         80 ///< fstat64
#define linux_syscall_name_sync                            81 ///< sync
#define linux_syscall_name_fsync                           82 ///< fsync
#define linux_syscall_name_fdatasync                       83 ///< fdatasync
#define linux_syscall_name_sync_file_range                 84 ///< sync_file_range
#define linux_syscall_name_timerfd_create                  85 ///< timerfd_create
//#define linux_syscall_name_timerfd_settime32             86 // unimplemented
//#define linux_syscall_name_timerfd_gettime32             87 // unimplemented
//#define linux_syscall_name_utimensat_time32              88 // unimplemented
#define linux_syscall_name_acct                            89 ///< acct
#define linux_syscall_name_capget                          90 ///< capget
#define linux_syscall_name_capset                          91 ///< capset
#define linux_syscall_name_personality                     92 ///< personality
#define linux_syscall_name_exit                            93 ///< exit
#define linux_syscall_name_exit_group                      94 ///< exit_group
#define linux_syscall_name_waitid                          95 ///< waitid
#define linux_syscall_name_set_tid_address                 96 ///< set_tid_address
#define linux_syscall_name_unshare                         97 ///< unshare
//#define linux_syscall_name_futex_time32                  98 // unimplemented
#define linux_syscall_name_set_robust_list                 99 ///< set_robust_list
#define linux_syscall_name_get_robust_list                100 ///< get_robust_list
//#define linux_syscall_name_nanosleep_time32             101 // unimplemented
#define linux_syscall_name_getitimer                      102 ///< getitimer
#define linux_syscall_name_setitimer                      103 ///< setitimer
#define linux_syscall_name_kexec_load                     104 ///< kexec_load
#define linux_syscall_name_init_module                    105 ///< init_module
#define linux_syscall_name_delete_module                  106 ///< delete_module
#define linux_syscall_name_timer_create                   107 ///< timer_create
//#define linux_syscall_name_timer_gettime32              108 // unimplemented
#define linux_syscall_name_timer_getoverrun               109 ///< timer_getoverrun
//#define linux_syscall_name_timer_settime32              110 // unimplemented
#define linux_syscall_name_timer_delete                   111 ///< timer_delete
//#define linux_syscall_name_clock_settime32              112 // unimplemented
//#define linux_syscall_name_clock_gettime32              113 // unimplemented
//#define linux_syscall_name_clock_getres_time32          114 // unimplemented
//#define linux_syscall_name_clock_nanosleep_time32       115 // unimplemented
#define linux_syscall_name_syslog                         116 ///< syslog
#define linux_syscall_name_ptrace                         117 ///< ptrace
#define linux_syscall_name_sched_setparam                 118 ///< sched_setparam
#define linux_syscall_name_sched_setscheduler             119 ///< sched_setscheduler
#define linux_syscall_name_sched_getscheduler             120 ///< sched_getscheduler
#define linux_syscall_name_sched_getparam                 121 ///< sched_getparam
#define linux_syscall_name_sched_setaffinity              122 ///< sched_setaffinity
#define linux_syscall_name_sched_getaffinity              123 ///< sched_getaffinity
#define linux_syscall_name_sched_yield                    124 ///< sched_yield
#define linux_syscall_name_sched_get_priority_max         125 ///< sched_get_priority_max
#define linux_syscall_name_sched_get_priority_min         126 ///< sched_get_priority_min
//#define linux_syscall_name_sched_rr_get_interval_time32 127 // unimplemented
//#define linux_syscall_name_restart_syscall              128 // Don't use in userspace.
#define linux_syscall_name_kill                           129 ///< kill
#define linux_syscall_name_tkill                          130 ///< tkill
#define linux_syscall_name_tgkill                         131 ///< tgkill
#define linux_syscall_name_sigaltstack                    132 ///< sigaltstack
#define linux_syscall_name_rt_sigsuspend                  133 ///< rt_sigsuspend
#define linux_syscall_name_rt_sigaction                   134 ///< rt_sigaction
#define linux_syscall_name_rt_sigprocmask                 135 ///< rt_sigprocmask
#define linux_syscall_name_rt_sigpending                  136 ///< rt_sigpending
//#define linux_syscall_name_rt_sigtimedwait_time32       137 // unimplemented
#define linux_syscall_name_rt_sigqueueinfo                138 ///< rt_sigqueueinfo
#define linux_syscall_name_rt_sigreturn                   139 // Use linux_rt_sigreturn().
#define linux_syscall_name_setpriority                    140 ///< setpriority
#define linux_syscall_name_getpriority                    141 ///< getpriority
#define linux_syscall_name_reboot                         142 ///< reboot
#define linux_syscall_name_setregid                       143 ///< setregid
#define linux_syscall_name_setgid                         144 ///< setgid
#define linux_syscall_name_setreuid                       145 ///< setreuid
#define linux_syscall_name_setuid                         146 ///< setuid
#define linux_syscall_name_setresuid                      147 ///< setresuid
#define linux_syscall_name_getresuid                      148 ///< getresuid
#define linux_syscall_name_setresgid                      149 ///< setresgid
#define linux_syscall_name_getresgid                      150 ///< getresgid
#define linux_syscall_name_setfsuid                       151 ///< setfsuid
#define linux_syscall_name_setfsgid                       152 ///< setfsgid
#define linux_syscall_name_times                          153 ///< times
#define linux_syscall_name_setpgid                        154 ///< setpgid
#define linux_syscall_name_getpgid                        155 ///< getpgid
#define linux_syscall_name_getsid                         156 ///< getsid
#define linux_syscall_name_setsid                         157 ///< setsid
#define linux_syscall_name_getgroups                      158 ///< getgroups
#define linux_syscall_name_setgroups                      159 ///< setgroups
#define linux_syscall_name_newuname                       160 ///< newuname
#define linux_syscall_name_sethostname                    161 ///< sethostname
#define linux_syscall_name_setdomainname                  162 ///< setdomainname
#define linux_syscall_name_getrlimit                      163 ///< getrlimit
#define linux_syscall_name_setrlimit                      164 ///< setrlimit
#define linux_syscall_name_getrusage                      165 ///< getrusage
#define linux_syscall_name_umask                          166 ///< umask
#define linux_syscall_name_prctl                          167 ///< prctl
#define linux_syscall_name_getcpu                         168 ///< getcpu
//#define linux_syscall_name_gettimeofday                 169 // unimplemented
//#define linux_syscall_name_settimeofday                 170 // unimplemented
//#define linux_syscall_name_adjtimex_time32              171 // unimplemented
#define linux_syscall_name_getpid                         172 ///< getpid
#define linux_syscall_name_getppid                        173 ///< getppid
#define linux_syscall_name_getuid                         174 ///< getuid
#define linux_syscall_name_geteuid                        175 ///< geteuid
#define linux_syscall_name_getgid                         176 ///< getgid
#define linux_syscall_name_getegid                        177 ///< getegid
#define linux_syscall_name_gettid                         178 ///< gettid
#define linux_syscall_name_sysinfo                        179 ///< sysinfo
#define linux_syscall_name_mq_open                        180 ///< mq_open
#define linux_syscall_name_mq_unlink                      181 ///< mq_unlink
//#define linux_syscall_name_mq_timedsend_time32          182 // unimplemented
//#define linux_syscall_name_mq_timedreceive_time32       183 // unimplemented
#define linux_syscall_name_mq_notify                      184 ///< mq_notify
#define linux_syscall_name_mq_getsetattr                  185 ///< mq_getsetattr
#define linux_syscall_name_msgget                         186 ///< msgget
#define linux_syscall_name_msgctl                         187 ///< msgctl
#define linux_syscall_name_msgrcv                         188 ///< msgrcv
#define linux_syscall_name_msgsnd                         189 ///< msgsnd
#define linux_syscall_name_semget                         190 ///< semget
#define linux_syscall_name_semctl                         191 ///< semctl
//#define linux_syscall_name_semtimedop_time32            192 // unimplemented
#define linux_syscall_name_semop                          193 ///< semop
#define linux_syscall_name_shmget                         194 ///< shmget
#define linux_syscall_name_shmctl                         195 ///< shmctl
#define linux_syscall_name_shmat                          196 ///< shmat
#define linux_syscall_name_shmdt                          197 ///< shmdt
#define linux_syscall_name_socket                         198 ///< socket
#define linux_syscall_name_socketpair                     199 ///< socketpair
#define linux_syscall_name_bind                           200 ///< bind
#define linux_syscall_name_listen                         201 ///< listen
#define linux_syscall_name_accept                         202 ///< accept
#define linux_syscall_name_connect                        203 ///< connect
#define linux_syscall_name_getsockname                    204 ///< getsockname
#define linux_syscall_name_getpeername                    205 ///< getpeername
#define linux_syscall_name_sendto                         206 ///< sendto
#define linux_syscall_name_recvfrom                       207 ///< recvfrom
#define linux_syscall_name_setsockopt                     208 ///< setsockopt
#define linux_syscall_name_getsockopt                     209 ///< getsockopt
#define linux_syscall_name_shutdown                       210 ///< shutdown
#define linux_syscall_name_sendmsg                        211 ///< sendmsg
#define linux_syscall_name_recvmsg                        212 ///< recvmsg
#define linux_syscall_name_readahead                      213 ///< readahead
#define linux_syscall_name_brk                            214 ///< brk
#define linux_syscall_name_munmap                         215 ///< munmap
#define linux_syscall_name_mremap                         216 ///< mremap
#define linux_syscall_name_add_key                        217 ///< add_key
#define linux_syscall_name_request_key                    218 ///< request_key
#define linux_syscall_name_keyctl                         219 ///< keyctl
#define linux_syscall_name_clone                          220 ///< clone
#define linux_syscall_name_execve                         221 ///< execve
#define linux_syscall_name_mmap                           222 ///< mmap
#define linux_syscall_name_fadvise64_64                   223 ///< fadvise64_64
#define linux_syscall_name_swapon                         224 ///< swapon
#define linux_syscall_name_swapoff                        225 ///< swapoff
#define linux_syscall_name_mprotect                       226 ///< mprotect
#define linux_syscall_name_msync                          227 ///< msync
#define linux_syscall_name_mlock                          228 ///< mlock
#define linux_syscall_name_munlock                        229 ///< munlock
#define linux_syscall_name_mlockall                       230 ///< mlockall
#define linux_syscall_name_munlockall                     231 ///< munlockall
#define linux_syscall_name_mincore                        232 ///< mincore
#define linux_syscall_name_madvise                        233 ///< madvise
#define linux_syscall_name_remap_file_pages               234 ///< remap_file_pages
#define linux_syscall_name_mbind                          235 ///< mbind
#define linux_syscall_name_get_mempolicy                  236 ///< get_mempolicy
#define linux_syscall_name_set_mempolicy                  237 ///< set_mempolicy
#define linux_syscall_name_migrate_pages                  238 ///< migrate_pages
#define linux_syscall_name_move_pages                     239 ///< move_pages
#define linux_syscall_name_rt_tgsigqueueinfo              240 ///< rt_tgsigqueueinfo
#define linux_syscall_name_perf_event_open                241 ///< perf_event_open
#define linux_syscall_name_accept4                        242 ///< accept4
//#define linux_syscall_name_recvmmsg_time32              243 // unimplemented
// ...
// 244 to 259 are reserved for architecture specific syscalls
// ...
//#define linux_syscall_name_wait4                        260 // unimplemented
#define linux_syscall_name_prlimit64                      261 ///< prlimit64
#define linux_syscall_name_fanotify_init                  262 ///< fanotify_init
#define linux_syscall_name_fanotify_mark                  263 ///< fanotify_mark
#define linux_syscall_name_name_to_handle_at              264 ///< name_to_handle_at
#define linux_syscall_name_open_by_handle_at              265 ///< open_by_handle_at
//#define linux_syscall_name_clock_adjtime32              266 // unimplemented
#define linux_syscall_name_syncfs                         267 ///< syncfs
#define linux_syscall_name_setns                          268 ///< setns
#define linux_syscall_name_sendmmsg                       269 ///< sendmmsg
#define linux_syscall_name_process_vm_readv               270 ///< process_vm_readv
#define linux_syscall_name_process_vm_writev              271 ///< process_vm_writev
#define linux_syscall_name_kcmp                           272 ///< kcmp
#define linux_syscall_name_finit_module                   273 ///< finit_module
#define linux_syscall_name_sched_setattr                  274 ///< sched_setattr
#define linux_syscall_name_sched_getattr                  275 ///< sched_getattr
#define linux_syscall_name_renameat2                      276 ///< renameat2
#define linux_syscall_name_seccomp                        277 ///< seccomp
#define linux_syscall_name_getrandom                      278 ///< getrandom
#define linux_syscall_name_memfd_create                   279 ///< memfd_create
#define linux_syscall_name_bpf                            280 ///< bpf
#define linux_syscall_name_execveat                       281 ///< execveat
#define linux_syscall_name_userfaultfd                    282 ///< userfaultfd
#define linux_syscall_name_membarrier                     283 ///< membarrier
#define linux_syscall_name_mlock2                         284 ///< mlock2
#define linux_syscall_name_copy_file_range                285 ///< copy_file_range
#define linux_syscall_name_preadv2                        286 ///< preadv2
#define linux_syscall_name_pwritev2                       287 ///< pwritev2
#define linux_syscall_name_pkey_mprotect                  288 ///< pkey_mprotect
#define linux_syscall_name_pkey_alloc                     289 ///< pkey_alloc
#define linux_syscall_name_pkey_free                      290 ///< pkey_free
#define linux_syscall_name_statx                          291 ///< statx
//#define linux_syscall_name_io_pgetevents_time32         292 // unimplemented
#define linux_syscall_name_rseq                           293 ///< rseq
#define linux_syscall_name_kexec_file_load                294 ///< kexec_file_load
// ...
// 295 to 402 are unused, so that the following numbers are in sync on 32 and 64 bit systems
// ...
#define linux_syscall_name_clock_gettime                  403 ///< clock_gettime
#define linux_syscall_name_clock_settime                  404 ///< clock_settime
#define linux_syscall_name_clock_adjtime                  405 ///< clock_adjtime
#define linux_syscall_name_clock_getres                   406 ///< clock_getres
#define linux_syscall_name_clock_nanosleep                407 ///< clock_nanosleep
#define linux_syscall_name_timer_gettime                  408 ///< timer_gettime
#define linux_syscall_name_timer_settime                  409 ///< timer_settime
#define linux_syscall_name_timerfd_gettime                410 ///< timerfd_gettime
#define linux_syscall_name_timerfd_settime                411 ///< timerfd_settime
#define linux_syscall_name_utimensat                      412 ///< utimensat
#define linux_syscall_name_pselect6                       413 ///< pselect6
#define linux_syscall_name_ppoll                          414 ///< ppoll
// unused
#define linux_syscall_name_io_pgetevents                  416 ///< io_pgetevents
#define linux_syscall_name_recvmmsg                       417 ///< recvmmsg
#define linux_syscall_name_mq_timedsend                   418 ///< mq_timedsend
#define linux_syscall_name_mq_timedreceive                419 ///< mq_timedreceive
#define linux_syscall_name_semtimedop                     420 ///< semtimedop
#define linux_syscall_name_rt_sigtimedwait                421 ///< rt_sigtimedwait
#define linux_syscall_name_futex                          422 ///< futex
#define linux_syscall_name_sched_rr_get_interval          423 ///< sched_rr_get_interval
#define linux_syscall_name_pidfd_send_signal              424 ///< pidfd_send_signal
#define linux_syscall_name_io_uring_setup                 425 ///< io_uring_setup
#define linux_syscall_name_io_uring_enter                 426 ///< io_uring_enter
#define linux_syscall_name_io_uring_register              427 ///< io_uring_register
#define linux_syscall_name_open_tree                      428 ///< open_tree
#define linux_syscall_name_move_mount                     429 ///< move_mount
#define linux_syscall_name_fsopen                         430 ///< fsopen
#define linux_syscall_name_fsconfig                       431 ///< fsconfig
#define linux_syscall_name_fsmount                        432 ///< fsmount
#define linux_syscall_name_fspick                         433 ///< fspick
#define linux_syscall_name_pidfd_open                     434 ///< pidfd_open
#define linux_syscall_name_clone3                         435 ///< clone3
#define linux_syscall_name_close_range                    436 ///< close_range
#define linux_syscall_name_openat2                        437 ///< openat2
#define linux_syscall_name_pidfd_getfd                    438 ///< pidfd_getfd
#define linux_syscall_name_faccessat2                     439 ///< faccessat2
#define linux_syscall_name_process_madvise                440 ///< process_madvise
#define linux_syscall_name_epoll_pwait2                   441 ///< epoll_pwait2
#define linux_syscall_name_mount_setattr                  442 ///< mount_setattr
#define linux_syscall_name_quotactl_fd                    443 ///< quotactl_fd
#define linux_syscall_name_landlock_create_ruleset        444 ///< landlock_create_ruleset
#define linux_syscall_name_landlock_add_rule              445 ///< landlock_add_rule
#define linux_syscall_name_landlock_restrict_self         446 ///< landlock_restrict_self
#define linux_syscall_name_memfd_secret                   447 ///< memfd_secret
#define linux_syscall_name_process_mrelease               448 ///< process_mrelease

#define linux_syscall_name_riscv_flush_icache            (244 + 15) ///< riscv_flush_icache

#endif // !HEADER_LIBLINUX_RISCV32_UNISTD_H_INCLUDED
