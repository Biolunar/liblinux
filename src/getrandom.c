#include <liblinux/linux.h>

extern inline linux_error_t linux_getrandom(char* buf, linux_size_t count, unsigned int flags, linux_ssize_t* result);
