#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_RET(select, int, n, linux_fd_set*, inp, linux_fd_set*, outp, linux_fd_set*, exp, struct linux_timeval*, tvp, int);
