#include <liblinux/linux.h>

extern inline linux_error_t linux_newfstatat(linux_fd_t dfd, char const* filename, struct linux_stat* statbuf, int flag);
