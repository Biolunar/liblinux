#include <liblinux/linux.h>

extern inline linux_error_t linux_truncate64(char const* path, linux_loff_t length);
