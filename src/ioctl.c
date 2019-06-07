#include <liblinux/linux.h>

extern inline enum linux_error linux_ioctl(linux_fd_t fd, unsigned int cmd, linux_uword_t arg, int* result);
