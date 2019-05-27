#include <liblinux/linux.h>

extern inline enum linux_error linux_sendmmsg(int fd, struct linux_mmsghdr* mmsg, unsigned int vlen, unsigned int flags, int* result);
