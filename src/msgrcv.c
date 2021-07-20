#include <liblinux/linux.h>

extern inline linux_error_t linux_msgrcv(int msqid, struct linux_msgbuf* msgp, linux_size_t msgsz, linux_word_t msgtyp, int msgflg, linux_word_t* result);
