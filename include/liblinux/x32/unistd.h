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

#ifndef HEADER_LIBLINUX_X32_UNISTD_H_INCLUDED
#define HEADER_LIBLINUX_X32_UNISTD_H_INCLUDED

// Differences (name/function/number):
// -----------------------------------
// stat newstat 4
// fstat newfstat 5
// lstat newlstat 6
// sendfile sendfile64 40
// uname newuname 63
// umount2 umount 166

#define LINUX_X32_SYSCALL_BIT 0x40000000

#define linux_syscall_name_read                    (LINUX_X32_SYSCALL_BIT +   0) ///< read
#define linux_syscall_name_write                   (LINUX_X32_SYSCALL_BIT +   1) ///< write
#define linux_syscall_name_open                    (LINUX_X32_SYSCALL_BIT +   2) ///< open
#define linux_syscall_name_close                   (LINUX_X32_SYSCALL_BIT +   3) ///< close
#define linux_syscall_name_newstat                 (LINUX_X32_SYSCALL_BIT +   4) ///< newstat
#define linux_syscall_name_newfstat                (LINUX_X32_SYSCALL_BIT +   5) ///< newfstat
#define linux_syscall_name_newlstat                (LINUX_X32_SYSCALL_BIT +   6) ///< newlstat
#define linux_syscall_name_poll                    (LINUX_X32_SYSCALL_BIT +   7) ///< poll
#define linux_syscall_name_lseek                   (LINUX_X32_SYSCALL_BIT +   8) ///< lseek
#define linux_syscall_name_mmap                    (LINUX_X32_SYSCALL_BIT +   9) ///< mmap
#define linux_syscall_name_mprotect                (LINUX_X32_SYSCALL_BIT +  10) ///< mprotect
#define linux_syscall_name_munmap                  (LINUX_X32_SYSCALL_BIT +  11) ///< munmap
#define linux_syscall_name_brk                     (LINUX_X32_SYSCALL_BIT +  12) ///< brk
//#define linux_syscall_name_rt_sigaction          (LINUX_X32_SYSCALL_BIT +  13) // x86_64
#define linux_syscall_name_rt_sigprocmask          (LINUX_X32_SYSCALL_BIT +  14) ///< rt_sigprocmask
//#define linux_syscall_name_rt_sigreturn          (LINUX_X32_SYSCALL_BIT +  15) // x86_64
//#define linux_syscall_name_ioctl                 (LINUX_X32_SYSCALL_BIT +  16) // x86_64
#define linux_syscall_name_pread64                 (LINUX_X32_SYSCALL_BIT +  17) ///< pread64
#define linux_syscall_name_pwrite64                (LINUX_X32_SYSCALL_BIT +  18) ///< pwrite64
//#define linux_syscall_name_readv                 (LINUX_X32_SYSCALL_BIT +  19) // x86_64
//#define linux_syscall_name_writev                (LINUX_X32_SYSCALL_BIT +  20) // x86_64
#define linux_syscall_name_access                  (LINUX_X32_SYSCALL_BIT +  21) ///< access
#define linux_syscall_name_pipe                    (LINUX_X32_SYSCALL_BIT +  22) ///< pipe
#define linux_syscall_name_select                  (LINUX_X32_SYSCALL_BIT +  23) ///< select
#define linux_syscall_name_sched_yield             (LINUX_X32_SYSCALL_BIT +  24) ///< sched_yield
#define linux_syscall_name_mremap                  (LINUX_X32_SYSCALL_BIT +  25) ///< mremap
#define linux_syscall_name_msync                   (LINUX_X32_SYSCALL_BIT +  26) ///< msync
#define linux_syscall_name_mincore                 (LINUX_X32_SYSCALL_BIT +  27) ///< mincore
#define linux_syscall_name_madvise                 (LINUX_X32_SYSCALL_BIT +  28) ///< madvise
#define linux_syscall_name_shmget                  (LINUX_X32_SYSCALL_BIT +  29) ///< shmget
#define linux_syscall_name_shmat                   (LINUX_X32_SYSCALL_BIT +  30) ///< shmat
#define linux_syscall_name_shmctl                  (LINUX_X32_SYSCALL_BIT +  31) ///< shmctl
#define linux_syscall_name_dup                     (LINUX_X32_SYSCALL_BIT +  32) ///< dup
#define linux_syscall_name_dup2                    (LINUX_X32_SYSCALL_BIT +  33) ///< dup2
#define linux_syscall_name_pause                   (LINUX_X32_SYSCALL_BIT +  34) ///< pause
#define linux_syscall_name_nanosleep               (LINUX_X32_SYSCALL_BIT +  35) ///< nanosleep
#define linux_syscall_name_getitimer               (LINUX_X32_SYSCALL_BIT +  36) ///< getitimer
#define linux_syscall_name_alarm                   (LINUX_X32_SYSCALL_BIT +  37) ///< alarm
#define linux_syscall_name_setitimer               (LINUX_X32_SYSCALL_BIT +  38) ///< setitimer
#define linux_syscall_name_getpid                  (LINUX_X32_SYSCALL_BIT +  39) ///< getpid
#define linux_syscall_name_sendfile64              (LINUX_X32_SYSCALL_BIT +  40) ///< sendfile64
#define linux_syscall_name_socket                  (LINUX_X32_SYSCALL_BIT +  41) ///< socket
#define linux_syscall_name_connect                 (LINUX_X32_SYSCALL_BIT +  42) ///< connect
#define linux_syscall_name_accept                  (LINUX_X32_SYSCALL_BIT +  43) ///< accept
#define linux_syscall_name_sendto                  (LINUX_X32_SYSCALL_BIT +  44) ///< sendto
//#define linux_syscall_name_recvfrom              (LINUX_X32_SYSCALL_BIT +  45) // x86_64
//#define linux_syscall_name_sendmsg               (LINUX_X32_SYSCALL_BIT +  46) // x86_64
//#define linux_syscall_name_recvmsg               (LINUX_X32_SYSCALL_BIT +  47) // x86_64
#define linux_syscall_name_shutdown                (LINUX_X32_SYSCALL_BIT +  48) ///< shutdown
#define linux_syscall_name_bind                    (LINUX_X32_SYSCALL_BIT +  49) ///< bind
#define linux_syscall_name_listen                  (LINUX_X32_SYSCALL_BIT +  50) ///< listen
#define linux_syscall_name_getsockname             (LINUX_X32_SYSCALL_BIT +  51) ///< getsockname
#define linux_syscall_name_getpeername             (LINUX_X32_SYSCALL_BIT +  52) ///< getpeername
#define linux_syscall_name_socketpair              (LINUX_X32_SYSCALL_BIT +  53) ///< socketpair
//#define linux_syscall_name_setsockopt            (LINUX_X32_SYSCALL_BIT +  54) // x86_64
//#define linux_syscall_name_getsockopt            (LINUX_X32_SYSCALL_BIT +  55) // x86_64
#define linux_syscall_name_clone                   (LINUX_X32_SYSCALL_BIT +  56) ///< clone
#define linux_syscall_name_fork                    (LINUX_X32_SYSCALL_BIT +  57) ///< fork
//#define linux_syscall_name_vfork                 (LINUX_X32_SYSCALL_BIT +  58) // Use linux_vfork().
//#define linux_syscall_name_execve                (LINUX_X32_SYSCALL_BIT +  59) // x86_64
#define linux_syscall_name_exit                    (LINUX_X32_SYSCALL_BIT +  60) ///< exit
#define linux_syscall_name_wait4                   (LINUX_X32_SYSCALL_BIT +  61) ///< wait4
#define linux_syscall_name_kill                    (LINUX_X32_SYSCALL_BIT +  62) ///< kill
#define linux_syscall_name_newuname                (LINUX_X32_SYSCALL_BIT +  63) ///< newuname
#define linux_syscall_name_semget                  (LINUX_X32_SYSCALL_BIT +  64) ///< semget
#define linux_syscall_name_semop                   (LINUX_X32_SYSCALL_BIT +  65) ///< semop
#define linux_syscall_name_semctl                  (LINUX_X32_SYSCALL_BIT +  66) ///< semctl
#define linux_syscall_name_shmdt                   (LINUX_X32_SYSCALL_BIT +  67) ///< shmdt
#define linux_syscall_name_msgget                  (LINUX_X32_SYSCALL_BIT +  68) ///< msgget
#define linux_syscall_name_msgsnd                  (LINUX_X32_SYSCALL_BIT +  69) ///< msgsnd
#define linux_syscall_name_msgrcv                  (LINUX_X32_SYSCALL_BIT +  70) ///< msgrcv
#define linux_syscall_name_msgctl                  (LINUX_X32_SYSCALL_BIT +  71) ///< msgctl
#define linux_syscall_name_fcntl                   (LINUX_X32_SYSCALL_BIT +  72) ///< fcntl
#define linux_syscall_name_flock                   (LINUX_X32_SYSCALL_BIT +  73) ///< flock
#define linux_syscall_name_fsync                   (LINUX_X32_SYSCALL_BIT +  74) ///< fsync
#define linux_syscall_name_fdatasync               (LINUX_X32_SYSCALL_BIT +  75) ///< fdatasync
#define linux_syscall_name_truncate                (LINUX_X32_SYSCALL_BIT +  76) ///< truncate
#define linux_syscall_name_ftruncate               (LINUX_X32_SYSCALL_BIT +  77) ///< ftruncate
#define linux_syscall_name_getdents                (LINUX_X32_SYSCALL_BIT +  78) ///< getdents
#define linux_syscall_name_getcwd                  (LINUX_X32_SYSCALL_BIT +  79) ///< getcwd
#define linux_syscall_name_chdir                   (LINUX_X32_SYSCALL_BIT +  80) ///< chdir
#define linux_syscall_name_fchdir                  (LINUX_X32_SYSCALL_BIT +  81) ///< fchdir
#define linux_syscall_name_rename                  (LINUX_X32_SYSCALL_BIT +  82) ///< rename
#define linux_syscall_name_mkdir                   (LINUX_X32_SYSCALL_BIT +  83) ///< mkdir
#define linux_syscall_name_rmdir                   (LINUX_X32_SYSCALL_BIT +  84) ///< rmdir
#define linux_syscall_name_creat                   (LINUX_X32_SYSCALL_BIT +  85) ///< creat
#define linux_syscall_name_link                    (LINUX_X32_SYSCALL_BIT +  86) ///< link
#define linux_syscall_name_unlink                  (LINUX_X32_SYSCALL_BIT +  87) ///< unlink
#define linux_syscall_name_symlink                 (LINUX_X32_SYSCALL_BIT +  88) ///< symlink
#define linux_syscall_name_readlink                (LINUX_X32_SYSCALL_BIT +  89) ///< readlink
#define linux_syscall_name_chmod                   (LINUX_X32_SYSCALL_BIT +  90) ///< chmod
#define linux_syscall_name_fchmod                  (LINUX_X32_SYSCALL_BIT +  91) ///< fchmod
#define linux_syscall_name_chown                   (LINUX_X32_SYSCALL_BIT +  92) ///< chown
#define linux_syscall_name_fchown                  (LINUX_X32_SYSCALL_BIT +  93) ///< fchown
#define linux_syscall_name_lchown                  (LINUX_X32_SYSCALL_BIT +  94) ///< lchown
#define linux_syscall_name_umask                   (LINUX_X32_SYSCALL_BIT +  95) ///< umask
#define linux_syscall_name_gettimeofday            (LINUX_X32_SYSCALL_BIT +  96) ///< gettimeofday
#define linux_syscall_name_getrlimit               (LINUX_X32_SYSCALL_BIT +  97) ///< getrlimit
#define linux_syscall_name_getrusage               (LINUX_X32_SYSCALL_BIT +  98) ///< getrusage
#define linux_syscall_name_sysinfo                 (LINUX_X32_SYSCALL_BIT +  99) ///< sysinfo
#define linux_syscall_name_times                   (LINUX_X32_SYSCALL_BIT + 100) ///< times
//#define linux_syscall_name_ptrace                (LINUX_X32_SYSCALL_BIT + 101) // x86_64
#define linux_syscall_name_getuid                  (LINUX_X32_SYSCALL_BIT + 102) ///< getuid
#define linux_syscall_name_syslog                  (LINUX_X32_SYSCALL_BIT + 103) ///< syslog
#define linux_syscall_name_getgid                  (LINUX_X32_SYSCALL_BIT + 104) ///< getgid
#define linux_syscall_name_setuid                  (LINUX_X32_SYSCALL_BIT + 105) ///< setuid
#define linux_syscall_name_setgid                  (LINUX_X32_SYSCALL_BIT + 106) ///< setgid
#define linux_syscall_name_geteuid                 (LINUX_X32_SYSCALL_BIT + 107) ///< geteuid
#define linux_syscall_name_getegid                 (LINUX_X32_SYSCALL_BIT + 108) ///< getegid
#define linux_syscall_name_setpgid                 (LINUX_X32_SYSCALL_BIT + 109) ///< setpgid
#define linux_syscall_name_getppid                 (LINUX_X32_SYSCALL_BIT + 110) ///< getppid
#define linux_syscall_name_getpgrp                 (LINUX_X32_SYSCALL_BIT + 111) ///< getpgrp
#define linux_syscall_name_setsid                  (LINUX_X32_SYSCALL_BIT + 112) ///< setsid
#define linux_syscall_name_setreuid                (LINUX_X32_SYSCALL_BIT + 113) ///< setreuid
#define linux_syscall_name_setregid                (LINUX_X32_SYSCALL_BIT + 114) ///< setregid
#define linux_syscall_name_getgroups               (LINUX_X32_SYSCALL_BIT + 115) ///< getgroups
#define linux_syscall_name_setgroups               (LINUX_X32_SYSCALL_BIT + 116) ///< setgroups
#define linux_syscall_name_setresuid               (LINUX_X32_SYSCALL_BIT + 117) ///< setresuid
#define linux_syscall_name_getresuid               (LINUX_X32_SYSCALL_BIT + 118) ///< getresuid
#define linux_syscall_name_setresgid               (LINUX_X32_SYSCALL_BIT + 119) ///< setresgid
#define linux_syscall_name_getresgid               (LINUX_X32_SYSCALL_BIT + 120) ///< getresgid
#define linux_syscall_name_getpgid                 (LINUX_X32_SYSCALL_BIT + 121) ///< getpgid
#define linux_syscall_name_setfsuid                (LINUX_X32_SYSCALL_BIT + 122) ///< setfsuid
#define linux_syscall_name_setfsgid                (LINUX_X32_SYSCALL_BIT + 123) ///< setfsgid
#define linux_syscall_name_getsid                  (LINUX_X32_SYSCALL_BIT + 124) ///< getsid
#define linux_syscall_name_capget                  (LINUX_X32_SYSCALL_BIT + 125) ///< capget
#define linux_syscall_name_capset                  (LINUX_X32_SYSCALL_BIT + 126) ///< capset
//#define linux_syscall_name_rt_sigpending         (LINUX_X32_SYSCALL_BIT + 127) // x86_64
//#define linux_syscall_name_rt_sigtimedwait       (LINUX_X32_SYSCALL_BIT + 128) // x86_64
//#define linux_syscall_name_rt_sigqueueinfo       (LINUX_X32_SYSCALL_BIT + 129) // x86_64
#define linux_syscall_name_rt_sigsuspend           (LINUX_X32_SYSCALL_BIT + 130) ///< rt_sigsuspend
//#define linux_syscall_name_sigaltstack           (LINUX_X32_SYSCALL_BIT + 131) // x86_64
#define linux_syscall_name_utime                   (LINUX_X32_SYSCALL_BIT + 132) ///< utime
#define linux_syscall_name_mknod                   (LINUX_X32_SYSCALL_BIT + 133) ///< mknod
//#define linux_syscall_name_uselib                (LINUX_X32_SYSCALL_BIT + 134) // unused
#define linux_syscall_name_personality             (LINUX_X32_SYSCALL_BIT + 135) ///< personality
#define linux_syscall_name_ustat                   (LINUX_X32_SYSCALL_BIT + 136) ///< ustat
#define linux_syscall_name_statfs                  (LINUX_X32_SYSCALL_BIT + 137) ///< statfs
#define linux_syscall_name_fstatfs                 (LINUX_X32_SYSCALL_BIT + 138) ///< fstatfs
#define linux_syscall_name_sysfs                   (LINUX_X32_SYSCALL_BIT + 139) ///< sysfs
#define linux_syscall_name_getpriority             (LINUX_X32_SYSCALL_BIT + 140) ///< getpriority
#define linux_syscall_name_setpriority             (LINUX_X32_SYSCALL_BIT + 141) ///< setpriority
#define linux_syscall_name_sched_setparam          (LINUX_X32_SYSCALL_BIT + 142) ///< sched_setparam
#define linux_syscall_name_sched_getparam          (LINUX_X32_SYSCALL_BIT + 143) ///< sched_getparam
#define linux_syscall_name_sched_setscheduler      (LINUX_X32_SYSCALL_BIT + 144) ///< sched_setscheduler
#define linux_syscall_name_sched_getscheduler      (LINUX_X32_SYSCALL_BIT + 145) ///< sched_getscheduler
#define linux_syscall_name_sched_get_priority_max  (LINUX_X32_SYSCALL_BIT + 146) ///< sched_get_priority_max
#define linux_syscall_name_sched_get_priority_min  (LINUX_X32_SYSCALL_BIT + 147) ///< sched_get_priority_min
#define linux_syscall_name_sched_rr_get_interval   (LINUX_X32_SYSCALL_BIT + 148) ///< sched_rr_get_interval
#define linux_syscall_name_mlock                   (LINUX_X32_SYSCALL_BIT + 149) ///< mlock
#define linux_syscall_name_munlock                 (LINUX_X32_SYSCALL_BIT + 150) ///< munlock
#define linux_syscall_name_mlockall                (LINUX_X32_SYSCALL_BIT + 151) ///< mlockall
#define linux_syscall_name_munlockall              (LINUX_X32_SYSCALL_BIT + 152) ///< munlockall
#define linux_syscall_name_vhangup                 (LINUX_X32_SYSCALL_BIT + 153) ///< vhangup
#define linux_syscall_name_modify_ldt              (LINUX_X32_SYSCALL_BIT + 154) ///< modify_ldt
#define linux_syscall_name_pivot_root              (LINUX_X32_SYSCALL_BIT + 155) ///< pivot_root
//#define linux_syscall_name_sysctl                (LINUX_X32_SYSCALL_BIT + 156) // unimplemented
#define linux_syscall_name_prctl                   (LINUX_X32_SYSCALL_BIT + 157) ///< prctl
#define linux_syscall_name_arch_prctl              (LINUX_X32_SYSCALL_BIT + 158) ///< arch_prctl
#define linux_syscall_name_adjtimex                (LINUX_X32_SYSCALL_BIT + 159) ///< adjtimex
#define linux_syscall_name_setrlimit               (LINUX_X32_SYSCALL_BIT + 160) ///< setrlimit
#define linux_syscall_name_chroot                  (LINUX_X32_SYSCALL_BIT + 161) ///< chroot
#define linux_syscall_name_sync                    (LINUX_X32_SYSCALL_BIT + 162) ///< sync
#define linux_syscall_name_acct                    (LINUX_X32_SYSCALL_BIT + 163) ///< acct
#define linux_syscall_name_settimeofday            (LINUX_X32_SYSCALL_BIT + 164) ///< settimeofday
#define linux_syscall_name_mount                   (LINUX_X32_SYSCALL_BIT + 165) ///< mount
#define linux_syscall_name_umount                  (LINUX_X32_SYSCALL_BIT + 166) ///< umount
#define linux_syscall_name_swapon                  (LINUX_X32_SYSCALL_BIT + 167) ///< swapon
#define linux_syscall_name_swapoff                 (LINUX_X32_SYSCALL_BIT + 168) ///< swapoff
#define linux_syscall_name_reboot                  (LINUX_X32_SYSCALL_BIT + 169) ///< reboot
#define linux_syscall_name_sethostname             (LINUX_X32_SYSCALL_BIT + 170) ///< sethostname
#define linux_syscall_name_setdomainname           (LINUX_X32_SYSCALL_BIT + 171) ///< setdomainname
#define linux_syscall_name_iopl                    (LINUX_X32_SYSCALL_BIT + 172) ///< iopl
#define linux_syscall_name_ioperm                  (LINUX_X32_SYSCALL_BIT + 173) ///< ioperm
//#define linux_syscall_name_create_module         (LINUX_X32_SYSCALL_BIT + 174) // unused
#define linux_syscall_name_init_module             (LINUX_X32_SYSCALL_BIT + 175) ///< init_module
#define linux_syscall_name_delete_module           (LINUX_X32_SYSCALL_BIT + 176) ///< delete_module
//#define linux_syscall_name_get_kernel_syms       (LINUX_X32_SYSCALL_BIT + 177) // unused
//#define linux_syscall_name_query_module          (LINUX_X32_SYSCALL_BIT + 178) // unused
#define linux_syscall_name_quotactl                (LINUX_X32_SYSCALL_BIT + 179) ///< quotactl
//#define linux_syscall_name_nfsservctl            (LINUX_X32_SYSCALL_BIT + 180) // unused
//#define linux_syscall_name_getpmsg               (LINUX_X32_SYSCALL_BIT + 181) // unused
//#define linux_syscall_name_putpmsg               (LINUX_X32_SYSCALL_BIT + 182) // unused
//#define linux_syscall_name_afs_syscall           (LINUX_X32_SYSCALL_BIT + 183) // unused
//#define linux_syscall_name_tuxcall               (LINUX_X32_SYSCALL_BIT + 184) // unused
//#define linux_syscall_name_security              (LINUX_X32_SYSCALL_BIT + 185) // unused
#define linux_syscall_name_gettid                  (LINUX_X32_SYSCALL_BIT + 186) ///< gettid
#define linux_syscall_name_readahead               (LINUX_X32_SYSCALL_BIT + 187) ///< readahead
#define linux_syscall_name_setxattr                (LINUX_X32_SYSCALL_BIT + 188) ///< setxattr
#define linux_syscall_name_lsetxattr               (LINUX_X32_SYSCALL_BIT + 189) ///< lsetxattr
#define linux_syscall_name_fsetxattr               (LINUX_X32_SYSCALL_BIT + 190) ///< fsetxattr
#define linux_syscall_name_getxattr                (LINUX_X32_SYSCALL_BIT + 191) ///< getxattr
#define linux_syscall_name_lgetxattr               (LINUX_X32_SYSCALL_BIT + 192) ///< lgetxattr
#define linux_syscall_name_fgetxattr               (LINUX_X32_SYSCALL_BIT + 193) ///< fgetxattr
#define linux_syscall_name_listxattr               (LINUX_X32_SYSCALL_BIT + 194) ///< listxattr
#define linux_syscall_name_llistxattr              (LINUX_X32_SYSCALL_BIT + 195) ///< llistxattr
#define linux_syscall_name_flistxattr              (LINUX_X32_SYSCALL_BIT + 196) ///< flistxattr
#define linux_syscall_name_removexattr             (LINUX_X32_SYSCALL_BIT + 197) ///< removexattr
#define linux_syscall_name_lremovexattr            (LINUX_X32_SYSCALL_BIT + 198) ///< lremovexattr
#define linux_syscall_name_fremovexattr            (LINUX_X32_SYSCALL_BIT + 199) ///< fremovexattr
#define linux_syscall_name_tkill                   (LINUX_X32_SYSCALL_BIT + 200) ///< tkill
#define linux_syscall_name_time                    (LINUX_X32_SYSCALL_BIT + 201) ///< time
#define linux_syscall_name_futex                   (LINUX_X32_SYSCALL_BIT + 202) ///< futex
#define linux_syscall_name_sched_setaffinity       (LINUX_X32_SYSCALL_BIT + 203) ///< sched_setaffinity
#define linux_syscall_name_sched_getaffinity       (LINUX_X32_SYSCALL_BIT + 204) ///< sched_getaffinity
//#define linux_syscall_name_set_thread_area       (LINUX_X32_SYSCALL_BIT + 205) // unused
//#define linux_syscall_name_io_setup              (LINUX_X32_SYSCALL_BIT + 206) // x86_64
#define linux_syscall_name_io_destroy              (LINUX_X32_SYSCALL_BIT + 207) ///< io_destroy
#define linux_syscall_name_io_getevents            (LINUX_X32_SYSCALL_BIT + 208) ///< io_getevents
//#define linux_syscall_name_io_submit             (LINUX_X32_SYSCALL_BIT + 209) // x86_64
#define linux_syscall_name_io_cancel               (LINUX_X32_SYSCALL_BIT + 210) ///< io_cancel
//#define linux_syscall_name_get_thread_area       (LINUX_X32_SYSCALL_BIT + 211) // unused
#define linux_syscall_name_lookup_dcookie          (LINUX_X32_SYSCALL_BIT + 212) ///< lookup_dcookie
#define linux_syscall_name_epoll_create            (LINUX_X32_SYSCALL_BIT + 213) ///< epoll_create
//#define linux_syscall_name_epoll_ctl_old         (LINUX_X32_SYSCALL_BIT + 214) // unused
//#define linux_syscall_name_epoll_wait_old        (LINUX_X32_SYSCALL_BIT + 215) // unused
#define linux_syscall_name_remap_file_pages        (LINUX_X32_SYSCALL_BIT + 216) ///< remap_file_pages
#define linux_syscall_name_getdents64              (LINUX_X32_SYSCALL_BIT + 217) ///< getdents64
#define linux_syscall_name_set_tid_address         (LINUX_X32_SYSCALL_BIT + 218) ///< set_tid_address
//#define linux_syscall_name_restart_syscall       (LINUX_X32_SYSCALL_BIT + 219) // Don't use in userspace.
#define linux_syscall_name_semtimedop              (LINUX_X32_SYSCALL_BIT + 220) ///< semtimedop
#define linux_syscall_name_fadvise64               (LINUX_X32_SYSCALL_BIT + 221) ///< fadvise64
//#define linux_syscall_name_timer_create          (LINUX_X32_SYSCALL_BIT + 222) // x86_64
#define linux_syscall_name_timer_settime           (LINUX_X32_SYSCALL_BIT + 223) ///< timer_settime
#define linux_syscall_name_timer_gettime           (LINUX_X32_SYSCALL_BIT + 224) ///< timer_gettime
#define linux_syscall_name_timer_getoverrun        (LINUX_X32_SYSCALL_BIT + 225) ///< timer_getoverrun
#define linux_syscall_name_timer_delete            (LINUX_X32_SYSCALL_BIT + 226) ///< timer_delete
#define linux_syscall_name_clock_settime           (LINUX_X32_SYSCALL_BIT + 227) ///< clock_settime
#define linux_syscall_name_clock_gettime           (LINUX_X32_SYSCALL_BIT + 228) ///< clock_gettime
#define linux_syscall_name_clock_getres            (LINUX_X32_SYSCALL_BIT + 229) ///< clock_getres
#define linux_syscall_name_clock_nanosleep         (LINUX_X32_SYSCALL_BIT + 230) ///< clock_nanosleep
#define linux_syscall_name_exit_group              (LINUX_X32_SYSCALL_BIT + 231) ///< exit_group
#define linux_syscall_name_epoll_wait              (LINUX_X32_SYSCALL_BIT + 232) ///< epoll_wait
#define linux_syscall_name_epoll_ctl               (LINUX_X32_SYSCALL_BIT + 233) ///< epoll_ctl
#define linux_syscall_name_tgkill                  (LINUX_X32_SYSCALL_BIT + 234) ///< tgkill
#define linux_syscall_name_utimes                  (LINUX_X32_SYSCALL_BIT + 235) ///< utimes
//#define linux_syscall_name_vserver               (LINUX_X32_SYSCALL_BIT + 236) // unused
#define linux_syscall_name_mbind                   (LINUX_X32_SYSCALL_BIT + 237) ///< mbind
#define linux_syscall_name_set_mempolicy           (LINUX_X32_SYSCALL_BIT + 238) ///< set_mempolicy
#define linux_syscall_name_get_mempolicy           (LINUX_X32_SYSCALL_BIT + 239) ///< get_mempolicy
#define linux_syscall_name_mq_open                 (LINUX_X32_SYSCALL_BIT + 240) ///< mq_open
#define linux_syscall_name_mq_unlink               (LINUX_X32_SYSCALL_BIT + 241) ///< mq_unlink
#define linux_syscall_name_mq_timedsend            (LINUX_X32_SYSCALL_BIT + 242) ///< mq_timedsend
#define linux_syscall_name_mq_timedreceive         (LINUX_X32_SYSCALL_BIT + 243) ///< mq_timedreceive
//#define linux_syscall_name_mq_notify             (LINUX_X32_SYSCALL_BIT + 244) // x86_64
#define linux_syscall_name_mq_getsetattr           (LINUX_X32_SYSCALL_BIT + 245) ///< mq_getsetattr
//#define linux_syscall_name_kexec_load            (LINUX_X32_SYSCALL_BIT + 246) // x86_64
//#define linux_syscall_name_waitid                (LINUX_X32_SYSCALL_BIT + 247) // x86_64
#define linux_syscall_name_add_key                 (LINUX_X32_SYSCALL_BIT + 248) ///< add_key
#define linux_syscall_name_request_key             (LINUX_X32_SYSCALL_BIT + 249) ///< request_key
#define linux_syscall_name_keyctl                  (LINUX_X32_SYSCALL_BIT + 250) ///< keyctl
#define linux_syscall_name_ioprio_set              (LINUX_X32_SYSCALL_BIT + 251) ///< ioprio_set
#define linux_syscall_name_ioprio_get              (LINUX_X32_SYSCALL_BIT + 252) ///< ioprio_get
#define linux_syscall_name_inotify_init            (LINUX_X32_SYSCALL_BIT + 253) ///< inotify_init
#define linux_syscall_name_inotify_add_watch       (LINUX_X32_SYSCALL_BIT + 254) ///< inotify_add_watch
#define linux_syscall_name_inotify_rm_watch        (LINUX_X32_SYSCALL_BIT + 255) ///< inotify_rm_watch
#define linux_syscall_name_migrate_pages           (LINUX_X32_SYSCALL_BIT + 256) ///< migrate_pages
#define linux_syscall_name_openat                  (LINUX_X32_SYSCALL_BIT + 257) ///< openat
#define linux_syscall_name_mkdirat                 (LINUX_X32_SYSCALL_BIT + 258) ///< mkdirat
#define linux_syscall_name_mknodat                 (LINUX_X32_SYSCALL_BIT + 259) ///< mknodat
#define linux_syscall_name_fchownat                (LINUX_X32_SYSCALL_BIT + 260) ///< fchownat
#define linux_syscall_name_futimesat               (LINUX_X32_SYSCALL_BIT + 261) ///< futimesat
#define linux_syscall_name_newfstatat              (LINUX_X32_SYSCALL_BIT + 262) ///< newfstatat
#define linux_syscall_name_unlinkat                (LINUX_X32_SYSCALL_BIT + 263) ///< unlinkat
#define linux_syscall_name_renameat                (LINUX_X32_SYSCALL_BIT + 264) ///< renameat
#define linux_syscall_name_linkat                  (LINUX_X32_SYSCALL_BIT + 265) ///< linkat
#define linux_syscall_name_symlinkat               (LINUX_X32_SYSCALL_BIT + 266) ///< symlinkat
#define linux_syscall_name_readlinkat              (LINUX_X32_SYSCALL_BIT + 267) ///< readlinkat
#define linux_syscall_name_fchmodat                (LINUX_X32_SYSCALL_BIT + 268) ///< fchmodat
#define linux_syscall_name_faccessat               (LINUX_X32_SYSCALL_BIT + 269) ///< faccessat
#define linux_syscall_name_pselect6                (LINUX_X32_SYSCALL_BIT + 270) ///< pselect6
#define linux_syscall_name_ppoll                   (LINUX_X32_SYSCALL_BIT + 271) ///< ppoll
#define linux_syscall_name_unshare                 (LINUX_X32_SYSCALL_BIT + 272) ///< unshare
//#define linux_syscall_name_set_robust_list       (LINUX_X32_SYSCALL_BIT + 273) // x86_64
//#define linux_syscall_name_get_robust_list       (LINUX_X32_SYSCALL_BIT + 274) // x86_64
#define linux_syscall_name_splice                  (LINUX_X32_SYSCALL_BIT + 275) ///< splice
#define linux_syscall_name_tee                     (LINUX_X32_SYSCALL_BIT + 276) ///< tee
#define linux_syscall_name_sync_file_range         (LINUX_X32_SYSCALL_BIT + 277) ///< sync_file_range
//#define linux_syscall_name_vmsplice              (LINUX_X32_SYSCALL_BIT + 278) // x86_64
//#define linux_syscall_name_move_pages            (LINUX_X32_SYSCALL_BIT + 279) // x86_64
#define linux_syscall_name_utimensat               (LINUX_X32_SYSCALL_BIT + 280) ///< utimensat
#define linux_syscall_name_epoll_pwait             (LINUX_X32_SYSCALL_BIT + 281) ///< epoll_pwait
#define linux_syscall_name_signalfd                (LINUX_X32_SYSCALL_BIT + 282) ///< signalfd
#define linux_syscall_name_timerfd_create          (LINUX_X32_SYSCALL_BIT + 283) ///< timerfd_create
#define linux_syscall_name_eventfd                 (LINUX_X32_SYSCALL_BIT + 284) ///< eventfd
#define linux_syscall_name_fallocate               (LINUX_X32_SYSCALL_BIT + 285) ///< fallocate
#define linux_syscall_name_timerfd_settime         (LINUX_X32_SYSCALL_BIT + 286) ///< timerfd_settime
#define linux_syscall_name_timerfd_gettime         (LINUX_X32_SYSCALL_BIT + 287) ///< timerfd_gettime
#define linux_syscall_name_accept4                 (LINUX_X32_SYSCALL_BIT + 288) ///< accept4
#define linux_syscall_name_signalfd4               (LINUX_X32_SYSCALL_BIT + 289) ///< signalfd4
#define linux_syscall_name_eventfd2                (LINUX_X32_SYSCALL_BIT + 290) ///< eventfd2
#define linux_syscall_name_epoll_create1           (LINUX_X32_SYSCALL_BIT + 291) ///< epoll_create1
#define linux_syscall_name_dup3                    (LINUX_X32_SYSCALL_BIT + 292) ///< dup3
#define linux_syscall_name_pipe2                   (LINUX_X32_SYSCALL_BIT + 293) ///< pipe2
#define linux_syscall_name_inotify_init1           (LINUX_X32_SYSCALL_BIT + 294) ///< inotify_init1
//#define linux_syscall_name_preadv                (LINUX_X32_SYSCALL_BIT + 295) // x86_64
//#define linux_syscall_name_pwritev               (LINUX_X32_SYSCALL_BIT + 296) // x86_64
//#define linux_syscall_name_rt_tgsigqueueinfo     (LINUX_X32_SYSCALL_BIT + 297) // x86_64
#define linux_syscall_name_perf_event_open         (LINUX_X32_SYSCALL_BIT + 298) ///< perf_event_open
//#define linux_syscall_name_recvmmsg              (LINUX_X32_SYSCALL_BIT + 298) // x86_64
#define linux_syscall_name_fanotify_init           (LINUX_X32_SYSCALL_BIT + 300) ///< fanotify_init
#define linux_syscall_name_fanotify_mark           (LINUX_X32_SYSCALL_BIT + 301) ///< fanotify_mark
#define linux_syscall_name_prlimit64               (LINUX_X32_SYSCALL_BIT + 302) ///< prlimit64
#define linux_syscall_name_name_to_handle_at       (LINUX_X32_SYSCALL_BIT + 303) ///< name_to_handle_at
#define linux_syscall_name_open_by_handle_at       (LINUX_X32_SYSCALL_BIT + 304) ///< open_by_handle_at
#define linux_syscall_name_clock_adjtime           (LINUX_X32_SYSCALL_BIT + 305) ///< clock_adjtime
#define linux_syscall_name_syncfs                  (LINUX_X32_SYSCALL_BIT + 306) ///< syncfs
//#define linux_syscall_name_sendmmsg              (LINUX_X32_SYSCALL_BIT + 307) // x86_64
#define linux_syscall_name_setns                   (LINUX_X32_SYSCALL_BIT + 308) ///< setns
#define linux_syscall_name_getcpu                  (LINUX_X32_SYSCALL_BIT + 309) ///< getcpu
//#define linux_syscall_name_process_vm_readv      (LINUX_X32_SYSCALL_BIT + 310) // x86_64
//#define linux_syscall_name_process_vm_writev     (LINUX_X32_SYSCALL_BIT + 311) // x86_64
#define linux_syscall_name_kcmp                    (LINUX_X32_SYSCALL_BIT + 312) ///< kcmp
#define linux_syscall_name_finit_module            (LINUX_X32_SYSCALL_BIT + 313) ///< finit_module
#define linux_syscall_name_sched_setattr           (LINUX_X32_SYSCALL_BIT + 314) ///< sched_setattr
#define linux_syscall_name_sched_getattr           (LINUX_X32_SYSCALL_BIT + 315) ///< sched_getattr
#define linux_syscall_name_renameat2               (LINUX_X32_SYSCALL_BIT + 316) ///< renameat2
#define linux_syscall_name_seccomp                 (LINUX_X32_SYSCALL_BIT + 317) ///< seccomp
#define linux_syscall_name_getrandom               (LINUX_X32_SYSCALL_BIT + 318) ///< getrandom
#define linux_syscall_name_memfd_create            (LINUX_X32_SYSCALL_BIT + 319) ///< memfd_create
#define linux_syscall_name_kexec_file_load         (LINUX_X32_SYSCALL_BIT + 320) ///< kexec_file_load
#define linux_syscall_name_bpf                     (LINUX_X32_SYSCALL_BIT + 321) ///< bpf
//#define linux_syscall_name_execveat              (LINUX_X32_SYSCALL_BIT + 322) // x86_64
#define linux_syscall_name_userfaultfd             (LINUX_X32_SYSCALL_BIT + 323) ///< userfaultfd
#define linux_syscall_name_membarrier              (LINUX_X32_SYSCALL_BIT + 324) ///< membarrier
#define linux_syscall_name_mlock2                  (LINUX_X32_SYSCALL_BIT + 325) ///< mlock2
#define linux_syscall_name_copy_file_range         (LINUX_X32_SYSCALL_BIT + 326) ///< copy_file_range
//#define linux_syscall_name_preadv2               (LINUX_X32_SYSCALL_BIT + 327) // x86_64
//#define linux_syscall_name_pwritev2              (LINUX_X32_SYSCALL_BIT + 328) // x86_64
#define linux_syscall_name_pkey_mprotect           (LINUX_X32_SYSCALL_BIT + 329) ///< pkey_mprotect
#define linux_syscall_name_pkey_alloc              (LINUX_X32_SYSCALL_BIT + 330) ///< pkey_alloc
#define linux_syscall_name_pkey_free               (LINUX_X32_SYSCALL_BIT + 331) ///< pkey_free
#define linux_syscall_name_statx                   (LINUX_X32_SYSCALL_BIT + 332) ///< statx
#define linux_syscall_name_io_pgetevents           (LINUX_X32_SYSCALL_BIT + 333) ///< io_pgetevents
#define linux_syscall_name_rseq                    (LINUX_X32_SYSCALL_BIT + 334) ///< rseq
// ...
// 335 to 423 are unused, so that the numbers are the same as on 32-bit systems
// ...
#define linux_syscall_name_pidfd_send_signal       (LINUX_X32_SYSCALL_BIT + 424) ///< pidfd_send_signal
#define linux_syscall_name_io_uring_setup          (LINUX_X32_SYSCALL_BIT + 425) ///< io_uring_setup
#define linux_syscall_name_io_uring_enter          (LINUX_X32_SYSCALL_BIT + 426) ///< io_uring_enter
#define linux_syscall_name_io_uring_register       (LINUX_X32_SYSCALL_BIT + 427) ///< io_uring_register
#define linux_syscall_name_open_tree               (LINUX_X32_SYSCALL_BIT + 428) ///< open_tree
#define linux_syscall_name_move_mount              (LINUX_X32_SYSCALL_BIT + 429) ///< move_mount
#define linux_syscall_name_fsopen                  (LINUX_X32_SYSCALL_BIT + 430) ///< fsopen
#define linux_syscall_name_fsconfig                (LINUX_X32_SYSCALL_BIT + 431) ///< fsconfig
#define linux_syscall_name_fsmount                 (LINUX_X32_SYSCALL_BIT + 432) ///< fsmount
#define linux_syscall_name_fspick                  (LINUX_X32_SYSCALL_BIT + 433) ///< fspick
#define linux_syscall_name_pidfd_open              (LINUX_X32_SYSCALL_BIT + 434) ///< pidfd_open
#define linux_syscall_name_clone3                  (LINUX_X32_SYSCALL_BIT + 435) ///< clone3
#define linux_syscall_name_close_range             (LINUX_X32_SYSCALL_BIT + 436) ///< close_range
#define linux_syscall_name_openat2                 (LINUX_X32_SYSCALL_BIT + 437) ///< openat2
#define linux_syscall_name_pidfd_getfd             (LINUX_X32_SYSCALL_BIT + 438) ///< pidfd_getfd
#define linux_syscall_name_faccessat2              (LINUX_X32_SYSCALL_BIT + 439) ///< faccessat2
#define linux_syscall_name_process_madvise         (LINUX_X32_SYSCALL_BIT + 440) ///< process_madvise
#define linux_syscall_name_epoll_pwait2            (LINUX_X32_SYSCALL_BIT + 441) ///< epoll_pwait2
#define linux_syscall_name_mount_setattr           (LINUX_X32_SYSCALL_BIT + 442) ///< mount_setattr
#define linux_syscall_name_quotactl_fd             (LINUX_X32_SYSCALL_BIT + 443) ///< quotactl_fd
#define linux_syscall_name_landlock_create_ruleset (LINUX_X32_SYSCALL_BIT + 444) ///< landlock_create_ruleset
#define linux_syscall_name_landlock_add_rule       (LINUX_X32_SYSCALL_BIT + 445) ///< landlock_add_rule
#define linux_syscall_name_landlock_restrict_self  (LINUX_X32_SYSCALL_BIT + 446) ///< landlock_restrict_self
#define linux_syscall_name_memfd_secret            (LINUX_X32_SYSCALL_BIT + 447) ///< memfd_secret
#define linux_syscall_name_process_mrelease        (LINUX_X32_SYSCALL_BIT + 448) ///< process_mrelease

#define linux_syscall_name_rt_sigaction            (LINUX_X32_SYSCALL_BIT + 512) ///< rt_sigaction
#define linux_syscall_name_rt_sigreturn            (LINUX_X32_SYSCALL_BIT + 513) ///< rt_sigreturn
#define linux_syscall_name_ioctl                   (LINUX_X32_SYSCALL_BIT + 514) ///< ioctl
#define linux_syscall_name_readv                   (LINUX_X32_SYSCALL_BIT + 515) ///< readv
#define linux_syscall_name_writev                  (LINUX_X32_SYSCALL_BIT + 516) ///< writev
#define linux_syscall_name_recvfrom                (LINUX_X32_SYSCALL_BIT + 517) ///< recvfrom
#define linux_syscall_name_sendmsg                 (LINUX_X32_SYSCALL_BIT + 518) ///< sendmsg
#define linux_syscall_name_recvmsg                 (LINUX_X32_SYSCALL_BIT + 519) ///< recvmsg
#define linux_syscall_name_execve                  (LINUX_X32_SYSCALL_BIT + 520) ///< execve
#define linux_syscall_name_ptrace                  (LINUX_X32_SYSCALL_BIT + 521) ///< ptrace
#define linux_syscall_name_rt_sigpending           (LINUX_X32_SYSCALL_BIT + 522) ///< rt_sigpending
#define linux_syscall_name_rt_sigtimedwait         (LINUX_X32_SYSCALL_BIT + 523) ///< rt_sigtimedwait
#define linux_syscall_name_rt_sigqueueinfo         (LINUX_X32_SYSCALL_BIT + 524) ///< rt_sigqueueinfo
#define linux_syscall_name_sigaltstack             (LINUX_X32_SYSCALL_BIT + 525) ///< sigaltstack
#define linux_syscall_name_timer_create            (LINUX_X32_SYSCALL_BIT + 526) ///< timer_create
#define linux_syscall_name_mq_notify               (LINUX_X32_SYSCALL_BIT + 527) ///< mq_notify
#define linux_syscall_name_kexec_load              (LINUX_X32_SYSCALL_BIT + 528) ///< kexec_load
#define linux_syscall_name_waitid                  (LINUX_X32_SYSCALL_BIT + 529) ///< waitid
#define linux_syscall_name_set_robust_list         (LINUX_X32_SYSCALL_BIT + 530) ///< set_robust_list
#define linux_syscall_name_get_robust_list         (LINUX_X32_SYSCALL_BIT + 531) ///< get_robust_list
#define linux_syscall_name_vmsplice                (LINUX_X32_SYSCALL_BIT + 532) ///< vmsplice
#define linux_syscall_name_move_pages              (LINUX_X32_SYSCALL_BIT + 533) ///< move_pages
#define linux_syscall_name_preadv                  (LINUX_X32_SYSCALL_BIT + 534) ///< preadv
#define linux_syscall_name_pwritev                 (LINUX_X32_SYSCALL_BIT + 535) ///< pwritev
#define linux_syscall_name_rt_tgsigqueueinfo       (LINUX_X32_SYSCALL_BIT + 536) ///< rt_tgsigqueueinfo
#define linux_syscall_name_recvmmsg                (LINUX_X32_SYSCALL_BIT + 537) ///< recvmmsg
#define linux_syscall_name_sendmmsg                (LINUX_X32_SYSCALL_BIT + 538) ///< sendmmsg
#define linux_syscall_name_process_vm_readv        (LINUX_X32_SYSCALL_BIT + 539) ///< process_vm_readv
#define linux_syscall_name_process_vm_writev       (LINUX_X32_SYSCALL_BIT + 540) ///< process_vm_writev
#define linux_syscall_name_setsockopt              (LINUX_X32_SYSCALL_BIT + 541) ///< setsockopt
#define linux_syscall_name_getsockopt              (LINUX_X32_SYSCALL_BIT + 542) ///< getsockopt
#define linux_syscall_name_io_setup                (LINUX_X32_SYSCALL_BIT + 543) ///< io_setup
#define linux_syscall_name_io_submit               (LINUX_X32_SYSCALL_BIT + 544) ///< io_submit
#define linux_syscall_name_execveat                (LINUX_X32_SYSCALL_BIT + 545) ///< execveat
#define linux_syscall_name_preadv2                 (LINUX_X32_SYSCALL_BIT + 546) ///< preadv2
#define linux_syscall_name_pwritev2                (LINUX_X32_SYSCALL_BIT + 547) ///< pwritev2

#endif // !HEADER_LIBLINUX_X32_UNISTD_H_INCLUDED
