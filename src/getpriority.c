#include <liblinux/linux.h>

extern inline enum linux_error linux_getpriority(int which, int who, linux_word_t* result);
