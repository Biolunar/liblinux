#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(mkdir, char const*, pathname, linux_umode_t, mode);
