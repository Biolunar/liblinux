#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_RET(recvmsg, int, fd, struct linux_user_msghdr*, msg, unsigned int, flags, int);
