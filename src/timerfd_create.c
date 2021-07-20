#include <liblinux/linux.h>

extern inline linux_error_t linux_timerfd_create(int clockid, int flags, linux_fd_t* result);
