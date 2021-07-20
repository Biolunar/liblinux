#include <liblinux/linux.h>

extern inline linux_error_t linux_fadvise64_64(linux_fd_t fd, linux_loff_t offset, linux_loff_t len, int advice);
