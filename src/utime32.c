#include <liblinux/linux.h>

extern inline enum linux_error_t linux_utime32(char const* filename, struct linux_old_utimbuf32* t);
