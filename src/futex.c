#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL6_RET(futex, uint32_t*, uaddr, int, op, uint32_t, val, struct linux_timespec*, utime, uint32_t*, uaddr2, uint32_t, val3, long);
