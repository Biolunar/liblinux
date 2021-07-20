#include <liblinux/linux.h>

extern inline linux_error_t linux_shmat(int shmid, char* shmaddr, int shmflg, linux_word_t* result);
