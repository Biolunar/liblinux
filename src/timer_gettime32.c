#include <liblinux/linux.h>

extern inline linux_error_t linux_timer_gettime32(linux_timer_t timer_id, struct linux_itimerspec32* setting);
