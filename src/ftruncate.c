#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(ftruncate, unsigned int, fd, unsigned long, length);
