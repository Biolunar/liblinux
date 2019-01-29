#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL6_RET(epoll_pwait, int, epfd, struct linux_epoll_event*, events, int, maxevents, int, timeout, linux_sigset_t const*, sigmask, linux_size_t, sigsetsize, int);
