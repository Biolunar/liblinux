#include <liblinux/linux.h>

extern inline linux_error_t linux_bind(linux_fd_t fd, struct linux_sockaddr const* umyaddr, int addrlen);
