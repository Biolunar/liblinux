#include <liblinux/linux.h>

extern inline linux_error_t linux_timer_settime(linux_timer_t timer_id, int flags, struct linux_itimerspec const* new_setting, struct linux_itimerspec* old_setting);
