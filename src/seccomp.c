#include <liblinux/linux.h>

extern inline enum linux_error_t linux_seccomp(unsigned int op, unsigned int flags, char const* uargs, linux_word_t* result);
