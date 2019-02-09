#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL6_RET(mmap_pgoff, linux_uword_t, addr, linux_uword_t, len, linux_uword_t, prot, linux_uword_t, flags, linux_uword_t, fd, linux_uword_t, pgoff, linux_uword_t);
