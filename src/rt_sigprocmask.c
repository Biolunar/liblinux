#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_NORET(rt_sigprocmask, int, how, linux_sigset_t*, nset, linux_sigset_t*, oset, linux_size_t, sigsetsize);
