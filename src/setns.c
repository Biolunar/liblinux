#include <liblinux/linux.h>

extern inline linux_error_t linux_setns(linux_fd_t fd, int nstype);
