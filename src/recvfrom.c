#include <liblinux/linux.h>

extern inline enum linux_error linux_recvfrom(linux_fd_t fd, void* ubuf, linux_size_t size, unsigned int flags, struct linux_sockaddr* addr, int* addr_len, int* result);
