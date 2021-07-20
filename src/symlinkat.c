#include <liblinux/linux.h>

extern inline linux_error_t linux_symlinkat(char const* oldname, linux_fd_t newdfd, char const* newname);
