#include <liblinux/linux.h>

extern inline enum linux_error_t linux_accept4(int fd, struct linux_sockaddr* upeer_sockaddr, int* upeer_addrlen, int flags, int* result);
