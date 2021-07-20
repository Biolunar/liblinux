#include <liblinux/linux.h>

extern inline linux_error_t linux_fsopen(char const* fs_name, unsigned int flags, linux_fd_t* result);
