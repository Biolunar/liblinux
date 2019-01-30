#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(old_getrlimit, unsigned int, resource, struct linux_rlimit*, rlim);
