#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL6_RET(pwritev2, linux_uword_t, fd, struct linux_iovec const*, vec, linux_uword_t, vlen, linux_uword_t, pos_l, linux_uword_t, pos_h, linux_rwf_t, flags, linux_ssize_t);
