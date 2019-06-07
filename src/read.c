#include <liblinux/linux.h>

extern inline enum linux_error linux_read(linux_fd_t fd, char* buf, linux_size_t count, linux_ssize_t* result);
