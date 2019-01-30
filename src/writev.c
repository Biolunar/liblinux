#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_RET(writev, unsigned long, fd, struct linux_iovec const*, vec, unsigned long, vlen, linux_ssize_t);
