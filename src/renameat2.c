#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL5_NORET(renameat2, int, olddfd, char const*, oldname, int, newdfd, char const*, newname, unsigned int, flags);
