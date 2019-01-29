#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(truncate, char const*, path, long, length);
