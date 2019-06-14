#include <liblinux/linux.h>

extern inline enum linux_error linux_fchown16(linux_fd_t fd, linux_old_uid_t user, linux_old_gid_t group);
