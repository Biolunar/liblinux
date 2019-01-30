#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_RET(write, unsigned int, fd, char const*, buf, linux_size_t, count, linux_ssize_t);
