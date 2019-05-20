#include <liblinux/linux.h>

extern inline enum linux_error_t linux_sendfile64(int out_fd, int in_fd, linux_loff_t* offset, linux_size_t count, linux_ssize_t* result);
