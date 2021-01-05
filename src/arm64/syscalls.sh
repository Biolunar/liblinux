SYSCALLS="io_setup\
          io_destroy\
          io_submit\
          io_cancel\
          io_getevents\
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
          getcwd\
          lookup_dcookie\
          eventfd2\
          epoll_create1\
          epoll_ctl\
          epoll_pwait\
          dup\
          dup3\
          fcntl\
          inotify_init1\
          inotify_add_watch\
          inotify_rm_watch\
          ioctl\
          ioprio_set\
          ioprio_get\
          flock\
          mknodat\
          mkdirat\
          unlinkat\
          symlinkat\
          linkat\
          renameat\
          umount\
          mount\
          pivot_root\
          statfs\
          fstatfs\
          truncate\
          ftruncate\
          fallocate\
          faccessat\
          chdir\
          fchdir\
          chroot\
          fchmod\
          fchmodat\
          fchownat\
          fchown\
          openat\
          close\
          vhangup\
          pipe2\
          quotactl\
          getdents64\
          lseek\
          read\
          write\
          readv\
          writev\
          pread64\
          pwrite64\
          preadv\
          pwritev\
          sendfile64\
          pselect6\
          ppoll\
          signalfd4\
          vmsplice\
          splice\
          tee\
          readlinkat\
          newfstatat\
          newfstat\
          sync\
          fsync\
          fdatasync\
          sync_file_range\
          timerfd_create\
          timerfd_settime\
          timerfd_gettime\
          utimensat\
          acct\
          capget\
          capset\
          personality\
          waitid\
          set_tid_address\
          unshare\
          futex\
          set_robust_list\
          get_robust_list\
          nanosleep\
          getitimer\
          setitimer\
          kexec_load\
          init_module\
          delete_module\
          timer_create\
          timer_gettime\
          timer_getoverrun\
          timer_settime\
          timer_delete\
          clock_settime\
          clock_gettime\
          clock_getres\
          clock_nanosleep\
          syslog\
          ptrace\
          sched_setparam\
          sched_setscheduler\
          sched_getscheduler\
          sched_getparam\
          sched_setaffinity\
          sched_getaffinity\
          sched_yield\
          sched_get_priority_max\
          sched_get_priority_min\
          sched_rr_get_interval\
          kill\
          tkill\
          tgkill\
          sigaltstack\
          rt_sigsuspend\
          rt_sigaction\
          rt_sigprocmask\
          rt_sigpending\
          rt_sigtimedwait\
          rt_sigqueueinfo\
          setpriority\
          getpriority\
          reboot\
          setregid\
          setgid\
          setreuid\
          setuid\
          setresuid\
          getresuid\
          setresgid\
          getresgid\
          setfsuid\
          setfsgid\
          times\
          setpgid\
          getpgid\
          getsid\
          setsid\
          getgroups\
          setgroups\
          newuname\
          sethostname\
          setdomainname\
          getrlimit\
          setrlimit\
          getrusage\
          umask\
          prctl\
          getcpu\
          gettimeofday\
          settimeofday\
          adjtimex\
          getpid\
          getppid\
          getuid\
          geteuid\
          getgid\
          getegid\
          gettid\
          sysinfo\
          mq_open\
          mq_unlink\
          mq_timedsend\
          mq_timedreceive\
          mq_notify\
          mq_getsetattr\
          msgget\
          msgctl\
          msgrcv\
          msgsnd\
          semget\
          semctl\
          semtimedop\
          semop\
          shmget\
          shmctl\
          shmat\
          shmdt\
          socket\
          socketpair\
          bind\
          listen\
          accept\
          connect\
          getsockname\
          getpeername\
          sendto\
          recvfrom\
          setsockopt\
          getsockopt\
          shutdown\
          sendmsg\
          recvmsg\
          readahead\
          brk\
          munmap\
          mremap\
          add_key\
          request_key\
          keyctl\
          clone\
          execve\
          mmap\
          fadvise64_64\
          swapon\
          swapoff\
          mprotect\
          msync\
          mlock\
          munlock\
          mlockall\
          munlockall\
          mincore\
          madvise\
          remap_file_pages\
          mbind\
          get_mempolicy\
          set_mempolicy\
          migrate_pages\
          move_pages\
          rt_tgsigqueueinfo\
          perf_event_open\
          accept4\
          recvmmsg\
          wait4\
          prlimit64\
          fanotify_init\
          fanotify_mark\
          name_to_handle_at\
          open_by_handle_at\
          clock_adjtime\
          syncfs\
          setns\
          sendmmsg\
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
          kexec_file_load\
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
          process_madvise"
