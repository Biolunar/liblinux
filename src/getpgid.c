#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL1_RET(getpgid, linux_pid_t, pid, int);
