#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(flock, unsigned int, fd, unsigned int, cmd);
