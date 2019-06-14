#include <liblinux/linux.h>

extern inline enum linux_error linux_setns(linux_fd_t fd, int nstype);
