#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(setns, int, fd, int, nstype);
