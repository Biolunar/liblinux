#include <liblinux/linux.h>

extern inline enum linux_error linux_lseek(linux_fd_t fd, linux_off_t offset, unsigned int whence, linux_off_t* result);
