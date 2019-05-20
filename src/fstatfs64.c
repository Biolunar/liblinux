#include <liblinux/linux.h>

extern inline enum linux_error_t linux_fstatfs64(unsigned int fd, linux_size_t sz, struct linux_statfs64* buf);
