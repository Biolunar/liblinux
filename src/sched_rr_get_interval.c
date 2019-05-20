#include <liblinux/linux.h>

extern inline enum linux_error_t linux_sched_rr_get_interval(linux_pid_t pid, struct linux_kernel_timespec* interval);
