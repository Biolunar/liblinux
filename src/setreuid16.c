#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(setreuid16, linux_old_uid_t, ruid, linux_old_uid_t, euid);
