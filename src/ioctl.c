#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_RET(ioctl, unsigned int, fd, unsigned int, cmd, linux_uword_t, arg, int);
