#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_NORET(get_mempolicy, int*, policy, linux_uword_t*, nmask, linux_uword_t, maxnode, linux_uword_t, addr, linux_uword_t, flags);
