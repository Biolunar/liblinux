#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_NORET(ioprio_set, int, which, int, who, int, ioprio);
