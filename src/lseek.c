#include <liblinux/linux.h>

extern inline linux_error_t linux_lseek(linux_fd_t fd, linux_off_t offset, unsigned int whence, linux_off_t* result);
