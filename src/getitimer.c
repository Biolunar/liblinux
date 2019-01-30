#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(getitimer, int, which, struct linux_itimerval*, value);
