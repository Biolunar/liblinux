#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_RET(wait4, linux_pid_t, upid, int*, stat_addr, int, options, struct linux_rusage*, ru, long);
