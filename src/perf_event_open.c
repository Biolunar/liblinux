#include <liblinux/linux.h>

extern inline enum linux_error_t linux_perf_event_open(struct linux_perf_event_attr* attr_uptr, linux_pid_t pid, int cpu, int group_fd, linux_uword_t flags, int* result);
