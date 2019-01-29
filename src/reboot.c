#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL4_NORET(reboot, int, magic1, int, magic2, unsigned int, cmd, void*, arg);
