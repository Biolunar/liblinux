#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(newlstat, char const*, filename, struct linux_stat*, statbuf);
