#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_NORET(fadvise64_64, int, fd, linux_loff_t, offset, linux_loff_t, len, int, advice);
