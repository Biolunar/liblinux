#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(timerfd_gettime, int, ufd, struct linux_kernel_itimerspec*, otmr);
