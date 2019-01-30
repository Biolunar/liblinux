#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(munmap, unsigned long, addr, linux_size_t, len);
