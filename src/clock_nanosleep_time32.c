#include <liblinux/linux.h>

extern inline linux_error_t linux_clock_nanosleep_time32(linux_clockid_t which_clock, int flags, struct linux_timespec32 const* rqtp, struct linux_timespec32* rmtp);
