#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL1_NORET(timer_delete, linux_timer_t, timer_id);
