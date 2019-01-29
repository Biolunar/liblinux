#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL5_RET(recvmmsg, int, fd, struct linux_mmsghdr*, mmsg, unsigned int, vlen, unsigned int, flags, struct linux_kernel_timespec*, timeout, int);
