#include <liblinux/linux.h>

extern inline enum linux_error_t linux_readlink(char const* path, char* buf, int bufsiz, int* result);
