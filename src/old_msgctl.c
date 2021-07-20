#include <liblinux/linux.h>

extern inline linux_error_t linux_old_msgctl(int msqid, int cmd, struct linux_msqid64_ds* buf, linux_word_t* result);
