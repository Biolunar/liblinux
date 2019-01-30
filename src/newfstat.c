#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(newfstat, unsigned int, fd, struct linux_stat*, statbuf);
