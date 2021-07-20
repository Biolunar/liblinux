#include <liblinux/linux.h>

extern inline linux_error_t linux_pidfd_getfd(linux_pid_t pidfd, linux_fd_t fd, unsigned int flags, linux_fd_t* result);
