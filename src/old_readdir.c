#include <liblinux/linux.h>

extern inline linux_error_t linux_old_readdir(linux_fd_t fd, struct linux_old_linux_dirent* dirent, unsigned int count);
