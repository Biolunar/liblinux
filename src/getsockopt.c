#include <liblinux/linux.h>

extern inline enum linux_error_t linux_getsockopt(int fd, int level, int optname, char* optval, int* optlen);
