#include <liblinux/linux.h>

extern inline enum linux_error_t linux_ioctl(unsigned int fd, unsigned int cmd, linux_uword_t arg, int* result);
