#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL6_RET(recvfrom, int, fd, void*, ubuf, linux_size_t, size, unsigned int, flags, struct linux_sockaddr*, addr, int*, addr_len, int);
