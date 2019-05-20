#include <liblinux/linux.h>

extern inline enum linux_error_t linux_timer_settime32(linux_timer_t timer_id, int flags, struct linux_old_itimerspec32* new, struct linux_old_itimerspec32* old);
