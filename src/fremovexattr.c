#include <liblinux/linux.h>

extern inline enum linux_error_t linux_fremovexattr(int fd, char const* name);
