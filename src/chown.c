#include <liblinux/linux.h>

extern inline enum linux_error_t linux_chown(char const* filename, linux_uid_t user, linux_gid_t group);
