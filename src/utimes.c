#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(utimes, char*, filename, struct linux_timeval*, utimes);
