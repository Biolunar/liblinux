#include <liblinux/linux.h>

extern inline enum linux_error linux_seccomp(unsigned int op, unsigned int flags, void* uargs, linux_word_t* result);
