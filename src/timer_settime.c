#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL4_NORET(timer_settime, linux_timer_t, timer_id, int, flags, struct linux_kernel_itimerspec const*, new_setting, struct linux_kernel_itimerspec*, old_setting);
