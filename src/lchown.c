#include <liblinux/linux.h>

extern inline linux_error_t linux_lchown(char const* filename, linux_uid_t user, linux_gid_t group);
