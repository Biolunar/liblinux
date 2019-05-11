#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_NORET(timerfd_settime32, int, ufd, int, flags, struct linux_old_itimerspec32 const*, utmr, struct linux_old_itimerspec32*, otmr);
