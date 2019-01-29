#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL6_RET(ipc, unsigned int, call, int, first, unsigned long, second, unsigned long, third, void*, ptr, long, fifth, long);
