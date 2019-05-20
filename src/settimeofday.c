#include <liblinux/linux.h>

extern inline enum linux_error_t linux_settimeofday(struct linux_timeval* tv, struct linux_timezone* tz);
