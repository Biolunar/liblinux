#include <liblinux/linux.h>

extern inline enum linux_error linux_fstat64(linux_uword_t fd, struct linux_stat64* statbuf);
