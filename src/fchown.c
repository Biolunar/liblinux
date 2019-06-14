#include <liblinux/linux.h>

extern inline enum linux_error linux_fchown(linux_fd_t fd, linux_uid_t user, linux_gid_t group);
