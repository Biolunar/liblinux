#include <liblinux/linux.h>

extern inline linux_error_t linux_readahead(linux_fd_t fd, linux_loff_t offset, linux_size_t count);
