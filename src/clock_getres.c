#include <liblinux/linux.h>

extern inline linux_error_t linux_clock_getres(linux_clockid_t which_clock, struct linux_timespec* tp);
