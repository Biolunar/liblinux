#include <liblinux/linux.h>

extern inline linux_error_t linux_clock_nanosleep(linux_clockid_t which_clock, int flags, struct linux_timespec const* rqtp, struct linux_timespec* rmtp);
