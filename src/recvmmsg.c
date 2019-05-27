#include <liblinux/linux.h>

extern inline enum linux_error linux_recvmmsg(int fd, struct linux_mmsghdr* mmsg, unsigned int vlen, unsigned int flags, struct linux_kernel_timespec* timeout, int* result);
