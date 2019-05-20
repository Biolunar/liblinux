#include <liblinux/linux.h>

extern inline enum linux_error_t linux_fallocate(int fd, int mode, linux_loff_t offset, linux_loff_t len);
