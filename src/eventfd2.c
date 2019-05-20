#include <liblinux/linux.h>

extern inline enum linux_error_t linux_eventfd2(unsigned int count, int flags, int* result);
