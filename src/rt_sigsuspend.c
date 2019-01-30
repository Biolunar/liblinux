#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(rt_sigsuspend, linux_sigset_t*, unewset, linux_size_t, sigsetsize);
