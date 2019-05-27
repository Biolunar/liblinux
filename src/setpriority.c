#include <liblinux/linux.h>

extern inline enum linux_error linux_setpriority(int which, int who, int niceval);
