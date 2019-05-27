#include <liblinux/linux.h>

extern inline enum linux_error linux_readlinkat(int dfd, char const* pathname, char* buf, int bufsiz, int* result);
