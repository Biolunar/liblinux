#include <liblinux/linux.h>

extern inline linux_error_t linux_fsetxattr_v(linux_fd_t fd, char const* name, void const* value, linux_size_t size, int flags);
