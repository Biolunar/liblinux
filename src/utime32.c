#include <liblinux/linux.h>

extern inline enum linux_error linux_utime32(char const* filename, struct linux_old_utimbuf32* t);
