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

#ifndef HEADER_LIBLINUX_X86_64_UNISTD_H_INCLUDED
#define HEADER_LIBLINUX_X86_64_UNISTD_H_INCLUDED

// Differences (name/function/number):
// -----------------------------------
// stat newstat 4
// fstat newfstat 5
// lstat newlstat 6
// sendfile sendfile64 40
// uname newuname 63
// umount2 umount 166

#define linux_syscall_name_read                      0 ///< read
#define linux_syscall_name_write                     1 ///< write
#define linux_syscall_name_open                      2 ///< open
#define linux_syscall_name_close                     3 ///< close
#define linux_syscall_name_newstat                   4 ///< newstat
#define linux_syscall_name_newfstat                  5 ///< newfstat
#define linux_syscall_name_newlstat                  6 ///< newlstat
#define linux_syscall_name_poll                      7 ///< poll
#define linux_syscall_name_lseek                     8 ///< lseek
#define linux_syscall_name_mmap                      9 ///< mmap
#define linux_syscall_name_mprotect                 10 ///< mprotect
#define linux_syscall_name_munmap                   11 ///< munmap
#define linux_syscall_name_brk                      12 ///< brk
#define linux_syscall_name_rt_sigaction             13 ///< rt_sigaction
#define linux_syscall_name_rt_sigprocmask           14 ///< rt_sigprocmask
//#define linux_syscall_name_rt_sigreturn           15 // Use linux_rt_sigreturn().
#define linux_syscall_name_ioctl                    16 ///< ioctl
#define linux_syscall_name_pread64                  17 ///< pread64
#define linux_syscall_name_pwrite64                 18 ///< pwrite64
#define linux_syscall_name_readv                    19 ///< readv
#define linux_syscall_name_writev                   20 ///< writev
#define linux_syscall_name_access                   21 ///< access
#define linux_syscall_name_pipe                     22 ///< pipe
#define linux_syscall_name_select                   23 ///< select
#define linux_syscall_name_sched_yield              24 ///< sched_yield
#define linux_syscall_name_mremap                   25 ///< mremap
#define linux_syscall_name_msync                    26 ///< msync
#define linux_syscall_name_mincore                  27 ///< mincore
#define linux_syscall_name_madvise                  28 ///< madvise
#define linux_syscall_name_shmget                   29 ///< shmget
#define linux_syscall_name_shmat                    30 ///< shmat
#define linux_syscall_name_shmctl                   31 ///< shmctl
#define linux_syscall_name_dup                      32 ///< dup
#define linux_syscall_name_dup2                     33 ///< dup2
#define linux_syscall_name_pause                    34 ///< pause
#define linux_syscall_name_nanosleep                35 ///< nanosleep
#define linux_syscall_name_getitimer                36 ///< getitimer
#define linux_syscall_name_alarm                    37 ///< alarm
#define linux_syscall_name_setitimer                38 ///< setitimer
#define linux_syscall_name_getpid                   39 ///< getpid
#define linux_syscall_name_sendfile64               40 ///< sendfile64
#define linux_syscall_name_socket                   41 ///< socket
#define linux_syscall_name_connect                  42 ///< connect
#define linux_syscall_name_accept                   43 ///< accept
#define linux_syscall_name_sendto                   44 ///< sendto
#define linux_syscall_name_recvfrom                 45 ///< recvfrom
#define linux_syscall_name_sendmsg                  46 ///< sendmsg
#define linux_syscall_name_recvmsg                  47 ///< recvmsg
#define linux_syscall_name_shutdown                 48 ///< shutdown
#define linux_syscall_name_bind                     49 ///< bind
#define linux_syscall_name_listen                   50 ///< listen
#define linux_syscall_name_getsockname              51 ///< getsockname
#define linux_syscall_name_getpeername              52 ///< getpeername
#define linux_syscall_name_socketpair               53 ///< socketpair
#define linux_syscall_name_setsockopt               54 ///< setsockopt
#define linux_syscall_name_getsockopt               55 ///< getsockopt
#define linux_syscall_name_clone                    56 ///< clone
#define linux_syscall_name_fork                     57 ///< fork
//#define linux_syscall_name_vfork                  58 // Use linux_vfork().
#define linux_syscall_name_execve                   59 ///< execve
#define linux_syscall_name_exit                     60 ///< exit
#define linux_syscall_name_wait4                    61 ///< wait4
#define linux_syscall_name_kill                     62 ///< kill
#define linux_syscall_name_newuname                 63 ///< newuname
#define linux_syscall_name_semget                   64 ///< semget
#define linux_syscall_name_semop                    65 ///< semop
#define linux_syscall_name_semctl                   66 ///< semctl
#define linux_syscall_name_shmdt                    67 ///< shmdt
#define linux_syscall_name_msgget                   68 ///< msgget
#define linux_syscall_name_msgsnd                   69 ///< msgsnd
#define linux_syscall_name_msgrcv                   70 ///< msgrcv
#define linux_syscall_name_msgctl                   71 ///< msgctl
#define linux_syscall_name_fcntl                    72 ///< fcntl
#define linux_syscall_name_flock                    73 ///< flock
#define linux_syscall_name_fsync                    74 ///< fsync
#define linux_syscall_name_fdatasync                75 ///< fdatasync
#define linux_syscall_name_truncate                 76 ///< truncate
#define linux_syscall_name_ftruncate                77 ///< ftruncate
#define linux_syscall_name_getdents                 78 ///< getdents
#define linux_syscall_name_getcwd                   79 ///< getcwd
#define linux_syscall_name_chdir                    80 ///< chdir
#define linux_syscall_name_fchdir                   81 ///< fchdir
#define linux_syscall_name_rename                   82 ///< rename
#define linux_syscall_name_mkdir                    83 ///< mkdir
#define linux_syscall_name_rmdir                    84 ///< rmdir
#define linux_syscall_name_creat                    85 ///< creat
#define linux_syscall_name_link                     86 ///< link
#define linux_syscall_name_unlink                   87 ///< unlink
#define linux_syscall_name_symlink                  88 ///< symlink
#define linux_syscall_name_readlink                 89 ///< readlink
#define linux_syscall_name_chmod                    90 ///< chmod
#define linux_syscall_name_fchmod                   91 ///< fchmod
#define linux_syscall_name_chown                    92 ///< chown
#define linux_syscall_name_fchown                   93 ///< fchown
#define linux_syscall_name_lchown                   94 ///< lchown
#define linux_syscall_name_umask                    95 ///< umask
#define linux_syscall_name_gettimeofday             96 ///< gettimeofday
#define linux_syscall_name_getrlimit                97 ///< getrlimit
#define linux_syscall_name_getrusage                98 ///< getrusage
#define linux_syscall_name_sysinfo                  99 ///< sysinfo
#define linux_syscall_name_times                   100 ///< times
#define linux_syscall_name_ptrace                  101 ///< ptrace
#define linux_syscall_name_getuid                  102 ///< getuid
#define linux_syscall_name_syslog                  103 ///< syslog
#define linux_syscall_name_getgid                  104 ///< getgid
#define linux_syscall_name_setuid                  105 ///< setuid
#define linux_syscall_name_setgid                  106 ///< setgid
#define linux_syscall_name_geteuid                 107 ///< geteuid
#define linux_syscall_name_getegid                 108 ///< getegid
#define linux_syscall_name_setpgid                 109 ///< setpgid
#define linux_syscall_name_getppid                 110 ///< getppid
#define linux_syscall_name_getpgrp                 111 ///< getpgrp
#define linux_syscall_name_setsid                  112 ///< setsid
#define linux_syscall_name_setreuid                113 ///< setreuid
#define linux_syscall_name_setregid                114 ///< setregid
#define linux_syscall_name_getgroups               115 ///< getgroups
#define linux_syscall_name_setgroups               116 ///< setgroups
#define linux_syscall_name_setresuid               117 ///< setresuid
#define linux_syscall_name_getresuid               118 ///< getresuid
#define linux_syscall_name_setresgid               119 ///< setresgid
#define linux_syscall_name_getresgid               120 ///< getresgid
#define linux_syscall_name_getpgid                 121 ///< getpgid
#define linux_syscall_name_setfsuid                122 ///< setfsuid
#define linux_syscall_name_setfsgid                123 ///< setfsgid
#define linux_syscall_name_getsid                  124 ///< getsid
#define linux_syscall_name_capget                  125 ///< capget
#define linux_syscall_name_capset                  126 ///< capset
#define linux_syscall_name_rt_sigpending           127 ///< rt_sigpending
#define linux_syscall_name_rt_sigtimedwait         128 ///< rt_sigtimedwait
#define linux_syscall_name_rt_sigqueueinfo         129 ///< rt_sigqueueinfo
#define linux_syscall_name_rt_sigsuspend           130 ///< rt_sigsuspend
#define linux_syscall_name_sigaltstack             131 ///< sigaltstack
#define linux_syscall_name_utime                   132 ///< utime
#define linux_syscall_name_mknod                   133 ///< mknod
//#define linux_syscall_name_uselib                134 // unused
#define linux_syscall_name_personality             135 ///< personality
#define linux_syscall_name_ustat                   136 ///< ustat
#define linux_syscall_name_statfs                  137 ///< statfs
#define linux_syscall_name_fstatfs                 138 ///< fstatfs
#define linux_syscall_name_sysfs                   139 ///< sysfs
#define linux_syscall_name_getpriority             140 ///< getpriority
#define linux_syscall_name_setpriority             141 ///< setpriority
#define linux_syscall_name_sched_setparam          142 ///< sched_setparam
#define linux_syscall_name_sched_getparam          143 ///< sched_getparam
#define linux_syscall_name_sched_setscheduler      144 ///< sched_setscheduler
#define linux_syscall_name_sched_getscheduler      145 ///< sched_getscheduler
#define linux_syscall_name_sched_get_priority_max  146 ///< sched_get_priority_max
#define linux_syscall_name_sched_get_priority_min  147 ///< sched_get_priority_min
#define linux_syscall_name_sched_rr_get_interval   148 ///< sched_rr_get_interval
#define linux_syscall_name_mlock                   149 ///< mlock
#define linux_syscall_name_munlock                 150 ///< munlock
#define linux_syscall_name_mlockall                151 ///< mlockall
#define linux_syscall_name_munlockall              152 ///< munlockall
#define linux_syscall_name_vhangup                 153 ///< vhangup
#define linux_syscall_name_modify_ldt              154 ///< modify_ldt
#define linux_syscall_name_pivot_root              155 ///< pivot_root
//#define linux_syscall_name_sysctl                156 // unimplemented
#define linux_syscall_name_prctl                   157 ///< prctl
#define linux_syscall_name_arch_prctl              158 ///< arch_prctl
#define linux_syscall_name_adjtimex                159 ///< adjtimex
#define linux_syscall_name_setrlimit               160 ///< setrlimit
#define linux_syscall_name_chroot                  161 ///< chroot
#define linux_syscall_name_sync                    162 ///< sync
#define linux_syscall_name_acct                    163 ///< acct
#define linux_syscall_name_settimeofday            164 ///< settimeofday
#define linux_syscall_name_mount                   165 ///< mount
#define linux_syscall_name_umount                  166 ///< umount
#define linux_syscall_name_swapon                  167 ///< swapon
#define linux_syscall_name_swapoff                 168 ///< swapoff
#define linux_syscall_name_reboot                  169 ///< reboot
#define linux_syscall_name_sethostname             170 ///< sethostname
#define linux_syscall_name_setdomainname           171 ///< setdomainname
#define linux_syscall_name_iopl                    172 ///< iopl
#define linux_syscall_name_ioperm                  173 ///< ioperm
//#define linux_syscall_name_create_module         174 // unused
#define linux_syscall_name_init_module             175 ///< init_module
#define linux_syscall_name_delete_module           176 ///< delete_module
//#define linux_syscall_name_get_kernel_syms       177 // unused
//#define linux_syscall_name_query_module          178 // unused
#define linux_syscall_name_quotactl                179 ///< quotactl
//#define linux_syscall_name_nfsservctl            180 // unused
//#define linux_syscall_name_getpmsg               181 // unused
//#define linux_syscall_name_putpmsg               182 // unused
//#define linux_syscall_name_afs_syscall           183 // unused
//#define linux_syscall_name_tuxcall               184 // unused
//#define linux_syscall_name_security              185 // unused
#define linux_syscall_name_gettid                  186 ///< gettid
#define linux_syscall_name_readahead               187 ///< readahead
#define linux_syscall_name_setxattr                188 ///< setxattr
#define linux_syscall_name_lsetxattr               189 ///< lsetxattr
#define linux_syscall_name_fsetxattr               190 ///< fsetxattr
#define linux_syscall_name_getxattr                191 ///< getxattr
#define linux_syscall_name_lgetxattr               192 ///< lgetxattr
#define linux_syscall_name_fgetxattr               193 ///< fgetxattr
#define linux_syscall_name_listxattr               194 ///< listxattr
#define linux_syscall_name_llistxattr              195 ///< llistxattr
#define linux_syscall_name_flistxattr              196 ///< flistxattr
#define linux_syscall_name_removexattr             197 ///< removexattr
#define linux_syscall_name_lremovexattr            198 ///< lremovexattr
#define linux_syscall_name_fremovexattr            199 ///< fremovexattr
#define linux_syscall_name_tkill                   200 ///< tkill
#define linux_syscall_name_time                    201 ///< time
#define linux_syscall_name_futex                   202 ///< futex
#define linux_syscall_name_sched_setaffinity       203 ///< sched_setaffinity
#define linux_syscall_name_sched_getaffinity       204 ///< sched_getaffinity
//#define linux_syscall_name_set_thread_area       205 // unused
#define linux_syscall_name_io_setup                206 ///< io_setup
#define linux_syscall_name_io_destroy              207 ///< io_destroy
#define linux_syscall_name_io_getevents            208 ///< io_getevents
#define linux_syscall_name_io_submit               209 ///< io_submit
#define linux_syscall_name_io_cancel               210 ///< io_cancel
//#define linux_syscall_name_get_thread_area       211 // unused
#define linux_syscall_name_lookup_dcookie          212 ///< lookup_dcookie
#define linux_syscall_name_epoll_create            213 ///< epoll_create
//#define linux_syscall_name_epoll_ctl_old         214 // unused
//#define linux_syscall_name_epoll_wait_old        215 // unused
#define linux_syscall_name_remap_file_pages        216 ///< remap_file_pages
#define linux_syscall_name_getdents64              217 ///< getdents64
#define linux_syscall_name_set_tid_address         218 ///< set_tid_address
//#define linux_syscall_name_restart_syscall       219 // Don't use in userspace.
#define linux_syscall_name_semtimedop              220 ///< semtimedop
#define linux_syscall_name_fadvise64               221 ///< fadvise64
#define linux_syscall_name_timer_create            222 ///< timer_create
#define linux_syscall_name_timer_settime           223 ///< timer_settime
#define linux_syscall_name_timer_gettime           224 ///< timer_gettime
#define linux_syscall_name_timer_getoverrun        225 ///< timer_getoverrun
#define linux_syscall_name_timer_delete            226 ///< timer_delete
#define linux_syscall_name_clock_settime           227 ///< clock_settime
#define linux_syscall_name_clock_gettime           228 ///< clock_gettime
#define linux_syscall_name_clock_getres            229 ///< clock_getres
#define linux_syscall_name_clock_nanosleep         230 ///< clock_nanosleep
#define linux_syscall_name_exit_group              231 ///< exit_group
#define linux_syscall_name_epoll_wait              232 ///< epoll_wait
#define linux_syscall_name_epoll_ctl               233 ///< epoll_ctl
#define linux_syscall_name_tgkill                  234 ///< tgkill
#define linux_syscall_name_utimes                  235 ///< utimes
//#define linux_syscall_name_vserver               236 // unused
#define linux_syscall_name_mbind                   237 ///< mbind
#define linux_syscall_name_set_mempolicy           238 ///< set_mempolicy
#define linux_syscall_name_get_mempolicy           239 ///< get_mempolicy
#define linux_syscall_name_mq_open                 240 ///< mq_open
#define linux_syscall_name_mq_unlink               241 ///< mq_unlink
#define linux_syscall_name_mq_timedsend            242 ///< mq_timedsend
#define linux_syscall_name_mq_timedreceive         243 ///< mq_timedreceive
#define linux_syscall_name_mq_notify               244 ///< mq_notify
#define linux_syscall_name_mq_getsetattr           245 ///< mq_getsetattr
#define linux_syscall_name_kexec_load              246 ///< kexec_load
#define linux_syscall_name_waitid                  247 ///< waitid
#define linux_syscall_name_add_key                 248 ///< add_key
#define linux_syscall_name_request_key             249 ///< request_key
#define linux_syscall_name_keyctl                  250 ///< keyctl
#define linux_syscall_name_ioprio_set              251 ///< ioprio_set
#define linux_syscall_name_ioprio_get              252 ///< ioprio_get
#define linux_syscall_name_inotify_init            253 ///< inotify_init
#define linux_syscall_name_inotify_add_watch       254 ///< inotify_add_watch
#define linux_syscall_name_inotify_rm_watch        255 ///< inotify_rm_watch
#define linux_syscall_name_migrate_pages           256 ///< migrate_pages
#define linux_syscall_name_openat                  257 ///< openat
#define linux_syscall_name_mkdirat                 258 ///< mkdirat
#define linux_syscall_name_mknodat                 259 ///< mknodat
#define linux_syscall_name_fchownat                260 ///< fchownat
#define linux_syscall_name_futimesat               261 ///< futimesat
#define linux_syscall_name_newfstatat              262 ///< newfstatat
#define linux_syscall_name_unlinkat                263 ///< unlinkat
#define linux_syscall_name_renameat                264 ///< renameat
#define linux_syscall_name_linkat                  265 ///< linkat
#define linux_syscall_name_symlinkat               266 ///< symlinkat
#define linux_syscall_name_readlinkat              267 ///< readlinkat
#define linux_syscall_name_fchmodat                268 ///< fchmodat
#define linux_syscall_name_faccessat               269 ///< faccessat
#define linux_syscall_name_pselect6                270 ///< pselect6
#define linux_syscall_name_ppoll                   271 ///< ppoll
#define linux_syscall_name_unshare                 272 ///< unshare
#define linux_syscall_name_set_robust_list         273 ///< set_robust_list
#define linux_syscall_name_get_robust_list         274 ///< get_robust_list
#define linux_syscall_name_splice                  275 ///< splice
#define linux_syscall_name_tee                     276 ///< tee
#define linux_syscall_name_sync_file_range         277 ///< sync_file_range
#define linux_syscall_name_vmsplice                278 ///< vmsplice
#define linux_syscall_name_move_pages              279 ///< move_pages
#define linux_syscall_name_utimensat               280 ///< utimensat
#define linux_syscall_name_epoll_pwait             281 ///< epoll_pwait
#define linux_syscall_name_signalfd                282 ///< signalfd
#define linux_syscall_name_timerfd_create          283 ///< timerfd_create
#define linux_syscall_name_eventfd                 284 ///< eventfd
#define linux_syscall_name_fallocate               285 ///< fallocate
#define linux_syscall_name_timerfd_settime         286 ///< timerfd_settime
#define linux_syscall_name_timerfd_gettime         287 ///< timerfd_gettime
#define linux_syscall_name_accept4                 288 ///< accept4
#define linux_syscall_name_signalfd4               289 ///< signalfd4
#define linux_syscall_name_eventfd2                290 ///< eventfd2
#define linux_syscall_name_epoll_create1           291 ///< epoll_create1
#define linux_syscall_name_dup3                    292 ///< dup3
#define linux_syscall_name_pipe2                   293 ///< pipe2
#define linux_syscall_name_inotify_init1           294 ///< inotify_init1
#define linux_syscall_name_preadv                  295 ///< preadv
#define linux_syscall_name_pwritev                 296 ///< pwritev
#define linux_syscall_name_rt_tgsigqueueinfo       297 ///< rt_tgsigqueueinfo
#define linux_syscall_name_perf_event_open         298 ///< perf_event_open
#define linux_syscall_name_recvmmsg                299 ///< recvmmsg
#define linux_syscall_name_fanotify_init           300 ///< fanotify_init
#define linux_syscall_name_fanotify_mark           301 ///< fanotify_mark
#define linux_syscall_name_prlimit64               302 ///< prlimit64
#define linux_syscall_name_name_to_handle_at       303 ///< name_to_handle_at
#define linux_syscall_name_open_by_handle_at       304 ///< open_by_handle_at
#define linux_syscall_name_clock_adjtime           305 ///< clock_adjtime
#define linux_syscall_name_syncfs                  306 ///< syncfs
#define linux_syscall_name_sendmmsg                307 ///< sendmmsg
#define linux_syscall_name_setns                   308 ///< setns
#define linux_syscall_name_getcpu                  309 ///< getcpu
#define linux_syscall_name_process_vm_readv        310 ///< process_vm_readv
#define linux_syscall_name_process_vm_writev       311 ///< process_vm_writev
#define linux_syscall_name_kcmp                    312 ///< kcmp
#define linux_syscall_name_finit_module            313 ///< finit_module
#define linux_syscall_name_sched_setattr           314 ///< sched_setattr
#define linux_syscall_name_sched_getattr           315 ///< sched_getattr
#define linux_syscall_name_renameat2               316 ///< renameat2
#define linux_syscall_name_seccomp                 317 ///< seccomp
#define linux_syscall_name_getrandom               318 ///< getrandom
#define linux_syscall_name_memfd_create            319 ///< memfd_create
#define linux_syscall_name_kexec_file_load         320 ///< kexec_file_load
#define linux_syscall_name_bpf                     321 ///< bpf
#define linux_syscall_name_execveat                322 ///< execveat
#define linux_syscall_name_userfaultfd             323 ///< userfaultfd
#define linux_syscall_name_membarrier              324 ///< membarrier
#define linux_syscall_name_mlock2                  325 ///< mlock2
#define linux_syscall_name_copy_file_range         326 ///< copy_file_range
#define linux_syscall_name_preadv2                 327 ///< preadv2
#define linux_syscall_name_pwritev2                328 ///< pwritev2
#define linux_syscall_name_pkey_mprotect           329 ///< pkey_mprotect
#define linux_syscall_name_pkey_alloc              330 ///< pkey_alloc
#define linux_syscall_name_pkey_free               331 ///< pkey_free
#define linux_syscall_name_statx                   332 ///< statx
#define linux_syscall_name_io_pgetevents           333 ///< io_pgetevents
#define linux_syscall_name_rseq                    334 ///< rseq
// ...
// 335 to 423 are unused, so that the numbers are the same as on 32-bit systems
// ...
#define linux_syscall_name_pidfd_send_signal       424 ///< pidfd_send_signal
#define linux_syscall_name_io_uring_setup          425 ///< io_uring_setup
#define linux_syscall_name_io_uring_enter          426 ///< io_uring_enter
#define linux_syscall_name_io_uring_register       427 ///< io_uring_register
#define linux_syscall_name_open_tree               428 ///< open_tree
#define linux_syscall_name_move_mount              429 ///< move_mount
#define linux_syscall_name_fsopen                  430 ///< fsopen
#define linux_syscall_name_fsconfig                431 ///< fsconfig
#define linux_syscall_name_fsmount                 432 ///< fsmount
#define linux_syscall_name_fspick                  433 ///< fspick
#define linux_syscall_name_pidfd_open              434 ///< pidfd_open
#define linux_syscall_name_clone3                  435 ///< clone3
#define linux_syscall_name_close_range             436 ///< close_range
#define linux_syscall_name_openat2                 437 ///< openat2
#define linux_syscall_name_pidfd_getfd             438 ///< pidfd_getfd
#define linux_syscall_name_faccessat2              439 ///< faccessat2
#define linux_syscall_name_process_madvise         440 ///< process_madvise
#define linux_syscall_name_epoll_pwait2            441 ///< epoll_pwait2
#define linux_syscall_name_mount_setattr           442 ///< mount_setattr
#define linux_syscall_name_quotactl_fd             443 ///< quotactl_fd
#define linux_syscall_name_landlock_create_ruleset 444 ///< landlock_create_ruleset
#define linux_syscall_name_landlock_add_rule       445 ///< landlock_add_rule
#define linux_syscall_name_landlock_restrict_self  446 ///< landlock_restrict_self
#define linux_syscall_name_memfd_secret            447 ///< memfd_secret
#define linux_syscall_name_process_mrelease        448 ///< process_mrelease

#endif // !HEADER_LIBLINUX_X86_64_UNISTD_H_INCLUDED
