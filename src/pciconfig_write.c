#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL5_NORET(pciconfig_write, unsigned long, bus, unsigned long, dfn, unsigned long, off, unsigned long, len, void*, buf);
