#include <liblinux/linux.h>

extern inline linux_error_t linux_recvmsg(linux_fd_t fd, struct linux_user_msghdr* msg, unsigned int flags, int* result);
