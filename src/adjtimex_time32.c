#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL1_RET(adjtimex_time32, struct linux_old_timex32*, utp, int);
