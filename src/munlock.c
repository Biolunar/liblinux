#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(munlock, unsigned long, start, linux_size_t, len);
