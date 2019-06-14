#include <liblinux/linux.h>

extern inline enum linux_error linux_timerfd_create(int clockid, int flags, linux_fd_t* result);
