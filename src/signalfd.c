#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_RET(signalfd, int, ufd, linux_sigset_t*, user_mask, linux_size_t, sizemask, int);
