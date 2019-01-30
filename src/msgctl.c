#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_RET(msgctl, int, msqid, int, cmd, struct linux_msqid64_ds*, buf, long);
