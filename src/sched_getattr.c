#include <liblinux/linux.h>

extern inline linux_error_t linux_sched_getattr(linux_pid_t pid, struct linux_sched_attr* uattr, unsigned int size, unsigned int flags);
