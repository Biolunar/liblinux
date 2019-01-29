#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(stat, char const*, filename, struct linux_old_kernel_stat*, statbuf);
