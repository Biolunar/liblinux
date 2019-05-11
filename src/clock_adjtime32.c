#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_RET(clock_adjtime32, linux_clockid_t, which_clock, struct linux_old_timex32*, utx, int);
