#include <liblinux/linux.h>

extern inline enum linux_error linux_getitimer(int which, struct linux_itimerval* value);
