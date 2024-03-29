SYSCALLS="fork\
          read\
          write\
          open\
          close\
          creat\
          link\
          unlink\
          execve\
          chdir\
          mknod\
          chmod\
          lchown16\
          lseek\
          getpid\
          mount\
          setuid16\
          getuid16\
          ptrace\
          pause\
          access\
          nice\
          sync\
          kill\
          rename\
          mkdir\
          rmdir\
          dup\
          pipe\
          times\
          brk\
          setgid16\
          getgid16\
          geteuid16\
          getegid16\
          acct\
          umount\
          ioctl\
          fcntl\
          setpgid\
          umask\
          chroot\
          ustat\
          dup2\
          getppid\
          getpgrp\
          setsid\
          sigaction\
          setreuid16\
          setregid16\
          sigsuspend\
          sigpending\
          sethostname\
          setrlimit\
          getrusage\
          gettimeofday\
          settimeofday\
          getgroups16\
          setgroups16\
          symlink\
          readlink\
          uselib\
          swapon\
          reboot\
          munmap\
          truncate\
          ftruncate\
          fchmod\
          fchown16\
          getpriority\
          setpriority\
          statfs\
          fstatfs\
          syslog\
          setitimer\
          getitimer\
          newstat\
          newlstat\
          newfstat\
          vhangup\
          wait4\
          swapoff\
          sysinfo\
          fsync\
          clone\
          setdomainname\
          newuname\
          adjtimex_time32\
          mprotect\
          sigprocmask\
          init_module\
          delete_module\
          quotactl\
          getpgid\
          fchdir\
          bdflush\
          sysfs\
          personality\
          setfsuid16\
          setfsgid16\
          llseek\
          getdents\
          select\
          flock\
          msync\
          readv\
          writev\
          getsid\
          fdatasync\
          mlock\
          munlock\
          mlockall\
          munlockall\
          sched_setparam\
          sched_getparam\
          sched_setscheduler\
          sched_getscheduler\
          sched_yield\
          sched_get_priority_max\
          sched_get_priority_min\
          sched_rr_get_interval_time32\
          nanosleep_time32\
          mremap\
          setresuid16\
          getresuid16\
          poll\
          setresgid16\
          getresgid16\
          prctl\
          rt_sigaction\
          rt_sigprocmask\
          rt_sigpending\
          rt_sigtimedwait_time32\
          rt_sigqueueinfo\
          rt_sigsuspend\
          pread64\
          pwrite64\
          chown16\
          getcwd\
          capget\
          capset\
          sigaltstack\
          sendfile\
          vfork\
          getrlimit\
          mmap_pgoff\
          truncate64\
          ftruncate64\
          stat64\
          lstat64\
          fstat64\
          lchown\
          getuid\
          getgid\
          geteuid\
          getegid\
          setreuid\
          setregid\
          getgroups\
          setgroups\
          fchown\
          setresuid\
          getresuid\
          setresgid\
          getresgid\
          chown\
          setuid\
          setgid\
          setfsuid\
          setfsgid\
          getdents64\
          pivot_root\
          mincore\
          madvise\
          fcntl64\
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
          sendfile64\
          futex_time32\
          sched_setaffinity\
          sched_getaffinity\
          io_setup\
          io_destroy\
          io_getevents_time32\
          io_submit\
          io_cancel\
          lookup_dcookie\
          epoll_create\
          epoll_ctl\
          epoll_wait\
          remap_file_pages\
          set_tid_address\
          timer_create\
          timer_settime32\
          timer_gettime32\
          timer_getoverrun\
          timer_delete\
          clock_settime32\
          clock_gettime32\
          clock_getres_time32\
          clock_nanosleep_time32\
          statfs64\
          fstatfs64\
          tgkill\
          utimes_time32\
          fadvise64_64\
          pciconfig_iobase\
          pciconfig_read\
          pciconfig_write\
          mq_open\
          mq_unlink\
          mq_timedsend_time32\
          mq_timedreceive_time32\
          mq_notify\
          mq_getsetattr\
          waitid\
          socket\
          bind\
          connect\
          listen\
          accept\
          getsockname\
          getpeername\
          socketpair\
          send\
          sendto\
          recv\
          recvfrom\
          shutdown\
          setsockopt\
          getsockopt\
          sendmsg\
          recvmsg\
          semop\
          semget\
          old_semctl\
          msgsnd\
          msgrcv\
          msgget\
          old_msgctl\
          shmat\
          shmdt\
          shmget\
          old_shmctl\
          add_key\
          request_key\
          keyctl\
          semtimedop_time32\
          ioprio_set\
          ioprio_get\
          inotify_init\
          inotify_add_watch\
          inotify_rm_watch\
          mbind\
          get_mempolicy\
          set_mempolicy\
          openat\
          mkdirat\
          mknodat\
          fchownat\
          futimesat_time32\
          fstatat64\
          unlinkat\
          renameat\
          linkat\
          symlinkat\
          readlinkat\
          fchmodat\
          faccessat\
          pselect6_time32\
          ppoll_time32\
          unshare\
          set_robust_list\
          get_robust_list\
          splice\
          sync_file_range\
          tee\
          vmsplice\
          move_pages\
          getcpu\
          epoll_pwait\
          kexec_load\
          utimensat_time32\
          signalfd\
          timerfd_create\
          eventfd\
          fallocate\
          timerfd_settime32\
          timerfd_gettime32\
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
          recvmmsg_time32\
          accept4\
          fanotify_init\
          fanotify_mark\
          prlimit64\
          name_to_handle_at\
          open_by_handle_at\
          clock_adjtime32\
          syncfs\
          sendmmsg\
          setns\
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
          rseq\
          io_pgetevents_time32\
          migrate_pages\
          kexec_file_load\
          clock_gettime\
          clock_settime\
          clock_adjtime\
          clock_getres\
          clock_nanosleep\
          timer_gettime\
          timer_settime\
          timerfd_gettime\
          timerfd_settime\
          utimensat\
          pselect6\
          ppoll\
          io_pgetevents\
          recvmmsg\
          mq_timedsend\
          mq_timedreceive\
          semtimedop\
          rt_sigtimedwait\
          futex\
          sched_rr_get_interval\
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
          process_mrelease\
          breakpoint\
          cacheflush\
          usr26\
          usr32\
          set_tls\
          get_tls"
