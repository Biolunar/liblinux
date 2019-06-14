#include <liblinux/linux.h>

extern inline enum linux_error linux_getdents64(linux_fd_t fd, struct linux_dirent64* dirent, unsigned int count, int* result);
