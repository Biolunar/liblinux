#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_NORET(utimensat, int, dfd, char const*, filename, struct linux_kernel_timespec*, utimes, int, flags);
