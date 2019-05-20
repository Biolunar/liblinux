#include <liblinux/linux.h>

extern inline enum linux_error_t linux_truncate64(char const* path, linux_loff_t length);
