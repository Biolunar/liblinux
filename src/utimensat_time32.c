#include <liblinux/linux.h>

extern inline enum linux_error linux_utimensat_time32(linux_fd_t dfd, char const* filename, struct linux_timespec32* t, int flags);
