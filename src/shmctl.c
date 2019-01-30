#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_RET(shmctl, int, shmid, int, cmd, struct linux_shmid64_ds*, buf, long);
