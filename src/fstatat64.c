#include <liblinux/linux.h>

extern inline linux_error_t linux_fstatat64(linux_fd_t dfd, char const* filename, struct linux_stat64* statbuf, int flag);
