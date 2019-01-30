#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_RET(sendmmsg, int, fd, struct linux_mmsghdr*, mmsg, unsigned int, vlen, unsigned int, flags, int);
