#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_RET(msgrcv, int, msqid, struct linux_msgbuf*, msgp, linux_size_t, msgsz, long, msgtyp, int, msgflg, long);
