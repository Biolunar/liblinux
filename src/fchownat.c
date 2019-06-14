#include <liblinux/linux.h>

extern inline enum linux_error linux_fchownat(linux_fd_t dfd, char const* filename, linux_uid_t user, linux_gid_t group, int flag);
