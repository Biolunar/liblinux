#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_NORET(linkat, int, olddfd, char const*, oldname, int, newdfd, char const*, newname, int, flags);
