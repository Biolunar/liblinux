#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL4_NORET(fstatat64, int, dfd, char const*, filename, struct linux_stat64*, statbuf, int, flag);
