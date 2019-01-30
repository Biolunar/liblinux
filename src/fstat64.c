#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(fstat64, unsigned long, fd, struct linux_stat64*, statbuf);
