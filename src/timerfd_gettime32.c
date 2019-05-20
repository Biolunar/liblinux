#include <liblinux/linux.h>

extern inline enum linux_error_t linux_timerfd_gettime32(int ufd, struct linux_old_itimerspec32* otmr);
