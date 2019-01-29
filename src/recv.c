#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL4_RET(recv, int, fd, void*, ubuf, linux_size_t, size, unsigned int, flags, int);
