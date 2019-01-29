#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL4_NORET(mknodat, int, dfd, char const*, filename, linux_umode_t, mode, unsigned int, dev);
