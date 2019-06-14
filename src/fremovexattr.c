#include <liblinux/linux.h>

extern inline enum linux_error linux_fremovexattr(linux_fd_t fd, char const* name);
