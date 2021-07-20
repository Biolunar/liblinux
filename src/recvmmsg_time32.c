#include <liblinux/linux.h>

extern inline linux_error_t linux_recvmmsg_time32(linux_fd_t fd, struct linux_mmsghdr* mmsg, unsigned int vlen, unsigned int flags, struct linux_timespec32* timeout, int* result);
