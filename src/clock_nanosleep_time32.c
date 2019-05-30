#include <liblinux/linux.h>

extern inline enum linux_error linux_clock_nanosleep_time32(linux_clockid_t which_clock, int flags, struct linux_old_timespec32 const* rqtp, struct linux_old_timespec32* rmtp);
