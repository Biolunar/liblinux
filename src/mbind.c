#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL6_NORET(mbind, unsigned long, start, unsigned long, len, unsigned long, mode, unsigned long const*, nmask, unsigned long, maxnode, unsigned int, flags);
