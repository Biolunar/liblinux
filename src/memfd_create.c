#include <liblinux/linux.h>

extern inline linux_error_t linux_memfd_create(char const* uname, unsigned int flags, linux_fd_t* result);
