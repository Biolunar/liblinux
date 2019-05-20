#include <liblinux/linux.h>

extern inline enum linux_error_t linux_unlinkat(int dfd, char const* pathname, int flag);
