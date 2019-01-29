#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL4_NORET(fadvise64, int, fd, linux_loff_t, offset, linux_size_t, len, int, advice);
