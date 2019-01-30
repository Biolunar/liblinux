#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_NORET(arm_fadvise64_64, int, fd, int, advice, linux_loff_t, offset, linux_loff_t, len);
