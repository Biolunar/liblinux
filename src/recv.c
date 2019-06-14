#include <liblinux/linux.h>

extern inline enum linux_error linux_recv(linux_fd_t fd, void* ubuf, linux_size_t size, unsigned int flags, int* result);
