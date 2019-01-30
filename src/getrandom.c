#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_RET(getrandom, char*, buf, linux_size_t, count, unsigned int, flags, linux_ssize_t);
