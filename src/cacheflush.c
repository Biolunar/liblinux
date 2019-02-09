#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(cacheflush, unsigned long, start, unsigned long, end, int, flags);
