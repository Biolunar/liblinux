#include <liblinux/linux.h>

extern inline enum linux_error linux_unlinkat(linux_fd_t dfd, char const* pathname, int flag);
