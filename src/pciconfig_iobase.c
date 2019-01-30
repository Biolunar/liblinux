#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_RET(pciconfig_iobase, long, which, unsigned long, bus, unsigned long, devfn, long);
