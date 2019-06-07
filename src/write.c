#include <liblinux/linux.h>

extern inline enum linux_error linux_write(linux_fd_t fd, char const* buf, linux_size_t count, linux_ssize_t* result);
