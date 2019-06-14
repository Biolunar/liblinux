#include <liblinux/linux.h>

extern inline enum linux_error linux_utimensat(linux_fd_t dfd, char const* filename, struct linux_kernel_timespec* utimes, int flags);
