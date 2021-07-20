#include <liblinux/linux.h>

extern inline linux_error_t linux_statx(linux_fd_t dfd, char const* filename, unsigned int flags, unsigned int mask, struct linux_statx* buffer);
