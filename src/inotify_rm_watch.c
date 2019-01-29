#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(inotify_rm_watch, int, fd, int32_t, wd);
