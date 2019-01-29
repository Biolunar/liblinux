#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL4_RET(epoll_wait, int, epfd, struct linux_epoll_event*, events, int, maxevents, int, timeout, int);
