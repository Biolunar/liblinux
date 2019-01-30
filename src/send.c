#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_RET(send, int, fd, void*, buff, linux_size_t, len, unsigned int, flags, int);
