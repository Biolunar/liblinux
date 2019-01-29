#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL4_RET(tee, int, fdin, int, fdout, linux_size_t, len, unsigned int, flags, int);
