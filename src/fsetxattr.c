#include <liblinux/linux.h>

extern inline enum linux_error linux_fsetxattr(linux_fd_t fd, char const* name, void const* value, linux_size_t size, int flags);
