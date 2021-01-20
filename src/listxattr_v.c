#include <liblinux/linux.h>

extern inline enum linux_error linux_listxattr_v(char const* pathname, char* list, linux_size_t size, linux_ssize_t* result);
