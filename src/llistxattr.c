#include <liblinux/linux.h>

extern inline linux_error_t linux_llistxattr(char const* pathname, char* list, linux_size_t size, linux_ssize_t* result);
