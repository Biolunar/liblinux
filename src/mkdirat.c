#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(mkdirat, int, dfd, char const*, pathname, linux_umode_t, mode);
