#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_RET(timerfd_create, int, clockid, int, flags, int);
