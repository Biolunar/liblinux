#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(setgroups, int, gidsetsize, linux_gid_t*, grouplist);
