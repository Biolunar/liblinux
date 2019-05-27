#include <liblinux/linux.h>

extern inline enum linux_error linux_timerfd_gettime(int ufd, struct linux_kernel_itimerspec* otmr);
