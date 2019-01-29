#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(sched_rr_get_interval, linux_pid_t, pid, struct linux_kernel_timespec*, interval);
