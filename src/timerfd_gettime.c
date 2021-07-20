#include <liblinux/linux.h>

extern inline linux_error_t linux_timerfd_gettime(linux_fd_t ufd, struct linux_itimerspec* otmr);
