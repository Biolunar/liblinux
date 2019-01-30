#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(nanosleep, struct linux_kernel_timespec*, rqtp, struct linux_kernel_timespec*, rmtp);
