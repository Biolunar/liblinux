#include <liblinux/linux.h>

extern inline linux_error_t linux_utime32(char const* filename, struct linux_utimbuf32* t);
