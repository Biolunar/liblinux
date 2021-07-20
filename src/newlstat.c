#include <liblinux/linux.h>

extern inline linux_error_t linux_newlstat(char const* filename, struct linux_stat* statbuf);
