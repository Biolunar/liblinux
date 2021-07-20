#include <liblinux/linux.h>

extern inline linux_error_t linux_send(linux_fd_t fd, void* buff, linux_size_t len, unsigned int flags, int* result);
