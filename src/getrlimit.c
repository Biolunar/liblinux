#include <liblinux/linux.h>

extern inline enum linux_error linux_getrlimit(unsigned int resource, struct linux_rlimit* rlim);
