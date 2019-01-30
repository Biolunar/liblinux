#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_RET(signalfd4, int, ufd, linux_sigset_t*, user_mask, linux_size_t, sizemask, int, flags, int);
