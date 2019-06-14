#include <liblinux/linux.h>

extern inline enum linux_error linux_ftruncate64(linux_fd_t fd, linux_loff_t length);
