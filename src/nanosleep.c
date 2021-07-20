#include <liblinux/linux.h>

extern inline linux_error_t linux_nanosleep(struct linux_timespec const* rqtp, struct linux_timespec* rmtp);
