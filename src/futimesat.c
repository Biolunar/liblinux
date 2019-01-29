#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_NORET(futimesat, int, dfd, char const*, filename, struct linux_timeval*, utimes);
