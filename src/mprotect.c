#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(mprotect, unsigned long, start, linux_size_t, len, unsigned long, prot);
