#include <liblinux/linux.h>

extern inline linux_error_t linux_chown16(char const* filename, linux_old_uid_t user, linux_old_gid_t group);
