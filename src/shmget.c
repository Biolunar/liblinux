#include <liblinux/linux.h>

extern inline linux_error_t linux_shmget(linux_key_t key, linux_size_t size, int shmflg, linux_word_t* result);
