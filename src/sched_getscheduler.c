#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL1_RET(sched_getscheduler, linux_pid_t, pid, int);
