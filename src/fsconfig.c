#include <liblinux/linux.h>

extern inline linux_error_t linux_fsconfig(linux_fd_t fs_fd, unsigned int cmd, char const* key, void const* value, int aux);
