#include <liblinux/linux.h>

extern inline enum linux_error_t linux_timer_create(linux_clockid_t which_clock, struct linux_sigevent* timer_event_spec, linux_timer_t* created_timer_id);
