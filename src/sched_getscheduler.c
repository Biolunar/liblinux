#include <liblinux/linux.h>

extern inline linux_error_t linux_sched_getscheduler(linux_pid_t pid, int* result);
