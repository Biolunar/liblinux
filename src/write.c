#include <liblinux/linux.h>

extern inline linux_error_t linux_write(linux_fd_t fd, char const* buf, linux_size_t count, linux_ssize_t* result);
