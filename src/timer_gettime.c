#include <liblinux/linux.h>

extern inline enum linux_error_t linux_timer_gettime(linux_timer_t timer_id, struct linux_kernel_itimerspec* setting);
