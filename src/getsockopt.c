#include <liblinux/linux.h>

extern inline enum linux_error linux_getsockopt(int fd, int level, int optname, char* optval, int* optlen);
