#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL5_NORET(waitid, int, which, linux_pid_t, upid, struct linux_siginfo*, infop, int, options, struct linux_rusage*, ru);
