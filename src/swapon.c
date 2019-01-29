#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(swapon, char const*, specialfile, int, swap_flags);
