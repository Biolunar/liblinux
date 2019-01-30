#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_RET(ioprio_get, int, which, int, who, int);
