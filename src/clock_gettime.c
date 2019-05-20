#include <liblinux/linux.h>

extern inline enum linux_error_t linux_clock_gettime(linux_clockid_t which_clock, struct linux_kernel_timespec* tp);
