#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_RET(ppoll_time32, struct linux_pollfd*, ufds, unsigned int, nfds, struct linux_old_timespec32*, tsp, linux_sigset_t const*, sigmask, linux_size_t, sigsetsize, int);
