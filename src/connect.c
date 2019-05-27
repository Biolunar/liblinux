#include <liblinux/linux.h>

extern inline enum linux_error linux_connect(linux_fd_t fd, struct linux_sockaddr const* uservaddr, int addrlen);
