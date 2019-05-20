#include <liblinux/linux.h>

extern inline enum linux_error_t linux_recvmmsg_time32(int fd, struct linux_mmsghdr* mmsg, unsigned int vlen, unsigned int flags, struct linux_old_timespec32* timeout, int* result);
