#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(ftruncate64, unsigned int, fd, linux_loff_t, length);
