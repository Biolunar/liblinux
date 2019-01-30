#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(fstat, unsigned int, fd, struct linux_old_kernel_stat*, statbuf);
