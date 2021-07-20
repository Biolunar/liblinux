#include <liblinux/linux.h>

extern inline linux_error_t linux_fsmount(linux_fd_t fs_fd, unsigned int flags, unsigned int ms_flags, linux_fd_t* result);
