#include <liblinux/linux.h>

extern inline enum linux_error_t linux_fstatfs(unsigned int fd, struct linux_statfs* buf);
