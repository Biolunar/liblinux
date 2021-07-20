#include <liblinux/linux.h>

extern inline linux_error_t linux_sendmmsg(linux_fd_t fd, struct linux_mmsghdr* mmsg, unsigned int vlen, unsigned int flags, int* result);
