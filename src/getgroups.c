#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_RET(getgroups, int, gidsetsize, linux_gid_t*, grouplis, int);
