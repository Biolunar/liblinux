#include <liblinux/linux.h>

extern inline enum linux_error linux_lchown(char const* filename, linux_uid_t user, linux_gid_t group);
