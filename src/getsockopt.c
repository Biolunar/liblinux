#include <liblinux/linux.h>

extern inline enum linux_error linux_getsockopt(linux_fd_t fd, int level, int optname, char* optval, int* optlen);
