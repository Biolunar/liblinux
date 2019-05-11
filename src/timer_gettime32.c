#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(timer_gettime32, linux_timer_t, timer_id, struct linux_old_itimerspec32*, setting);
