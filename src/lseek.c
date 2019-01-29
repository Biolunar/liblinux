#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_RET(lseek, unsigned int, fd, linux_off_t, offset, unsigned int, whence, linux_off_t);
