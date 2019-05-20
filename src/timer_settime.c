#include <liblinux/linux.h>

extern inline enum linux_error_t linux_timer_settime(linux_timer_t timer_id, int flags, struct linux_kernel_itimerspec const* new_setting, struct linux_kernel_itimerspec* old_setting);
