csrc = \
       src/error.c\
       src/io_setup.c\
       src/io_destroy.c\
       src/io_submit.c\
       src/io_cancel.c\
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
       src/getcwd.c\
       src/lookup_dcookie.c\
       src/eventfd2.c\
       src/epoll_create1.c\
       src/epoll_ctl.c\
       src/epoll_pwait.c\
       src/dup.c\
       src/dup3.c\
       src/fcntl64.c\
       src/inotify_init1.c\
       src/inotify_add_watch.c\
       src/inotify_rm_watch.c\
       src/ioctl.c\
       src/ioprio_set.c\
       src/ioprio_get.c\
       src/flock.c\
       src/mknodat.c\
       src/mkdirat.c\
       src/unlinkat.c\
       src/symlinkat.c\
       src/linkat.c\
       src/umount.c\
       src/mount.c\
       src/pivot_root.c\
       src/statfs64.c\
       src/fstatfs64.c\
       src/truncate64.c\
       src/ftruncate64.c\
       src/fallocate.c\
       src/faccessat.c\
       src/chdir.c\
       src/fchdir.c\
       src/chroot.c\
       src/fchmod.c\
       src/fchmodat.c\
       src/fchownat.c\
       src/fchown.c\
       src/openat.c\
       src/close.c\
       src/vhangup.c\
       src/pipe2.c\
       src/quotactl.c\
       src/getdents64.c\
       src/llseek.c\
       src/read.c\
       src/write.c\
       src/readv.c\
       src/writev.c\
       src/pread64.c\
       src/pwrite64.c\
       src/preadv.c\
       src/pwritev.c\
       src/sendfile64.c\
       src/signalfd4.c\
       src/vmsplice.c\
       src/splice.c\
       src/tee.c\
       src/readlinkat.c\
       src/fstatat64.c\
       src/fstat64.c\
       src/sync.c\
       src/fsync.c\
       src/fdatasync.c\
       src/sync_file_range.c\
       src/timerfd_create.c\
       src/acct.c\
       src/capget.c\
       src/capset.c\
       src/personality.c\
       src/waitid.c\
       src/set_tid_address.c\
       src/unshare.c\
       src/set_robust_list.c\
       src/get_robust_list.c\
       src/getitimer.c\
       src/setitimer.c\
       src/kexec_load.c\
       src/init_module.c\
       src/delete_module.c\
       src/timer_create.c\
       src/timer_getoverrun.c\
       src/timer_delete.c\
       src/syslog.c\
       src/ptrace.c\
       src/sched_setparam.c\
       src/sched_setscheduler.c\
       src/sched_getscheduler.c\
       src/sched_getparam.c\
       src/sched_setaffinity.c\
       src/sched_getaffinity.c\
       src/sched_yield.c\
       src/sched_get_priority_max.c\
       src/sched_get_priority_min.c\
       src/kill.c\
       src/tkill.c\
       src/tgkill.c\
       src/sigaltstack.c\
       src/rt_sigsuspend.c\
       src/rt_sigaction.c\
       src/rt_sigprocmask.c\
       src/rt_sigpending.c\
       src/rt_sigqueueinfo.c\
       src/setpriority.c\
       src/getpriority.c\
       src/reboot.c\
       src/setregid.c\
       src/setgid.c\
       src/setreuid.c\
       src/setuid.c\
       src/setresuid.c\
       src/getresuid.c\
       src/setresgid.c\
       src/getresgid.c\
       src/setfsuid.c\
       src/setfsgid.c\
       src/times.c\
       src/setpgid.c\
       src/getpgid.c\
       src/getsid.c\
       src/setsid.c\
       src/getgroups.c\
       src/setgroups.c\
       src/newuname.c\
       src/sethostname.c\
       src/setdomainname.c\
       src/getrlimit.c\
       src/setrlimit.c\
       src/getrusage.c\
       src/umask.c\
       src/prctl.c\
       src/getcpu.c\
       src/getpid.c\
       src/getppid.c\
       src/getuid.c\
       src/geteuid.c\
       src/getgid.c\
       src/getegid.c\
       src/gettid.c\
       src/sysinfo.c\
       src/mq_open.c\
       src/mq_unlink.c\
       src/mq_notify.c\
       src/mq_getsetattr.c\
       src/msgget.c\
       src/msgctl.c\
       src/msgrcv.c\
       src/msgsnd.c\
       src/semget.c\
       src/semctl.c\
       src/semop.c\
       src/shmget.c\
       src/shmctl.c\
       src/shmat.c\
       src/shmdt.c\
       src/socket.c\
       src/socketpair.c\
       src/bind.c\
       src/listen.c\
       src/accept.c\
       src/connect.c\
       src/getsockname.c\
       src/getpeername.c\
       src/sendto.c\
       src/recvfrom.c\
       src/setsockopt.c\
       src/getsockopt.c\
       src/shutdown.c\
       src/sendmsg.c\
       src/recvmsg.c\
       src/readahead.c\
       src/brk.c\
       src/munmap.c\
       src/mremap.c\
       src/add_key.c\
       src/request_key.c\
       src/keyctl.c\
       src/clone.c\
       src/execve.c\
       src/mmap.c\
       src/fadvise64_64.c\
       src/swapon.c\
       src/swapoff.c\
       src/mprotect.c\
       src/msync.c\
       src/mlock.c\
       src/munlock.c\
       src/mlockall.c\
       src/munlockall.c\
       src/mincore.c\
       src/madvise.c\
       src/remap_file_pages.c\
       src/mbind.c\
       src/get_mempolicy.c\
       src/set_mempolicy.c\
       src/migrate_pages.c\
       src/move_pages.c\
       src/rt_tgsigqueueinfo.c\
       src/perf_event_open.c\
       src/accept4.c\
       src/prlimit64.c\
       src/fanotify_init.c\
       src/fanotify_mark.c\
       src/name_to_handle_at.c\
       src/open_by_handle_at.c\
       src/syncfs.c\
       src/setns.c\
       src/sendmmsg.c\
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
       src/quotactl_fd.c\
       src/landlock_create_ruleset.c\
       src/landlock_add_rule.c\
       src/landlock_restrict_self.c\
       src/memfd_secret.c\
       src/process_mrelease.c\
       src/riscv_flush_icache.c

tests = \
        tests/syscalls/io_setup\
        tests/syscalls/io_destroy\
        tests/syscalls/io_submit\
        tests/syscalls/io_cancel\
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
        tests/syscalls/getcwd\
        tests/syscalls/lookup_dcookie\
        tests/syscalls/eventfd2\
        tests/syscalls/epoll_create1\
        tests/syscalls/epoll_ctl\
        tests/syscalls/epoll_pwait\
        tests/syscalls/dup\
        tests/syscalls/dup3\
        tests/syscalls/fcntl64\
        tests/syscalls/inotify_init1\
        tests/syscalls/inotify_add_watch\
        tests/syscalls/inotify_rm_watch\
        tests/syscalls/ioctl\
        tests/syscalls/ioprio_set\
        tests/syscalls/ioprio_get\
        tests/syscalls/flock\
        tests/syscalls/mknodat\
        tests/syscalls/mkdirat\
        tests/syscalls/unlinkat\
        tests/syscalls/symlinkat\
        tests/syscalls/linkat\
        tests/syscalls/umount\
        tests/syscalls/mount\
        tests/syscalls/pivot_root\
        tests/syscalls/statfs64\
        tests/syscalls/fstatfs64\
        tests/syscalls/truncate64\
        tests/syscalls/ftruncate64\
        tests/syscalls/fallocate\
        tests/syscalls/faccessat\
        tests/syscalls/chdir\
        tests/syscalls/fchdir\
        tests/syscalls/chroot\
        tests/syscalls/fchmod\
        tests/syscalls/fchmodat\
        tests/syscalls/fchownat\
        tests/syscalls/fchown\
        tests/syscalls/openat\
        tests/syscalls/close\
        tests/syscalls/vhangup\
        tests/syscalls/pipe2\
        tests/syscalls/quotactl\
        tests/syscalls/getdents64\
        tests/syscalls/llseek\
        tests/syscalls/read\
        tests/syscalls/write\
        tests/syscalls/readv\
        tests/syscalls/writev\
        tests/syscalls/pread64\
        tests/syscalls/pwrite64\
        tests/syscalls/preadv\
        tests/syscalls/pwritev\
        tests/syscalls/sendfile64\
        tests/syscalls/signalfd4\
        tests/syscalls/vmsplice\
        tests/syscalls/splice\
        tests/syscalls/tee\
        tests/syscalls/readlinkat\
        tests/syscalls/fstatat64\
        tests/syscalls/fstat64\
        tests/syscalls/sync\
        tests/syscalls/fsync\
        tests/syscalls/fdatasync\
        tests/syscalls/sync_file_range\
        tests/syscalls/timerfd_create\
        tests/syscalls/acct\
        tests/syscalls/capget\
        tests/syscalls/capset\
        tests/syscalls/personality\
        tests/syscalls/waitid\
        tests/syscalls/set_tid_address\
        tests/syscalls/unshare\
        tests/syscalls/set_robust_list\
        tests/syscalls/get_robust_list\
        tests/syscalls/getitimer\
        tests/syscalls/setitimer\
        tests/syscalls/kexec_load\
        tests/syscalls/init_module\
        tests/syscalls/delete_module\
        tests/syscalls/timer_create\
        tests/syscalls/timer_getoverrun\
        tests/syscalls/timer_delete\
        tests/syscalls/syslog\
        tests/syscalls/ptrace\
        tests/syscalls/sched_setparam\
        tests/syscalls/sched_setscheduler\
        tests/syscalls/sched_getscheduler\
        tests/syscalls/sched_getparam\
        tests/syscalls/sched_setaffinity\
        tests/syscalls/sched_getaffinity\
        tests/syscalls/sched_yield\
        tests/syscalls/sched_get_priority_max\
        tests/syscalls/sched_get_priority_min\
        tests/syscalls/kill\
        tests/syscalls/tkill\
        tests/syscalls/tgkill\
        tests/syscalls/sigaltstack\
        tests/syscalls/rt_sigsuspend\
        tests/syscalls/rt_sigaction\
        tests/syscalls/rt_sigprocmask\
        tests/syscalls/rt_sigpending\
        tests/syscalls/rt_sigqueueinfo\
        tests/syscalls/setpriority\
        tests/syscalls/getpriority\
        tests/syscalls/reboot\
        tests/syscalls/setregid\
        tests/syscalls/setgid\
        tests/syscalls/setreuid\
        tests/syscalls/setuid\
        tests/syscalls/setresuid\
        tests/syscalls/getresuid\
        tests/syscalls/setresgid\
        tests/syscalls/getresgid\
        tests/syscalls/setfsuid\
        tests/syscalls/setfsgid\
        tests/syscalls/times\
        tests/syscalls/setpgid\
        tests/syscalls/getpgid\
        tests/syscalls/getsid\
        tests/syscalls/setsid\
        tests/syscalls/getgroups\
        tests/syscalls/setgroups\
        tests/syscalls/newuname\
        tests/syscalls/sethostname\
        tests/syscalls/setdomainname\
        tests/syscalls/getrlimit\
        tests/syscalls/setrlimit\
        tests/syscalls/getrusage\
        tests/syscalls/umask\
        tests/syscalls/prctl\
        tests/syscalls/getcpu\
        tests/syscalls/getpid\
        tests/syscalls/getppid\
        tests/syscalls/getuid\
        tests/syscalls/geteuid\
        tests/syscalls/getgid\
        tests/syscalls/getegid\
        tests/syscalls/gettid\
        tests/syscalls/sysinfo\
        tests/syscalls/mq_open\
        tests/syscalls/mq_unlink\
        tests/syscalls/mq_notify\
        tests/syscalls/mq_getsetattr\
        tests/syscalls/msgget\
        tests/syscalls/msgctl\
        tests/syscalls/msgrcv\
        tests/syscalls/msgsnd\
        tests/syscalls/semget\
        tests/syscalls/semctl\
        tests/syscalls/semop\
        tests/syscalls/shmget\
        tests/syscalls/shmctl\
        tests/syscalls/shmat\
        tests/syscalls/shmdt\
        tests/syscalls/socket\
        tests/syscalls/socketpair\
        tests/syscalls/bind\
        tests/syscalls/listen\
        tests/syscalls/accept\
        tests/syscalls/connect\
        tests/syscalls/getsockname\
        tests/syscalls/getpeername\
        tests/syscalls/sendto\
        tests/syscalls/recvfrom\
        tests/syscalls/setsockopt\
        tests/syscalls/getsockopt\
        tests/syscalls/shutdown\
        tests/syscalls/sendmsg\
        tests/syscalls/recvmsg\
        tests/syscalls/readahead\
        tests/syscalls/brk\
        tests/syscalls/munmap\
        tests/syscalls/mremap\
        tests/syscalls/add_key\
        tests/syscalls/request_key\
        tests/syscalls/keyctl\
        tests/syscalls/clone\
        tests/syscalls/execve\
        tests/syscalls/mmap\
        tests/syscalls/fadvise64_64\
        tests/syscalls/swapon\
        tests/syscalls/swapoff\
        tests/syscalls/mprotect\
        tests/syscalls/msync\
        tests/syscalls/mlock\
        tests/syscalls/munlock\
        tests/syscalls/mlockall\
        tests/syscalls/munlockall\
        tests/syscalls/mincore\
        tests/syscalls/madvise\
        tests/syscalls/remap_file_pages\
        tests/syscalls/mbind\
        tests/syscalls/get_mempolicy\
        tests/syscalls/set_mempolicy\
        tests/syscalls/migrate_pages\
        tests/syscalls/move_pages\
        tests/syscalls/rt_tgsigqueueinfo\
        tests/syscalls/perf_event_open\
        tests/syscalls/accept4\
        tests/syscalls/prlimit64\
        tests/syscalls/fanotify_init\
        tests/syscalls/fanotify_mark\
        tests/syscalls/name_to_handle_at\
        tests/syscalls/open_by_handle_at\
        tests/syscalls/syncfs\
        tests/syscalls/setns\
        tests/syscalls/sendmmsg\
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
        tests/syscalls/quotactl_fd\
        tests/syscalls/landlock_create_ruleset\
        tests/syscalls/landlock_add_rule\
        tests/syscalls/landlock_restrict_self\
        tests/syscalls/memfd_secret\
        tests/syscalls/process_mrelease\
        tests/syscalls/riscv_flush_icache
