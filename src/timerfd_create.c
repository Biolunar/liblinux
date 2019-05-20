#include <liblinux/linux.h>

extern inline enum linux_error_t linux_timerfd_create(int clockid, int flags, int* result);
