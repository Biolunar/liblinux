#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL4_NORET(rt_tgsigqueueinfo, linux_pid_t, tgid, linux_pid_t, pid, int, sig, linux_siginfo_t*, uinfo);
