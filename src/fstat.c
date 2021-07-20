#include <liblinux/linux.h>

extern inline linux_error_t linux_fstat(linux_fd_t fd, struct linux_old_kernel_stat* statbuf);
