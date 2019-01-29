#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL5_NORET(fsetxattr, int, fd, char const*, name, void const*,value, linux_size_t, size, int, flags);
