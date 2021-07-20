#include <liblinux/linux.h>

extern inline linux_error_t linux_readlinkat(linux_fd_t dfd, char const* pathname, char* buf, int bufsiz, int* result);
