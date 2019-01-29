#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL4_NORET(clock_nanosleep, linux_clockid_t, which_clock, int, flags, struct linux_kernel_timespec const*, rqtp, struct linux_kernel_timespec*, rmtp);
