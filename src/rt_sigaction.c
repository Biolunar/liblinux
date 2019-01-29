#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL4_NORET(rt_sigaction, int, sig, struct linux_sigaction const*, act, struct linux_sigaction*, oact, linux_size_t, sigsetsize);
