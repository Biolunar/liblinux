#include <liblinux/linux.h>

extern inline enum linux_error_t linux_newfstatat(int dfd, char const* filename, struct linux_stat* statbuf, int flag);
