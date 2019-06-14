#include <liblinux/linux.h>

extern inline enum linux_error linux_readahead(linux_fd_t fd, linux_loff_t offset, linux_size_t count);
