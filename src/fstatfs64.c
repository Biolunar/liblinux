#include <liblinux/linux.h>

extern inline enum linux_error linux_fstatfs64(linux_fd_t fd, linux_size_t sz, struct linux_statfs64* buf);
