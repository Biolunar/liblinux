#include <liblinux/linux.h>

extern inline enum linux_error linux_timerfd_settime(linux_fd_t ufd, int flags, struct linux_kernel_itimerspec const* utmr, struct linux_kernel_itimerspec* otmr);
