#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(mknod, char const*, filename, linux_umode_t, mode, unsigned, dev);
