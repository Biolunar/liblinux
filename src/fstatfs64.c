#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(fstatfs64, unsigned int, fd, linux_size_t, sz, struct linux_statfs64*, buf);
