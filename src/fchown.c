#include <liblinux/linux.h>

extern inline linux_error_t linux_fchown(linux_fd_t fd, linux_uid_t user, linux_gid_t group);
