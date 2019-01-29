#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(getrlimit, unsigned int, resource, struct linux_rlimit*, rlim);
