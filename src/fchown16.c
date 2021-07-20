#include <liblinux/linux.h>

extern inline linux_error_t linux_fchown16(linux_fd_t fd, linux_old_uid_t user, linux_old_gid_t group);
