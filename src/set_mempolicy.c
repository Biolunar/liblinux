#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(set_mempolicy, int, mode, unsigned long const*, nmask, unsigned long, maxnode);
