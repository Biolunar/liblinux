#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_NORET(msgsnd, int, msqid, struct linux_msgbuf*, msgp, linux_size_t, msgsz, int, msgflg);
