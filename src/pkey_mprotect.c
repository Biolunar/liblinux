#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL4_NORET(pkey_mprotect, unsigned long, start, linux_size_t, len, unsigned long, prot, int, pkey);
