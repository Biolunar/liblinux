#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(gettimeofday, struct linux_timeval*, tv, struct linux_timezone*, tz);
