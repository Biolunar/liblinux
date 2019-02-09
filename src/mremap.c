#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_RET(mremap, linux_uword_t, addr, linux_uword_t, old_len, linux_uword_t, new_len, linux_uword_t, flags, linux_uword_t, new_addr, linux_uword_t);
