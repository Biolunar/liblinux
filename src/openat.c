#include <liblinux/linux.h>

extern inline linux_error_t linux_openat(linux_fd_t dfd, char const* filename, int flags, linux_umode_t mode, linux_fd_t* result);
