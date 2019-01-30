#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_NORET(newfstatat, int, dfd, char const*, filename, struct linux_stat*, statbuf, int, flag);
