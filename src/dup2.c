#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_RET(dup2, unsigned int, oldfd, unsigned int, newfd, int);
