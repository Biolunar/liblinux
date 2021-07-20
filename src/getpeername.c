#include <liblinux/linux.h>

extern inline linux_error_t linux_getpeername(linux_fd_t fd, struct linux_sockaddr* usockaddr, int* usockaddr_len);
