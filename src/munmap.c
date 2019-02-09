#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(munmap, linux_uword_t, addr, linux_size_t, len);
