#include <liblinux/linux.h>

extern inline linux_error_t linux_nanosleep_time32(struct linux_timespec32 const* rqtp, struct linux_timespec32* rmtp);
