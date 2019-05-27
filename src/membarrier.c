#include <liblinux/linux.h>

extern inline enum linux_error linux_membarrier(int cmd, int flags, int* result);
