#include <liblinux/linux.h>

extern inline linux_error_t linux_sendfile64(linux_fd_t out_fd, linux_fd_t in_fd, linux_loff_t* offset, linux_size_t count, linux_ssize_t* result);
