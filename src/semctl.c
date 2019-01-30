#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_RET(semctl, int, semid, int, semnum, int, cmd, unsigned long, arg, long);
