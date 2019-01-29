#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(setgroups16, int, gidsetsize, linux_old_gid_t*, grouplist);
