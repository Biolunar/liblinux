#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_RET(read, unsigned int, fd, char*, buf, linux_size_t, count, linux_ssize_t);
