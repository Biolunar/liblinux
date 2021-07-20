#include <liblinux/linux.h>

extern inline linux_error_t linux_unlinkat(linux_fd_t dfd, char const* pathname, int flag);
