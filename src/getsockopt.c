#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL5_NORET(getsockopt, int, fd, int, level, int, optname, char*, optval, int*, optlen);
