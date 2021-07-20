#include <liblinux/linux.h>

extern inline linux_error_t linux_getsockname(linux_fd_t fd, struct linux_sockaddr* usockaddr, int* usockaddr_len);
