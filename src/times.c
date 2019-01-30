#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL1_RET(times, struct linux_tms*, tbuf, long);
