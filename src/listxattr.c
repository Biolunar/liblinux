#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_RET(listxattr, char const*, pathname, char*, list, linux_size_t, size, linux_ssize_t);
