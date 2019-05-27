#include <liblinux/linux.h>

extern inline enum linux_error linux_timerfd_settime32(int ufd, int flags, struct linux_old_itimerspec32 const* utmr, struct linux_old_itimerspec32* otmr);
