#include <liblinux/linux.h>

extern inline enum linux_error_t linux_listxattr(char const* pathname, char* list, linux_size_t size, linux_ssize_t* result);
