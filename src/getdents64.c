#include <liblinux/linux.h>

extern inline linux_error_t linux_getdents64(linux_fd_t fd, struct linux_dirent64* dirent, unsigned int count, int* result);
