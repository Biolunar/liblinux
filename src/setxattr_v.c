#include <liblinux/linux.h>

extern inline linux_error_t linux_setxattr_v(char const* pathname, char const* name, void const* value, linux_size_t size, int flags);
