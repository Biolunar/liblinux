#include <liblinux/linux.h>

extern inline enum linux_error_t linux_clock_adjtime(linux_clockid_t which_clock, struct linux_kernel_timex* ktx, int* result);
