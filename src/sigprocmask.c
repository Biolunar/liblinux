#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_NORET(sigprocmask, int, how, linux_old_sigset_t*, nset, linux_old_sigset_t*, oset);
