#include <liblinux/linux.h>

extern inline enum linux_error_t linux_newstat(char const* filename, struct linux_stat* statbuf);
