#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_RET(creat, char const*, pathname, linux_umode_t, mode, long);
