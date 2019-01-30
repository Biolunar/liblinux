#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_RET(preadv, unsigned long, fd, struct linux_iovec const*, vec, unsigned long, vlen, unsigned long, pos_l, unsigned long, pos_h, linux_ssize_t);
