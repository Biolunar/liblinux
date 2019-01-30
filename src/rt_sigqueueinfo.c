#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(rt_sigqueueinfo, linux_pid_t, pid, int, sig, linux_siginfo_t*, uinfo);
