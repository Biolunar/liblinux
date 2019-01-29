#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(setrlimit, unsigned int, resource, struct linux_rlimit*, rlim);
