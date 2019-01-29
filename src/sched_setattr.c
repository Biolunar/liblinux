#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_NORET(sched_setattr, linux_pid_t, pid, struct linux_sched_attr*, uattr, unsigned int, flags);
