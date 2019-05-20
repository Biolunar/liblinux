#include <liblinux/linux.h>

extern inline enum linux_error_t linux_memfd_create(char const* uname, unsigned int flags, int* result);
