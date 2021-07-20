#include <liblinux/linux.h>

extern inline linux_error_t linux_ioprio_get(int which, int who, int* result);
