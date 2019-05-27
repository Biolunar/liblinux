#include <liblinux/linux.h>

extern inline enum linux_error linux_ioprio_get(int which, int who, int* result);
