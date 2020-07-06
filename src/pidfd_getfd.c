#include <liblinux/linux.h>

extern inline enum linux_error linux_pidfd_getfd(linux_pid_t pidfd, linux_fd_t fd, unsigned int flags, linux_fd_t* result);
