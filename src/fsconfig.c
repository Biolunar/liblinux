#include <liblinux/linux.h>

extern inline enum linux_error linux_fsconfig(linux_fd_t fs_fd, unsigned int cmd, char const* key, void const* value, int aux);
