#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(lstat, char const*, filename, struct linux_old_kernel_stat*, statbuf);
