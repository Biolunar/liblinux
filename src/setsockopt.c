#include <liblinux/linux.h>

extern inline linux_error_t linux_setsockopt(linux_fd_t fd, int level, int optname, char const* optval, int optlen);
