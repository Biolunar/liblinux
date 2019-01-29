#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_NORET(msync, unsigned long, start, linux_size_t, len, int, flags);
