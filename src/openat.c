#include <liblinux/linux.h>

extern inline enum linux_error_t linux_openat(int dfd, char const* filename, int flags, linux_umode_t mode, linux_word_t* result);
