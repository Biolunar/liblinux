#include <liblinux/linux.h>

extern inline linux_error_t linux_renameat2(linux_fd_t olddfd, char const* oldname, linux_fd_t newdfd, char const* newname, unsigned int flags);
