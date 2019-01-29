#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL4_NORET(sched_getattr, linux_pid_t, pid, struct linux_sched_attr*, uattr, unsigned int, size, unsigned int, flags);
