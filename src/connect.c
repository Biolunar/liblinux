#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_NORET(connect, int, fd, struct linux_sockaddr*, uservaddr, int, addrlen);
