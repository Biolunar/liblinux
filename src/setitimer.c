#include <liblinux/linux.h>

extern inline enum linux_error_t linux_setitimer(int which, struct linux_itimerval* value, struct linux_itimerval* ovalue);
