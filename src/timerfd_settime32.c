#include <liblinux/linux.h>

extern inline linux_error_t linux_timerfd_settime32(linux_fd_t ufd, int flags, struct linux_itimerspec32 const* utmr, struct linux_itimerspec32* otmr);
