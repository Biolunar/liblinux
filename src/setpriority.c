#include <liblinux/linux.h>

extern inline enum linux_error_t linux_setpriority(int which, int who, int niceval);
