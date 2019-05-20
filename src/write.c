#include <liblinux/linux.h>

extern inline enum linux_error_t linux_write(unsigned int fd, char const* buf, linux_size_t count, linux_ssize_t* result);
