#include <liblinux/linux.h>

extern inline linux_error_t linux_mount_setattr(linux_fd_t dfd, char const* path, unsigned int flags, struct linux_mount_attr* uattr, linux_size_t usize);
