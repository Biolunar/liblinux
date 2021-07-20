#include <liblinux/linux.h>

extern inline linux_error_t linux_utimes_time32(char const* filename, struct linux_timeval32* t);
