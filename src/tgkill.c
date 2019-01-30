#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(tgkill, linux_pid_t, tgid, linux_pid_t, pid, int, sig);
