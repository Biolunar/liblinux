#include <liblinux/linux.h>

extern inline enum linux_error linux_accept(linux_fd_t fd, struct linux_sockaddr* upeer_sockaddr, int* upeer_addrlen, linux_fd_t* result);
