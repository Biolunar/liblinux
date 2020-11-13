#include <liblinux/linux.h>

extern inline enum linux_error linux_close_range(linux_fd_t fd, linux_fd_t max_fd, unsigned int flags);
