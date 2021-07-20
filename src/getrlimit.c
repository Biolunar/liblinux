#include <liblinux/linux.h>

extern inline linux_error_t linux_getrlimit(unsigned int resource, struct linux_rlimit* rlim);
