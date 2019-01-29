#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL6_RET(sendto, int, fd, void*, buff, linux_size_t, len, unsigned int, flags, struct linux_sockaddr*, addr, int, addr_le, int);
