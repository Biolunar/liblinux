#include <liblinux/linux.h>

extern inline enum linux_error linux_clock_settime32(linux_clockid_t which_clock, struct linux_timespec32* tp);
