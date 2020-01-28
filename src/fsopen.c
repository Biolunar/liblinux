#include <liblinux/linux.h>

extern inline enum linux_error linux_fsopen(char const* fs_name, unsigned int flags, linux_fd_t* result);
