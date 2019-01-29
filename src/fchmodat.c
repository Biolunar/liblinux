#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_NORET(fchmodat, int, dfd, char const*, filename, linux_umode_t, mode);
