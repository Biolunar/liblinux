#include <liblinux/linux.h>

extern inline linux_error_t linux_fgetxattr_v(linux_fd_t fd, char const* name, void* value, linux_size_t size, linux_ssize_t* result);
