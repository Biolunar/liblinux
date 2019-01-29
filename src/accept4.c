#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL4_RET(accept4, int, fd, struct linux_sockaddr*, upeer_sockaddr, int*, upeer_addrlen, int, flags, int);
