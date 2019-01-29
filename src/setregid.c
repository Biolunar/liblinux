#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(setregid, linux_gid_t, rgid, linux_gid_t, egid);
