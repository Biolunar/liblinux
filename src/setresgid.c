#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_NORET(setresgid, linux_gid_t, rgid, linux_gid_t, egid, linux_gid_t, sgid);
