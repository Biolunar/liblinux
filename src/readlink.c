#include <liblinux/linux.h>

extern inline enum linux_error linux_readlink(char const* path, char* buf, int bufsiz, int* result);
