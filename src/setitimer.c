#include <liblinux/linux.h>

extern inline linux_error_t linux_setitimer(int which, struct linux_old_itimerval const* value, struct linux_old_itimerval* ovalue);
