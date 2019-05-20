#include <liblinux/linux.h>

extern inline enum linux_error_t linux_sendfile(int out_fd, int in_fd, linux_off_t* offset, linux_size_t count, linux_ssize_t* result);
