#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_NORET(pkey_mprotect, linux_uword_t, start, linux_size_t, len, linux_uword_t, prot, int, pkey);
