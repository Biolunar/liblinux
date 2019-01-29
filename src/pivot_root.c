#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(pivot_root, char const*, new_root, char const*, put_old);
