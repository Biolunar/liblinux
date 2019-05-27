#include <liblinux/linux.h>

extern inline enum linux_error linux_old_shmctl(int shmid, int cmd, struct linux_shmid64_ds* buf, linux_word_t* result);
