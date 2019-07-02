#include <liblinux/linux.h>

extern inline enum linux_error linux_openat(linux_fd_t dfd, char const* filename, int flags, linux_umode_t mode, linux_fd_t* result);
