#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_NORET(setresuid16, linux_old_uid_t, ruid, linux_old_uid_t, euid, linux_old_uid_t, suid);
