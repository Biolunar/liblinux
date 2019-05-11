#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_RET(rt_sigtimedwait_time32, linux_sigset_t const*, uthese, linux_siginfo_t*, uinfo, struct linux_old_timespec32 const*, uts, linux_size_t, sigsetsize, int);
