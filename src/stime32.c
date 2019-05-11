#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL1_NORET(stime32, linux_time_t*, tptr);
