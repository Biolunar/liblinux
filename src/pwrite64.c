#include <liblinux/linux.h>

extern inline enum linux_error_t linux_pwrite64(unsigned int fd, char const* buf, linux_size_t count, linux_loff_t pos, linux_ssize_t* result);
