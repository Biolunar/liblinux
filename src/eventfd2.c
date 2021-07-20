#include <liblinux/linux.h>

extern inline linux_error_t linux_eventfd2(unsigned int count, int flags, linux_fd_t* result);
