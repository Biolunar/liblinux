#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(symlinkat, char const*, oldname, int, newdfd, char const*, newname);
