#include <liblinux/linux.h>

extern inline enum linux_error linux_fsmount(linux_fd_t fs_fd, unsigned int flags, unsigned int ms_flags, linux_fd_t* result);
