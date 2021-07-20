#include <liblinux/linux.h>

extern inline linux_error_t linux_getsockopt(linux_fd_t fd, int level, int optname, char* optval, int* optlen);
