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

#ifndef HEADER_LIBLINUX_ARM_EABI_UNISTD_H_INCLUDED
#define HEADER_LIBLINUX_ARM_EABI_UNISTD_H_INCLUDED

// Differences (name/function/number):
// -----------------------------------
// lchown lchown16 16
// setuid setuid16 23
// getuid getuid16 24
// setgid setgid16 46
// getgid getgid16 47
// geteuid geteuid16 49
// getegid getegid16 50
// umount2 umount 52
// setreuid setreuid16 70
// setregid setregid16 71
// getgroups getgroups16 80
// setgroups setgroups16 81
// fchown fchown16 95
// stat newstat 106
// lstat newlstat 107
// fstat newfstat 108
// sigreturn sigreturn_wrapper 119
// uname newuname 122
// adjtimex adjtimex_time32 124
// setfsuid setfsuid16 138
// setfsgid setfsgid16 139
// newselect select 142
// sched_rr_get_interval sched_rr_get_interval_time32 161
// nanosleep nanosleep_time32 162
// setresuid setresuid16 164
// getresuid getresuid16 165
// setresgid setresgid16 170
// getresgid getresgid16 171
// rt_sigreturn rt_sigreturn_wrapper 173
// rt_sigtimedwait rt_sigtimedwait_time32 177
// chown chown16 182
// ugetrlimit getrlimit 191
// lchown32 lchown 198
// getuid32 getuid 199
// getgid32 getgid 200
// geteuid32 geteuid 201
// getegid32 getegid 202
// setreuid32 setreuid 203
// setregid32 setregid 204
// getgroups32 getgroups 205
// setgroups32 setgroups 206
// fchown32 fchown 207
// setresuid32 setresuid 208
// getresuid32 getresuid 209
// setresgid32 setresgid 210
// getresgid32 getresgid 211
// chown32 chown 212
// setuid32 setuid 213
// setgid32 setgid 214
// setfsuid32 setfsuid 215
// setfsgid32 setfsgid 216
// futex futex_time32 240
// io_getevents io_getevents_time32 245
// timer_settime timer_settime32 258
// timer_gettime timer_gettime32 259
// clock_settime clock_settime32 262
// clock_gettime clock_gettime32 263
// clock_getres clock_getres_time32 264
// clock_nanosleep clock_nanosleep_time32 265
// utimes utimes_time32 269
// fadvise64_64 arm_fadvise64_64 270
// mq_timedsend mq_timedsend_time32 276
// mq_timedreceive mq_timedreceive_time32 277
// semctl old_semctl 300
// msgctl old_msgctl 304
// shmctl old_shmctl 308
// semtimedop semtimedop_time32 312
// futimesat futimesat_time32 326
// pselect6 pselect6_time32 335
// ppoll ppoll_time32 336
// sync_file_range2 arm_sync_file_range 341
// utimensat utimensat_time32 348
// timerfd_settime timerfd_settime32 353
// timerfd_gettime timerfd_gettime32 354
// recvmmsg recvmmsg_time32 365
// clock_adjtime clock_adjtime32 372
// io_pgetevents io_pgetevents_time32 399
// clock_gettime64 clock_gettime 403
// clock_settime64 clock_settime 404
// clock_adjtime64 clock_adjtime 405
// clock_getres_time64 clock_getres 406
// clock_nanosleep_time64 clock_nanosleep 407
// timer_gettime64 timer_gettime 408
// timer_settime64 timer_settime 409
// timerfd_gettime64 timerfd_gettime 410
// timerfd_settime64 timerfd_settime 411
// utimensat_time64 utimensat 412
// pselect6_time64 pselect6 413
// ppoll_time64 ppoll 414
// io_pgetevents_time64 io_pgetevents 416
// recvmmsg_time64 recvmmsg 417
// mq_timedsend_time64 mq_timedsend 418
// mq_timedreceive_time64 mq_timedreceive 419
// semtimedop_time64 semtimedop 420
// rt_sigtimedwait_time64 rt_sigtimedwait 421
// futex_time64 futex 422
// sched_rr_get_interval_time64 sched_rr_get_interval 423

//#define linux_syscall_name_restart_syscall              0 // Don't use in userspace.
#define linux_syscall_name_exit                           1 ///< exit
#define linux_syscall_name_fork                           2 ///< fork
#define linux_syscall_name_read                           3 ///< read
#define linux_syscall_name_write                          4 ///< write
#define linux_syscall_name_open                           5 ///< open
#define linux_syscall_name_close                          6 ///< close
//#define linux_waitpid                                   7 // unused
#define linux_syscall_name_creat                          8 ///< creat
#define linux_syscall_name_link                           9 ///< link
#define linux_syscall_name_unlink                        10 ///< unlink
#define linux_syscall_name_execve                        11 ///< execve
#define linux_syscall_name_chdir                         12 ///< chdir
//#define linux_time                                     13 // oabi
#define linux_syscall_name_mknod                         14 ///< mknod
#define linux_syscall_name_chmod                         15 ///< chmod
#define linux_syscall_name_lchown16                      16 ///< lchown16
//#define linux_break                                    17 // unused
//#define linux_stat                                     18 // unused
#define linux_syscall_name_lseek                         19 ///< lseek
#define linux_syscall_name_getpid                        20 ///< getpid
#define linux_syscall_name_mount                         21 ///< mount
//#define linux_oldumount                                22 // oabi
#define linux_syscall_name_setuid16                      23 ///< setuid16
#define linux_syscall_name_getuid16                      24 ///< getuid16
//#define linux_stime                                    25 // oabi
#define linux_syscall_name_ptrace                        26 ///< ptrace
//#define linux_alarm                                    27 // oabi
//#define linux_fstat                                    28 // unused
#define linux_syscall_name_pause                         29 ///< pause
//#define linux_utime                                    30 // oabi
//#define linux_stty                                     31 // unused
//#define linux_gtty                                     32 // unused
#define linux_syscall_name_access                        33 ///< access
#define linux_syscall_name_nice                          34 ///< nice
//#define linux_ftime                                    35 // unused
#define linux_syscall_name_sync                          36 ///< sync
#define linux_syscall_name_kill                          37 ///< kill
#define linux_syscall_name_rename                        38 ///< rename
#define linux_syscall_name_mkdir                         39 ///< mkdir
#define linux_syscall_name_rmdir                         40 ///< rmdir
#define linux_syscall_name_dup                           41 ///< dup
#define linux_syscall_name_pipe                          42 ///< pipe
#define linux_syscall_name_times                         43 ///< times
//#define linux_prof                                     44 // unused
#define linux_syscall_name_brk                           45 ///< brk
#define linux_syscall_name_setgid16                      46 ///< setgid16
#define linux_syscall_name_getgid16                      47 ///< getgid16
//#define linux_signal                                   48 // unused
#define linux_syscall_name_geteuid16                     49 ///< geteuid16
#define linux_syscall_name_getegid16                     50 ///< getegid16
#define linux_syscall_name_acct                          51 ///< acct
#define linux_syscall_name_umount                        52 ///< umount
//#define linux_lock                                     53 // unused
#define linux_syscall_name_ioctl                         54 ///< ioctl
#define linux_syscall_name_fcntl                         55 ///< fcntl
//#define linux_mpx                                      56 // unused
#define linux_syscall_name_setpgid                       57 ///< setpgid
//#define linux_ulimit                                   58 // unused
//#define linux_olduname                                 59 // unused
#define linux_syscall_name_umask                         60 ///< umask
#define linux_syscall_name_chroot                        61 ///< chroot
#define linux_syscall_name_ustat                         62 ///< ustat
#define linux_syscall_name_dup2                          63 ///< dup2
#define linux_syscall_name_getppid                       64 ///< getppid
#define linux_syscall_name_getpgrp                       65 ///< getpgrp
#define linux_syscall_name_setsid                        66 ///< setsid
#define linux_syscall_name_sigaction                     67 ///< sigaction
//#define linux_sgetmask                                 68 // unused
//#define linux_ssetmask                                 69 // unused
#define linux_syscall_name_setreuid16                    70 ///< setreuid16
#define linux_syscall_name_setregid16                    71 ///< setregid16
#define linux_syscall_name_sigsuspend                    72 ///< sigsuspend
#define linux_syscall_name_sigpending                    73 ///< sigpending
#define linux_syscall_name_sethostname                   74 ///< sethostname
#define linux_syscall_name_setrlimit                     75 ///< setrlimit
//#define linux_old_getrlimit                            76 // oabi
#define linux_syscall_name_getrusage                     77 ///< getrusage
#define linux_syscall_name_gettimeofday                  78 ///< gettimeofday
#define linux_syscall_name_settimeofday                  79 ///< settimeofday
#define linux_syscall_name_getgroups16                   80 ///< getgroups16
#define linux_syscall_name_setgroups16                   81 ///< setgroups16
//#define linux_old_select                               82 // oabi
#define linux_syscall_name_symlink                       83 ///< symlink
//#define linux_lstat                                    84 // unused
#define linux_syscall_name_readlink                      85 ///< readlink
#define linux_syscall_name_uselib                        86 ///< uselib
#define linux_syscall_name_swapon                        87 ///< swapon
#define linux_syscall_name_reboot                        88 ///< reboot
//#define linux_old_readdir                              89 // oabi
//#define linux_old_mmap                                 90 // oabi
#define linux_syscall_name_munmap                        91 ///< munmap
#define linux_syscall_name_truncate                      92 ///< truncate
#define linux_syscall_name_ftruncate                     93 ///< ftruncate
#define linux_syscall_name_fchmod                        94 ///< fchmod
#define linux_syscall_name_fchown16                      95 ///< fchown16
#define linux_syscall_name_getpriority                   96 ///< getpriority
#define linux_syscall_name_setpriority                   97 ///< setpriority
//#define linux_profil                                   98 // unused
#define linux_syscall_name_statfs                        99 ///< statfs
#define linux_syscall_name_fstatfs                      100 ///< fstatfs
//#define linux_ioperm                                  101 // unused
//#define linux_socketcall                              102 // oabi
#define linux_syscall_name_syslog                       103 ///< syslog
#define linux_syscall_name_setitimer                    104 ///< setitimer
#define linux_syscall_name_getitimer                    105 ///< getitimer
#define linux_syscall_name_newstat                      106 ///< newstat
#define linux_syscall_name_newlstat                     107 ///< newlstat
#define linux_syscall_name_newfstat                     108 ///< newfstat
//#define linux_uname                                   109 // unused
//#define linux_iopl                                    110 // unused
#define linux_syscall_name_vhangup                      111 ///< vhangup
//#define linux_idle                                    112 // unused
//#define linux_syscall                                 113 // oabi
#define linux_syscall_name_wait4                        114 ///< wait4
#define linux_syscall_name_swapoff                      115 ///< swapoff
#define linux_syscall_name_sysinfo                      116 ///< sysinfo
//#define linux_ipc                                     117 // oabi
#define linux_syscall_name_fsync                        118 ///< fsync
//#define linux_syscall_name_sigreturn_wrapper          119 // Use linux_sigreturn().
#define linux_syscall_name_clone                        120 ///< clone
#define linux_syscall_name_setdomainname                121 ///< setdomainname
#define linux_syscall_name_newuname                     122 ///< newuname
//#define linux_modify_ldt                              123 // unused
#define linux_syscall_name_adjtimex_time32              124 ///< adjtimex_time32
#define linux_syscall_name_mprotect                     125 ///< mprotect
#define linux_syscall_name_sigprocmask                  126 ///< sigprocmask
//#define linux_create_module                           127 // unused
#define linux_syscall_name_init_module                  128 ///< init_module
#define linux_syscall_name_delete_module                129 ///< delete_module
//#define linux_get_kernel_syms                         130 // unused
#define linux_syscall_name_quotactl                     131 ///< quotactl
#define linux_syscall_name_getpgid                      132 ///< getpgid
#define linux_syscall_name_fchdir                       133 ///< fchdir
#define linux_syscall_name_bdflush                      134 ///< bdflush
#define linux_syscall_name_sysfs                        135 ///< sysfs
#define linux_syscall_name_personality                  136 ///< personality
//#define linux_afs_syscall                             137 // unused
#define linux_syscall_name_setfsuid16                   138 ///< setfsuid16
#define linux_syscall_name_setfsgid16                   139 ///< setfsgid16
#define linux_syscall_name_llseek                       140 ///< llseek
#define linux_syscall_name_getdents                     141 ///< getdents
#define linux_syscall_name_select                       142 ///< select
#define linux_syscall_name_flock                        143 ///< flock
#define linux_syscall_name_msync                        144 ///< msync
#define linux_syscall_name_readv                        145 ///< readv
#define linux_syscall_name_writev                       146 ///< writev
#define linux_syscall_name_getsid                       147 ///< getsid
#define linux_syscall_name_fdatasync                    148 ///< fdatasync
//#define linux_syscall_name_sysctl                     149 // unimplemented
#define linux_syscall_name_mlock                        150 ///< mlock
#define linux_syscall_name_munlock                      151 ///< munlock
#define linux_syscall_name_mlockall                     152 ///< mlockall
#define linux_syscall_name_munlockall                   153 ///< munlockall
#define linux_syscall_name_sched_setparam               154 ///< sched_setparam
#define linux_syscall_name_sched_getparam               155 ///< sched_getparam
#define linux_syscall_name_sched_setscheduler           156 ///< sched_setscheduler
#define linux_syscall_name_sched_getscheduler           157 ///< sched_getscheduler
#define linux_syscall_name_sched_yield                  158 ///< sched_yield
#define linux_syscall_name_sched_get_priority_max       159 ///< sched_get_priority_max
#define linux_syscall_name_sched_get_priority_min       160 ///< sched_get_priority_min
#define linux_syscall_name_sched_rr_get_interval_time32 161 ///< sched_rr_get_interval_time32
#define linux_syscall_name_nanosleep_time32             162 ///< nanosleep_time32
#define linux_syscall_name_mremap                       163 ///< mremap
#define linux_syscall_name_setresuid16                  164 ///< setresuid16
#define linux_syscall_name_getresuid16                  165 ///< getresuid16
//#define linux_vm86                                    166 // unused
//#define linux_query_module                            167 // unused
#define linux_syscall_name_poll                         168 ///< poll
//#define linux_nfsservctl                              169 // unused
#define linux_syscall_name_setresgid16                  170 ///< setresgid16
#define linux_syscall_name_getresgid16                  171 ///< getresgid16
#define linux_syscall_name_prctl                        172 ///< prctl
//#define linux_syscall_name_rt_sigreturn_wrapper       173 // Use linux_rt_sigreturn().
#define linux_syscall_name_rt_sigaction                 174 ///< rt_sigaction
#define linux_syscall_name_rt_sigprocmask               175 ///< rt_sigprocmask
#define linux_syscall_name_rt_sigpending                176 ///< rt_sigpending
#define linux_syscall_name_rt_sigtimedwait_time32       177 ///< rt_sigtimedwait_time32
#define linux_syscall_name_rt_sigqueueinfo              178 ///< rt_sigqueueinfo
#define linux_syscall_name_rt_sigsuspend                179 ///< rt_sigsuspend
#define linux_syscall_name_pread64                      180 ///< pread64
#define linux_syscall_name_pwrite64                     181 ///< pwrite64
#define linux_syscall_name_chown16                      182 ///< chown16
#define linux_syscall_name_getcwd                       183 ///< getcwd
#define linux_syscall_name_capget                       184 ///< capget
#define linux_syscall_name_capset                       185 ///< capset
#define linux_syscall_name_sigaltstack                  186 ///< sigaltstack
#define linux_syscall_name_sendfile                     187 ///< sendfile
// unused
// unused
#define linux_syscall_name_vfork                        190 ///< vfork
#define linux_syscall_name_getrlimit                    191 ///< getrlimit
#define linux_syscall_name_mmap_pgoff                   192 ///< mmap_pgoff
#define linux_syscall_name_truncate64                   193 ///< truncate64
#define linux_syscall_name_ftruncate64                  194 ///< ftruncate64
#define linux_syscall_name_stat64                       195 ///< stat64
#define linux_syscall_name_lstat64                      196 ///< lstat64
#define linux_syscall_name_fstat64                      197 ///< fstat64
#define linux_syscall_name_lchown                       198 ///< lchown
#define linux_syscall_name_getuid                       199 ///< getuid
#define linux_syscall_name_getgid                       200 ///< getgid
#define linux_syscall_name_geteuid                      201 ///< geteuid
#define linux_syscall_name_getegid                      202 ///< getegid
#define linux_syscall_name_setreuid                     203 ///< setreuid
#define linux_syscall_name_setregid                     204 ///< setregid
#define linux_syscall_name_getgroups                    205 ///< getgroups
#define linux_syscall_name_setgroups                    206 ///< setgroups
#define linux_syscall_name_fchown                       207 ///< fchown
#define linux_syscall_name_setresuid                    208 ///< setresuid
#define linux_syscall_name_getresuid                    209 ///< getresuid
#define linux_syscall_name_setresgid                    210 ///< setresgid
#define linux_syscall_name_getresgid                    211 ///< getresgid
#define linux_syscall_name_chown                        212 ///< chown
#define linux_syscall_name_setuid                       213 ///< setuid
#define linux_syscall_name_setgid                       214 ///< setgid
#define linux_syscall_name_setfsuid                     215 ///< setfsuid
#define linux_syscall_name_setfsgid                     216 ///< setfsgid
#define linux_syscall_name_getdents64                   217 ///< getdents64
#define linux_syscall_name_pivot_root                   218 ///< pivot_root
#define linux_syscall_name_mincore                      219 ///< mincore
#define linux_syscall_name_madvise                      220 ///< madvise
#define linux_syscall_name_fcntl64                      221 ///< fcntl64
//#define linux_syscall_name_tux                        222 // unused
// unused
#define linux_syscall_name_gettid                       224 ///< gettid
#define linux_syscall_name_readahead                    225 ///< readahead
#define linux_syscall_name_setxattr                     226 ///< setxattr
#define linux_syscall_name_lsetxattr                    227 ///< lsetxattr
#define linux_syscall_name_fsetxattr                    228 ///< fsetxattr
#define linux_syscall_name_getxattr                     229 ///< getxattr
#define linux_syscall_name_lgetxattr                    230 ///< lgetxattr
#define linux_syscall_name_fgetxattr                    231 ///< fgetxattr
#define linux_syscall_name_listxattr                    232 ///< listxattr
#define linux_syscall_name_llistxattr                   233 ///< llistxattr
#define linux_syscall_name_flistxattr                   234 ///< flistxattr
#define linux_syscall_name_removexattr                  235 ///< removexattr
#define linux_syscall_name_lremovexattr                 236 ///< lremovexattr
#define linux_syscall_name_fremovexattr                 237 ///< fremovexattr
#define linux_syscall_name_tkill                        238 ///< tkill
#define linux_syscall_name_sendfile64                   239 ///< sendfile64
#define linux_syscall_name_futex_time32                 240 ///< futex_time32
#define linux_syscall_name_sched_setaffinity            241 ///< sched_setaffinity
#define linux_syscall_name_sched_getaffinity            242 ///< sched_getaffinity
#define linux_syscall_name_io_setup                     243 ///< io_setup
#define linux_syscall_name_io_destroy                   244 ///< io_destroy
#define linux_syscall_name_io_getevents_time32          245 ///< io_getevents_time32
#define linux_syscall_name_io_submit                    246 ///< io_submit
#define linux_syscall_name_io_cancel                    247 ///< io_cancel
#define linux_syscall_name_exit_group                   248 ///< exit_group
#define linux_syscall_name_lookup_dcookie               249 ///< lookup_dcookie
#define linux_syscall_name_epoll_create                 250 ///< epoll_create
#define linux_syscall_name_epoll_ctl                    251 ///< epoll_ctl
#define linux_syscall_name_epoll_wait                   252 ///< epoll_wait
#define linux_syscall_name_remap_file_pages             253 ///< remap_file_pages
//#define linux_set_thread_area                         254 // unused
//#define linux_get_thread_area                         255 // unused
#define linux_syscall_name_set_tid_address              256 ///< set_tid_address
#define linux_syscall_name_timer_create                 257 ///< timer_create
#define linux_syscall_name_timer_settime32              258 ///< timer_settime32
#define linux_syscall_name_timer_gettime32              259 ///< timer_gettime32
#define linux_syscall_name_timer_getoverrun             260 ///< timer_getoverrun
#define linux_syscall_name_timer_delete                 261 ///< timer_delete
#define linux_syscall_name_clock_settime32              262 ///< clock_settime32
#define linux_syscall_name_clock_gettime32              263 ///< clock_gettime32
#define linux_syscall_name_clock_getres_time32          264 ///< clock_getres_time32
#define linux_syscall_name_clock_nanosleep_time32       265 ///< clock_nanosleep_time32
#define linux_syscall_name_statfs64                     266 ///< statfs64
#define linux_syscall_name_fstatfs64                    267 ///< fstatfs64
#define linux_syscall_name_tgkill                       268 ///< tgkill
#define linux_syscall_name_utimes_time32                269 ///< utimes_time32
#define linux_syscall_name_fadvise64_64                 270 ///< fadvise64_64
#define linux_syscall_name_pciconfig_iobase             271 ///< pciconfig_iobase
#define linux_syscall_name_pciconfig_read               272 ///< pciconfig_read
#define linux_syscall_name_pciconfig_write              273 ///< pciconfig_write
#define linux_syscall_name_mq_open                      274 ///< mq_open
#define linux_syscall_name_mq_unlink                    275 ///< mq_unlink
#define linux_syscall_name_mq_timedsend_time32          276 ///< mq_timedsend_time32
#define linux_syscall_name_mq_timedreceive_time32       277 ///< mq_timedreceive_time32
#define linux_syscall_name_mq_notify                    278 ///< mq_notify
#define linux_syscall_name_mq_getsetattr                279 ///< mq_getsetattr
#define linux_syscall_name_waitid                       280 ///< waitid
#define linux_syscall_name_socket                       281 ///< socket
#define linux_syscall_name_bind                         282 ///< bind
#define linux_syscall_name_connect                      283 ///< connect
#define linux_syscall_name_listen                       284 ///< listen
#define linux_syscall_name_accept                       285 ///< accept
#define linux_syscall_name_getsockname                  286 ///< getsockname
#define linux_syscall_name_getpeername                  287 ///< getpeername
#define linux_syscall_name_socketpair                   288 ///< socketpair
#define linux_syscall_name_send                         289 ///< send
#define linux_syscall_name_sendto                       290 ///< sendto
#define linux_syscall_name_recv                         291 ///< recv
#define linux_syscall_name_recvfrom                     292 ///< recvfrom
#define linux_syscall_name_shutdown                     293 ///< shutdown
#define linux_syscall_name_setsockopt                   294 ///< setsockopt
#define linux_syscall_name_getsockopt                   295 ///< getsockopt
#define linux_syscall_name_sendmsg                      296 ///< sendmsg
#define linux_syscall_name_recvmsg                      297 ///< recvmsg
#define linux_syscall_name_semop                        298 ///< semop
#define linux_syscall_name_semget                       299 ///< semget
#define linux_syscall_name_old_semctl                   300 ///< old_semctl
#define linux_syscall_name_msgsnd                       301 ///< msgsnd
#define linux_syscall_name_msgrcv                       302 ///< msgrcv
#define linux_syscall_name_msgget                       303 ///< msgget
#define linux_syscall_name_old_msgctl                   304 ///< old_msgctl
#define linux_syscall_name_shmat                        305 ///< shmat
#define linux_syscall_name_shmdt                        306 ///< shmdt
#define linux_syscall_name_shmget                       307 ///< shmget
#define linux_syscall_name_old_shmctl                   308 ///< old_shmctl
#define linux_syscall_name_add_key                      309 ///< add_key
#define linux_syscall_name_request_key                  310 ///< request_key
#define linux_syscall_name_keyctl                       311 ///< keyctl
#define linux_syscall_name_semtimedop_time32            312 ///< semtimedop_time32
//#define linux_vserver                                 313 // unused
#define linux_syscall_name_ioprio_set                   314 ///< ioprio_set
#define linux_syscall_name_ioprio_get                   315 ///< ioprio_get
#define linux_syscall_name_inotify_init                 316 ///< inotify_init
#define linux_syscall_name_inotify_add_watch            317 ///< inotify_add_watch
#define linux_syscall_name_inotify_rm_watch             318 ///< inotify_rm_watch
#define linux_syscall_name_mbind                        319 ///< mbind
#define linux_syscall_name_get_mempolicy                320 ///< get_mempolicy
#define linux_syscall_name_set_mempolicy                321 ///< set_mempolicy
#define linux_syscall_name_openat                       322 ///< openat
#define linux_syscall_name_mkdirat                      323 ///< mkdirat
#define linux_syscall_name_mknodat                      324 ///< mknodat
#define linux_syscall_name_fchownat                     325 ///< fchownat
#define linux_syscall_name_futimesat_time32             326 ///< futimesat_time32
#define linux_syscall_name_fstatat64                    327 ///< fstatat64
#define linux_syscall_name_unlinkat                     328 ///< unlinkat
#define linux_syscall_name_renameat                     329 ///< renameat
#define linux_syscall_name_linkat                       330 ///< linkat
#define linux_syscall_name_symlinkat                    331 ///< symlinkat
#define linux_syscall_name_readlinkat                   332 ///< readlinkat
#define linux_syscall_name_fchmodat                     333 ///< fchmodat
#define linux_syscall_name_faccessat                    334 ///< faccessat
#define linux_syscall_name_pselect6_time32              335 ///< pselect6_time32
#define linux_syscall_name_ppoll_time32                 336 ///< ppoll_time32
#define linux_syscall_name_unshare                      337 ///< unshare
#define linux_syscall_name_set_robust_list              338 ///< set_robust_list
#define linux_syscall_name_get_robust_list              339 ///< get_robust_list
#define linux_syscall_name_splice                       340 ///< splice
#define linux_syscall_name_sync_file_range2             341 ///< sync_file_range2
#define linux_syscall_name_tee                          342 ///< tee
#define linux_syscall_name_vmsplice                     343 ///< vmsplice
#define linux_syscall_name_move_pages                   344 ///< move_pages
#define linux_syscall_name_getcpu                       345 ///< getcpu
#define linux_syscall_name_epoll_pwait                  346 ///< epoll_pwait
#define linux_syscall_name_kexec_load                   347 ///< kexec_load
#define linux_syscall_name_utimensat_time32             348 ///< utimensat_time32
#define linux_syscall_name_signalfd                     349 ///< signalfd
#define linux_syscall_name_timerfd_create               350 ///< timerfd_create
#define linux_syscall_name_eventfd                      351 ///< eventfd
#define linux_syscall_name_fallocate                    352 ///< fallocate
#define linux_syscall_name_timerfd_settime32            353 ///< timerfd_settime32
#define linux_syscall_name_timerfd_gettime32            354 ///< timerfd_gettime32
#define linux_syscall_name_signalfd4                    355 ///< signalfd4
#define linux_syscall_name_eventfd2                     356 ///< eventfd2
#define linux_syscall_name_epoll_create1                357 ///< epoll_create1
#define linux_syscall_name_dup3                         358 ///< dup3
#define linux_syscall_name_pipe2                        359 ///< pipe2
#define linux_syscall_name_inotify_init1                360 ///< inotify_init1
#define linux_syscall_name_preadv                       361 ///< preadv
#define linux_syscall_name_pwritev                      362 ///< pwritev
#define linux_syscall_name_rt_tgsigqueueinfo            363 ///< rt_tgsigqueueinfo
#define linux_syscall_name_perf_event_open              364 ///< perf_event_open
#define linux_syscall_name_recvmmsg_time32              365 ///< recvmmsg_time32
#define linux_syscall_name_accept4                      366 ///< accept4
#define linux_syscall_name_fanotify_init                367 ///< fanotify_init
#define linux_syscall_name_fanotify_mark                368 ///< fanotify_mark
#define linux_syscall_name_prlimit64                    369 ///< prlimit64
#define linux_syscall_name_name_to_handle_at            370 ///< name_to_handle_at
#define linux_syscall_name_open_by_handle_at            371 ///< open_by_handle_at
#define linux_syscall_name_clock_adjtime32              372 ///< clock_adjtime32
#define linux_syscall_name_syncfs                       373 ///< syncfs
#define linux_syscall_name_sendmmsg                     374 ///< sendmmsg
#define linux_syscall_name_setns                        375 ///< setns
#define linux_syscall_name_process_vm_readv             376 ///< process_vm_readv
#define linux_syscall_name_process_vm_writev            377 ///< process_vm_writev
#define linux_syscall_name_kcmp                         378 ///< kcmp
#define linux_syscall_name_finit_module                 379 ///< finit_module
#define linux_syscall_name_sched_setattr                380 ///< sched_setattr
#define linux_syscall_name_sched_getattr                381 ///< sched_getattr
#define linux_syscall_name_renameat2                    382 ///< renameat2
#define linux_syscall_name_seccomp                      383 ///< seccomp
#define linux_syscall_name_getrandom                    384 ///< getrandom
#define linux_syscall_name_memfd_create                 385 ///< memfd_create
#define linux_syscall_name_bpf                          386 ///< bpf
#define linux_syscall_name_execveat                     387 ///< execveat
#define linux_syscall_name_userfaultfd                  388 ///< userfaultfd
#define linux_syscall_name_membarrier                   389 ///< membarrier
#define linux_syscall_name_mlock2                       390 ///< mlock2
#define linux_syscall_name_copy_file_range              391 ///< copy_file_range
#define linux_syscall_name_preadv2                      392 ///< preadv2
#define linux_syscall_name_pwritev2                     393 ///< pwritev2
#define linux_syscall_name_pkey_mprotect                394 ///< pkey_mprotect
#define linux_syscall_name_pkey_alloc                   395 ///< pkey_alloc
#define linux_syscall_name_pkey_free                    396 ///< pkey_free
#define linux_syscall_name_statx                        397 ///< statx
#define linux_syscall_name_rseq                         398 ///< rseq
#define linux_syscall_name_io_pgetevents_time32         399 ///< io_pgetevents_time32
#define linux_syscall_name_migrate_pages                400 ///< migrate_pages
#define linux_syscall_name_kexec_file_load              401 ///< kexec_file_load
#define linux_syscall_name_clock_gettime                403 ///< clock_gettime
#define linux_syscall_name_clock_settime                404 ///< clock_settime
#define linux_syscall_name_clock_adjtime                405 ///< clock_adjtime
#define linux_syscall_name_clock_getres                 406 ///< clock_getres
#define linux_syscall_name_clock_nanosleep              407 ///< clock_nanosleep
#define linux_syscall_name_timer_gettime                408 ///< timer_gettime
#define linux_syscall_name_timer_settime                409 ///< timer_settime
#define linux_syscall_name_timerfd_gettime              410 ///< timerfd_gettime
#define linux_syscall_name_timerfd_settime              411 ///< timerfd_settime
#define linux_syscall_name_utimensat                    412 ///< utimensat
#define linux_syscall_name_pselect6                     413 ///< pselect6
#define linux_syscall_name_ppoll                        414 ///< ppoll
// unused
#define linux_syscall_name_io_pgetevents                416 ///< io_pgetevents
#define linux_syscall_name_recvmmsg                     417 ///< recvmmsg
#define linux_syscall_name_mq_timedsend                 418 ///< mq_timedsend
#define linux_syscall_name_mq_timedreceive              419 ///< mq_timedreceive
#define linux_syscall_name_semtimedop                   420 ///< semtimedop
#define linux_syscall_name_rt_sigtimedwait              421 ///< rt_sigtimedwait
#define linux_syscall_name_futex                        422 ///< futex
#define linux_syscall_name_sched_rr_get_interval        423 ///< sched_rr_get_interval
#define linux_syscall_name_pidfd_send_signal            424 ///< pidfd_send_signal
#define linux_syscall_name_io_uring_setup               425 ///< io_uring_setup
#define linux_syscall_name_io_uring_enter               426 ///< io_uring_enter
#define linux_syscall_name_io_uring_register            427 ///< io_uring_register
#define linux_syscall_name_open_tree                    428 ///< open_tree
#define linux_syscall_name_move_mount                   429 ///< move_mount
#define linux_syscall_name_fsopen                       430 ///< fsopen
#define linux_syscall_name_fsconfig                     431 ///< fsconfig
#define linux_syscall_name_fsmount                      432 ///< fsmount
#define linux_syscall_name_fspick                       433 ///< fspick
#define linux_syscall_name_pidfd_open                   434 ///< pidfd_open
#define linux_syscall_name_clone3                       435 ///< clone3
#define linux_syscall_name_close_range                  436 ///< close_range
#define linux_syscall_name_openat2                      437 ///< openat2
#define linux_syscall_name_pidfd_getfd                  438 ///< pidfd_getfd
#define linux_syscall_name_faccessat2                   439 ///< faccessat2
#define linux_syscall_name_process_madvise              440 ///< process_madvise
#define linux_syscall_name_epoll_pwait2                 441 ///< epoll_pwait2
#define linux_syscall_name_mount_setattr                442 ///< mount_setattr
//#define linux_syscall_name_quotactl_path              443 // reserved
#define linux_syscall_name_landlock_create_ruleset      444 ///< landlock_create_ruleset
#define linux_syscall_name_landlock_add_rule            445 ///< landlock_add_rule
#define linux_syscall_name_landlock_restrict_self       446 ///< landlock_restrict_self

#define linux_syscall_name_breakpoint                   (0x0f0000 + 1) ///< breakpoint
#define linux_syscall_name_cacheflush                   (0x0f0000 + 2) ///< cacheflush
#define linux_syscall_name_usr26                        (0x0f0000 + 3) ///< usr26
#define linux_syscall_name_usr32                        (0x0f0000 + 4) ///< usr32
#define linux_syscall_name_set_tls                      (0x0f0000 + 5) ///< set_tls
#define linux_syscall_name_get_tls                      (0x0f0000 + 6) ///< get_tls

#endif // !HEADER_LIBLINUX_ARM_EABI_UNISTD_H_INCLUDED
