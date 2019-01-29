#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(sched_setparam, linux_pid_t, pid, struct linux_sched_param*, param);
