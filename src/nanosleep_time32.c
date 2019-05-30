#include <liblinux/linux.h>

extern inline enum linux_error linux_nanosleep_time32(struct linux_old_timespec32 const* rqtp, struct linux_old_timespec32* rmtp);
