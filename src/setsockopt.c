#include <liblinux/linux.h>

extern inline enum linux_error linux_setsockopt(linux_fd_t fd, int level, int optname, char const* optval, int optlen);
