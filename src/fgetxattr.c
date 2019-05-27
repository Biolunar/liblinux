#include <liblinux/linux.h>

extern inline enum linux_error linux_fgetxattr(int fd, char const* name, void* value, linux_size_t size, linux_ssize_t* result);
