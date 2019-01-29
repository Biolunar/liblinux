#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(rt_sigpending, linux_sigset_t*, uset, linux_size_t, sigsetsize);
