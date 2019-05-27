#include <liblinux/linux.h>

extern inline enum linux_error linux_dup3(unsigned int oldfd, unsigned int newfd, int flags, int* result);
