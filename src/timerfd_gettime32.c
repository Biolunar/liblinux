#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(timerfd_gettime32, int, ufd, struct linux_old_itimerspec32*, otmr);
