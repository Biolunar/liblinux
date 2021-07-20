#include <liblinux/linux.h>

extern inline linux_error_t linux_fspick(linux_fd_t dfd, char const* path, unsigned int flags, linux_fd_t* result);
