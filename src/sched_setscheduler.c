#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(sched_setscheduler, linux_pid_t, pid, int, policy, struct linux_sched_param*, param);
