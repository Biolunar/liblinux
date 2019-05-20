#include <liblinux/linux.h>

extern inline enum linux_error_t linux_lstat(char const* filename, struct linux_old_kernel_stat* statbuf);
