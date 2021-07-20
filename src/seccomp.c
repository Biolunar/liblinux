#include <liblinux/linux.h>

extern inline linux_error_t linux_seccomp(unsigned int op, unsigned int flags, void* uargs, linux_word_t* result);
