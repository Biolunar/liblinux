#include <liblinux/linux.h>

extern inline enum linux_error_t linux_newfstat(unsigned int fd, struct linux_stat* statbuf);
