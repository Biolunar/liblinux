#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(mprotect, linux_uword_t, start, linux_size_t, len, linux_uword_t, prot);
