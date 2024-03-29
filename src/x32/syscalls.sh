SYSCALLS="read\
          write\
          open\
          close\
          newstat\
          newfstat\
          newlstat\
          poll\
          lseek\
          mmap\
          mprotect\
          munmap\
          brk\
          rt_sigaction\
          rt_sigprocmask\
          ioctl\
          pread64\
          pwrite64\
          readv\
          writev\
          access\
          pipe\
          select\
          sched_yield\
          mremap\
          msync\
          mincore\
          madvise\
          shmget\
          shmat\
          shmctl\
          dup\
          dup2\
          pause\
          nanosleep\
          getitimer\
          alarm\
          setitimer\
          getpid\
          sendfile64\
          socket\
          connect\
          accept\
          sendto\
          recvfrom\
          sendmsg\
          recvmsg\
          shutdown\
          bind\
          listen\
          getsockname\
          getpeername\
          socketpair\
          setsockopt\
          getsockopt\
          clone\
          fork\
          vfork\
          execve\
          wait4\
          kill\
          newuname\
          semget\
          semop\
          semctl\
          shmdt\
          msgget\
          msgsnd\
          msgrcv\
          msgctl\
          fcntl\
          flock\
          fsync\
          fdatasync\
          truncate\
          ftruncate\
          getdents\
          getcwd\
          chdir\
          fchdir\
          rename\
          mkdir\
          rmdir\
          creat\
          link\
          unlink\
          symlink\
          readlink\
          chmod\
          fchmod\
          chown\
          fchown\
          lchown\
          umask\
          gettimeofday\
          getrlimit\
          getrusage\
          sysinfo\
          times\
          ptrace\
          getuid\
          syslog\
          getgid\
          setuid\
          setgid\
          geteuid\
          getegid\
          setpgid\
          getppid\
          getpgrp\
          setsid\
          setreuid\
          setregid\
          getgroups\
          setgroups\
          setresuid\
          getresuid\
          setresgid\
          getresgid\
          getpgid\
          setfsuid\
          setfsgid\
          getsid\
          capget\
          capset\
          rt_sigpending\
          rt_sigtimedwait\
          rt_sigqueueinfo\
          rt_sigsuspend\
          sigaltstack\
          utime\
          mknod\
          personality\
          ustat\
          statfs\
          fstatfs\
          sysfs\
          getpriority\
          setpriority\
          sched_setparam\
          sched_getparam\
          sched_setscheduler\
          sched_getscheduler\
          sched_get_priority_max\
          sched_get_priority_min\
          sched_rr_get_interval\
          mlock\
          munlock\
          mlockall\
          munlockall\
          vhangup\
          modify_ldt\
          pivot_root\
          prctl\
          arch_prctl\
          adjtimex\
          setrlimit\
          chroot\
          sync\
          acct\
          settimeofday\
          mount\
          umount\
          swapon\
          swapoff\
          reboot\
          sethostname\
          setdomainname\
          iopl\
          ioperm\
          init_module\
          delete_module\
          quotactl\
          gettid\
          readahead\
          setxattr\
          lsetxattr\
          fsetxattr\
          getxattr\
          lgetxattr\
          fgetxattr\
          listxattr\
          llistxattr\
          flistxattr\
          removexattr\
          lremovexattr\
          fremovexattr\
          tkill\
          time\
          futex\
          sched_setaffinity\
          sched_getaffinity\
          io_setup\
          io_destroy\
          io_getevents\
          io_submit\
          io_cancel\
          lookup_dcookie\
          epoll_create\
          remap_file_pages\
          getdents64\
          set_tid_address\
          semtimedop\
          fadvise64\
          timer_create\
          timer_settime\
          timer_gettime\
          timer_getoverrun\
          timer_delete\
          clock_settime\
          clock_gettime\
          clock_getres\
          clock_nanosleep\
          epoll_wait\
          epoll_ctl\
          tgkill\
          utimes\
          mbind\
          set_mempolicy\
          get_mempolicy\
          mq_open\
          mq_unlink\
          mq_timedsend\
          mq_timedreceive\
          mq_notify\
          mq_getsetattr\
          kexec_load\
          waitid\
          add_key\
          request_key\
          keyctl\
          ioprio_set\
          ioprio_get\
          inotify_init\
          inotify_add_watch\
          inotify_rm_watch\
          migrate_pages\
          openat\
          mkdirat\
          mknodat\
          fchownat\
          futimesat\
          newfstatat\
          unlinkat\
          renameat\
          linkat\
          symlinkat\
          readlinkat\
          fchmodat\
          faccessat\
          pselect6\
          ppoll\
          unshare\
          set_robust_list\
          get_robust_list\
          splice\
          tee\
          sync_file_range\
          vmsplice\
          move_pages\
          utimensat\
          epoll_pwait\
          signalfd\
          timerfd_create\
          eventfd\
          fallocate\
          timerfd_settime\
          timerfd_gettime\
          accept4\
          signalfd4\
          eventfd2\
          epoll_create1\
          dup3\
          pipe2\
          inotify_init1\
          preadv\
          pwritev\
          rt_tgsigqueueinfo\
          perf_event_open\
          recvmmsg\
          fanotify_init\
          fanotify_mark\
          prlimit64\
          name_to_handle_at\
          open_by_handle_at\
          clock_adjtime\
          syncfs\
          sendmmsg\
          setns\
          getcpu\
          process_vm_readv\
          process_vm_writev\
          kcmp\
          finit_module\
          sched_setattr\
          sched_getattr\
          renameat2\
          seccomp\
          getrandom\
          memfd_create\
          kexec_file_load\
          bpf\
          execveat\
          userfaultfd\
          membarrier\
          mlock2\
          copy_file_range\
          preadv2\
          pwritev2\
          pkey_mprotect\
          pkey_alloc\
          pkey_free\
          statx\
          io_pgetevents\
          rseq\
          pidfd_send_signal\
          io_uring_setup\
          io_uring_enter\
          io_uring_register\
          open_tree\
          move_mount\
          fsopen\
          fsconfig\
          fsmount\
          fspick\
          pidfd_open\
          clone3\
          close_range\
          openat2\
          pidfd_getfd\
          faccessat2\
          process_madvise\
          epoll_pwait2\
          mount_setattr\
          quotactl_fd\
          landlock_create_ruleset\
          landlock_add_rule\
          landlock_restrict_self\
          memfd_secret\
          process_mrelease"
