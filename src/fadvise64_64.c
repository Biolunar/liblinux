#include <liblinux/linux.h>

extern inline enum linux_error_t linux_fadvise64_64(int fd, linux_loff_t offset, linux_loff_t len, int advice);
