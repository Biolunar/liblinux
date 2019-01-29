#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL5_RET(kcmp, linux_pid_t, pid1, linux_pid_t, pid2, int, type, unsigned long, idx1, unsigned long, idx2, int);
