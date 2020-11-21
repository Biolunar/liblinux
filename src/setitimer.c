#include <liblinux/linux.h>

extern inline enum linux_error linux_setitimer(int which, struct linux_old_itimerval const* value, struct linux_old_itimerval* ovalue);
