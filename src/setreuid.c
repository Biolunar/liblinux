#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(setreuid, linux_uid_t, ruid, linux_uid_t, euid);
