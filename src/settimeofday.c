#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(settimeofday, struct linux_timeval*, tv, struct linux_timezone*, tz);
