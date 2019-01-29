#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_NORET(readahead, int, fd, linux_loff_t, offset, linux_size_t, count);
