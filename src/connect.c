#include <liblinux/linux.h>

extern inline linux_error_t linux_connect(linux_fd_t fd, struct linux_sockaddr const* uservaddr, int addrlen);
