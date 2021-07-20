#include <liblinux/linux.h>

extern inline linux_error_t linux_lstat(char const* filename, struct linux_old_kernel_stat* statbuf);
