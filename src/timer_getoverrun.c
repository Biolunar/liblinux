#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL1_RET(timer_getoverrun, linux_timer_t, timer_id, int);
