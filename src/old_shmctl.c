#include <liblinux/linux.h>

extern inline linux_error_t linux_old_shmctl(int shmid, int cmd, struct linux_shmid64_ds* buf, linux_word_t* result);
