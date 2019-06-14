#include <liblinux/linux.h>

extern inline enum linux_error linux_symlinkat(char const* oldname, linux_fd_t newdfd, char const* newname);
