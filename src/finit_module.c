#include <liblinux/linux.h>

extern inline enum linux_error linux_finit_module(linux_fd_t fd, char const* uargs, int flags);
