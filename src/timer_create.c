#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_NORET(timer_create, linux_clockid_t, which_clock, struct linux_sigevent*, timer_event_spec, linux_timer_t*, created_timer_id);
