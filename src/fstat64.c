#include <liblinux/linux.h>

extern inline linux_error_t linux_fstat64(linux_uword_t fd, struct linux_stat64* statbuf);
