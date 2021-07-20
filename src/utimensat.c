#include <liblinux/linux.h>

extern inline linux_error_t linux_utimensat(linux_fd_t dfd, char const* filename, struct linux_timespec* utimes, int flags);
