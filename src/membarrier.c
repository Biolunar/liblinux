#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_RET(membarrier, int, cmd, int, flags, int);
