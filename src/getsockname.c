#include <liblinux/linux.h>

extern inline enum linux_error linux_getsockname(linux_fd_t fd, struct linux_sockaddr* usockaddr, int* usockaddr_len);
