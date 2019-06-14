#include <liblinux/linux.h>

extern inline enum linux_error linux_recvmsg(linux_fd_t fd, struct linux_user_msghdr* msg, unsigned int flags, int* result);
