#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL4_RET(openat, int, dfd, char const*, filename, int, flags, linux_umode_t, mode, long);
