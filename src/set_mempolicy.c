#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(set_mempolicy, int, mode, linux_uword_t const*, nmask, linux_uword_t, maxnode);
