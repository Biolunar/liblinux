#include <liblinux/linux.h>

extern inline linux_error_t linux_mkdirat(linux_fd_t dfd, char const* pathname, linux_umode_t mode);
