#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL4_RET(pwrite64, unsigned int, fd, char const*, buf, linux_size_t, count, linux_loff_t, pos, linux_ssize_t);
