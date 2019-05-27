#include <liblinux/linux.h>

extern inline enum linux_error linux_timerfd_create(int clockid, int flags, int* result);
