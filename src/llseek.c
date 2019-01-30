#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_NORET(llseek, unsigned int, fd, unsigned long, offset_high, unsigned long, offset_low, linux_loff_t*, result, unsigned int, whence);
