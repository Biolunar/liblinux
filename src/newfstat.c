#include <liblinux/linux.h>

extern inline linux_error_t linux_newfstat(linux_fd_t fd, struct linux_stat* statbuf);
