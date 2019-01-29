#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_NORET(statfs64, char const*, pathname, linux_size_t, sz, struct linux_statfs64*, buf);
