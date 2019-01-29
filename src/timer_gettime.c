#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(timer_gettime, linux_timer_t, timer_id, struct linux_kernel_itimerspec*, setting);
