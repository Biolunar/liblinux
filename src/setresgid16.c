#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_NORET(setresgid16, linux_old_gid_t, rgid, linux_old_gid_t, egid, linux_old_gid_t, sgid);
