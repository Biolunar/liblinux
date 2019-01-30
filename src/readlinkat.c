#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_RET(readlinkat, int, dfd, char const*, pathname, char*, buf, int, bufsiz, int);
