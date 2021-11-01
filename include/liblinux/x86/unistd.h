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

#ifndef HEADER_LIBLINUX_X86_UNISTD_H_INCLUDED
#define HEADER_LIBLINUX_X86_UNISTD_H_INCLUDED

// Differences (name/function/number):
// -----------------------------------
// time time32 13
// lchown lchown16 16
// oldstat stat 18
// umount oldumount 22
// setuid setuid16 23
// getuid getuid16 24
// stime stime32 25
// oldfstat fstat 28
// utime utime32 30
// setgid setgid16 46
// getgid getgid16 47
// geteuid geteuid16 49
// getegid getegid16 50
// umount2 umount 52
// oldolduname olduname 59
// setreuid setreuid16 70
// setregid setregid16 71
// getrlimit old_getrlimit 76
// getgroups getgroups16 80
// setgroups setgroups16 81
// select old_select 82
// oldlstat lstat 84
// readdir old_readdir 89
// mmap old_mmap 90
// fchown fchown16 95
// stat newstat 106
// lstat newlstat 107
// fstat newfstat 108
// olduname uname 109
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
// rt_sigtimedwait rt_sigtimedwait_time32 177
// chown chown16 182
// ugetrlimit getrlimit 191
// mmap2 mmap_pgoff 192
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
// io_getevents io_getevents_time32 247
// timer_settime timer_settime32 260
// timer_gettime timer_gettime32 261
// clock_settime clock_settime32 264
// clock_gettime clock_gettime32 265
// clock_getres clock_getres_time32 266
// clock_nanosleep clock_nanosleep_time32 267
// utimes utimes_time32 271
// mq_timedsend mq_timedsend_time32 279
// mq_timedreceive mq_timedreceive_time32 280
// futimesat futimesat_time32 299
// pselect6 pselect6_time32 308
// ppoll ppoll_time32 309
// utimensat utimensat_time32 320
// timerfd_settime timerfd_settime32 325
// timerfd_gettime timerfd_gettime32 326
// recvmmsg recvmmsg_time32 337
// clock_adjtime clock_adjtime32 343
// io_pgetevents io_pgetevents_time32 385
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
#define linux_syscall_name_waitpid                        7 ///< waitpid
#define linux_syscall_name_creat                          8 ///< creat
#define linux_syscall_name_link                           9 ///< link
#define linux_syscall_name_unlink                        10 ///< unlink
#define linux_syscall_name_execve                        11 ///< execve
#define linux_syscall_name_chdir                         12 ///< chdir
#define linux_syscall_name_time32                        13 ///< time32
#define linux_syscall_name_mknod                         14 ///< mknod
#define linux_syscall_name_chmod                         15 ///< chmod
#define linux_syscall_name_lchown16                      16 ///< lchown16
//#define linux_syscall_name_break                       17 // unused
#define linux_syscall_name_stat                          18 ///< stat
#define linux_syscall_name_lseek                         19 ///< lseek
#define linux_syscall_name_getpid                        20 ///< getpid
#define linux_syscall_name_mount                         21 ///< mount
#define linux_syscall_name_oldumount                     22 ///< oldumount
#define linux_syscall_name_setuid16                      23 ///< setuid16
#define linux_syscall_name_getuid16                      24 ///< getuid16
#define linux_syscall_name_stime32                       25 ///< stime32
#define linux_syscall_name_ptrace                        26 ///< ptrace
#define linux_syscall_name_alarm                         27 ///< alarm
#define linux_syscall_name_fstat                         28 ///< fstat
#define linux_syscall_name_pause                         29 ///< pause
#define linux_syscall_name_utime32                       30 ///< utime32
//#define linux_syscall_name_stty                        31 // unused
//#define linux_syscall_name_gtty                        32 // unused
#define linux_syscall_name_access                        33 ///< access
#define linux_syscall_name_nice                          34 ///< nice
//#define linux_syscall_name_ftime                       35 // unused
#define linux_syscall_name_sync                          36 ///< sync
#define linux_syscall_name_kill                          37 ///< kill
#define linux_syscall_name_rename                        38 ///< rename
#define linux_syscall_name_mkdir                         39 ///< mkdir
#define linux_syscall_name_rmdir                         40 ///< rmdir
#define linux_syscall_name_dup                           41 ///< dup
#define linux_syscall_name_pipe                          42 ///< pipe
#define linux_syscall_name_times                         43 ///< times
//#define linux_syscall_name_prof                        44 // unused
#define linux_syscall_name_brk                           45 ///< brk
#define linux_syscall_name_setgid16                      46 ///< setgid16
#define linux_syscall_name_getgid16                      47 ///< getgid16
#define linux_syscall_name_signal                        48 ///< signal
#define linux_syscall_name_geteuid16                     49 ///< geteuid16
#define linux_syscall_name_getegid16                     50 ///< getegid16
#define linux_syscall_name_acct                          51 ///< acct
#define linux_syscall_name_umount                        52 ///< umount
//#define linux_syscall_name_lock                        53 // unused
#define linux_syscall_name_ioctl                         54 ///< ioctl
#define linux_syscall_name_fcntl                         55 ///< fcntl
//#define linux_syscall_name_mpx                         56 // unused
#define linux_syscall_name_setpgid                       57 ///< setpgid
//#define linux_syscall_name_ulimit                      58 // unused
#define linux_syscall_name_olduname                      59 ///< olduname
#define linux_syscall_name_umask                         60 ///< umask
#define linux_syscall_name_chroot                        61 ///< chroot
#define linux_syscall_name_ustat                         62 ///< ustat
#define linux_syscall_name_dup2                          63 ///< dup2
#define linux_syscall_name_getppid                       64 ///< getppid
#define linux_syscall_name_getpgrp                       65 ///< getpgrp
#define linux_syscall_name_setsid                        66 ///< setsid
#define linux_syscall_name_sigaction                     67 ///< sigaction
#define linux_syscall_name_sgetmask                      68 ///< sgetmask
#define linux_syscall_name_ssetmask                      69 ///< ssetmask
#define linux_syscall_name_setreuid16                    70 ///< setreuid16
#define linux_syscall_name_setregid16                    71 ///< setregid16
#define linux_syscall_name_sigsuspend                    72 ///< sigsuspend
#define linux_syscall_name_sigpending                    73 ///< sigpending
#define linux_syscall_name_sethostname                   74 ///< sethostname
#define linux_syscall_name_setrlimit                     75 ///< setrlimit
#define linux_syscall_name_old_getrlimit                 76 ///< old_getrlimit
#define linux_syscall_name_getrusage                     77 ///< getrusage
#define linux_syscall_name_gettimeofday                  78 ///< gettimeofday
#define linux_syscall_name_settimeofday                  79 ///< settimeofday
#define linux_syscall_name_getgroups16                   80 ///< getgroups16
#define linux_syscall_name_setgroups16                   81 ///< setgroups16
#define linux_syscall_name_old_select                    82 ///< old_select
#define linux_syscall_name_symlink                       83 ///< symlink
#define linux_syscall_name_lstat                         84 ///< lstat
#define linux_syscall_name_readlink                      85 ///< readlink
#define linux_syscall_name_uselib                        86 ///< uselib
#define linux_syscall_name_swapon                        87 ///< swapon
#define linux_syscall_name_reboot                        88 ///< reboot
#define linux_syscall_name_old_readdir                   89 ///< old_readdir
#define linux_syscall_name_old_mmap                      90 ///< old_mmap
#define linux_syscall_name_munmap                        91 ///< munmap
#define linux_syscall_name_truncate                      92 ///< truncate
#define linux_syscall_name_ftruncate                     93 ///< ftruncate
#define linux_syscall_name_fchmod                        94 ///< fchmod
#define linux_syscall_name_fchown16                      95 ///< fchown16
#define linux_syscall_name_getpriority                   96 ///< getpriority
#define linux_syscall_name_setpriority                   97 ///< setpriority
//#define linux_syscall_name_profil                      98 // unused
#define linux_syscall_name_statfs                        99 ///< statfs
#define linux_syscall_name_fstatfs                      100 ///< fstatfs
#define linux_syscall_name_ioperm                       101 ///< ioperm
#define linux_syscall_name_socketcall                   102 ///< socketcall
#define linux_syscall_name_syslog                       103 ///< syslog
#define linux_syscall_name_setitimer                    104 ///< setitimer
#define linux_syscall_name_getitimer                    105 ///< getitimer
#define linux_syscall_name_newstat                      106 ///< newstat
#define linux_syscall_name_newlstat                     107 ///< newlstat
#define linux_syscall_name_newfstat                     108 ///< newfstat
#define linux_syscall_name_uname                        109 ///< uname
#define linux_syscall_name_iopl                         110 ///< iopl
#define linux_syscall_name_vhangup                      111 ///< vhangup
//#define linux_syscall_name_idle                       112 // unused
#define linux_syscall_name_vm86old                      113 ///< vm86old
#define linux_syscall_name_wait4                        114 ///< wait4
#define linux_syscall_name_swapoff                      115 ///< swapoff
#define linux_syscall_name_sysinfo                      116 ///< sysinfo
#define linux_syscall_name_ipc                          117 ///< ipc
#define linux_syscall_name_fsync                        118 ///< fsync
//#define linux_syscall_name_sigreturn                  119 // Use linux_sigreturn().
#define linux_syscall_name_clone                        120 ///< clone
#define linux_syscall_name_setdomainname                121 ///< setdomainname
#define linux_syscall_name_newuname                     122 ///< newuname
#define linux_syscall_name_modify_ldt                   123 ///< modify_ldt
#define linux_syscall_name_adjtimex_time32              124 ///< adjtimex_time32
#define linux_syscall_name_mprotect                     125 ///< mprotect
#define linux_syscall_name_sigprocmask                  126 ///< sigprocmask
//#define linux_syscall_name_create_module              127 // unused
#define linux_syscall_name_init_module                  128 ///< init_module
#define linux_syscall_name_delete_module                129 ///< delete_module
//#define linux_syscall_name_get_kernel_syms            130 // unused
#define linux_syscall_name_quotactl                     131 ///< quotactl
#define linux_syscall_name_getpgid                      132 ///< getpgid
#define linux_syscall_name_fchdir                       133 ///< fchdir
#define linux_syscall_name_bdflush                      134 ///< bdflush
#define linux_syscall_name_sysfs                        135 ///< sysfs
#define linux_syscall_name_personality                  136 ///< personality
//#define linux_syscall_name_afs_syscall                137 // unused
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
#define linux_syscall_name_vm86                         166 ///< vm86
//#define linux_syscall_name_query_module               167 // unused
#define linux_syscall_name_poll                         168 ///< poll
//#define linux_syscall_name_nfsservctl                 169 // unused
#define linux_syscall_name_setresgid16                  170 ///< setresgid16
#define linux_syscall_name_getresgid16                  171 ///< getresgid16
#define linux_syscall_name_prctl                        172 ///< prctl
//#define linux_syscall_name_rt_sigreturn               173 // Use linux_rt_sigreturn().
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
//#define linux_syscall_name_getpmsg                    188 // unused
//#define linux_syscall_name_putpmsg                    189 // unused
//#define linux_syscall_name_vfork                      190 // Use linux_vfork().
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
#define linux_syscall_name_pivot_root                   217 ///< pivot_root
#define linux_syscall_name_mincore                      218 ///< mincore
#define linux_syscall_name_madvise                      219 ///< madvise
#define linux_syscall_name_getdents64                   220 ///< getdents64
#define linux_syscall_name_fcntl64                      221 ///< fcntl64
// unused
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
#define linux_syscall_name_set_thread_area              243 ///< set_thread_area
#define linux_syscall_name_get_thread_area              244 ///< get_thread_area
#define linux_syscall_name_io_setup                     245 ///< io_setup
#define linux_syscall_name_io_destroy                   246 ///< io_destroy
#define linux_syscall_name_io_getevents_time32          247 ///< io_getevents_time32
#define linux_syscall_name_io_submit                    248 ///< io_submit
#define linux_syscall_name_io_cancel                    249 ///< io_cancel
#define linux_syscall_name_fadvise64                    250 ///< fadvise64
// unused
#define linux_syscall_name_exit_group                   252 ///< exit_group
#define linux_syscall_name_lookup_dcookie               253 ///< lookup_dcookie
#define linux_syscall_name_epoll_create                 254 ///< epoll_create
#define linux_syscall_name_epoll_ctl                    255 ///< epoll_ctl
#define linux_syscall_name_epoll_wait                   256 ///< epoll_wait
#define linux_syscall_name_remap_file_pages             257 ///< remap_file_pages
#define linux_syscall_name_set_tid_address              258 ///< set_tid_address
#define linux_syscall_name_timer_create                 259 ///< timer_create
#define linux_syscall_name_timer_settime32              260 ///< timer_settime32
#define linux_syscall_name_timer_gettime32              261 ///< timer_gettime32
#define linux_syscall_name_timer_getoverrun             262 ///< timer_getoverrun
#define linux_syscall_name_timer_delete                 263 ///< timer_delete
#define linux_syscall_name_clock_settime32              264 ///< clock_settime32
#define linux_syscall_name_clock_gettime32              265 ///< clock_gettime32
#define linux_syscall_name_clock_getres_time32          266 ///< clock_getres_time32
#define linux_syscall_name_clock_nanosleep_time32       267 ///< clock_nanosleep_time32
#define linux_syscall_name_statfs64                     268 ///< statfs64
#define linux_syscall_name_fstatfs64                    269 ///< fstatfs64
#define linux_syscall_name_tgkill                       270 ///< tgkill
#define linux_syscall_name_utimes_time32                271 ///< utimes_time32
#define linux_syscall_name_fadvise64_64                 272 ///< fadvise64_64
//#define linux_syscall_name_vserver                    273 // unused
#define linux_syscall_name_mbind                        274 ///< mbind
#define linux_syscall_name_get_mempolicy                275 ///< get_mempolicy
#define linux_syscall_name_set_mempolicy                276 ///< set_mempolicy
#define linux_syscall_name_mq_open                      277 ///< mq_open
#define linux_syscall_name_mq_unlink                    278 ///< mq_unlink
#define linux_syscall_name_mq_timedsend_time32          279 ///< mq_timedsend_time32
#define linux_syscall_name_mq_timedreceive_time32       280 ///< mq_timedreceive_time32
#define linux_syscall_name_mq_notify                    281 ///< mq_notify
#define linux_syscall_name_mq_getsetattr                282 ///< mq_getsetattr
#define linux_syscall_name_kexec_load                   283 ///< kexec_load
#define linux_syscall_name_waitid                       284 ///< waitid
//#define linux_syscall_name_setaltroot                 285 // unused
#define linux_syscall_name_add_key                      286 ///< add_key
#define linux_syscall_name_request_key                  287 ///< request_key
#define linux_syscall_name_keyctl                       288 ///< keyctl
#define linux_syscall_name_ioprio_set                   289 ///< ioprio_set
#define linux_syscall_name_ioprio_get                   290 ///< ioprio_get
#define linux_syscall_name_inotify_init                 291 ///< inotify_init
#define linux_syscall_name_inotify_add_watch            292 ///< inotify_add_watch
#define linux_syscall_name_inotify_rm_watch             293 ///< inotify_rm_watch
#define linux_syscall_name_migrate_pages                294 ///< migrate_pages
#define linux_syscall_name_openat                       295 ///< openat
#define linux_syscall_name_mkdirat                      296 ///< mkdirat
#define linux_syscall_name_mknodat                      297 ///< mknodat
#define linux_syscall_name_fchownat                     298 ///< fchownat
#define linux_syscall_name_futimesat_time32             299 ///< futimesat_time32
#define linux_syscall_name_fstatat64                    300 ///< fstatat64
#define linux_syscall_name_unlinkat                     301 ///< unlinkat
#define linux_syscall_name_renameat                     302 ///< renameat
#define linux_syscall_name_linkat                       303 ///< linkat
#define linux_syscall_name_symlinkat                    304 ///< symlinkat
#define linux_syscall_name_readlinkat                   305 ///< readlinkat
#define linux_syscall_name_fchmodat                     306 ///< fchmodat
#define linux_syscall_name_faccessat                    307 ///< faccessat
#define linux_syscall_name_pselect6_time32              308 ///< pselect6_time32
#define linux_syscall_name_ppoll_time32                 309 ///< ppoll_time32
#define linux_syscall_name_unshare                      310 ///< unshare
#define linux_syscall_name_set_robust_list              311 ///< set_robust_list
#define linux_syscall_name_get_robust_list              312 ///< get_robust_list
#define linux_syscall_name_splice                       313 ///< splice
#define linux_syscall_name_sync_file_range              314 ///< sync_file_range
#define linux_syscall_name_tee                          315 ///< tee
#define linux_syscall_name_vmsplice                     316 ///< vmsplice
#define linux_syscall_name_move_pages                   317 ///< move_pages
#define linux_syscall_name_getcpu                       318 ///< getcpu
#define linux_syscall_name_epoll_pwait                  319 ///< epoll_pwait
#define linux_syscall_name_utimensat_time32             320 ///< utimensat_time32
#define linux_syscall_name_signalfd                     321 ///< signalfd
#define linux_syscall_name_timerfd_create               322 ///< timerfd_create
#define linux_syscall_name_eventfd                      323 ///< eventfd
#define linux_syscall_name_fallocate                    324 ///< fallocate
#define linux_syscall_name_timerfd_settime32            325 ///< timerfd_settime32
#define linux_syscall_name_timerfd_gettime32            326 ///< timerfd_gettime32
#define linux_syscall_name_signalfd4                    327 ///< signalfd4
#define linux_syscall_name_eventfd2                     328 ///< eventfd2
#define linux_syscall_name_epoll_create1                329 ///< epoll_create1
#define linux_syscall_name_dup3                         330 ///< dup3
#define linux_syscall_name_pipe2                        331 ///< pipe2
#define linux_syscall_name_inotify_init1                332 ///< inotify_init1
#define linux_syscall_name_preadv                       333 ///< preadv
#define linux_syscall_name_pwritev                      334 ///< pwritev
#define linux_syscall_name_rt_tgsigqueueinfo            335 ///< rt_tgsigqueueinfo
#define linux_syscall_name_perf_event_open              336 ///< perf_event_open
#define linux_syscall_name_recvmmsg_time32              337 ///< recvmmsg_time32
#define linux_syscall_name_fanotify_init                338 ///< fanotify_init
#define linux_syscall_name_fanotify_mark                339 ///< fanotify_mark
#define linux_syscall_name_prlimit64                    340 ///< prlimit64
#define linux_syscall_name_name_to_handle_at            341 ///< name_to_handle_at
#define linux_syscall_name_open_by_handle_at            342 ///< open_by_handle_at
#define linux_syscall_name_clock_adjtime32              343 ///< clock_adjtime32
#define linux_syscall_name_syncfs                       344 ///< syncfs
#define linux_syscall_name_sendmmsg                     345 ///< sendmmsg
#define linux_syscall_name_setns                        346 ///< setns
#define linux_syscall_name_process_vm_readv             347 ///< process_vm_readv
#define linux_syscall_name_process_vm_writev            348 ///< process_vm_writev
#define linux_syscall_name_kcmp                         349 ///< kcmp
#define linux_syscall_name_finit_module                 350 ///< finit_module
#define linux_syscall_name_sched_setattr                351 ///< sched_setattr
#define linux_syscall_name_sched_getattr                352 ///< sched_getattr
#define linux_syscall_name_renameat2                    353 ///< renameat2
#define linux_syscall_name_seccomp                      354 ///< seccomp
#define linux_syscall_name_getrandom                    355 ///< getrandom
#define linux_syscall_name_memfd_create                 356 ///< memfd_create
#define linux_syscall_name_bpf                          357 ///< bpf
#define linux_syscall_name_execveat                     358 ///< execveat
#define linux_syscall_name_socket                       359 ///< socket
#define linux_syscall_name_socketpair                   360 ///< socketpair
#define linux_syscall_name_bind                         361 ///< bind
#define linux_syscall_name_connect                      362 ///< connect
#define linux_syscall_name_listen                       363 ///< listen
#define linux_syscall_name_accept4                      364 ///< accept4
#define linux_syscall_name_getsockopt                   365 ///< getsockopt
#define linux_syscall_name_setsockopt                   366 ///< setsockopt
#define linux_syscall_name_getsockname                  367 ///< getsockname
#define linux_syscall_name_getpeername                  368 ///< getpeername
#define linux_syscall_name_sendto                       369 ///< sendto
#define linux_syscall_name_sendmsg                      370 ///< sendmsg
#define linux_syscall_name_recvfrom                     371 ///< recvfrom
#define linux_syscall_name_recvmsg                      372 ///< recvmsg
#define linux_syscall_name_shutdown                     373 ///< shutdown
#define linux_syscall_name_userfaultfd                  374 ///< userfaultfd
#define linux_syscall_name_membarrier                   375 ///< membarrier
#define linux_syscall_name_mlock2                       376 ///< mlock2
#define linux_syscall_name_copy_file_range              377 ///< copy_file_range
#define linux_syscall_name_preadv2                      378 ///< preadv2
#define linux_syscall_name_pwritev2                     379 ///< pwritev2
#define linux_syscall_name_pkey_mprotect                380 ///< pkey_mprotect
#define linux_syscall_name_pkey_alloc                   381 ///< pkey_alloc
#define linux_syscall_name_pkey_free                    382 ///< pkey_free
#define linux_syscall_name_statx                        383 ///< statx
#define linux_syscall_name_arch_prctl                   384 ///< arch_prctl
#define linux_syscall_name_io_pgetevents_time32         385 ///< io_pgetevents_time32
#define linux_syscall_name_rseq                         386 ///< rseq
// unused
// unused
// unused
// unused
// unused
// unused
#define linux_syscall_name_semget                       393 ///< semget
#define linux_syscall_name_semctl                       394 ///< semctl
#define linux_syscall_name_shmget                       395 ///< shmget
#define linux_syscall_name_shmctl                       396 ///< shmctl
#define linux_syscall_name_shmat                        397 ///< shmat
#define linux_syscall_name_shmdt                        398 ///< shmdt
#define linux_syscall_name_msgget                       399 ///< msgget
#define linux_syscall_name_msgsnd                       400 ///< msgsnd
#define linux_syscall_name_msgrcv                       401 ///< msgrcv
#define linux_syscall_name_msgctl                       402 ///< msgctl
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
#define linux_syscall_name_quotactl_fd                  443 ///< quotactl_fd
#define linux_syscall_name_landlock_create_ruleset      444 ///< landlock_create_ruleset
#define linux_syscall_name_landlock_add_rule            445 ///< landlock_add_rule
#define linux_syscall_name_landlock_restrict_self       446 ///< landlock_restrict_self
#define linux_syscall_name_memfd_secret                 447 ///< memfd_secret
#define linux_syscall_name_process_mrelease             448 ///< process_mrelease

#endif // !HEADER_LIBLINUX_X86_UNISTD_H_INCLUDED
