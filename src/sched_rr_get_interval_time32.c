#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(sched_rr_get_interval_time32, linux_pid_t, pid, struct linux_old_timespec32*, interval);
