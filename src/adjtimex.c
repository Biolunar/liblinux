#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL1_RET(adjtimex, struct linux_timex*, txc_p, int);
