#include <liblinux/linux.h>

extern inline enum linux_error linux_ioprio_set(int which, int who, int ioprio);
