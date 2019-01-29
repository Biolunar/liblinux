#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_RET(memfd_create, char const*, uname, unsigned int, flags, int);
