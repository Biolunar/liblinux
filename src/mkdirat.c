#include <liblinux/linux.h>

extern inline enum linux_error linux_mkdirat(linux_fd_t dfd, char const* pathname, linux_umode_t mode);
