#include <liblinux/linux.h>

extern inline linux_error_t linux_recv(linux_fd_t fd, void* ubuf, linux_size_t size, unsigned int flags, int* result);
