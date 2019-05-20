#include <liblinux/linux.h>

extern inline enum linux_error_t linux_statfs64(char const* pathname, linux_size_t sz, struct linux_statfs64* buf);
