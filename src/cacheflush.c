#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(cacheflush, linux_uword_t, start, linux_uword_t, end, int, flags);
