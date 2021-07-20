#include <liblinux/linux.h>

extern inline linux_error_t linux_sched_rr_get_interval_time32(linux_pid_t pid, struct linux_timespec32* interval);
