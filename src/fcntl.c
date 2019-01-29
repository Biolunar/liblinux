#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_RET(fcntl, unsigned int, fd, unsigned int, cmd, unsigned long, arg, long);
