#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_RET(readv, unsigned long, fd, struct linux_iovec const*, vec, unsigned long, vlen, linux_ssize_t);
