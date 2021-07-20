#include <liblinux/linux.h>

extern inline linux_error_t linux_fstatfs(linux_fd_t fd, struct linux_statfs* buf);
