csrc = \
       src/error.c\
       src/read.c\
       src/write.c\
       src/open.c\
       src/close.c\
       src/newstat.c\
       src/newfstat.c\
       src/newlstat.c\
       src/poll.c\
       src/lseek.c\
       src/mmap.c\
       src/mprotect.c\
       src/munmap.c\
       src/brk.c\
       src/rt_sigaction.c\
       src/rt_sigprocmask.c\
       src/ioctl.c\
       src/pread64.c\
       src/pwrite64.c\
       src/readv.c\
       src/writev.c\
       src/access.c\
       src/pipe.c\
       src/select.c\
       src/sched_yield.c\
       src/mremap.c\
       src/msync.c\
       src/mincore.c\
       src/madvise.c\
       src/shmget.c\
       src/shmat.c\
       src/shmctl.c\
       src/dup.c\
       src/dup2.c\
       src/pause.c\
       src/nanosleep.c\
       src/getitimer.c\
       src/alarm.c\
       src/setitimer.c\
       src/getpid.c\
       src/sendfile64.c\
       src/socket.c\
       src/connect.c\
       src/accept.c\
       src/sendto.c\
       src/recvfrom.c\
       src/sendmsg.c\
       src/recvmsg.c\
       src/shutdown.c\
       src/bind.c\
       src/listen.c\
       src/getsockname.c\
       src/getpeername.c\
       src/socketpair.c\
       src/setsockopt.c\
       src/getsockopt.c\
       src/clone.c\
       src/fork.c\
       src/vfork.c\
       src/execve.c\
       src/wait4.c\
       src/kill.c\
       src/newuname.c\
       src/semget.c\
       src/semop.c\
       src/semctl.c\
       src/shmdt.c\
       src/msgget.c\
       src/msgsnd.c\
       src/msgrcv.c\
       src/msgctl.c\
       src/fcntl.c\
       src/flock.c\
       src/fsync.c\
       src/fdatasync.c\
       src/truncate.c\
       src/ftruncate.c\
       src/getdents.c\
       src/getcwd.c\
       src/chdir.c\
       src/fchdir.c\
       src/rename.c\
       src/mkdir.c\
       src/rmdir.c\
       src/creat.c\
       src/link.c\
       src/unlink.c\
       src/symlink.c\
       src/readlink.c\
       src/chmod.c\
       src/fchmod.c\
       src/chown.c\
       src/fchown.c\
       src/lchown.c\
       src/umask.c\
       src/gettimeofday.c\
       src/getrlimit.c\
       src/getrusage.c\
       src/sysinfo.c\
       src/times.c\
       src/ptrace.c\
       src/getuid.c\
       src/syslog.c\
       src/getgid.c\
       src/setuid.c\
       src/setgid.c\
       src/geteuid.c\
       src/getegid.c\
       src/setpgid.c\
       src/getppid.c\
       src/getpgrp.c\
       src/setsid.c\
       src/setreuid.c\
       src/setregid.c\
       src/getgroups.c\
       src/setgroups.c\
       src/setresuid.c\
       src/getresuid.c\
       src/setresgid.c\
       src/getresgid.c\
       src/getpgid.c\
       src/setfsuid.c\
       src/setfsgid.c\
       src/getsid.c\
       src/capget.c\
       src/capset.c\
       src/rt_sigpending.c\
       src/rt_sigtimedwait.c\
       src/rt_sigqueueinfo.c\
       src/rt_sigsuspend.c\
       src/sigaltstack.c\
       src/utime.c\
       src/mknod.c\
       src/personality.c\
       src/ustat.c\
       src/statfs.c\
       src/fstatfs.c\
       src/sysfs.c\
       src/getpriority.c\
       src/setpriority.c\
       src/sched_setparam.c\
       src/sched_getparam.c\
       src/sched_setscheduler.c\
       src/sched_getscheduler.c\
       src/sched_get_priority_max.c\
       src/sched_get_priority_min.c\
       src/sched_rr_get_interval.c\
       src/mlock.c\
       src/munlock.c\
       src/mlockall.c\
       src/munlockall.c\
       src/vhangup.c\
       src/modify_ldt.c\
       src/pivot_root.c\
       src/sysctl.c\
       src/prctl.c\
       src/arch_prctl.c\
       src/adjtimex.c\
       src/setrlimit.c\
       src/chroot.c\
       src/sync.c\
       src/acct.c\
       src/settimeofday.c\
       src/mount.c\
       src/umount.c\
       src/swapon.c\
       src/swapoff.c\
       src/reboot.c\
       src/sethostname.c\
       src/setdomainname.c\
       src/iopl.c\
       src/ioperm.c\
       src/init_module.c\
       src/delete_module.c\
       src/quotactl.c\
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
       src/time.c\
       src/futex.c\
       src/sched_setaffinity.c\
       src/sched_getaffinity.c\
       src/io_setup.c\
       src/io_destroy.c\
       src/io_getevents.c\
       src/io_submit.c\
       src/io_cancel.c\
       src/lookup_dcookie.c\
       src/epoll_create.c\
       src/remap_file_pages.c\
       src/getdents64.c\
       src/set_tid_address.c\
       src/semtimedop.c\
       src/fadvise64.c\
       src/timer_create.c\
       src/timer_settime.c\
       src/timer_gettime.c\
       src/timer_getoverrun.c\
       src/timer_delete.c\
       src/clock_settime.c\
       src/clock_gettime.c\
       src/clock_getres.c\
       src/clock_nanosleep.c\
       src/epoll_wait.c\
       src/epoll_ctl.c\
       src/tgkill.c\
       src/utimes.c\
       src/mbind.c\
       src/set_mempolicy.c\
       src/get_mempolicy.c\
       src/mq_open.c\
       src/mq_unlink.c\
       src/mq_timedsend.c\
       src/mq_timedreceive.c\
       src/mq_notify.c\
       src/mq_getsetattr.c\
       src/kexec_load.c\
       src/waitid.c\
       src/add_key.c\
       src/request_key.c\
       src/keyctl.c\
       src/ioprio_set.c\
       src/ioprio_get.c\
       src/inotify_init.c\
       src/inotify_add_watch.c\
       src/inotify_rm_watch.c\
       src/migrate_pages.c\
       src/openat.c\
       src/mkdirat.c\
       src/mknodat.c\
       src/fchownat.c\
       src/futimesat.c\
       src/newfstatat.c\
       src/unlinkat.c\
       src/renameat.c\
       src/linkat.c\
       src/symlinkat.c\
       src/readlinkat.c\
       src/fchmodat.c\
       src/faccessat.c\
       src/pselect6.c\
       src/ppoll.c\
       src/unshare.c\
       src/set_robust_list.c\
       src/get_robust_list.c\
       src/splice.c\
       src/tee.c\
       src/sync_file_range.c\
       src/vmsplice.c\
       src/move_pages.c\
       src/utimensat.c\
       src/epoll_pwait.c\
       src/signalfd.c\
       src/timerfd_create.c\
       src/eventfd.c\
       src/fallocate.c\
       src/timerfd_settime.c\
       src/timerfd_gettime.c\
       src/accept4.c\
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
       src/recvmmsg.c\
       src/fanotify_init.c\
       src/fanotify_mark.c\
       src/prlimit64.c\
       src/name_to_handle_at.c\
       src/open_by_handle_at.c\
       src/clock_adjtime.c\
       src/syncfs.c\
       src/sendmmsg.c\
       src/setns.c\
       src/getcpu.c\
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
       src/kexec_file_load.c\
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
       src/io_pgetevents.c\
       src/rseq.c\
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
       src/openat2.c\
       src/pidfd_getfd.c\
       src/faccessat2.c

tests = \
        tests/syscalls/read\
        tests/syscalls/write\
        tests/syscalls/open\
        tests/syscalls/close\
        tests/syscalls/newstat\
        tests/syscalls/newfstat\
        tests/syscalls/newlstat\
        tests/syscalls/poll\
        tests/syscalls/lseek\
        tests/syscalls/mmap\
        tests/syscalls/mprotect\
        tests/syscalls/munmap\
        tests/syscalls/brk\
        tests/syscalls/rt_sigaction\
        tests/syscalls/rt_sigprocmask\
        tests/syscalls/ioctl\
        tests/syscalls/pread64\
        tests/syscalls/pwrite64\
        tests/syscalls/readv\
        tests/syscalls/writev\
        tests/syscalls/access\
        tests/syscalls/pipe\
        tests/syscalls/select\
        tests/syscalls/sched_yield\
        tests/syscalls/mremap\
        tests/syscalls/msync\
        tests/syscalls/mincore\
        tests/syscalls/madvise\
        tests/syscalls/shmget\
        tests/syscalls/shmat\
        tests/syscalls/shmctl\
        tests/syscalls/dup\
        tests/syscalls/dup2\
        tests/syscalls/pause\
        tests/syscalls/nanosleep\
        tests/syscalls/getitimer\
        tests/syscalls/alarm\
        tests/syscalls/setitimer\
        tests/syscalls/getpid\
        tests/syscalls/sendfile64\
        tests/syscalls/socket\
        tests/syscalls/connect\
        tests/syscalls/accept\
        tests/syscalls/sendto\
        tests/syscalls/recvfrom\
        tests/syscalls/sendmsg\
        tests/syscalls/recvmsg\
        tests/syscalls/shutdown\
        tests/syscalls/bind\
        tests/syscalls/listen\
        tests/syscalls/getsockname\
        tests/syscalls/getpeername\
        tests/syscalls/socketpair\
        tests/syscalls/setsockopt\
        tests/syscalls/getsockopt\
        tests/syscalls/clone\
        tests/syscalls/fork\
        tests/syscalls/vfork\
        tests/syscalls/execve\
        tests/syscalls/wait4\
        tests/syscalls/kill\
        tests/syscalls/newuname\
        tests/syscalls/semget\
        tests/syscalls/semop\
        tests/syscalls/semctl\
        tests/syscalls/shmdt\
        tests/syscalls/msgget\
        tests/syscalls/msgsnd\
        tests/syscalls/msgrcv\
        tests/syscalls/msgctl\
        tests/syscalls/fcntl\
        tests/syscalls/flock\
        tests/syscalls/fsync\
        tests/syscalls/fdatasync\
        tests/syscalls/truncate\
        tests/syscalls/ftruncate\
        tests/syscalls/getdents\
        tests/syscalls/getcwd\
        tests/syscalls/chdir\
        tests/syscalls/fchdir\
        tests/syscalls/rename\
        tests/syscalls/mkdir\
        tests/syscalls/rmdir\
        tests/syscalls/creat\
        tests/syscalls/link\
        tests/syscalls/unlink\
        tests/syscalls/symlink\
        tests/syscalls/readlink\
        tests/syscalls/chmod\
        tests/syscalls/fchmod\
        tests/syscalls/chown\
        tests/syscalls/fchown\
        tests/syscalls/lchown\
        tests/syscalls/umask\
        tests/syscalls/gettimeofday\
        tests/syscalls/getrlimit\
        tests/syscalls/getrusage\
        tests/syscalls/sysinfo\
        tests/syscalls/times\
        tests/syscalls/ptrace\
        tests/syscalls/getuid\
        tests/syscalls/syslog\
        tests/syscalls/getgid\
        tests/syscalls/setuid\
        tests/syscalls/setgid\
        tests/syscalls/geteuid\
        tests/syscalls/getegid\
        tests/syscalls/setpgid\
        tests/syscalls/getppid\
        tests/syscalls/getpgrp\
        tests/syscalls/setsid\
        tests/syscalls/setreuid\
        tests/syscalls/setregid\
        tests/syscalls/getgroups\
        tests/syscalls/setgroups\
        tests/syscalls/setresuid\
        tests/syscalls/getresuid\
        tests/syscalls/setresgid\
        tests/syscalls/getresgid\
        tests/syscalls/getpgid\
        tests/syscalls/setfsuid\
        tests/syscalls/setfsgid\
        tests/syscalls/getsid\
        tests/syscalls/capget\
        tests/syscalls/capset\
        tests/syscalls/rt_sigpending\
        tests/syscalls/rt_sigtimedwait\
        tests/syscalls/rt_sigqueueinfo\
        tests/syscalls/rt_sigsuspend\
        tests/syscalls/sigaltstack\
        tests/syscalls/utime\
        tests/syscalls/mknod\
        tests/syscalls/personality\
        tests/syscalls/ustat\
        tests/syscalls/statfs\
        tests/syscalls/fstatfs\
        tests/syscalls/sysfs\
        tests/syscalls/getpriority\
        tests/syscalls/setpriority\
        tests/syscalls/sched_setparam\
        tests/syscalls/sched_getparam\
        tests/syscalls/sched_setscheduler\
        tests/syscalls/sched_getscheduler\
        tests/syscalls/sched_get_priority_max\
        tests/syscalls/sched_get_priority_min\
        tests/syscalls/sched_rr_get_interval\
        tests/syscalls/mlock\
        tests/syscalls/munlock\
        tests/syscalls/mlockall\
        tests/syscalls/munlockall\
        tests/syscalls/vhangup\
        tests/syscalls/modify_ldt\
        tests/syscalls/pivot_root\
        tests/syscalls/sysctl\
        tests/syscalls/prctl\
        tests/syscalls/arch_prctl\
        tests/syscalls/adjtimex\
        tests/syscalls/setrlimit\
        tests/syscalls/chroot\
        tests/syscalls/sync\
        tests/syscalls/acct\
        tests/syscalls/settimeofday\
        tests/syscalls/mount\
        tests/syscalls/umount\
        tests/syscalls/swapon\
        tests/syscalls/swapoff\
        tests/syscalls/reboot\
        tests/syscalls/sethostname\
        tests/syscalls/setdomainname\
        tests/syscalls/iopl\
        tests/syscalls/ioperm\
        tests/syscalls/init_module\
        tests/syscalls/delete_module\
        tests/syscalls/quotactl\
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
        tests/syscalls/time\
        tests/syscalls/futex\
        tests/syscalls/sched_setaffinity\
        tests/syscalls/sched_getaffinity\
        tests/syscalls/io_setup\
        tests/syscalls/io_destroy\
        tests/syscalls/io_getevents\
        tests/syscalls/io_submit\
        tests/syscalls/io_cancel\
        tests/syscalls/lookup_dcookie\
        tests/syscalls/epoll_create\
        tests/syscalls/remap_file_pages\
        tests/syscalls/getdents64\
        tests/syscalls/set_tid_address\
        tests/syscalls/semtimedop\
        tests/syscalls/fadvise64\
        tests/syscalls/timer_create\
        tests/syscalls/timer_settime\
        tests/syscalls/timer_gettime\
        tests/syscalls/timer_getoverrun\
        tests/syscalls/timer_delete\
        tests/syscalls/clock_settime\
        tests/syscalls/clock_gettime\
        tests/syscalls/clock_getres\
        tests/syscalls/clock_nanosleep\
        tests/syscalls/epoll_wait\
        tests/syscalls/epoll_ctl\
        tests/syscalls/tgkill\
        tests/syscalls/utimes\
        tests/syscalls/mbind\
        tests/syscalls/set_mempolicy\
        tests/syscalls/get_mempolicy\
        tests/syscalls/mq_open\
        tests/syscalls/mq_unlink\
        tests/syscalls/mq_timedsend\
        tests/syscalls/mq_timedreceive\
        tests/syscalls/mq_notify\
        tests/syscalls/mq_getsetattr\
        tests/syscalls/kexec_load\
        tests/syscalls/waitid\
        tests/syscalls/add_key\
        tests/syscalls/request_key\
        tests/syscalls/keyctl\
        tests/syscalls/ioprio_set\
        tests/syscalls/ioprio_get\
        tests/syscalls/inotify_init\
        tests/syscalls/inotify_add_watch\
        tests/syscalls/inotify_rm_watch\
        tests/syscalls/migrate_pages\
        tests/syscalls/openat\
        tests/syscalls/mkdirat\
        tests/syscalls/mknodat\
        tests/syscalls/fchownat\
        tests/syscalls/futimesat\
        tests/syscalls/newfstatat\
        tests/syscalls/unlinkat\
        tests/syscalls/renameat\
        tests/syscalls/linkat\
        tests/syscalls/symlinkat\
        tests/syscalls/readlinkat\
        tests/syscalls/fchmodat\
        tests/syscalls/faccessat\
        tests/syscalls/pselect6\
        tests/syscalls/ppoll\
        tests/syscalls/unshare\
        tests/syscalls/set_robust_list\
        tests/syscalls/get_robust_list\
        tests/syscalls/splice\
        tests/syscalls/tee\
        tests/syscalls/sync_file_range\
        tests/syscalls/vmsplice\
        tests/syscalls/move_pages\
        tests/syscalls/utimensat\
        tests/syscalls/epoll_pwait\
        tests/syscalls/signalfd\
        tests/syscalls/timerfd_create\
        tests/syscalls/eventfd\
        tests/syscalls/fallocate\
        tests/syscalls/timerfd_settime\
        tests/syscalls/timerfd_gettime\
        tests/syscalls/accept4\
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
        tests/syscalls/recvmmsg\
        tests/syscalls/fanotify_init\
        tests/syscalls/fanotify_mark\
        tests/syscalls/prlimit64\
        tests/syscalls/name_to_handle_at\
        tests/syscalls/open_by_handle_at\
        tests/syscalls/clock_adjtime\
        tests/syscalls/syncfs\
        tests/syscalls/sendmmsg\
        tests/syscalls/setns\
        tests/syscalls/getcpu\
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
        tests/syscalls/kexec_file_load\
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
        tests/syscalls/io_pgetevents\
        tests/syscalls/rseq\
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
        tests/syscalls/openat2\
        tests/syscalls/pidfd_getfd\
        tests/syscalls/faccessat2
