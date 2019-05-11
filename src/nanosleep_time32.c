#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(nanosleep_time32, struct linux_old_timespec32*, rqtp, struct linux_old_timespec32*, rmtp);
