#include <liblinux/linux.h>

extern inline linux_error_t linux_sched_getparam(linux_pid_t pid, struct linux_sched_param* param);
