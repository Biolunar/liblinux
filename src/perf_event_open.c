#include <liblinux/linux.h>

extern inline enum linux_error linux_perf_event_open(struct linux_perf_event_attr* attr_uptr, linux_pid_t pid, int cpu, linux_fd_t group_fd, linux_uword_t flags, linux_fd_t* result);
