#include <liblinux/linux.h>

extern inline enum linux_error linux_renameat2(linux_fd_t olddfd, char const* oldname, linux_fd_t newdfd, char const* newname, unsigned int flags);
