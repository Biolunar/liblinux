#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_NORET(timer_settime32, linux_timer_t, timer_id, int, flags, struct linux_old_itimerspec32*, new, struct linux_old_itimerspec32*, old);
