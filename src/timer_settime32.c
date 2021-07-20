#include <liblinux/linux.h>

extern inline linux_error_t linux_timer_settime32(linux_timer_t timer_id, int flags, struct linux_itimerspec32* new, struct linux_itimerspec32* old);
