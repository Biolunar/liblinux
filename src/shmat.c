#include <liblinux/linux.h>

extern inline enum linux_error linux_shmat(int shmid, char* shmaddr, int shmflg, linux_word_t* result);
