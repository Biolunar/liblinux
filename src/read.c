#include <liblinux/linux.h>

extern inline enum linux_error linux_read(unsigned int fd, char* buf, linux_size_t count, linux_ssize_t* result);
