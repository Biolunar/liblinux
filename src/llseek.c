#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_NORET(llseek, unsigned int, fd, linux_uword_t, offset_high, linux_uword_t, offset_low, linux_loff_t*, result, unsigned int, whence);
