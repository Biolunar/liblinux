#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_RET(waitpid, linux_pid_t, pid, int*, stat_addr, int, options, long);
