#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_RET(writev, linux_uword_t, fd, struct linux_iovec const*, vec, linux_uword_t, vlen, linux_ssize_t);
