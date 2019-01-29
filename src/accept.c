#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_RET(accept, int, fd, struct linux_sockaddr*, upeer_sockaddr, int*, upeer_addrlen, int);
