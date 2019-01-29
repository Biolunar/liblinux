#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_NORET(old_readdir, unsigned int, fd, struct linux_old_linux_dirent*, dirent, unsigned int, count);
