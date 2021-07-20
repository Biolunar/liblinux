#include <liblinux/linux.h>

extern inline linux_error_t linux_read(linux_fd_t fd, char* buf, linux_size_t count, linux_ssize_t* result);
