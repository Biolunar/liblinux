#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL6_RET(preadv2, unsigned long, fd, struct linux_iovec const*, vec, unsigned long, vlen, unsigned long, pos_l, unsigned long, pos_h, linux_rwf_t, flags, linux_ssize_t);
