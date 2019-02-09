#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_RET(pkey_alloc, linux_uword_t, flags, linux_uword_t, init_val, int);
