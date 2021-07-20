#include <liblinux/linux.h>

extern inline linux_error_t linux_mknod(char const* filename, linux_umode_t mode, unsigned int dev);
