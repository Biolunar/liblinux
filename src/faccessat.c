#include <liblinux/linux.h>

extern inline enum linux_error linux_faccessat(linux_fd_t dfd, char const* filename, int mode);
