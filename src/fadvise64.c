#include <liblinux/linux.h>

extern inline linux_error_t linux_fadvise64(linux_fd_t fd, linux_loff_t offset, linux_size_t len, int advice);
