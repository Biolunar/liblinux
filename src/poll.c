#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_RET(poll, struct linux_pollfd*, ufds, unsigned int, nfds, int, timeout_msecs, int);
