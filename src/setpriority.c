#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(setpriority, int, which, int, who, int, niceval);
