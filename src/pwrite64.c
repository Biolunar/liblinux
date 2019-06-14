#include <liblinux/linux.h>

extern inline enum linux_error linux_pwrite64(linux_fd_t fd, char const* buf, linux_size_t count, linux_loff_t pos, linux_ssize_t* result);
