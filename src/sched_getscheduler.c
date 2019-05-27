#include <liblinux/linux.h>

extern inline enum linux_error linux_sched_getscheduler(linux_pid_t pid, int* result);
