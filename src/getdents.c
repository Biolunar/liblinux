#include <liblinux/linux.h>

extern inline linux_error_t linux_getdents(linux_fd_t fd, struct linux_dirent* dirent, unsigned int count, int* result);
