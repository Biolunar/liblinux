#include <liblinux/linux.h>

extern inline linux_error_t linux_semctl(int semid, int semnum, int cmd, linux_uword_t arg, linux_word_t* result);
