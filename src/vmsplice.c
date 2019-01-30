#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_RET(vmsplice, int, fd, struct linux_iovec const*, uiov, unsigned long, nr_segs, unsigned int, flags, long);
