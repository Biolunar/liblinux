#include <liblinux/linux.h>

extern inline linux_error_t linux_utime(char* filename, struct linux_utimbuf* times);
