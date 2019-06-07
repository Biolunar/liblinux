#include <liblinux/linux.h>

extern inline enum linux_error linux_sendto(linux_fd_t fd, void const* buff, linux_size_t len, unsigned int flags, struct linux_sockaddr const* addr, int addr_le, int* result);
