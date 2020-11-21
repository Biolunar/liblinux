#include <liblinux/linux.h>

extern inline enum linux_error linux_clock_adjtime32(linux_clockid_t which_clock, struct linux_timex32* utp, int* result);
