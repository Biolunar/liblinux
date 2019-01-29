#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_NORET(bind, int, fd, struct linux_sockaddr*, umyaddr, int, addrlen);
