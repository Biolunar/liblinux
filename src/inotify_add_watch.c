#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_RET(inotify_add_watch, int, fd, char const*, pathname, uint32_t, mask, int);
