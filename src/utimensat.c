#include <liblinux/linux.h>

extern inline enum linux_error_t linux_utimensat(int dfd, char const* filename, struct linux_kernel_timespec* utimes, int flags);
