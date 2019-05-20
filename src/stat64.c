#include <liblinux/linux.h>

extern inline enum linux_error_t linux_stat64(char const* filename, struct linux_stat64* statbuf);
