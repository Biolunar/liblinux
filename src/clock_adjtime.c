#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_RET(clock_adjtime, linux_clockid_t, which_clock, struct linux_timex*, utx, int);
