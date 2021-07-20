#include <liblinux/linux.h>

extern inline linux_error_t linux_tee(linux_fd_t fdin, linux_fd_t fdout, linux_size_t len, unsigned int flags, int* result);
