#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(newstat, char const*, filename, struct linux_stat*, statbuf);
