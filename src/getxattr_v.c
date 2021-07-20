#include <liblinux/linux.h>

extern inline linux_error_t linux_getxattr_v(char const* pathname, char const* name, void* value, linux_size_t size, linux_ssize_t* result);
