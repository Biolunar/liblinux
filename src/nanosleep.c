#include <liblinux/linux.h>

extern inline enum linux_error linux_nanosleep(struct linux_timespec const* rqtp, struct linux_timespec* rmtp);
