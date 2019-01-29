#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_RET(getgroups16, int, gidsetsize, linux_old_gid_t*, grouplist, int);
