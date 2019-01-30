#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_NORET(timerfd_settime, int, ufd, int, flags, struct linux_kernel_itimerspec const*, utmr, struct linux_kernel_itimerspec*, otmr);
