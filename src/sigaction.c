#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_NORET(sigaction, int, sig, struct linux_old_sigaction const*, act, struct linux_old_sigaction*, oact);
