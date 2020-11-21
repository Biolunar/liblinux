#include <liblinux/linux.h>

extern inline enum linux_error linux_timer_gettime32(linux_timer_t timer_id, struct linux_itimerspec32* setting);
