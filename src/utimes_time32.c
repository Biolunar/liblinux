#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(utimes_time32, char const*, filename, struct linux_old_timeval32*, t);
