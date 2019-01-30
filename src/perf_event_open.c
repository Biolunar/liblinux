#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_RET(perf_event_open, struct linux_perf_event_attr*, attr_uptr, linux_pid_t, pid, int, cpu, int, group_fd, unsigned long, flags, int);
