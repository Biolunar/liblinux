#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_NORET(utimensat_time32, unsigned int, dfd, char const*, filename, struct linux_old_timespec32*, t, int, flags);
