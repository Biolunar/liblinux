#include <liblinux/linux.h>

extern inline enum linux_error linux_sched_getattr(linux_pid_t pid, struct linux_sched_attr* uattr, unsigned int size, unsigned int flags);
