#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_NORET(clock_nanosleep_time32, linux_clockid_t, which_clock, int, flags, struct linux_old_timespec32*, rqtp, struct linux_old_timespec32*, rmtp);
