#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_NORET(renameat, int, olddfd, char const*, oldname, int, newdfd, char const*, newname);
