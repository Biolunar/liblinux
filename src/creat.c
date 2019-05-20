#include <liblinux/linux.h>

extern inline enum linux_error_t linux_creat(char const* pathname, linux_umode_t mode, linux_word_t* result);
