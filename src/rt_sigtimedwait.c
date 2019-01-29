#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL4_RET(rt_sigtimedwait, linux_sigset_t const*, uthese, linux_siginfo_t*, uinfo, struct linux_kernel_timespec const*, uts, linux_size_t, sigsetsize, int);
