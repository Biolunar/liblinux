#include <liblinux/linux.h>

extern inline enum linux_error linux_setsockopt(int fd, int level, int optname, char* optval, int optlen);
