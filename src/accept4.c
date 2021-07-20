#include <liblinux/linux.h>

extern inline linux_error_t linux_accept4(linux_fd_t fd, struct linux_sockaddr* upeer_sockaddr, int* upeer_addrlen, int flags, linux_fd_t* result);
