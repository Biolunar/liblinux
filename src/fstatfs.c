#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(fstatfs, unsigned int, fd, struct linux_statfs*, buf);
