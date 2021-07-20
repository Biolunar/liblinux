#include <liblinux/linux.h>

extern inline linux_error_t linux_fremovexattr(linux_fd_t fd, char const* name);
