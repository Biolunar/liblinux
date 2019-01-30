#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(kill, linux_pid_t, pid, int, sig);
