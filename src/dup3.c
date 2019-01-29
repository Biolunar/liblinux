#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_RET(dup3, unsigned int, oldfd, unsigned int, newfd, int, flags, int);
