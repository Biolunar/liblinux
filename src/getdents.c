#include <liblinux/linux.h>

extern inline enum linux_error linux_getdents(linux_fd_t fd, struct linux_dirent* dirent, unsigned int count, int* result);
