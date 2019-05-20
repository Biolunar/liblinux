#include <liblinux/linux.h>

extern inline enum linux_error_t linux_mkdirat(int dfd, char const* pathname, linux_umode_t mode);
