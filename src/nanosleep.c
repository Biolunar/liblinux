#include <liblinux/linux.h>

extern inline enum linux_error_t linux_nanosleep(struct linux_kernel_timespec* rqtp, struct linux_kernel_timespec* rmtp);
