#include <liblinux/linux.h>

extern inline enum linux_error linux_mknodat(linux_fd_t dfd, char const* filename, linux_umode_t mode, unsigned int dev);
