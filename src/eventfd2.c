#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_RET(eventfd2, unsigned int, count, int, flags, int);
