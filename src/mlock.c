#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(mlock, unsigned long, start, linux_size_t, len);
