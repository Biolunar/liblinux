#include <liblinux/linux.h>

extern inline enum linux_error_t linux_old_getrlimit(unsigned int resource, struct linux_rlimit* rlim);
