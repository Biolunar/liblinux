#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(fstat64, linux_uword_t, fd, struct linux_stat64*, statbuf);
