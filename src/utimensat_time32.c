#include <liblinux/linux.h>

extern inline enum linux_error linux_utimensat_time32(unsigned int dfd, char const* filename, struct linux_old_timespec32* t, int flags);
