#include <liblinux/linux.h>

extern inline linux_error_t linux_fchmodat(linux_fd_t dfd, char const* filename, linux_umode_t mode);
