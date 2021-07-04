csrc = \
       src/error.c\
       src/fork.c\
       src/read.c\
       src/write.c\
       src/open.c\
       src/close.c\
       src/creat.c\
       src/link.c\
       src/unlink.c\
       src/execve.c\
       src/chdir.c\
       src/mknod.c\
       src/chmod.c\
       src/lchown16.c\
       src/lseek.c\
       src/getpid.c\
       src/mount.c\
       src/setuid16.c\
       src/getuid16.c\
       src/ptrace.c\
       src/pause.c\
       src/access.c\
       src/nice.c\
       src/sync.c\
       src/kill.c\
       src/rename.c\
       src/mkdir.c\
       src/rmdir.c\
       src/dup.c\
       src/pipe.c\
       src/times.c\
       src/brk.c\
       src/setgid16.c\
       src/getgid16.c\
       src/geteuid16.c\
       src/getegid16.c\
       src/acct.c\
       src/umount.c\
       src/ioctl.c\
       src/fcntl.c\
       src/setpgid.c\
       src/umask.c\
       src/chroot.c\
       src/ustat.c\
       src/dup2.c\
       src/getppid.c\
       src/getpgrp.c\
       src/setsid.c\
       src/sigaction.c\
       src/setreuid16.c\
       src/setregid16.c\
       src/sigsuspend.c\
       src/sigpending.c\
       src/sethostname.c\
       src/setrlimit.c\
       src/getrusage.c\
       src/gettimeofday.c\
       src/settimeofday.c\
       src/getgroups16.c\
       src/setgroups16.c\
       src/symlink.c\
       src/readlink.c\
       src/uselib.c\
       src/swapon.c\
       src/reboot.c\
       src/munmap.c\
       src/truncate.c\
       src/ftruncate.c\
       src/fchmod.c\
       src/fchown16.c\
       src/getpriority.c\
       src/setpriority.c\
       src/statfs.c\
       src/fstatfs.c\
       src/syslog.c\
       src/setitimer.c\
       src/getitimer.c\
       src/newstat.c\
       src/newlstat.c\
       src/newfstat.c\
       src/vhangup.c\
       src/wait4.c\
       src/swapoff.c\
       src/sysinfo.c\
       src/fsync.c\
       src/clone.c\
       src/setdomainname.c\
       src/newuname.c\
       src/adjtimex_time32.c\
       src/mprotect.c\
       src/sigprocmask.c\
       src/init_module.c\
       src/delete_module.c\
       src/quotactl.c\
       src/getpgid.c\
       src/fchdir.c\
       src/bdflush.c\
       src/sysfs.c\
       src/personality.c\
       src/setfsuid16.c\
       src/setfsgid16.c\
       src/llseek.c\
       src/getdents.c\
       src/select.c\
       src/flock.c\
       src/msync.c\
       src/readv.c\
       src/writev.c\
       src/getsid.c\
       src/fdatasync.c\
       src/mlock.c\
       src/munlock.c\
       src/mlockall.c\
       src/munlockall.c\
       src/sched_setparam.c\
       src/sched_getparam.c\
       src/sched_setscheduler.c\
       src/sched_getscheduler.c\
       src/sched_yield.c\
       src/sched_get_priority_max.c\
       src/sched_get_priority_min.c\
       src/sched_rr_get_interval_time32.c\
       src/nanosleep_time32.c\
       src/mremap.c\
       src/setresuid16.c\
       src/getresuid16.c\
       src/poll.c\
       src/setresgid16.c\
       src/getresgid16.c\
       src/prctl.c\
       src/rt_sigaction.c\
       src/rt_sigprocmask.c\
       src/rt_sigpending.c\
       src/rt_sigtimedwait_time32.c\
       src/rt_sigqueueinfo.c\
       src/rt_sigsuspend.c\
       src/pread64.c\
       src/pwrite64.c\
       src/chown16.c\
       src/getcwd.c\
       src/capget.c\
       src/capset.c\
       src/sigaltstack.c\
       src/sendfile.c\
       src/vfork.c\
       src/getrlimit.c\
       src/mmap_pgoff.c\
       src/truncate64.c\
       src/ftruncate64.c\
       src/stat64.c\
       src/lstat64.c\
       src/fstat64.c\
       src/lchown.c\
       src/getuid.c\
       src/getgid.c\
       src/geteuid.c\
       src/getegid.c\
       src/setreuid.c\
       src/setregid.c\
       src/getgroups.c\
       src/setgroups.c\
       src/fchown.c\
       src/setresuid.c\
       src/getresuid.c\
       src/setresgid.c\
       src/getresgid.c\
       src/chown.c\
       src/setuid.c\
       src/setgid.c\
       src/setfsuid.c\
       src/setfsgid.c\
       src/getdents64.c\
       src/pivot_root.c\
       src/mincore.c\
       src/madvise.c\
       src/fcntl64.c\
       src/gettid.c\
       src/readahead.c\
       src/setxattr.c\
       src/lsetxattr.c\
       src/fsetxattr.c\
       src/getxattr.c\
       src/lgetxattr.c\
       src/fgetxattr.c\
       src/listxattr.c\
       src/llistxattr.c\
       src/flistxattr.c\
       src/removexattr.c\
       src/lremovexattr.c\
       src/fremovexattr.c\
       src/tkill.c\
       src/sendfile64.c\
       src/futex_time32.c\
       src/sched_setaffinity.c\
       src/sched_getaffinity.c\
       src/io_setup.c\
       src/io_destroy.c\
       src/io_getevents_time32.c\
       src/io_submit.c\
       src/io_cancel.c\
       src/lookup_dcookie.c\
       src/epoll_create.c\
       src/epoll_ctl.c\
       src/epoll_wait.c\
       src/remap_file_pages.c\
       src/set_tid_address.c\
       src/timer_create.c\
       src/timer_settime32.c\
       src/timer_gettime32.c\
       src/timer_getoverrun.c\
       src/timer_delete.c\
       src/clock_settime32.c\
       src/clock_gettime32.c\
       src/clock_getres_time32.c\
       src/clock_nanosleep_time32.c\
       src/statfs64.c\
       src/fstatfs64.c\
       src/tgkill.c\
       src/utimes_time32.c\
       src/arm_fadvise64_64.c\
       src/pciconfig_iobase.c\
       src/pciconfig_read.c\
       src/pciconfig_write.c\
       src/mq_open.c\
       src/mq_unlink.c\
       src/mq_timedsend_time32.c\
       src/mq_timedreceive_time32.c\
       src/mq_notify.c\
       src/mq_getsetattr.c\
       src/waitid.c\
       src/socket.c\
       src/bind.c\
       src/connect.c\
       src/listen.c\
       src/accept.c\
       src/getsockname.c\
       src/getpeername.c\
       src/socketpair.c\
       src/send.c\
       src/sendto.c\
       src/recv.c\
       src/recvfrom.c\
       src/shutdown.c\
       src/setsockopt.c\
       src/getsockopt.c\
       src/sendmsg.c\
       src/recvmsg.c\
       src/semop.c\
       src/semget.c\
       src/old_semctl.c\
       src/msgsnd.c\
       src/msgrcv.c\
       src/msgget.c\
       src/old_msgctl.c\
       src/shmat.c\
       src/shmdt.c\
       src/shmget.c\
       src/old_shmctl.c\
       src/add_key.c\
       src/request_key.c\
       src/keyctl.c\
       src/semtimedop_time32.c\
       src/ioprio_set.c\
       src/ioprio_get.c\
       src/inotify_init.c\
       src/inotify_add_watch.c\
       src/inotify_rm_watch.c\
       src/mbind.c\
       src/get_mempolicy.c\
       src/set_mempolicy.c\
       src/openat.c\
       src/mkdirat.c\
       src/mknodat.c\
       src/fchownat.c\
       src/futimesat_time32.c\
       src/fstatat64.c\
       src/unlinkat.c\
       src/renameat.c\
       src/linkat.c\
       src/symlinkat.c\
       src/readlinkat.c\
       src/fchmodat.c\
       src/faccessat.c\
       src/pselect6_time32.c\
       src/ppoll_time32.c\
       src/unshare.c\
       src/set_robust_list.c\
       src/get_robust_list.c\
       src/splice.c\
       src/sync_file_range.c\
       src/tee.c\
       src/vmsplice.c\
       src/move_pages.c\
       src/getcpu.c\
       src/epoll_pwait.c\
       src/kexec_load.c\
       src/utimensat_time32.c\
       src/signalfd.c\
       src/timerfd_create.c\
       src/eventfd.c\
       src/fallocate.c\
       src/timerfd_settime32.c\
       src/timerfd_gettime32.c\
       src/signalfd4.c\
       src/eventfd2.c\
       src/epoll_create1.c\
       src/dup3.c\
       src/pipe2.c\
       src/inotify_init1.c\
       src/preadv.c\
       src/pwritev.c\
       src/rt_tgsigqueueinfo.c\
       src/perf_event_open.c\
       src/recvmmsg_time32.c\
       src/accept4.c\
       src/fanotify_init.c\
       src/fanotify_mark.c\
       src/prlimit64.c\
       src/name_to_handle_at.c\
       src/open_by_handle_at.c\
       src/clock_adjtime32.c\
       src/syncfs.c\
       src/sendmmsg.c\
       src/setns.c\
       src/process_vm_readv.c\
       src/process_vm_writev.c\
       src/kcmp.c\
       src/finit_module.c\
       src/sched_setattr.c\
       src/sched_getattr.c\
       src/renameat2.c\
       src/seccomp.c\
       src/getrandom.c\
       src/memfd_create.c\
       src/bpf.c\
       src/execveat.c\
       src/userfaultfd.c\
       src/membarrier.c\
       src/mlock2.c\
       src/copy_file_range.c\
       src/preadv2.c\
       src/pwritev2.c\
       src/pkey_mprotect.c\
       src/pkey_alloc.c\
       src/pkey_free.c\
       src/statx.c\
       src/rseq.c\
       src/io_pgetevents_time32.c\
       src/migrate_pages.c\
       src/kexec_file_load.c\
       src/clock_gettime.c\
       src/clock_settime.c\
       src/clock_adjtime.c\
       src/clock_getres.c\
       src/clock_nanosleep.c\
       src/timer_gettime.c\
       src/timer_settime.c\
       src/timerfd_gettime.c\
       src/timerfd_settime.c\
       src/utimensat.c\
       src/pselect6.c\
       src/ppoll.c\
       src/io_pgetevents.c\
       src/recvmmsg.c\
       src/mq_timedsend.c\
       src/mq_timedreceive.c\
       src/semtimedop.c\
       src/rt_sigtimedwait.c\
       src/futex.c\
       src/sched_rr_get_interval.c\
       src/pidfd_send_signal.c\
       src/io_uring_setup.c\
       src/io_uring_enter.c\
       src/io_uring_register.c\
       src/open_tree.c\
       src/move_mount.c\
       src/fsopen.c\
       src/fsconfig.c\
       src/fsmount.c\
       src/fspick.c\
       src/pidfd_open.c\
       src/clone3.c\
       src/close_range.c\
       src/openat2.c\
       src/pidfd_getfd.c\
       src/faccessat2.c\
       src/process_madvise.c\
       src/epoll_pwait2.c\
       src/mount_setattr.c\
       src/landlock_create_ruleset.c\
       src/landlock_add_rule.c\
       src/landlock_restrict_self.c\
       src/breakpoint.c\
       src/cacheflush.c\
       src/usr26.c\
       src/usr32.c\
       src/set_tls.c\
       src/get_tls.c

tests = \
        tests/syscalls/fork\
        tests/syscalls/read\
        tests/syscalls/write\
        tests/syscalls/open\
        tests/syscalls/close\
        tests/syscalls/creat\
        tests/syscalls/link\
        tests/syscalls/unlink\
        tests/syscalls/execve\
        tests/syscalls/chdir\
        tests/syscalls/mknod\
        tests/syscalls/chmod\
        tests/syscalls/lchown16\
        tests/syscalls/lseek\
        tests/syscalls/getpid\
        tests/syscalls/mount\
        tests/syscalls/setuid16\
        tests/syscalls/getuid16\
        tests/syscalls/ptrace\
        tests/syscalls/pause\
        tests/syscalls/access\
        tests/syscalls/nice\
        tests/syscalls/sync\
        tests/syscalls/kill\
        tests/syscalls/rename\
        tests/syscalls/mkdir\
        tests/syscalls/rmdir\
        tests/syscalls/dup\
        tests/syscalls/pipe\
        tests/syscalls/times\
        tests/syscalls/brk\
        tests/syscalls/setgid16\
        tests/syscalls/getgid16\
        tests/syscalls/geteuid16\
        tests/syscalls/getegid16\
        tests/syscalls/acct\
        tests/syscalls/umount\
        tests/syscalls/ioctl\
        tests/syscalls/fcntl\
        tests/syscalls/setpgid\
        tests/syscalls/umask\
        tests/syscalls/chroot\
        tests/syscalls/ustat\
        tests/syscalls/dup2\
        tests/syscalls/getppid\
        tests/syscalls/getpgrp\
        tests/syscalls/setsid\
        tests/syscalls/sigaction\
        tests/syscalls/setreuid16\
        tests/syscalls/setregid16\
        tests/syscalls/sigsuspend\
        tests/syscalls/sigpending\
        tests/syscalls/sethostname\
        tests/syscalls/setrlimit\
        tests/syscalls/getrusage\
        tests/syscalls/gettimeofday\
        tests/syscalls/settimeofday\
        tests/syscalls/getgroups16\
        tests/syscalls/setgroups16\
        tests/syscalls/symlink\
        tests/syscalls/readlink\
        tests/syscalls/uselib\
        tests/syscalls/swapon\
        tests/syscalls/reboot\
        tests/syscalls/munmap\
        tests/syscalls/truncate\
        tests/syscalls/ftruncate\
        tests/syscalls/fchmod\
        tests/syscalls/fchown16\
        tests/syscalls/getpriority\
        tests/syscalls/setpriority\
        tests/syscalls/statfs\
        tests/syscalls/fstatfs\
        tests/syscalls/syslog\
        tests/syscalls/setitimer\
        tests/syscalls/getitimer\
        tests/syscalls/newstat\
        tests/syscalls/newlstat\
        tests/syscalls/newfstat\
        tests/syscalls/vhangup\
        tests/syscalls/wait4\
        tests/syscalls/swapoff\
        tests/syscalls/sysinfo\
        tests/syscalls/fsync\
        tests/syscalls/clone\
        tests/syscalls/setdomainname\
        tests/syscalls/newuname\
        tests/syscalls/adjtimex_time32\
        tests/syscalls/mprotect\
        tests/syscalls/sigprocmask\
        tests/syscalls/init_module\
        tests/syscalls/delete_module\
        tests/syscalls/quotactl\
        tests/syscalls/getpgid\
        tests/syscalls/fchdir\
        tests/syscalls/bdflush\
        tests/syscalls/sysfs\
        tests/syscalls/personality\
        tests/syscalls/setfsuid16\
        tests/syscalls/setfsgid16\
        tests/syscalls/llseek\
        tests/syscalls/getdents\
        tests/syscalls/select\
        tests/syscalls/flock\
        tests/syscalls/msync\
        tests/syscalls/readv\
        tests/syscalls/writev\
        tests/syscalls/getsid\
        tests/syscalls/fdatasync\
        tests/syscalls/mlock\
        tests/syscalls/munlock\
        tests/syscalls/mlockall\
        tests/syscalls/munlockall\
        tests/syscalls/sched_setparam\
        tests/syscalls/sched_getparam\
        tests/syscalls/sched_setscheduler\
        tests/syscalls/sched_getscheduler\
        tests/syscalls/sched_yield\
        tests/syscalls/sched_get_priority_max\
        tests/syscalls/sched_get_priority_min\
        tests/syscalls/sched_rr_get_interval_time32\
        tests/syscalls/nanosleep_time32\
        tests/syscalls/mremap\
        tests/syscalls/setresuid16\
        tests/syscalls/getresuid16\
        tests/syscalls/poll\
        tests/syscalls/setresgid16\
        tests/syscalls/getresgid16\
        tests/syscalls/prctl\
        tests/syscalls/rt_sigaction\
        tests/syscalls/rt_sigprocmask\
        tests/syscalls/rt_sigpending\
        tests/syscalls/rt_sigtimedwait_time32\
        tests/syscalls/rt_sigqueueinfo\
        tests/syscalls/rt_sigsuspend\
        tests/syscalls/pread64\
        tests/syscalls/pwrite64\
        tests/syscalls/chown16\
        tests/syscalls/getcwd\
        tests/syscalls/capget\
        tests/syscalls/capset\
        tests/syscalls/sigaltstack\
        tests/syscalls/sendfile\
        tests/syscalls/vfork\
        tests/syscalls/getrlimit\
        tests/syscalls/mmap_pgoff\
        tests/syscalls/truncate64\
        tests/syscalls/ftruncate64\
        tests/syscalls/stat64\
        tests/syscalls/lstat64\
        tests/syscalls/fstat64\
        tests/syscalls/lchown\
        tests/syscalls/getuid\
        tests/syscalls/getgid\
        tests/syscalls/geteuid\
        tests/syscalls/getegid\
        tests/syscalls/setreuid\
        tests/syscalls/setregid\
        tests/syscalls/getgroups\
        tests/syscalls/setgroups\
        tests/syscalls/fchown\
        tests/syscalls/setresuid\
        tests/syscalls/getresuid\
        tests/syscalls/setresgid\
        tests/syscalls/getresgid\
        tests/syscalls/chown\
        tests/syscalls/setuid\
        tests/syscalls/setgid\
        tests/syscalls/setfsuid\
        tests/syscalls/setfsgid\
        tests/syscalls/getdents64\
        tests/syscalls/pivot_root\
        tests/syscalls/mincore\
        tests/syscalls/madvise\
        tests/syscalls/fcntl64\
        tests/syscalls/gettid\
        tests/syscalls/readahead\
        tests/syscalls/setxattr\
        tests/syscalls/lsetxattr\
        tests/syscalls/fsetxattr\
        tests/syscalls/getxattr\
        tests/syscalls/lgetxattr\
        tests/syscalls/fgetxattr\
        tests/syscalls/listxattr\
        tests/syscalls/llistxattr\
        tests/syscalls/flistxattr\
        tests/syscalls/removexattr\
        tests/syscalls/lremovexattr\
        tests/syscalls/fremovexattr\
        tests/syscalls/tkill\
        tests/syscalls/sendfile64\
        tests/syscalls/futex_time32\
        tests/syscalls/sched_setaffinity\
        tests/syscalls/sched_getaffinity\
        tests/syscalls/io_setup\
        tests/syscalls/io_destroy\
        tests/syscalls/io_getevents_time32\
        tests/syscalls/io_submit\
        tests/syscalls/io_cancel\
        tests/syscalls/lookup_dcookie\
        tests/syscalls/epoll_create\
        tests/syscalls/epoll_ctl\
        tests/syscalls/epoll_wait\
        tests/syscalls/remap_file_pages\
        tests/syscalls/set_tid_address\
        tests/syscalls/timer_create\
        tests/syscalls/timer_settime32\
        tests/syscalls/timer_gettime32\
        tests/syscalls/timer_getoverrun\
        tests/syscalls/timer_delete\
        tests/syscalls/clock_settime32\
        tests/syscalls/clock_gettime32\
        tests/syscalls/clock_getres_time32\
        tests/syscalls/clock_nanosleep_time32\
        tests/syscalls/statfs64\
        tests/syscalls/fstatfs64\
        tests/syscalls/tgkill\
        tests/syscalls/utimes_time32\
        tests/syscalls/arm_fadvise64_64\
        tests/syscalls/pciconfig_iobase\
        tests/syscalls/pciconfig_read\
        tests/syscalls/pciconfig_write\
        tests/syscalls/mq_open\
        tests/syscalls/mq_unlink\
        tests/syscalls/mq_timedsend_time32\
        tests/syscalls/mq_timedreceive_time32\
        tests/syscalls/mq_notify\
        tests/syscalls/mq_getsetattr\
        tests/syscalls/waitid\
        tests/syscalls/socket\
        tests/syscalls/bind\
        tests/syscalls/connect\
        tests/syscalls/listen\
        tests/syscalls/accept\
        tests/syscalls/getsockname\
        tests/syscalls/getpeername\
        tests/syscalls/socketpair\
        tests/syscalls/send\
        tests/syscalls/sendto\
        tests/syscalls/recv\
        tests/syscalls/recvfrom\
        tests/syscalls/shutdown\
        tests/syscalls/setsockopt\
        tests/syscalls/getsockopt\
        tests/syscalls/sendmsg\
        tests/syscalls/recvmsg\
        tests/syscalls/semop\
        tests/syscalls/semget\
        tests/syscalls/old_semctl\
        tests/syscalls/msgsnd\
        tests/syscalls/msgrcv\
        tests/syscalls/msgget\
        tests/syscalls/old_msgctl\
        tests/syscalls/shmat\
        tests/syscalls/shmdt\
        tests/syscalls/shmget\
        tests/syscalls/old_shmctl\
        tests/syscalls/add_key\
        tests/syscalls/request_key\
        tests/syscalls/keyctl\
        tests/syscalls/semtimedop_time32\
        tests/syscalls/ioprio_set\
        tests/syscalls/ioprio_get\
        tests/syscalls/inotify_init\
        tests/syscalls/inotify_add_watch\
        tests/syscalls/inotify_rm_watch\
        tests/syscalls/mbind\
        tests/syscalls/get_mempolicy\
        tests/syscalls/set_mempolicy\
        tests/syscalls/openat\
        tests/syscalls/mkdirat\
        tests/syscalls/mknodat\
        tests/syscalls/fchownat\
        tests/syscalls/futimesat_time32\
        tests/syscalls/fstatat64\
        tests/syscalls/unlinkat\
        tests/syscalls/renameat\
        tests/syscalls/linkat\
        tests/syscalls/symlinkat\
        tests/syscalls/readlinkat\
        tests/syscalls/fchmodat\
        tests/syscalls/faccessat\
        tests/syscalls/pselect6_time32\
        tests/syscalls/ppoll_time32\
        tests/syscalls/unshare\
        tests/syscalls/set_robust_list\
        tests/syscalls/get_robust_list\
        tests/syscalls/splice\
        tests/syscalls/sync_file_range\
        tests/syscalls/tee\
        tests/syscalls/vmsplice\
        tests/syscalls/move_pages\
        tests/syscalls/getcpu\
        tests/syscalls/epoll_pwait\
        tests/syscalls/kexec_load\
        tests/syscalls/utimensat_time32\
        tests/syscalls/signalfd\
        tests/syscalls/timerfd_create\
        tests/syscalls/eventfd\
        tests/syscalls/fallocate\
        tests/syscalls/timerfd_settime32\
        tests/syscalls/timerfd_gettime32\
        tests/syscalls/signalfd4\
        tests/syscalls/eventfd2\
        tests/syscalls/epoll_create1\
        tests/syscalls/dup3\
        tests/syscalls/pipe2\
        tests/syscalls/inotify_init1\
        tests/syscalls/preadv\
        tests/syscalls/pwritev\
        tests/syscalls/rt_tgsigqueueinfo\
        tests/syscalls/perf_event_open\
        tests/syscalls/recvmmsg_time32\
        tests/syscalls/accept4\
        tests/syscalls/fanotify_init\
        tests/syscalls/fanotify_mark\
        tests/syscalls/prlimit64\
        tests/syscalls/name_to_handle_at\
        tests/syscalls/open_by_handle_at\
        tests/syscalls/clock_adjtime32\
        tests/syscalls/syncfs\
        tests/syscalls/sendmmsg\
        tests/syscalls/setns\
        tests/syscalls/process_vm_readv\
        tests/syscalls/process_vm_writev\
        tests/syscalls/kcmp\
        tests/syscalls/finit_module\
        tests/syscalls/sched_setattr\
        tests/syscalls/sched_getattr\
        tests/syscalls/renameat2\
        tests/syscalls/seccomp\
        tests/syscalls/getrandom\
        tests/syscalls/memfd_create\
        tests/syscalls/bpf\
        tests/syscalls/execveat\
        tests/syscalls/userfaultfd\
        tests/syscalls/membarrier\
        tests/syscalls/mlock2\
        tests/syscalls/copy_file_range\
        tests/syscalls/preadv2\
        tests/syscalls/pwritev2\
        tests/syscalls/pkey_mprotect\
        tests/syscalls/pkey_alloc\
        tests/syscalls/pkey_free\
        tests/syscalls/statx\
        tests/syscalls/rseq\
        tests/syscalls/io_pgetevents_time32\
        tests/syscalls/migrate_pages\
        tests/syscalls/kexec_file_load\
        tests/syscalls/clock_gettime\
        tests/syscalls/clock_settime\
        tests/syscalls/clock_adjtime\
        tests/syscalls/clock_getres\
        tests/syscalls/clock_nanosleep\
        tests/syscalls/timer_gettime\
        tests/syscalls/timer_settime\
        tests/syscalls/timerfd_gettime\
        tests/syscalls/timerfd_settime\
        tests/syscalls/utimensat\
        tests/syscalls/pselect6\
        tests/syscalls/ppoll\
        tests/syscalls/io_pgetevents\
        tests/syscalls/recvmmsg\
        tests/syscalls/mq_timedsend\
        tests/syscalls/mq_timedreceive\
        tests/syscalls/semtimedop\
        tests/syscalls/rt_sigtimedwait\
        tests/syscalls/futex\
        tests/syscalls/sched_rr_get_interval\
        tests/syscalls/pidfd_send_signal\
        tests/syscalls/io_uring_setup\
        tests/syscalls/io_uring_enter\
        tests/syscalls/io_uring_register\
        tests/syscalls/open_tree\
        tests/syscalls/move_mount\
        tests/syscalls/fsopen\
        tests/syscalls/fsconfig\
        tests/syscalls/fsmount\
        tests/syscalls/fspick\
        tests/syscalls/pidfd_open\
        tests/syscalls/clone3\
        tests/syscalls/close_range\
        tests/syscalls/openat2\
        tests/syscalls/pidfd_getfd\
        tests/syscalls/faccessat2\
        tests/syscalls/process_madvise\
        tests/syscalls/epoll_pwait2\
        tests/syscalls/mount_setattr\
        tests/syscalls/landlock_create_ruleset\
        tests/syscalls/landlock_add_rule\
        tests/syscalls/landlock_restrict_self\
        tests/syscalls/breakpoint\
        tests/syscalls/cacheflush\
        tests/syscalls/usr26\
        tests/syscalls/usr32\
        tests/syscalls/set_tls\
        tests/syscalls/get_tls
