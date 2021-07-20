#include <liblinux/linux.h>

extern inline linux_error_t linux_msgsnd(int msqid, struct linux_msgbuf* msgp, linux_size_t msgsz, int msgflg);
