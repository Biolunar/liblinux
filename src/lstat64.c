#include <liblinux/linux.h>

extern inline enum linux_error linux_lstat64(char const* filename, struct linux_stat64* statbuf);
