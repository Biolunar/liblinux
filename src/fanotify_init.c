#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_RET(fanotify_init, unsigned int, flags, unsigned int, event_f_flags, int);
