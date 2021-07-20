#include <liblinux/linux.h>

extern inline linux_error_t linux_ustat(unsigned int dev, struct linux_ustat* ubuf);
