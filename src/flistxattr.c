#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_RET(flistxattr, int, fd, char*, list, linux_size_t, size, linux_ssize_t);
