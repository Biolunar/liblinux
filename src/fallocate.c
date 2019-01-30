#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_NORET(fallocate, int, fd, int, mode, linux_loff_t, offset, linux_loff_t, len);
