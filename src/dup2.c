#include <liblinux/linux.h>

extern inline enum linux_error_t linux_dup2(unsigned int oldfd, unsigned int newfd, int* result);
