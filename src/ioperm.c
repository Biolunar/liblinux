#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(ioperm, linux_uword_t, from, linux_uword_t, num, int, turn_on);
