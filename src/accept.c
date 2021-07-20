#include <liblinux/linux.h>

extern inline linux_error_t linux_accept(linux_fd_t fd, struct linux_sockaddr* upeer_sockaddr, int* upeer_addrlen, linux_fd_t* result);
