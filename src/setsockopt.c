#include <liblinux/linux.h>

extern inline enum linux_error_t linux_setsockopt(int fd, int level, int optname, char* optval, int optlen);
