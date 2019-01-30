#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(finit_module, int, fd, char const*, uargs, int, flags);
