#include <liblinux/linux.h>

extern inline enum linux_error linux_sched_setparam(linux_pid_t pid, struct linux_sched_param* param);
