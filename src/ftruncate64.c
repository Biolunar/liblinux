#include <liblinux/linux.h>

extern inline enum linux_error_t linux_ftruncate64(unsigned int fd, linux_loff_t length);
