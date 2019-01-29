#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL6_RET(mmap_pgoff, unsigned long, addr, unsigned long, len, unsigned long, prot, unsigned long, flags, unsigned long, fd, unsigned long, pgoff, unsigned long);
