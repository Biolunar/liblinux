#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL5_RET(ppoll, struct linux_pollfd*, ufds, unsigned int, nfds, struct linux_timespec*, tsp, linux_sigset_t const*, sigmask, linux_size_t, sigsetsize, int);
