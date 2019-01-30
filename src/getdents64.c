#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_RET(getdents64, unsigned int, fd, struct linux_dirent64*, dirent, unsigned int, count, int);
