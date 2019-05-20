#include <liblinux/linux.h>

extern inline enum linux_error_t linux_bind(int fd, struct linux_sockaddr* umyaddr, int addrlen);
