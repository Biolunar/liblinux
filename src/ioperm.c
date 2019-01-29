#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_NORET(ioperm, unsigned long, from, unsigned long, num, int, turn_on);
