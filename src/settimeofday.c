#include <liblinux/linux.h>

extern inline linux_error_t linux_settimeofday(struct linux_old_timeval* tv, struct linux_timezone* tz);
