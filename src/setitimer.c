#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_NORET(setitimer, int, which, struct linux_itimerval*, value, struct linux_itimerval*, ovalue);
