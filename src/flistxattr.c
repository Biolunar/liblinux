#include <liblinux/linux.h>

extern inline enum linux_error linux_flistxattr(linux_fd_t fd, char* list, linux_size_t size, linux_ssize_t* result);
