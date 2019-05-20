#include <liblinux/linux.h>

extern inline enum linux_error_t linux_sync_file_range(int fd, linux_loff_t offset, linux_loff_t nbytes, unsigned int flags);
