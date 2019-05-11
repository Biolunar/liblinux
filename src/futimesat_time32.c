#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(futimesat_time32, unsigned int, dfd, char const*, filename, struct linux_old_timeval32*, t);
