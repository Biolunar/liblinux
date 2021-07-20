#include <liblinux/linux.h>

extern inline linux_error_t linux_dup3(linux_fd_t oldfd, linux_fd_t newfd, int flags, linux_fd_t* result);
