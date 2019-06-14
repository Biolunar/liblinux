#include <liblinux/linux.h>

extern inline enum linux_error linux_fstat(linux_fd_t fd, struct linux_old_kernel_stat* statbuf);
