#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(umount, char*, name, int, flags);
