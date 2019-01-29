#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_RET(syslog, int, type, char*, buf, int, len, int);
