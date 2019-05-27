#include <liblinux/linux.h>

extern inline enum linux_error linux_utimes_time32(char const* filename, struct linux_old_timeval32* t);
