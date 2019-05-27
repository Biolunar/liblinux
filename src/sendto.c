#include <liblinux/linux.h>

extern inline enum linux_error linux_sendto(int fd, void* buff, linux_size_t len, unsigned int flags, struct linux_sockaddr* addr, int addr_le, int* result);
