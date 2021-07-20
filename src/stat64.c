#include <liblinux/linux.h>

extern inline linux_error_t linux_stat64(char const* filename, struct linux_stat64* statbuf);
