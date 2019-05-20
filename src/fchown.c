#include <liblinux/linux.h>

extern inline enum linux_error_t linux_fchown(unsigned int fd, linux_uid_t user, linux_gid_t group);
