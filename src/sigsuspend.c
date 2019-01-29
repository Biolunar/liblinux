#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_NORET(sigsuspend, int, unused1, int, unused2, linux_old_sigset_t, mask);
