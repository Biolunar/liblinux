#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL4_NORET(epoll_ctl, int, epfd, int, op, int, fd, struct linux_epoll_event*, event);
