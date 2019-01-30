#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL6_RET(mmap, unsigned long, addr, unsigned long, len, unsigned long, prot, unsigned long, flags, unsigned long, fd, unsigned long, off, unsigned long);
