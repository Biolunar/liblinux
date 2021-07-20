#include <liblinux/linux.h>

extern inline linux_error_t linux_faccessat2(linux_fd_t dfd, char const* filename, int mode, int flags);
