#include <liblinux/linux.h>

extern inline enum linux_error_t linux_semget(linux_key_t key, int nsems, int semflg, linux_word_t* result);
