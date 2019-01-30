#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(faccessat, int, dfd, char const*, filename, int, mode);
