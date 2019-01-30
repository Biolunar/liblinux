#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_NORET(get_mempolicy, int*, policy, unsigned long*, nmask, unsigned long, maxnode, unsigned long, addr, unsigned long, flags);
