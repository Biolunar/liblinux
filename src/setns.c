#include <liblinux/linux.h>

extern inline enum linux_error_t linux_setns(int fd, int nstype);
