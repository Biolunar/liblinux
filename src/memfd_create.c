#include <liblinux/linux.h>

extern inline enum linux_error linux_memfd_create(char const* uname, unsigned int flags, linux_fd_t* result);
