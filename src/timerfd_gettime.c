#include <liblinux/linux.h>

extern inline enum linux_error_t linux_timerfd_gettime(int ufd, struct linux_kernel_itimerspec* otmr);
