#include <liblinux/linux.h>

extern inline enum linux_error linux_accept(int fd, struct linux_sockaddr* upeer_sockaddr, int* upeer_addrlen, int* result);
