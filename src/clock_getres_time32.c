#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(clock_getres_time32, linux_clockid_t, which_clock, struct linux_old_timespec32*, tp);
