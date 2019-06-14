#include <liblinux/linux.h>

extern inline enum linux_error linux_sync_file_range(linux_fd_t fd, linux_loff_t offset, linux_loff_t nbytes, unsigned int flags);
