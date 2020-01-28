#include <liblinux/linux.h>

extern inline enum linux_error linux_fspick(linux_fd_t dfd, char const* path, unsigned int flags, linux_fd_t* result);
