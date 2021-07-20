#include <liblinux/linux.h>

extern inline linux_error_t linux_fallocate(linux_fd_t fd, int mode, linux_loff_t offset, linux_loff_t len);
