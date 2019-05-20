#include <liblinux/linux.h>

extern inline enum linux_error_t linux_recv(int fd, void* ubuf, linux_size_t size, unsigned int flags, int* result);
