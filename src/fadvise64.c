#include <liblinux/linux.h>

extern inline enum linux_error linux_fadvise64(linux_fd_t fd, linux_loff_t offset, linux_size_t len, int advice);
