#include <liblinux/linux.h>

extern inline enum linux_error linux_newfstatat(linux_fd_t dfd, char const* filename, struct linux_stat* statbuf, int flag);
