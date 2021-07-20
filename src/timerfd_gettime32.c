#include <liblinux/linux.h>

extern inline linux_error_t linux_timerfd_gettime32(linux_fd_t ufd, struct linux_itimerspec32* otmr);
