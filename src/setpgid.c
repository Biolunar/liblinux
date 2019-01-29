#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(setpgid, linux_pid_t, pid, linux_pid_t, pgid);
