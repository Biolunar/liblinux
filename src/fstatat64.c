#include <liblinux/linux.h>

extern inline enum linux_error_t linux_fstatat64(int dfd, char const* filename, struct linux_stat64* statbuf, int flag);
