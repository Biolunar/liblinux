#include <liblinux/linux.h>

extern inline linux_error_t linux_ftruncate64(linux_fd_t fd, linux_loff_t length);
