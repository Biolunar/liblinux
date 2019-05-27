#include <liblinux/linux.h>

extern inline enum linux_error linux_fstat(unsigned int fd, struct linux_old_kernel_stat* statbuf);
