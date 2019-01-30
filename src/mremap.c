#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_RET(mremap, unsigned long, addr, unsigned long, old_len, unsigned long, new_len, unsigned long, flags, unsigned long, new_addr, unsigned long);
