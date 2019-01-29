#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL4_NORET(prlimit64, linux_pid_t, pid, unsigned int, resource, struct linux_rlimit64 const*, new_rlim, struct linux_rlimit64*, old_rlim);
