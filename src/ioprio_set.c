#include <liblinux/linux.h>

extern inline linux_error_t linux_ioprio_set(int which, int who, int ioprio);
