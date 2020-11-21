#include <liblinux/linux.h>

extern inline enum linux_error linux_settimeofday(struct linux_old_timeval* tv, struct linux_timezone* tz);
