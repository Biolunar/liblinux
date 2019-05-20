#include <liblinux/linux.h>

extern inline enum linux_error_t linux_statfs(char const* pathname, struct linux_statfs* buf);
