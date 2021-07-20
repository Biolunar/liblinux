#include <liblinux/linux.h>

extern inline linux_error_t linux_utimes(char* filename, struct linux_old_timeval* utimes);
