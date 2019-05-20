#include <liblinux/linux.h>

extern inline enum linux_error_t linux_membarrier(int cmd, int flags, int* result);
