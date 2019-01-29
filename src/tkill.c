#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(tkill, linux_pid_t, pid, int, sig);
