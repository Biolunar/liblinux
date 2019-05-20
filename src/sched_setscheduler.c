#include <liblinux/linux.h>

extern inline enum linux_error_t linux_sched_setscheduler(linux_pid_t pid, int policy, struct linux_sched_param* param);
