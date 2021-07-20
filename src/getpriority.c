#include <liblinux/linux.h>

extern inline linux_error_t linux_getpriority(int which, int who, linux_word_t* result);
