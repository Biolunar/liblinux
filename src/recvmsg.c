#include <liblinux/linux.h>

extern inline enum linux_error linux_recvmsg(int fd, struct linux_user_msghdr* msg, unsigned int flags, int* result);
