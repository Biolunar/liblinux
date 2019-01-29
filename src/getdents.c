#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_RET(getdents, unsigned int, fd, struct linux_dirent*, dirent, unsigned int, count, int);
