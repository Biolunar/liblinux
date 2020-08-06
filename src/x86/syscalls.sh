SYSCALLS="fork\
          read\
          write\
          open\
          close\
          waitpid\
          creat\
          link\
          unlink\
          execve\
          chdir\
          time32\
          mknod\
          chmod\
          lchown16\
          stat\
          lseek\
          getpid\
          mount\
          oldumount\
          setuid16\
          getuid16\
          stime32\
          ptrace\
          alarm\
          fstat\
          pause\
          utime32\
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
          signal\
          geteuid16\
          getegid16\
          acct\
          umount\
          ioctl\
          fcntl\
          setpgid\
          olduname\
          umask\
          chroot\
          ustat\
          dup2\
          getppid\
          getpgrp\
          setsid\
          sigaction\
          sgetmask\
          ssetmask\
          setreuid16\
          setregid16\
          sigsuspend\
          sigpending\
          sethostname\
          setrlimit\
          old_getrlimit\
          getrusage\
          gettimeofday\
          settimeofday\
          getgroups16\
          setgroups16\
          old_select\
          symlink\
          lstat\
          readlink\
          uselib\
          swapon\
          reboot\
          old_readdir\
          old_mmap\
          munmap\
          truncate\
          ftruncate\
          fchmod\
          fchown16\
          getpriority\
          setpriority\
          statfs\
          fstatfs\
          ioperm\
          socketcall\
          syslog\
          setitimer\
          getitimer\
          newstat\
          newlstat\
          newfstat\
          uname\
          iopl\
          vhangup\
          vm86old\
          wait4\
          swapoff\
          sysinfo\
          ipc\
          fsync\
          clone\
          setdomainname\
          newuname\
          modify_ldt\
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
          sysctl\
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
          vm86\
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
          pivot_root\
          mincore\
          madvise\
          getdents64\
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
          set_thread_area\
          get_thread_area\
          io_setup\
          io_destroy\
          io_getevents_time32\
          io_submit\
          io_cancel\
          fadvise64\
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
          mbind\
          get_mempolicy\
          set_mempolicy\
          mq_open\
          mq_unlink\
          mq_timedsend_time32\
          mq_timedreceive_time32\
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
          socket\
          socketpair\
          bind\
          connect\
          listen\
          accept4\
          getsockopt\
          setsockopt\
          getsockname\
          getpeername\
          sendto\
          sendmsg\
          recvfrom\
          recvmsg\
          shutdown\
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
          arch_prctl\
          io_pgetevents_time32\
          rseq\
          semget\
          semctl\
          shmget\
          shmctl\
          shmat\
          shmdt\
          msgget\
          msgsnd\
          msgrcv\
          msgctl\
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
          openat2\
          pidfd_getfd\
          faccessat2"
