#include <liblinux/linux.h>

extern inline enum linux_error linux_bind(linux_fd_t fd, struct linux_sockaddr const* umyaddr, int addrlen);
