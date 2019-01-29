#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_RET(readlink, char const*, path, char*, buf, int, bufsiz, int);
