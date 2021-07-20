#include <liblinux/linux.h>

extern inline linux_error_t linux_readlink(char const* path, char* buf, int bufsiz, int* result);
