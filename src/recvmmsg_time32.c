#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_RET(recvmmsg_time32, int, fd, struct linux_mmsghdr*, mmsg, unsigned int, vlen, unsigned int, flags, struct linux_old_timespec32*, timeout, int);
