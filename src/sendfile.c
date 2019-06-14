#include <liblinux/linux.h>

extern inline enum linux_error linux_sendfile(linux_fd_t out_fd, linux_fd_t in_fd, linux_off_t* offset, linux_size_t count, linux_ssize_t* result);
