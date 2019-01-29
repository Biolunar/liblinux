#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_NORET(unlinkat, int, dfd, char const*, pathname, int, flag);
